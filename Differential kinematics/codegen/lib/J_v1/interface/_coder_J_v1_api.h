/*
 * File: _coder_J_v1_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:02:07
 */

#ifndef _CODER_J_V1_API_H
#define _CODER_J_V1_API_H

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
extern void J_v1(real_T system_parameters[5], real_T phi_ee[3], real_T J[9]);
extern void J_v1_api(const mxArray * const prhs[2], int32_T nlhs, const mxArray *
                     plhs[1]);
extern void J_v1_atexit(void);
extern void J_v1_initialize(void);
extern void J_v1_terminate(void);
extern void J_v1_xil_shutdown(void);
extern void J_v1_xil_terminate(void);

#endif

/*
 * File trailer for _coder_J_v1_api.h
 *
 * [EOF]
 */
