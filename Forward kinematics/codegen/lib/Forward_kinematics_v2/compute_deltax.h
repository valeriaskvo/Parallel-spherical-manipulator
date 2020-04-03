/*
 * File: compute_deltax.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

#ifndef COMPUTE_DELTAX_H
#define COMPUTE_DELTAX_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void compute_deltax(const double H[25], d_struct_T *solution, c_struct_T *
  memspace, const i_struct_T *qrmanager, k_struct_T *cholmanager, const
  j_struct_T *objective);

#endif

/*
 * File trailer for compute_deltax.h
 *
 * [EOF]
 */
