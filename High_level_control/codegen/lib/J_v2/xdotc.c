/*
 * File: xdotc.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:04:06
 */

/* Include Files */
#include "xdotc.h"
#include "J_v2.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const double x[25]
 *                int ix0
 *                const double y[25]
 *                int iy0
 * Return Type  : double
 */
double b_xdotc(int n, const double x[25], int ix0, const double y[25], int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/*
 * Arguments    : int n
 *                const double x[30]
 *                int ix0
 *                const double y[30]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[30], int ix0, const double y[30], int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
