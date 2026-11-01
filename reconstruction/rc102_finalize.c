/* Original response finalizer 0x080273a2. Writable disjoint buffers and owner;
 * no concurrent mutation. Unsigned subtraction/comparison matches ARM behavior.
 * The capacity check occurs after handler output, so it does NOT prevent an
 * earlier out-of-bounds write; callers must still provide sufficient storage. */
typedef unsigned int u32;
_Static_assert(sizeof(u32)==4,"32-bit words required");
u32 rc_finalize_response(volatile u32 *owner) {
    u32 context=owner[0];
    u32 buffer=*(volatile u32 *)(context+8);
    u32 end=owner[2];
    owner[2]=buffer+4;
    u32 capacity=*(volatile u32 *)(context+16);
    u32 length=end-(buffer+4);
    if (capacity<length) {
        *(volatile u32 *)(buffer+4)=*(const u32 *)0x08027d8c;
        length=4;
    }
    *(volatile u32 *)buffer=length;
    u32 state=*(const u32 *)0x08027d6c;
    u32 first=*(volatile u32 *)(buffer+4);
    u32 flags=*(volatile u32 *)state;
    *(volatile u32 *)(buffer+4)=first|flags;
    return flags;
}
