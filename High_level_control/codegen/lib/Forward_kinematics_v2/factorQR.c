/*
 * File: factorQR.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "factorQR.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : i_struct_T *obj
 *                const double A[6]
 *                int mrows
 *                int ncols
 * Return Type  : void
 */
void factorQR(i_struct_T *obj, const double A[6], int mrows, int ncols)
{
  int ix0;
  boolean_T guard1 = false;
  int i;
  int iy0;
  int k;
  int b_k;
  double b_A[36];
  ix0 = mrows * ncols;
  guard1 = false;
  if (ix0 > 0) {
    for (i = 0; i < ncols; i++) {
      ix0 = 6 * i;
      iy0 = obj->ldq * i;
      for (k = 0; k < mrows; k++) {
        b_k = k + 1;
        obj->QR[(iy0 + b_k) - 1] = A[(ix0 + b_k) - 1];
      }
    }

    guard1 = true;
  } else if (ix0 == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    for (i = 0; i < ncols; i++) {
      obj->jpvt[i] = i + 1;
    }

    if (mrows < ncols) {
      ix0 = mrows;
    } else {
      ix0 = ncols;
    }

    obj->minRowCol = ix0;
    for (i = 0; i < 36; i++) {
      b_A[i] = obj->QR[i];
    }

    for (i = 0; i < 6; i++) {
      obj->tau[i] = 0.0;
    }

    if (ix0 >= 1) {
      for (i = 0; i < 6; i++) {
        obj->tau[i] = 0.0;
      }

      qrf(b_A, 1, mrows, ncols, ix0, obj->tau);
    }

    memcpy(&obj->QR[0], &b_A[0], 36U * sizeof(double));
  }
}

/*
 * File trailer for factorQR.c
 *
 * [EOF]
 */
