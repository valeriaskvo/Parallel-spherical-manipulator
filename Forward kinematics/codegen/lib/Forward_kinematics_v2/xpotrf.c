/*
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "xpotrf.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : int n
 *                double A[36]
 *                int lda
 * Return Type  : int
 */
int xpotrf(int n, double A[36], int lda)
{
  int info;
  int j;
  boolean_T exitg1;
  int idxA1j;
  int idxAjj;
  double ssq;
  int ix;
  int iy;
  int k;
  int nmj;
  int ia0;
  int idxAjjp1;
  int i;
  double c;
  int ia;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= n - 1)) {
    idxA1j = j * lda;
    idxAjj = idxA1j + j;
    ssq = 0.0;
    if (j >= 1) {
      ix = idxA1j;
      iy = idxA1j;
      for (k = 0; k < j; k++) {
        ssq += A[ix] * A[iy];
        ix++;
        iy++;
      }
    }

    ssq = A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = sqrt(ssq);
      A[idxAjj] = ssq;
      if (j + 1 < n) {
        nmj = (n - j) - 2;
        ia0 = (idxA1j + lda) + 1;
        idxAjjp1 = idxAjj + lda;
        if ((j != 0) && (nmj + 1 != 0)) {
          iy = idxAjjp1;
          i = ia0 + lda * nmj;
          for (idxAjj = ia0; lda < 0 ? idxAjj >= i : idxAjj <= i; idxAjj += lda)
          {
            ix = idxA1j;
            c = 0.0;
            k = (idxAjj + j) - 1;
            for (ia = idxAjj; ia <= k; ia++) {
              c += A[ia - 1] * A[ix];
              ix++;
            }

            A[iy] += -c;
            iy += lda;
          }
        }

        ssq = 1.0 / ssq;
        if (lda >= 1) {
          i = (idxAjjp1 + lda * nmj) + 1;
          for (k = idxAjjp1 + 1; lda < 0 ? k >= i : k <= i; k += lda) {
            A[k - 1] *= ssq;
          }
        }
      }

      j++;
    } else {
      A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

/*
 * File trailer for xpotrf.c
 *
 * [EOF]
 */
