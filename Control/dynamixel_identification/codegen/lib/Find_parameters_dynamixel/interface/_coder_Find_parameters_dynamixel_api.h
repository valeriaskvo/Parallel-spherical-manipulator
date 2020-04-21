/*
 * File: _coder_Find_parameters_dynamixel_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

#ifndef _CODER_FIND_PARAMETERS_DYNAMIXEL_API_H
#define _CODER_FIND_PARAMETERS_DYNAMIXEL_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_rtString
#define typedef_rtString

typedef struct {
  emxArray_char_T *Value;
} rtString;

#endif                                 /*typedef_rtString*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void Find_parameters_dynamixel(real_T N, emxArray_real_T *t,
  emxArray_real_T *dtheta, emxArray_real_T *ddtheta, emxArray_real_T *b_I,
  rtString *dtype, real_T k_dtheta, real_T K_m, real_T p[3], emxArray_real_T
  *p_s, real_T R[9], emxArray_real_T *R_s, emxArray_real_T *time);
extern void Find_parameters_dynamixel_api(const mxArray * const prhs[8], int32_T
  nlhs, const mxArray *plhs[5]);
extern void Find_parameters_dynamixel_atexit(void);
extern void Find_parameters_dynamixel_initialize(void);
extern void Find_parameters_dynamixel_terminate(void);
extern void Find_parameters_dynamixel_xil_shutdown(void);
extern void Find_parameters_dynamixel_xil_terminate(void);

#endif

/*
 * File trailer for _coder_Find_parameters_dynamixel_api.h
 *
 * [EOF]
 */
