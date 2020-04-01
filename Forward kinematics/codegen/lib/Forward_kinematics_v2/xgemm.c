/*
 * File: xgemm.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "xgemm.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                int k
 *                const double A[36]
 *                int ia0
 *                int lda
 *                const double B[36]
 *                double C[36]
 *                int ldc
 * Return Type  : void
 */
void b_xgemm(int m, int n, int k, const double A[36], int ia0, int lda, const
             double B[36], double C[36], int ldc)
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
    lastColC = ldc * (n - 1);
    for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
      i = cr + 1;
      i1 = cr + m;
      if (i <= i1) {
        memset(&C[i + -1], 0, ((i1 - i) + 1) * sizeof(double));
      }
    }

    br = -1;
    for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
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
        ar += lda;
      }

      br += 6;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                int k
 *                const double A[25]
 *                int lda
 *                const double B[36]
 *                int ib0
 *                int ldb
 *                double C[36]
 * Return Type  : void
 */
void xgemm(int m, int n, int k, const double A[25], int lda, const double B[36],
           int ib0, int ldb, double C[36])
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
    lastColC = 6 * (n - 1);
    for (cr = 0; cr <= lastColC; cr += 6) {
      i = cr + 1;
      i1 = cr + m;
      if (i <= i1) {
        memset(&C[i + -1], 0, ((i1 - i) + 1) * sizeof(double));
      }
    }

    for (cr = 0; cr <= lastColC; cr += 6) {
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

      br += ldb;
    }
  }
}

/*
 * File trailer for xgemm.c
 *
 * [EOF]
 */
