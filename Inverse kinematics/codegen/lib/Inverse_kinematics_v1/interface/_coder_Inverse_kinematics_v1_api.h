/*
 * File: _coder_Inverse_kinematics_v1_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 11:55:34
 */

#ifndef _CODER_INVERSE_KINEMATICS_V1_API_H
#define _CODER_INVERSE_KINEMATICS_V1_API_H

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
extern void Inverse_kinematics_v1(real_T system_parameters[5], real_T phi_ee[3],
  real_T q_v1[3]);
extern void Inverse_kinematics_v1_api(const mxArray * const prhs[2], int32_T
  nlhs, const mxArray *plhs[1]);
extern void Inverse_kinematics_v1_atexit(void);
extern void Inverse_kinematics_v1_initialize(void);
extern void Inverse_kinematics_v1_terminate(void);
extern void Inverse_kinematics_v1_xil_shutdown(void);
extern void Inverse_kinematics_v1_xil_terminate(void);

#endif

/*
 * File trailer for _coder_Inverse_kinematics_v1_api.h
 *
 * [EOF]
 */
