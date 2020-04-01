/*
 * File: xgeqp3.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "xgeqp3.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzgeqp3.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : double A[36]
 *                int m
 *                int n
 *                int jpvt[6]
 *                double tau[6]
 * Return Type  : void
 */
void xgeqp3(double A[36], int m, int n, int jpvt[6], double tau[6])
{
  int minmn_tmp;
  int i;
  int nfxd;
  int pvt;
  int ix;
  int iy;
  int k;
  int b_i;
  double work[6];
  double vn1[6];
  double temp;
  double vn2[6];
  double d;
  int ip1;
  int ii;
  int nmi;
  int mmi;
  double s;
  if (m < n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = n;
  }

  for (i = 0; i < 6; i++) {
    tau[i] = 0.0;
  }

  if (minmn_tmp < 1) {
    for (pvt = 0; pvt < n; pvt++) {
      jpvt[pvt] = pvt + 1;
    }
  } else {
    nfxd = 0;
    for (pvt = 0; pvt < n; pvt++) {
      if (jpvt[pvt] != 0) {
        nfxd++;
        if (pvt + 1 != nfxd) {
          ix = pvt * 6;
          iy = (nfxd - 1) * 6;
          for (k = 0; k < m; k++) {
            temp = A[ix];
            A[ix] = A[iy];
            A[iy] = temp;
            ix++;
            iy++;
          }

          jpvt[pvt] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = pvt + 1;
        } else {
          jpvt[pvt] = pvt + 1;
        }
      } else {
        jpvt[pvt] = pvt + 1;
      }
    }

    if (nfxd >= minmn_tmp) {
      nfxd = minmn_tmp;
    }

    qrf(A, 1, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      for (i = 0; i < 6; i++) {
        work[i] = 0.0;
        vn1[i] = 0.0;
        vn2[i] = 0.0;
      }

      b_i = nfxd + 1;
      for (pvt = b_i; pvt <= n; pvt++) {
        d = xnrm2(m - nfxd, A, (nfxd + (pvt - 1) * 6) + 1);
        vn1[pvt - 1] = d;
        vn2[pvt - 1] = d;
      }

      b_i = nfxd + 1;
      for (i = b_i; i <= minmn_tmp; i++) {
        ip1 = i + 1;
        iy = (i - 1) * 6;
        ii = (iy + i) - 1;
        nmi = (n - i) + 1;
        mmi = m - i;
        if (nmi < 1) {
          nfxd = -2;
        } else {
          nfxd = -1;
          if (nmi > 1) {
            ix = i;
            temp = fabs(vn1[i - 1]);
            for (k = 2; k <= nmi; k++) {
              ix++;
              s = fabs(vn1[ix - 1]);
              if (s > temp) {
                nfxd = k - 2;
                temp = s;
              }
            }
          }
        }

        pvt = i + nfxd;
        if (pvt + 1 != i) {
          ix = pvt * 6;
          for (k = 0; k < m; k++) {
            temp = A[ix];
            A[ix] = A[iy];
            A[iy] = temp;
            ix++;
            iy++;
          }

          nfxd = jpvt[pvt];
          jpvt[pvt] = jpvt[i - 1];
          jpvt[i - 1] = nfxd;
          vn1[pvt] = vn1[i - 1];
          vn2[pvt] = vn2[i - 1];
        }

        if (i < m) {
          temp = A[ii];
          d = xzlarfg(mmi + 1, &temp, A, ii + 2);
          tau[i - 1] = d;
          A[ii] = temp;
        } else {
          d = 0.0;
          tau[i - 1] = 0.0;
        }

        if (i < n) {
          temp = A[ii];
          A[ii] = 1.0;
          xzlarf(mmi + 1, nmi - 1, ii + 1, d, A, ii + 7, work);
          A[ii] = temp;
        }

        for (pvt = ip1; pvt <= n; pvt++) {
          nfxd = i + (pvt - 1) * 6;
          d = vn1[pvt - 1];
          if (d != 0.0) {
            temp = fabs(A[nfxd - 1]) / d;
            temp = 1.0 - temp * temp;
            if (temp < 0.0) {
              temp = 0.0;
            }

            s = d / vn2[pvt - 1];
            s = temp * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if (i < m) {
                d = xnrm2(mmi, A, nfxd + 1);
                vn1[pvt - 1] = d;
                vn2[pvt - 1] = d;
              } else {
                vn1[pvt - 1] = 0.0;
                vn2[pvt - 1] = 0.0;
              }
            } else {
              vn1[pvt - 1] = d * sqrt(temp);
            }
          }
        }
      }
    }
  }
}

/*
 * File trailer for xgeqp3.c
 *
 * [EOF]
 */
