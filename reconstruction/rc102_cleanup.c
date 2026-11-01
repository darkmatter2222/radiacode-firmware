/* Recovered 0x08029086 -> 0x08022e60 -> 0x08016780.
 * Reference image only. Valid writable nodes, acyclic list, no concurrent mutation.
 * Names describe observed operations; physical scheduling semantics are unproven. */
typedef unsigned int u32;
typedef unsigned char u8;
_Static_assert(sizeof(u32)==4, "32-bit ARM required");

u32 rc_session_cleanup(void) {
    u32 owner = *(const u32 *)0x08029160;
    u32 flag = *(volatile u32 *)(owner + 0x10);
    *(volatile u8 *)flag = 0;
    u32 state = *(const u32 *)0x0802915c;
    u32 bits = *(volatile u32 *)state;
    *(volatile u32 *)(state + 0x14) = 0;
    *(volatile u32 *)state = bits & ~4u;
    u32 node = *(const u32 *)0x08022ec0;
    u32 head_slot = *(const u32 *)0x08016854;
    u32 current = *(volatile u32 *)head_slot;
    if (current == node) {
        *(volatile u32 *)head_slot = *(volatile u32 *)(node + 4);
    } else if (current != 0) {
        u32 previous;
        do {
            previous = current;
            current = *(volatile u32 *)(current + 4);
        } while (current != 0 && current != node);
        if (current != 0)
            *(volatile u32 *)(previous + 4) = *(volatile u32 *)(current + 4);
    }
    *(volatile u8 *)(node + 0x0c) = 0;
    *(volatile u32 *)(node + 4) = 0;
    return node; /* Original r0 survives the unlink tail call. */
}
