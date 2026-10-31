/* Reviewed candidates tied to rc-102/hw1-fw4.14. Not complete firmware.
 * Each function retains the original address in its name for traceability.
 * Compile for Cortex-M4 Thumb with a 32-bit ABI. */
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
_Static_assert(sizeof(u32) == 4, "32-bit ABI required");
u32 recovered_080166ce(void) { return 1; }
u32 recovered_08017ef2(void) { return 2; }
u32 recovered_08017ef6(void) { return 3; }
u32 recovered_08017eb4(void) {
    volatile u8 *state = (volatile u8 *)0x20000d6c;
    u32 mode = state[0x11];
    s32 head = *(volatile s32 *)(state + 0x50);
    s32 tail = *(volatile s32 *)(state + 0x54);
    if (mode == 2 || mode == 4 || mode == 6) return head <= tail;
    return head < tail;
}
/* Only the 0x502 path of the original multi-item accessor is reconstructed. */
u32 recovered_item_502(u32 *owner, u32 id) {
    if (id != 0x502) return 0; /* outside the tested contract */
    u32 *cursor = (u32 *)owner[2];
    owner[2] += 4;
    *cursor = *(volatile u8 *)0x20000cc0;
    return 1;
}
