/*
 * File: sortLambdaQP.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "sortLambdaQP.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : double *lambda
 *                int WorkingSet_nActiveConstr
 *                const int WorkingSet_sizes[5]
 *                int WorkingSet_Wid
 *                double workspace[49]
 * Return Type  : void
 */
void sortLambdaQP(double *lambda, int WorkingSet_nActiveConstr, const int
                  WorkingSet_sizes[5], int WorkingSet_Wid, double workspace[49])
{
  int mAll;
  int idx;
  if (WorkingSet_nActiveConstr != 0) {
    mAll = ((((WorkingSet_sizes[0] + WorkingSet_sizes[1]) + WorkingSet_sizes[3])
             + WorkingSet_sizes[4]) + WorkingSet_sizes[2]) - 1;
    for (idx = 0; idx <= mAll; idx++) {
      workspace[idx] = *lambda;
    }

    for (idx = 0; idx <= mAll; idx++) {
      *lambda = 0.0;
    }

    mAll = 0;
    idx = 1;
    while ((idx <= WorkingSet_nActiveConstr) && (WorkingSet_Wid <= 2)) {
      *lambda = workspace[mAll];
      mAll++;
      idx = 2;
    }

    while (idx <= WorkingSet_nActiveConstr) {
      *lambda = workspace[mAll];
      mAll++;
      idx = 2;
    }
  }
}

/*
 * File trailer for sortLambdaQP.c
 *
 * [EOF]
 */
