/*
 * File: factorQRE.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "factorQRE.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"

/* Function Definitions */

/*
 * Arguments    : i_struct_T *obj
 *                const double A[6]
 *                int mrows
 *                int ncols
 * Return Type  : void
 */
void factorQRE(i_struct_T *obj, const double A[6], int mrows, int ncols)
{
  int idx;
  boolean_T guard1 = false;
  int ix0;
  int iy0;
  int k;
  int b_k;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    for (idx = 0; idx < ncols; idx++) {
      ix0 = 6 * idx;
      iy0 = obj->ldq * idx;
      for (k = 0; k < mrows; k++) {
        b_k = k + 1;
        obj->QR[(iy0 + b_k) - 1] = A[(ix0 + b_k) - 1];
      }
    }

    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows < ncols) {
      idx = mrows;
    } else {
      idx = ncols;
    }

    obj->minRowCol = idx;
    xgeqp3(obj->QR, mrows, ncols, obj->jpvt, obj->tau);
  }
}

/*
 * File trailer for factorQRE.c
 *
 * [EOF]
 */
