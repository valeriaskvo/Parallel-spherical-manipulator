/*
 * File: maxConstraintViolation.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

#ifndef MAXCONSTRAINTVIOLATION_H
#define MAXCONSTRAINTVIOLATION_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern double b_maxConstraintViolation(const f_struct_T *obj, const double x[7]);
extern double maxConstraintViolation(const f_struct_T *obj, const double x[49],
  int ix0);

#endif

/*
 * File trailer for maxConstraintViolation.h
 *
 * [EOF]
 */
