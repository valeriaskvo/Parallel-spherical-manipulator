/*
 * File: driver.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

#ifndef DRIVER_H
#define DRIVER_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern void driver(d_struct_T *TrialState, h_struct_T *MeritFunction, const
                   e_struct_T *FcnEvaluator, g_struct_T *FiniteDifferences,
                   c_struct_T *memspace, f_struct_T *WorkingSet, i_struct_T
                   *QRManager, j_struct_T *QPObjective, double Hessian[36],
                   k_struct_T *CholManager);

#endif

/*
 * File trailer for driver.h
 *
 * [EOF]
 */
