/*
 * File: test_exit.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef TEST_EXIT_H
#define TEST_EXIT_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void b_test_exit(struct_T *Flags, c_struct_T *memspace, h_struct_T
  *MeritFunction, g_struct_T *WorkingSet, d_struct_T *TrialState, i_struct_T
  *QRManager);
extern void test_exit(c_struct_T *memspace, h_struct_T *MeritFunction,
                      g_struct_T *WorkingSet, d_struct_T *TrialState, i_struct_T
                      *QRManager, boolean_T *Flags_gradOK, boolean_T
                      *Flags_fevalOK, boolean_T *Flags_done, boolean_T
                      *Flags_stepAccepted, boolean_T *Flags_failedLineSearch,
                      int *Flags_stepType);

#endif

/*
 * File trailer for test_exit.h
 *
 * [EOF]
 */
