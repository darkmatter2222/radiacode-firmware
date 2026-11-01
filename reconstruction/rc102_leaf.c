/* Reference rc-102 hardware 1 / firmware 4.14, address-linked source recovery.
 * These routines are independently compiled and compared with original ARM code.
 * This is a partial reconstruction, not a bootable application.
 *
 * Naming policy: describe demonstrated operations. Physical meanings of state
 * fields remain provisional unless supported by callers/configuration evidence.
 * Address aliases below keep existing analysis/test integrations compatible. */
typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
_Static_assert(sizeof(u32) == 4 && sizeof(u16) == 2, "ARM data widths required");

/* No caller-specific meaning is established for these constant-return leaves.
 * Calling them success/error/type getters would invent semantics. */
u32 rc_return_one(void) { return 1; }
u32 rc_return_two(void) { return 2; }
u32 rc_return_three(void) { return 3; }

/* Only fields actually used here are named. Padding preserves the observed
 * binary layout; it is not a declaration that intervening bytes are unused. */
typedef struct {
    u8 unresolved_00_10[0x11];
    u8 mode;
    u8 unresolved_12_4f[0x3e];
    s32 position_a;
    s32 position_b;
} RcTransferState;
_Static_assert(__builtin_offsetof(RcTransferState, mode) == 0x11, "mode offset");
_Static_assert(__builtin_offsetof(RcTransferState, position_a) == 0x50, "position A offset");
_Static_assert(__builtin_offsetof(RcTransferState, position_b) == 0x54, "position B offset");

/* Original 0x08017eb4. Signed ordering is essential at 0x7fffffff/0x80000000.
 * Modes 2,4,6 admit equality. All other byte values require strict ordering.
 * Volatile reads retain access to asynchronously updated shared state. Neither
 * the field names nor this bounded test establish a lock-free concurrency proof. */
u32 rc_transfer_positions_allow_progress(void) {
    volatile RcTransferState *transfer_state = (volatile RcTransferState *)0x20000d6c;
    u32 transfer_mode = transfer_state->mode;
    s32 position_a = transfer_state->position_a;
    s32 position_b = transfer_state->position_b;
    if (transfer_mode == 2 || transfer_mode == 4 || transfer_mode == 6)
        return position_a <= position_b;
    return position_a < position_b;
}

/* Symbol aliases have no wrapper instructions and preserve existing callers. */
extern __typeof__(rc_return_one) recovered_080166ce __attribute__((alias("rc_return_one")));
extern __typeof__(rc_return_two) recovered_08017ef2 __attribute__((alias("rc_return_two")));
extern __typeof__(rc_return_three) recovered_08017ef6 __attribute__((alias("rc_return_three")));
extern __typeof__(rc_transfer_positions_allow_progress) recovered_08017eb4 __attribute__((alias("rc_transfer_positions_allow_progress")));

/* Only the 0x502 path of the original multi-item accessor is reconstructed.
 * Owner word +8 is an advancing output cursor. The language-index interpretation
 * is supported by the VSFR map; the machine-code contract is a BYTE load from
 * 0x20000cc0 widened into a 32-bit output slot. Loading a word here was a real
 * prior defect. The caller must supply a valid writable output slot.
 * Returning zero for another id is a local test guard, not recovered dispatch. */
u32 rc_write_language_index_item(u32 *response_owner, u32 item_id) {
    if (item_id != 0x502) return 0;
    u32 *output_cursor = (u32 *)response_owner[2];
    response_owner[2] += sizeof(u32);
    *output_cursor = *(volatile u8 *)0x20000cc0;
    return 1;
}
extern __typeof__(rc_write_language_index_item) recovered_item_502 __attribute__((alias("rc_write_language_index_item")));

/* The event-ring pointer is read from literal 0x080168d0 in the reference image.
 * 16 halfword slots precede the write/read indices. One slot remains unused, so
 * the ring can hold 15 events. Preconditions: both indices are in [0,15], and no
 * concurrent producer/consumer modifies them during this bounded test. */
typedef struct {
    u16 event_codes[16];
    u32 write_index;
    u32 read_index;
} RcEventRing;
_Static_assert(__builtin_offsetof(RcEventRing, write_index) == 0x20, "ring write offset");
_Static_assert(__builtin_offsetof(RcEventRing, read_index) == 0x24, "ring read offset");

/* Original 0x08016862. Important convention: 0=queued, 1=full.
 * Advance before storing, and publish the write index after storing the event.
 * The firmware does not clear or overwrite an occupied slot when full. */
u32 rc_event_ring_try_push(u32 event_code) {
    volatile RcEventRing *event_ring = (volatile RcEventRing *)0x2000f424;
    u32 next_write_index = event_ring->write_index + 1;
    if (next_write_index == 16) next_write_index = 0;
    if (event_ring->read_index == next_write_index) return 1;
    event_ring->event_codes[next_write_index] = (u16)event_code;
    event_ring->write_index = next_write_index;
    return 0;
}
/* Original 0x080168a0: a boolean comparison, not a count of pending events. */
u32 rc_event_ring_has_pending(void) {
    volatile RcEventRing *event_ring = (volatile RcEventRing *)0x2000f424;
    return event_ring->read_index != event_ring->write_index;
}
extern __typeof__(rc_event_ring_try_push) recovered_08016862 __attribute__((alias("rc_event_ring_try_push")));
extern __typeof__(rc_event_ring_has_pending) recovered_080168a0 __attribute__((alias("rc_event_ring_has_pending")));

/* Original 0x08029370, 24 bytes (0x08029370-0x08029386), return-value only, no stores.
 * The literal slot at 0x080293fc holds the session-state block address (0x20000c0c in
 * the reference image); the compared state is the BYTE at block+0x0d, called S below.
 * Result = ((context == S) || (S == 0) ? 1 : 0) | (S << 8): the low byte is an
 * equality/zero-state flag, NOT a copy of the caller's byte, and the second byte is
 * the stored state. The observed reply word 0x00000201 therefore forces S = 2 and
 * context = 2. The volatile byte load keeps reads of shared state visible. */
u32 rc_session_state_flag(u32 context) {
    u32 state_block = *(const u32 *)0x080293fc;
    u32 stored = *(volatile const u8 *)(state_block + 0x0d);
    u32 match = (context == stored) ? 1u : ((stored == 0u) ? 1u : 0u);
    return match | (stored << 8);
}
extern __typeof__(rc_session_state_flag) recovered_08029370 __attribute__((alias("rc_session_state_flag")));
