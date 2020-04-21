/*
 * File: Find_parameters_dynamixel_emxutil.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

#ifndef FIND_PARAMETERS_DYNAMIXEL_EMXUTIL_H
#define FIND_PARAMETERS_DYNAMIXEL_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Find_parameters_dynamixel_types.h"

/* Function Declarations */
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFreeStruct_rtString(rtString *pStruct);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_rtString(rtString *pStruct);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for Find_parameters_dynamixel_emxutil.h
 *
 * [EOF]
 */
