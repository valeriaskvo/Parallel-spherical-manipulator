/*
 * File: solve.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "solve.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const k_struct_T *obj
 *                double rhs[6]
 * Return Type  : void
 */
void solve(const k_struct_T *obj, double rhs[6])
{
  int n;
  int j;
  int jA;
  double temp;
  int i;
  int ix;
  n = obj->ndims;
  if (obj->ndims != 0) {
    for (j = 0; j < n; j++) {
      jA = j * obj->ldu;
      temp = rhs[j];
      for (i = 0; i < j; i++) {
        temp -= obj->UU[jA + i] * rhs[i];
      }

      rhs[j] = temp / obj->UU[jA + j];
    }
  }

  n = obj->ndims;
  if (obj->ndims != 0) {
    for (j = n; j >= 1; j--) {
      jA = (j + (j - 1) * obj->ldu) - 1;
      rhs[j - 1] /= obj->UU[jA];
      for (i = 0; i <= j - 2; i++) {
        ix = (j - i) - 2;
        rhs[ix] -= rhs[j - 1] * obj->UU[(jA - i) - 1];
      }
    }
  }
}

/*
 * File trailer for solve.c
 *
 * [EOF]
 */
