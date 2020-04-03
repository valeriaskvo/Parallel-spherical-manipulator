/*
 * File: driver1.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef DRIVER1_H
#define DRIVER1_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void b_driver(const double H[25], const double f[6], d_struct_T *solution,
                     c_struct_T *memspace, g_struct_T *workingset, i_struct_T
                     *qrmanager, k_struct_T *cholmanager, j_struct_T *objective,
                     b_struct_T options);

#endif

/*
 * File trailer for driver1.h
 *
 * [EOF]
 */
