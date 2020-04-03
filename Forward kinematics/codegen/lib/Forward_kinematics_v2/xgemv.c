/*
 * File: xgemv.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "xgemv.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                int lda
 *                const double x[6]
 *                double y[36]
 * Return Type  : void
 */
void b_xgemv(int m, int n, int lda, const double x[6], double y[36])
{
  int iy;
  int i;
  int iac;
  int ix;
  double c;
  int i1;
  int ia;
  if ((m != 0) && (n != 0)) {
    for (iy = 0; iy < n; iy++) {
      y[iy] = -y[iy];
    }

    iy = 0;
    i = lda * (n - 1) + 1;
    for (iac = 1; lda < 0 ? iac >= i : iac <= i; iac += lda) {
      ix = 0;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (ia = iac; ia <= i1; ia++) {
        c += y[ia - 1] * x[ix];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                const double A[36]
 *                int lda
 *                const double x[6]
 *                double y[36]
 * Return Type  : void
 */
void xgemv(int m, int n, const double A[36], int lda, const double x[6], double
           y[36])
{
  int iy;
  int i;
  int iac;
  int ix;
  double c;
  int i1;
  int ia;
  if ((m != 0) && (n != 0)) {
    if (0 <= n - 1) {
      memset(&y[0], 0, n * sizeof(double));
    }

    iy = 0;
    i = lda * (n - 1) + 1;
    for (iac = 1; lda < 0 ? iac >= i : iac <= i; iac += lda) {
      ix = 0;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (ia = iac; ia <= i1; ia++) {
        c += A[ia - 1] * x[ix];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

/*
 * File trailer for xgemv.c
 *
 * [EOF]
 */
