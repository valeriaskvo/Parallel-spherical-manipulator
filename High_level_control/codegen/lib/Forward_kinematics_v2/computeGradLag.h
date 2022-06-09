/*
 * File: computeGradLag.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

#ifndef COMPUTEGRADLAG_H
#define COMPUTEGRADLAG_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void b_computeGradLag(double workspace[36], int ldA, int nVar, const
  double grad[6], int mIneq, int mEq, const int finiteFixed[6], int mFixed,
  const int finiteLB[6], int mLB, const int finiteUB[6], int mUB, double lambda);
extern void computeGradLag(double workspace[6], int ldA, int nVar, const double
  grad[6], int mIneq, int mEq, const int finiteFixed[6], int mFixed, const int
  finiteLB[6], int mLB, const int finiteUB[6], int mUB, double lambda);

#endif

/*
 * File trailer for computeGradLag.h
 *
 * [EOF]
 */
