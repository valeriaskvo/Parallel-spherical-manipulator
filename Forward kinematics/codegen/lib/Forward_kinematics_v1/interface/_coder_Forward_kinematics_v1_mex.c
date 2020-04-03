/*
 * File: _coder_Forward_kinematics_v1_mex.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "_coder_Forward_kinematics_v1_mex.h"
#include "_coder_Forward_kinematics_v1_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_Forward_kinematics_v1_mexFunc(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[2]
 * Return Type  : void
 */
void c_Forward_kinematics_v1_mexFunc(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[2])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        21, "Forward_kinematics_v1");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "Forward_kinematics_v1");
  }

  /* Call the function. */
  Forward_kinematics_v1_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
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
  mexAtExit(Forward_kinematics_v1_atexit);

  /* Module initialization. */
  Forward_kinematics_v1_initialize();

  /* Dispatch the entry-point. */
  c_Forward_kinematics_v1_mexFunc(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Forward_kinematics_v1_terminate();
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
 * File trailer for _coder_Forward_kinematics_v1_mex.c
 *
 * [EOF]
 */
