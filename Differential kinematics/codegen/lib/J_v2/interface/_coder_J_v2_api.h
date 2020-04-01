/*
 * File: _coder_J_v2_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:04:06
 */

#ifndef _CODER_J_V2_API_H
#define _CODER_J_V2_API_H

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
extern void J_v2(real_T system_parameters[5], real_T phi_ee[3], real_T J[12]);
extern void J_v2_api(const mxArray * const prhs[2], int32_T nlhs, const mxArray *
                     plhs[1]);
extern void J_v2_atexit(void);
extern void J_v2_initialize(void);
extern void J_v2_terminate(void);
extern void J_v2_xil_shutdown(void);
extern void J_v2_xil_terminate(void);

#endif

/*
 * File trailer for _coder_J_v2_api.h
 *
 * [EOF]
 */
