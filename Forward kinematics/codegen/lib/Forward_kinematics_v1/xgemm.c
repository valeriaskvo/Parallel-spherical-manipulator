/*
 * File: xgemm.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "xgemm.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                int k
 *                const double A[49]
 *                int ia0
 *                const double B[49]
 *                double C[49]
 * Return Type  : void
 */
void b_xgemm(int m, int n, int k, const double A[49], int ia0, const double B[49],
             double C[49])
{
  int lastColC;
  int cr;
  int br;
  int i;
  int i1;
  int ar;
  int ic;
  double temp;
  int w;
  int b_w;
  if ((m != 0) && (n != 0)) {
    lastColC = 7 * (n - 1);
    for (cr = 0; cr <= lastColC; cr += 7) {
      i = cr + 1;
      i1 = cr + m;
      if (i <= i1) {
        memset(&C[i + -1], 0, ((i1 - i) + 1) * sizeof(double));
      }
    }

    br = -1;
    for (cr = 0; cr <= lastColC; cr += 7) {
      ar = ia0;
      i = cr + 1;
      i1 = cr + m;
      for (ic = i; ic <= i1; ic++) {
        temp = 0.0;
        for (w = 0; w < k; w++) {
          b_w = w + 1;
          temp += A[(b_w + ar) - 2] * B[b_w + br];
        }

        C[ic - 1] += temp;
        ar += 7;
      }

      br += 7;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                int k
 *                const double A[36]
 *                int lda
 *                const double B[49]
 *                int ib0
 *                double C[49]
 * Return Type  : void
 */
void xgemm(int m, int n, int k, const double A[36], int lda, const double B[49],
           int ib0, double C[49])
{
  int br;
  int lastColC;
  int cr;
  int i;
  int i1;
  int ar;
  int ib;
  int ia;
  int i2;
  int ic;
  if ((m != 0) && (n != 0)) {
    br = ib0;
    lastColC = 7 * (n - 1);
    for (cr = 0; cr <= lastColC; cr += 7) {
      i = cr + 1;
      i1 = cr + m;
      if (i <= i1) {
        memset(&C[i + -1], 0, ((i1 - i) + 1) * sizeof(double));
      }
    }

    for (cr = 0; cr <= lastColC; cr += 7) {
      ar = -1;
      i = br + k;
      for (ib = br; ib < i; ib++) {
        ia = ar;
        i1 = cr + 1;
        i2 = cr + m;
        for (ic = i1; ic <= i2; ic++) {
          ia++;
          C[ic - 1] += B[ib - 1] * A[ia];
        }

        ar += lda;
      }

      br += 7;
    }
  }
}

/*
 * File trailer for xgemm.c
 *
 * [EOF]
 */
