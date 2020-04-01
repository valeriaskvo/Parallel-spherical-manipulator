/*
 * Cost_function_initialize.c
 *
 * Code generation for function 'Cost_function_initialize'
 *
 */

/* Include files */
#include "Cost_function_initialize.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "_coder_Cost_function_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Cost_function_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (Cost_function_initialize.c) */
