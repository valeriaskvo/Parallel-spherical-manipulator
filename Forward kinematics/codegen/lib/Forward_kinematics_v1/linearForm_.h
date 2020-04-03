/*
 * File: linearForm_.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

#ifndef LINEARFORM__H
#define LINEARFORM__H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern void linearForm_(boolean_T obj_hasLinear, int obj_nvar, double workspace
  [49], const double H[36], const double f[7], const double x[7]);

#endif

/*
 * File trailer for linearForm_.h
 *
 * [EOF]
 */
