/*
 * File: maxConstraintViolation.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef MAXCONSTRAINTVIOLATION_H
#define MAXCONSTRAINTVIOLATION_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern double b_maxConstraintViolation(const g_struct_T *obj, const double x[6],
  int ix0);
extern double maxConstraintViolation(const g_struct_T *obj, const double x[36],
  int ix0);

#endif

/*
 * File trailer for maxConstraintViolation.h
 *
 * [EOF]
 */
