/*
 * File: computeGradLag.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "computeGradLag.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : double workspace[49]
 *                int ldA
 *                int nVar
 *                const double grad[7]
 *                int mIneq
 *                int mEq
 *                const int finiteFixed[7]
 *                int mFixed
 *                const int finiteLB[7]
 *                int mLB
 *                const int finiteUB[7]
 *                int mUB
 *                double lambda
 * Return Type  : void
 */
void b_computeGradLag(double workspace[49], int ldA, int nVar, const double
                      grad[7], int mIneq, int mEq, const int finiteFixed[7], int
                      mFixed, const int finiteLB[7], int mLB, const int
                      finiteUB[7], int mUB, double lambda)
{
  int idx;
  int iac;
  int iy;
  int i;
  int ia;
  if (0 <= nVar - 1) {
    memcpy(&workspace[0], &grad[0], nVar * sizeof(double));
  }

  for (idx = 0; idx < mFixed; idx++) {
    workspace[finiteFixed[0] - 1] += lambda;
  }

  if ((nVar != 0) && (mEq != 0)) {
    idx = ldA * (mEq - 1) + 1;
    for (iac = 1; ldA < 0 ? iac >= idx : iac <= idx; iac += ldA) {
      iy = 0;
      i = (iac + nVar) - 1;
      for (ia = iac; ia <= i; ia++) {
        workspace[iy] += workspace[ia - 1] * lambda;
        iy++;
      }
    }
  }

  if ((nVar != 0) && (mIneq != 0)) {
    idx = ldA * (mIneq - 1) + 1;
    for (iac = 1; ldA < 0 ? iac >= idx : iac <= idx; iac += ldA) {
      iy = 0;
      i = (iac + nVar) - 1;
      for (ia = iac; ia <= i; ia++) {
        workspace[iy] += workspace[ia - 1] * lambda;
        iy++;
      }
    }
  }

  for (idx = 0; idx < mLB; idx++) {
    workspace[finiteLB[idx] - 1] -= lambda;
  }

  for (idx = 0; idx < mUB; idx++) {
    workspace[finiteUB[idx] - 1] += lambda;
  }
}

/*
 * Arguments    : double workspace[7]
 *                int ldA
 *                int nVar
 *                const double grad[7]
 *                int mIneq
 *                int mEq
 *                const int finiteFixed[7]
 *                int mFixed
 *                const int finiteLB[7]
 *                int mLB
 *                const int finiteUB[7]
 *                int mUB
 *                double lambda
 * Return Type  : void
 */
void computeGradLag(double workspace[7], int ldA, int nVar, const double grad[7],
                    int mIneq, int mEq, const int finiteFixed[7], int mFixed,
                    const int finiteLB[7], int mLB, const int finiteUB[7], int
                    mUB, double lambda)
{
  int idx;
  int iac;
  int iy;
  int i;
  int ia;
  if (0 <= nVar - 1) {
    memcpy(&workspace[0], &grad[0], nVar * sizeof(double));
  }

  for (idx = 0; idx < mFixed; idx++) {
    workspace[finiteFixed[0] - 1] += lambda;
  }

  if ((nVar != 0) && (mEq != 0)) {
    idx = ldA * (mEq - 1) + 1;
    for (iac = 1; ldA < 0 ? iac >= idx : iac <= idx; iac += ldA) {
      iy = 0;
      i = (iac + nVar) - 1;
      for (ia = iac; ia <= i; ia++) {
        workspace[iy] += workspace[ia - 1] * lambda;
        iy++;
      }
    }
  }

  if ((nVar != 0) && (mIneq != 0)) {
    idx = ldA * (mIneq - 1) + 1;
    for (iac = 1; ldA < 0 ? iac >= idx : iac <= idx; iac += ldA) {
      iy = 0;
      i = (iac + nVar) - 1;
      for (ia = iac; ia <= i; ia++) {
        workspace[iy] += workspace[ia - 1] * lambda;
        iy++;
      }
    }
  }

  for (idx = 0; idx < mLB; idx++) {
    workspace[finiteLB[idx] - 1] -= lambda;
  }

  for (idx = 0; idx < mUB; idx++) {
    workspace[finiteUB[idx] - 1] += lambda;
  }
}

/*
 * File trailer for computeGradLag.c
 *
 * [EOF]
 */
