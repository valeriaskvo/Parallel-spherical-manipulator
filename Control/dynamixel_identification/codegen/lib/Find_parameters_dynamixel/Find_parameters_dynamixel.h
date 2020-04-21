/*
 * File: Find_parameters_dynamixel.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

#ifndef FIND_PARAMETERS_DYNAMIXEL_H
#define FIND_PARAMETERS_DYNAMIXEL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Find_parameters_dynamixel_types.h"

/* Function Declarations */
extern void Find_parameters_dynamixel(double N, const emxArray_real_T *t, const
  emxArray_real_T *dtheta, const emxArray_real_T *ddtheta, const emxArray_real_T
  *b_I, const rtString *dtype, double k_dtheta, double K_m, double p[3],
  emxArray_real_T *p_s, double R[9], emxArray_real_T *R_s, emxArray_real_T *time);

#endif

/*
 * File trailer for Find_parameters_dynamixel.h
 *
 * [EOF]
 */
