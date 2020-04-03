/*
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "xpotrf.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : int n
 *                double A[49]
 * Return Type  : int
 */
int xpotrf(int n, double A[49])
{
  int info;
  int j;
  boolean_T exitg1;
  int idxA1j;
  int idxAjj;
  double ssq;
  int ix;
  int iy;
  int nmj;
  int ia0;
  int idxAjjp1;
  int i;
  int iac;
  double c;
  int i1;
  int ia;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= n - 1)) {
    idxA1j = j * 7;
    idxAjj = idxA1j + j;
    ssq = 0.0;
    if (j >= 1) {
      ix = idxA1j;
      iy = idxA1j;
      for (nmj = 0; nmj < j; nmj++) {
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
        ia0 = idxA1j + 8;
        idxAjjp1 = idxAjj + 8;
        if ((j != 0) && (nmj + 1 != 0)) {
          iy = idxAjj + 7;
          i = (idxA1j + 7 * nmj) + 8;
          for (iac = ia0; iac <= i; iac += 7) {
            ix = idxA1j;
            c = 0.0;
            i1 = (iac + j) - 1;
            for (ia = iac; ia <= i1; ia++) {
              c += A[ia - 1] * A[ix];
              ix++;
            }

            A[iy] += -c;
            iy += 7;
          }
        }

        ssq = 1.0 / ssq;
        i = (idxAjj + 7 * nmj) + 8;
        for (nmj = idxAjjp1; nmj <= i; nmj += 7) {
          A[nmj - 1] *= ssq;
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
