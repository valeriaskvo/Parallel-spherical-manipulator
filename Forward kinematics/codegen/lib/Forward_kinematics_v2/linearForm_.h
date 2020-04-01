/*
 * File: linearForm_.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

#ifndef LINEARFORM__H
#define LINEARFORM__H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void linearForm_(boolean_T obj_hasLinear, int obj_nvar, double workspace
  [36], const double H[25], const double f[6], const double x[6]);

#endif

/*
 * File trailer for linearForm_.h
 *
 * [EOF]
 */
