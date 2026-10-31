/* rc-102 4.14, entry 0x0802abf8. Contract recovered from Thumb/VFP,
 * not inferred domain semantics. NaNs intentionally follow ARM unordered flags.
 * VMLA.F32 is non-fused: compile with -ffp-contract=off, without fast-math. */
/* ISO C comparisons may compile to VCMPE, which raises invalid-operation
 * for quiet NaNs. Preserve the original quiet VCMP and its FPSCR flags.
 * This small ARM-specific adapter is intentional, not a portable-C claim. */
static unsigned quiet_compare(float a, float b) {
    unsigned flags;
    __asm__ volatile ("vcmp.f32 %1, %2\n\tvmrs %0, fpscr"
                      : "=r" (flags) : "t" (a), "t" (b) : "cc");
    return flags;
}
static unsigned negative(unsigned f) { return f >> 31; }
static unsigned less_or_unordered(unsigned f) {
    return (f >> 31) ^ ((f >> 28) & 1u);
}
unsigned recovered_0802abf8(volatile const float *p) {
    float a = p[0];
    if (!less_or_unordered(quiet_compare(__builtin_fabsf(a), 0x1.e00002p+4f))) return 0;
    float b = p[1];
    if (negative(quiet_compare(b, 4.0f))) return 0;
    float c = p[2];
    if (negative(quiet_compare(c, 0.0f))) return 0;
    float result = a + (b + c * 256.0f) * 256.0f;
    if (negative(quiet_compare(result, 2000.0f))) return 0;
    return less_or_unordered(quiet_compare(result, 0x1.f40002p+11f));
}
/* Deliberately wrong ordered-comparison transcription, retained as a negative
 * oracle: this is the logic suggested by the readable Ghidra export. */
unsigned ordered_transcription(const float *p) {
    float r = p[0] + (p[1] + p[2] * 256.0f) * 256.0f;
    return __builtin_fabsf(p[0]) < 0x1.e00002p+4f && p[1] >= 4.0f &&
           p[2] >= 0.0f && r >= 2000.0f && r < 0x1.f40002p+11f;
}
