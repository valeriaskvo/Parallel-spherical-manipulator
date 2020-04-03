/*
 * File: _coder_Forward_kinematics_v2_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef _CODER_FORWARD_KINEMATICS_V2_API_H
#define _CODER_FORWARD_KINEMATICS_V2_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void Forward_kinematics_v2(real_T system_parameters[5], real_T q[4],
  real_T phi[3]);
extern void Forward_kinematics_v2_api(const mxArray * const prhs[2], int32_T
  nlhs, const mxArray *plhs[1]);
extern void Forward_kinematics_v2_atexit(void);
extern void Forward_kinematics_v2_initialize(void);
extern void Forward_kinematics_v2_terminate(void);
extern void Forward_kinematics_v2_xil_shutdown(void);
extern void Forward_kinematics_v2_xil_terminate(void);

#endif

/*
 * File trailer for _coder_Forward_kinematics_v2_api.h
 *
 * [EOF]
 */
