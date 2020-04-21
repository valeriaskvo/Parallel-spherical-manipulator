/*
 * File: _coder_Find_parameters_dynamixel_mex.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "_coder_Find_parameters_dynamixel_mex.h"
#include "_coder_Find_parameters_dynamixel_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_Find_parameters_dynamixel_mex(int32_T nlhs, mxArray
  *plhs[5], int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[5]
 *                int32_T nrhs
 *                const mxArray *prhs[8]
 * Return Type  : void
 */
void c_Find_parameters_dynamixel_mex(int32_T nlhs, mxArray *plhs[5], int32_T
  nrhs, const mxArray *prhs[8])
{
  const mxArray *outputs[5];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        25, "Find_parameters_dynamixel");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "Find_parameters_dynamixel");
  }

  /* Call the function. */
  Find_parameters_dynamixel_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Find_parameters_dynamixel_atexit);

  /* Module initialization. */
  Find_parameters_dynamixel_initialize();

  /* Dispatch the entry-point. */
  c_Find_parameters_dynamixel_mex(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Find_parameters_dynamixel_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_Find_parameters_dynamixel_mex.c
 *
 * [EOF]
 */
