/*
 * File: Find_parameters_dynamixel_emxAPI.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

#ifndef FIND_PARAMETERS_DYNAMIXEL_EMXAPI_H
#define FIND_PARAMETERS_DYNAMIXEL_EMXAPI_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Find_parameters_dynamixel_types.h"

/* Function Declarations */
extern emxArray_char_T *emxCreateND_char_T(int numDimensions, const int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);
extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
  const int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, const int *size);
extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_char_T *emxCreate_char_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_rtString(rtString emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_rtString(rtString *pStruct);

#endif

/*
 * File trailer for Find_parameters_dynamixel_emxAPI.h
 *
 * [EOF]
 */
