/* Reference rc-102 4.14, entry 0x0802abf8: three-coefficient bounds predicate.
 *
 * The expression is a quadratic evaluated at x=256. Caller/domain analysis is
 * still needed before claiming physical units or a complete calibration API.
 * Compile for Cortex-M4 VFP with -ffp-contract=off and without fast-math:
 * original VMLA.F32 rounds the multiply and add separately, not as fused FMA.
 *
 * Contract tested: integer return, memory writes, integer callee-saved registers,
 * stack and full FPSCR. NaN acceptance is deliberately retained. */

/* Exact binary32 literals recovered from the original literal pool. Decimal
 * rounding to 30 or 4000 would move comparison boundaries by one ULP. */
#define RC_CONSTANT_TERM_ABS_LIMIT 0x1.e00002p+4f  /* bits 0x41f00001 */
#define RC_POLYNOMIAL_SAMPLE_INDEX 256.0f         /* bits 0x43800000 */
#define RC_POLYNOMIAL_LOWER_BOUND 2000.0f         /* bits 0x44fa0000 */
#define RC_POLYNOMIAL_UPPER_BOUND 0x1.f40002p+11f  /* bits 0x457a0001 */

/* Ordinary C comparisons compiled to VCMPE in the first reconstruction,
 * changing quiet-NaN exception flags in 1,513 test cases. Preserve VCMP itself.
 * "t" constrains operands to scalar VFP registers; VMRS reads FPSCR without
 * replacing it. The caller uses N and V exactly as the original branches do. */
static unsigned rc_fp_compare_quiet(float left_operand, float right_operand) {
    unsigned comparison_fpscr;
    __asm__ volatile ("vcmp.f32 %1, %2\n\tvmrs %0, fpscr"
                      : "=r" (comparison_fpscr)
                      : "t" (left_operand), "t" (right_operand) : "cc");
    return comparison_fpscr;
}

/* After VCMP: N=1 means ordered less-than. Unordered produces N=0,V=1.
 * Consequently ARM LT (N != V) admits unordered comparisons, while MI (N=1)
 * does not. Converting both branches to the same C comparison is incorrect. */
static unsigned rc_fp_is_ordered_less(unsigned comparison_fpscr) {
    return comparison_fpscr >> 31;
}
static unsigned rc_fp_is_less_or_unordered(unsigned comparison_fpscr) {
    unsigned negative_flag = comparison_fpscr >> 31;
    unsigned unordered_flag = (comparison_fpscr >> 28) & 1u;
    return negative_flag ^ unordered_flag;
}

unsigned rc_coefficient_triplet_passes_bounds(volatile const float *coefficients) {
    /* Preserve conditional loads: rejecting an early coefficient must not
     * eagerly read subsequent array entries. Caller supplies readable floats. */
    float constant_term = coefficients[0];
    if (!rc_fp_is_less_or_unordered(rc_fp_compare_quiet(
            __builtin_fabsf(constant_term), RC_CONSTANT_TERM_ABS_LIMIT))) return 0;

    float linear_term = coefficients[1];
    if (rc_fp_is_ordered_less(rc_fp_compare_quiet(linear_term, 4.0f))) return 0;

    float quadratic_term = coefficients[2];
    if (rc_fp_is_ordered_less(rc_fp_compare_quiet(quadratic_term, 0.0f))) return 0;

    /* Horner form preserves the original arithmetic association and rounding. */
    float polynomial_value_at_256 = constant_term +
        (linear_term + quadratic_term * RC_POLYNOMIAL_SAMPLE_INDEX) * RC_POLYNOMIAL_SAMPLE_INDEX;
    if (rc_fp_is_ordered_less(rc_fp_compare_quiet(
            polynomial_value_at_256, RC_POLYNOMIAL_LOWER_BOUND))) return 0;
    return rc_fp_is_less_or_unordered(rc_fp_compare_quiet(
            polynomial_value_at_256, RC_POLYNOMIAL_UPPER_BOUND));
}

/* Compatibility symbol for address-based harnesses; no extra wrapper code. */
extern __typeof__(rc_coefficient_triplet_passes_bounds) recovered_0802abf8
    __attribute__((alias("rc_coefficient_triplet_passes_bounds")));

/* TEST-ONLY NEGATIVE ORACLE. This is intentionally wrong for NaNs. It captures
 * the ordered conjunction suggested by the raw Ghidra export, so tests prove
 * they can reject that attractive but behavior-changing cleanup. */
unsigned ordered_transcription(const float *coefficients) {
    float polynomial_value_at_256 = coefficients[0] +
        (coefficients[1] + coefficients[2] * RC_POLYNOMIAL_SAMPLE_INDEX) * RC_POLYNOMIAL_SAMPLE_INDEX;
    return __builtin_fabsf(coefficients[0]) < RC_CONSTANT_TERM_ABS_LIMIT && coefficients[1] >= 4.0f &&
           coefficients[2] >= 0.0f && polynomial_value_at_256 >= RC_POLYNOMIAL_LOWER_BOUND &&
           polynomial_value_at_256 < RC_POLYNOMIAL_UPPER_BOUND;
}
