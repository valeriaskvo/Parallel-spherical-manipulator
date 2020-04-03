/*
 * File: iterate.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

#ifndef ITERATE_H
#define ITERATE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Type Definitions */
#include <stdio.h>

/* Function Declarations */
extern void iterate(const double H[25], const double f[6], d_struct_T *solution,
                    c_struct_T *memspace, g_struct_T *workingset, i_struct_T
                    *qrmanager, k_struct_T *cholmanager, j_struct_T *objective,
                    int options_MaxIterations, double options_StepTolerance,
                    double options_ConstraintTolerance, double
                    options_ObjectiveLimit, boolean_T options_DisplayQP);

#endif

/*
 * File trailer for iterate.h
 *
 * [EOF]
 */
