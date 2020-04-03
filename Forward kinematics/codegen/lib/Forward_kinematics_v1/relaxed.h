/*
 * File: relaxed.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

#ifndef RELAXED_H
#define RELAXED_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern void relaxed(const double Hessian[36], const double grad[7], d_struct_T
                    *TrialState, h_struct_T *MeritFunction, c_struct_T *memspace,
                    f_struct_T *WorkingSet, i_struct_T *QRManager, k_struct_T
                    *CholManager, j_struct_T *QPObjective, b_struct_T *qpoptions);

#endif

/*
 * File trailer for relaxed.h
 *
 * [EOF]
 */
