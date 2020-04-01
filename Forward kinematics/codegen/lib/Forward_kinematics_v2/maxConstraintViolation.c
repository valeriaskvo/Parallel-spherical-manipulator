/*
 * File: maxConstraintViolation.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "maxConstraintViolation.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : const g_struct_T *obj
 *                const double x[6]
 *                int ix0
 * Return Type  : double
 */
double b_maxConstraintViolation(const g_struct_T *obj, const double x[6], int
  ix0)
{
  double v;
  int mLB;
  int mUB;
  int mFixed;
  int idx;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  v = 0.0;
  if (obj->sizes[3] > 0) {
    for (idx = 0; idx < mLB; idx++) {
      v = fmax(v, -x[(ix0 + obj->indexLB[idx]) - 2] - obj->lb[obj->indexLB[idx]
               - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    for (idx = 0; idx < mUB; idx++) {
      v = fmax(v, x[(ix0 + obj->indexUB[idx]) - 2] - obj->ub[obj->indexUB[idx] -
               1]);
    }
  }

  if (obj->sizes[0] > 0) {
    for (idx = 0; idx < mFixed; idx++) {
      v = fmax(v, fabs(x[(ix0 + obj->indexFixed[idx]) - 2] - obj->ub
                       [obj->indexFixed[idx] - 1]));
    }
  }

  return v;
}

/*
 * Arguments    : const g_struct_T *obj
 *                const double x[36]
 *                int ix0
 * Return Type  : double
 */
double maxConstraintViolation(const g_struct_T *obj, const double x[36], int ix0)
{
  double v;
  int mLB;
  int mUB;
  int mFixed;
  int idx;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  v = 0.0;
  if (obj->sizes[3] > 0) {
    for (idx = 0; idx < mLB; idx++) {
      v = fmax(v, -x[(ix0 + obj->indexLB[idx]) - 2] - obj->lb[obj->indexLB[idx]
               - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    for (idx = 0; idx < mUB; idx++) {
      v = fmax(v, x[(ix0 + obj->indexUB[idx]) - 2] - obj->ub[obj->indexUB[idx] -
               1]);
    }
  }

  if (obj->sizes[0] > 0) {
    for (idx = 0; idx < mFixed; idx++) {
      v = fmax(v, fabs(x[(ix0 + obj->indexFixed[idx]) - 2] - obj->ub
                       [obj->indexFixed[idx] - 1]));
    }
  }

  return v;
}

/*
 * File trailer for maxConstraintViolation.c
 *
 * [EOF]
 */
