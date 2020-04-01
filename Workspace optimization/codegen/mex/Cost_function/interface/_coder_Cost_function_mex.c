/*
 * _coder_Cost_function_mex.c
 *
 * Code generation for function '_coder_Cost_function_mex'
 *
 */

/* Include files */
#include "_coder_Cost_function_mex.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "Cost_function_initialize.h"
#include "Cost_function_terminate.h"
#include "_coder_Cost_function_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void Cost_function_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[5]);

/* Function Definitions */
void Cost_function_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[5])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        13, "Cost_function");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "Cost_function");
  }

  /* Call the function. */
  Cost_function_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Cost_function_atexit);

  /* Module initialization. */
  Cost_function_initialize();

  /* Dispatch the entry-point. */
  Cost_function_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Cost_function_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Cost_function_mex.c) */
