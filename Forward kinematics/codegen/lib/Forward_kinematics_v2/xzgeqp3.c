/*
 * File: xzgeqp3.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "xzgeqp3.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"

/* Function Definitions */

/*
 * Arguments    : double A[36]
 *                int ia0
 *                int m
 *                int n
 *                int nfxd
 *                double tau[6]
 * Return Type  : void
 */
void qrf(double A[36], int ia0, int m, int n, int nfxd, double tau[6])
{
  int i;
  double work[6];
  int ii;
  int mmi;
  double atmp;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  for (i = 0; i < nfxd; i++) {
    ii = ((ia0 + i * 6) + i) - 1;
    mmi = m - i;
    if (i + 1 < m) {
      atmp = A[ii];
      tau[i] = xzlarfg(mmi, &atmp, A, ii + 2);
      A[ii] = atmp;
    } else {
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      atmp = A[ii];
      A[ii] = 1.0;
      xzlarf(mmi, (n - i) - 1, ii + 1, tau[i], A, ii + 7, work);
      A[ii] = atmp;
    }
  }
}

/*
 * File trailer for xzgeqp3.c
 *
 * [EOF]
 */
