/*
 * File: computeGradLag.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

#ifndef COMPUTEGRADLAG_H
#define COMPUTEGRADLAG_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern void b_computeGradLag(double workspace[49], int ldA, int nVar, const
  double grad[7], int mIneq, int mEq, const int finiteFixed[7], int mFixed,
  const int finiteLB[7], int mLB, const int finiteUB[7], int mUB, double lambda);
extern void computeGradLag(double workspace[7], int ldA, int nVar, const double
  grad[7], int mIneq, int mEq, const int finiteFixed[7], int mFixed, const int
  finiteLB[7], int mLB, const int finiteUB[7], int mUB, double lambda);

#endif

/*
 * File trailer for computeGradLag.h
 *
 * [EOF]
 */
