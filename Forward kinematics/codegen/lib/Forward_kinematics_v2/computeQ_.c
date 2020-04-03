/*
 * File: computeQ_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "computeQ_.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : i_struct_T *obj
 *                int nrows
 * Return Type  : void
 */
void computeQ_(i_struct_T *obj, int nrows)
{
  int i;
  int b_i;
  int m;
  int iQR0;
  int ix;
  int n;
  int lda;
  int i1;
  int itau;
  int ia;
  int c_i;
  double work[6];
  int iaii;
  int jA;
  double C[36];
  int lastv;
  int lastc;
  boolean_T exitg2;
  double c;
  int exitg1;
  i = obj->minRowCol;
  for (b_i = 0; b_i < i; b_i++) {
    iQR0 = obj->ldq * b_i + b_i;
    n = obj->mrows - b_i;
    for (ix = 0; ix <= n - 2; ix++) {
      i1 = (iQR0 + ix) + 1;
      obj->Q[i1] = obj->QR[i1];
    }
  }

  m = obj->mrows;
  ix = obj->minRowCol;
  lda = obj->ldq;
  if (nrows >= 1) {
    i = nrows - 1;
    for (b_i = ix; b_i <= i; b_i++) {
      ia = b_i * lda;
      i1 = m - 1;
      if (0 <= i1) {
        memset(&obj->Q[ia], 0, (((i1 + ia) - ia) + 1) * sizeof(double));
      }

      obj->Q[ia + b_i] = 1.0;
    }

    itau = obj->minRowCol - 1;
    for (c_i = 0; c_i < 6; c_i++) {
      work[c_i] = 0.0;
    }

    for (c_i = obj->minRowCol; c_i >= 1; c_i--) {
      iaii = (c_i + (c_i - 1) * lda) - 1;
      if (c_i < nrows) {
        obj->Q[iaii] = 1.0;
        jA = (iaii + lda) + 1;
        for (i = 0; i < 36; i++) {
          C[i] = obj->Q[i];
        }

        if (obj->tau[itau] != 0.0) {
          lastv = m - c_i;
          b_i = (iaii + m) - c_i;
          while ((lastv + 1 > 0) && (obj->Q[b_i] == 0.0)) {
            lastv--;
            b_i--;
          }

          lastc = (nrows - c_i) - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc + 1 > 0)) {
            iQR0 = jA + lastc * lda;
            ia = iQR0;
            do {
              exitg1 = 0;
              if (ia <= iQR0 + lastv) {
                if (obj->Q[ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  ia++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = -1;
        }

        if (lastv + 1 > 0) {
          if (lastc + 1 != 0) {
            if (0 <= lastc) {
              memset(&work[0], 0, (lastc + 1) * sizeof(double));
            }

            iQR0 = 0;
            i = jA + lda * lastc;
            for (n = jA; lda < 0 ? n >= i : n <= i; n += lda) {
              ix = iaii;
              c = 0.0;
              i1 = n + lastv;
              for (ia = n; ia <= i1; ia++) {
                c += obj->Q[ia - 1] * obj->Q[ix];
                ix++;
              }

              work[iQR0] += c;
              iQR0++;
            }
          }

          if (!(-obj->tau[itau] == 0.0)) {
            iQR0 = 0;
            for (b_i = 0; b_i <= lastc; b_i++) {
              if (work[iQR0] != 0.0) {
                c = work[iQR0] * -obj->tau[itau];
                ix = iaii;
                i = lastv + jA;
                for (n = jA; n <= i; n++) {
                  C[n - 1] += C[ix] * c;
                  ix++;
                }
              }

              iQR0++;
              jA += lda;
            }
          }
        }

        memcpy(&obj->Q[0], &C[0], 36U * sizeof(double));
      }

      if (c_i < m) {
        iQR0 = iaii + 2;
        i = ((iaii + m) - c_i) + 1;
        for (ix = iQR0; ix <= i; ix++) {
          obj->Q[ix - 1] *= -obj->tau[itau];
        }
      }

      obj->Q[iaii] = 1.0 - obj->tau[itau];
      for (b_i = 0; b_i <= c_i - 2; b_i++) {
        obj->Q[(iaii - b_i) - 1] = 0.0;
      }

      itau--;
    }
  }
}

/*
 * File trailer for computeQ_.c
 *
 * [EOF]
 */
