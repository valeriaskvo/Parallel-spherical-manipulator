/*
 * File: generate_model_vectors.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

#ifndef GENERATE_MODEL_VECTORS_H
#define GENERATE_MODEL_VECTORS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Find_parameters_dynamixel_types.h"

/* Function Declarations */
extern void generate_model_vectors(const emxArray_real_T *time, const
  emxArray_real_T *dtheta, const emxArray_real_T *ddtheta, const emxArray_real_T
  *b_I, const emxArray_char_T *dtype_Value, double k_dtheta, double K_m,
  emxArray_real_T *Y_k, emxArray_real_T *tau_k);

#endif

/*
 * File trailer for generate_model_vectors.h
 *
 * [EOF]
 */
