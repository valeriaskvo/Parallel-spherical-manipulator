/*
 * eps.c
 *
 * Code generation for function 'eps'
 *
 */

/* Include files */
#include "eps.h"
#include "Cost_function.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
real_T eps(real_T x)
{
  real_T r;
  real_T absx;
  int32_T exponent;
  absx = muDoubleScalarAbs(x);
  if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
    if (absx <= 2.2250738585072014E-308) {
      r = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      r = ldexp(1.0, exponent - 53);
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/* End of code generation (eps.c) */
