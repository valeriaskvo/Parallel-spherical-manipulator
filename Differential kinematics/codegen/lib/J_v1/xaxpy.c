/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:02:07
 */

/* Include Files */
#include "xaxpy.h"
#include "J_v1.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                double a
 *                const double x[36]
 *                int ix0
 *                double y[6]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const double x[36], int ix0, double y[6], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[6]
 *                int ix0
 *                double y[36]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[6], int ix0, double y[36], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[36]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[36], int iy0)
{
  int ix;
  int iy;
  int i;
  int k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    for (k = 0; k <= i; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
