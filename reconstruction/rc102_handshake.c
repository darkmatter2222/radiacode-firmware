/* Reference handler at 0x08027490. Valid disjoint request/response/context buffers,
 * sufficient output capacity, valid acyclic cleanup list, no concurrent mutation.
 * The machine code saves incoming r3 then pops it into r0 on every return.
 * Preserve that observed behavior explicitly; do not invent a status return. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct {
    u32 context;
    u32 input_cursor;
    u32 output_cursor;
    u32 unresolved;
    u32 flag;
} RcRequest;
_Static_assert(sizeof(u32)==4, "32-bit ARM required");
_Static_assert(__builtin_offsetof(RcRequest,flag)==16, "owner layout");
extern u32 rc_session_state_flag(u32 context);
extern u32 rc_session_cleanup(void);

u32 rc_handshake_handler(volatile RcRequest *owner, u32 arg1, u32 arg2, u32 incoming_r3) {
    (void)arg1; (void)arg2;
    u32 input=owner->input_cursor;
    owner->input_cursor=input+4;
    if (*(volatile u32 *)input != *(const u32 *)0x08027da0) {
        u32 output=owner->output_cursor;
        owner->output_cursor=output+4;
        *(volatile u32 *)output=*(const u32 *)0x08027d98;
        return incoming_r3;
    }
    u32 state=*(const u32 *)0x08027d6c;
    *(volatile u32 *)(state+4) |= 2u;
    u32 output=owner->output_cursor;
    *(volatile u32 *)output=*(const u32 *)0x08027da8;
    *(volatile u32 *)(output+4)=*(const u32 *)0x08027da4;
    owner->output_cursor=output+12;
    u32 context=owner->context;
    u32 word_a=*(volatile u32 *)(context+12);
    u32 word_b=*(volatile u32 *)(context+16);
    *(volatile u32 *)(output+8)=word_b | ((word_a-32u)<<16);
    u32 reply=owner->output_cursor;
    owner->output_cursor=reply+4;
    *(volatile u32 *)reply=rc_session_state_flag(*(volatile u8 *)context);
    context=owner->context;
    u32 kind=*(volatile u8 *)context;
    if (kind==1) {
        *(volatile u8 *)owner->flag=0;
    } else if (kind==2) {
        rc_session_cleanup();
        u32 block=*(const u32 *)0x08027dac;
        if (*(volatile u8 *)(block+13)==0)
            *(volatile u8 *)(block+13)=1;
    }
    return incoming_r3;
}
