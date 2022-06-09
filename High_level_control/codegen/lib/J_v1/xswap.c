/*
 * File: xswap.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:02:07
 */

/* Include Files */
#include "xswap.h"
#include "J_v1.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : double x[36]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[36], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 6; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
