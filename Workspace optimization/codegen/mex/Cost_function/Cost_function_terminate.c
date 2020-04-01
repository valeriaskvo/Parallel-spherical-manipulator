/*
 * Cost_function_terminate.c
 *
 * Code generation for function 'Cost_function_terminate'
 *
 */

/* Include files */
#include "Cost_function_terminate.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "_coder_Cost_function_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Cost_function_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Cost_function_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Cost_function_terminate.c) */
