/* rc-102 4.14, entry 0x0802abf8. Contract recovered from Thumb/VFP,
 * not inferred domain semantics. NaNs intentionally follow ARM unordered flags.
 * VMLA.F32 is non-fused: compile with -ffp-contract=off, without fast-math. */
unsigned recovered_0802abf8(volatile const float *p) {
    float a = p[0];
    if (__builtin_fabsf(a) >= 0x1.e00002p+4f) return 0;
    float b = p[1];
    if (b < 4.0f) return 0;
    float c = p[2];
    if (c < 0.0f) return 0;
    float result = a + (b + c * 256.0f) * 256.0f;
    if (result < 2000.0f) return 0;
    return !(result >= 0x1.f40002p+11f);
}
/* Deliberately wrong ordered-comparison transcription, retained as a negative
 * oracle: this is the logic suggested by the readable Ghidra export. */
unsigned ordered_transcription(const float *p) {
    float r = p[0] + (p[1] + p[2] * 256.0f) * 256.0f;
    return __builtin_fabsf(p[0]) < 0x1.e00002p+4f && p[1] >= 4.0f &&
           p[2] >= 0.0f && r >= 2000.0f && r < 0x1.f40002p+11f;
}
