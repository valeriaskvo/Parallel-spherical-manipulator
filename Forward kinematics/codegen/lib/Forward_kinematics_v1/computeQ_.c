/*
 * File: computeQ_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "computeQ_.h"
#include "Forward_kinematics_v1.h"
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
  int ia;
  int m;
  int iQR0;
  int k;
  int jy;
  int j;
  int i1;
  int itau;
  int b_i;
  double work[7];
  int iaii;
  double C[49];
  int lastv;
  int lastc;
  boolean_T exitg2;
  int ix;
  int exitg1;
  double c;
  i = obj->minRowCol;
  for (ia = 0; ia < i; ia++) {
    iQR0 = 7 * ia + ia;
    jy = obj->mrows - ia;
    for (k = 0; k <= jy - 2; k++) {
      i1 = (iQR0 + k) + 1;
      obj->Q[i1] = obj->QR[i1];
    }
  }

  m = obj->mrows;
  k = obj->minRowCol;
  if (nrows >= 1) {
    i = nrows - 1;
    for (j = k; j <= i; j++) {
      ia = j * 7;
      i1 = m - 1;
      if (0 <= i1) {
        memset(&obj->Q[ia], 0, (((i1 + ia) - ia) + 1) * sizeof(double));
      }

      obj->Q[ia + j] = 1.0;
    }

    itau = obj->minRowCol - 1;
    for (b_i = 0; b_i < 7; b_i++) {
      work[b_i] = 0.0;
    }

    for (b_i = obj->minRowCol; b_i >= 1; b_i--) {
      iaii = b_i + (b_i - 1) * 7;
      if (b_i < nrows) {
        obj->Q[iaii - 1] = 1.0;
        k = iaii + 7;
        for (i = 0; i < 49; i++) {
          C[i] = obj->Q[i];
        }

        if (obj->tau[itau] != 0.0) {
          lastv = m - b_i;
          ia = (iaii + m) - b_i;
          while ((lastv + 1 > 0) && (obj->Q[ia - 1] == 0.0)) {
            lastv--;
            ia--;
          }

          lastc = (nrows - b_i) - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc + 1 > 0)) {
            iQR0 = (iaii + lastc * 7) + 7;
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
            i = (iaii + 7 * lastc) + 7;
            for (jy = k; jy <= i; jy += 7) {
              ix = iaii;
              c = 0.0;
              i1 = jy + lastv;
              for (ia = jy; ia <= i1; ia++) {
                c += obj->Q[ia - 1] * obj->Q[ix - 1];
                ix++;
              }

              work[iQR0] += c;
              iQR0++;
            }
          }

          if (!(-obj->tau[itau] == 0.0)) {
            iQR0 = iaii;
            jy = 0;
            for (j = 0; j <= lastc; j++) {
              if (work[jy] != 0.0) {
                c = work[jy] * -obj->tau[itau];
                ix = iaii;
                i = iQR0 + 7;
                i1 = lastv + iQR0;
                for (ia = i; ia <= i1 + 7; ia++) {
                  C[ia - 1] += C[ix - 1] * c;
                  ix++;
                }
              }

              jy++;
              iQR0 += 7;
            }
          }
        }

        memcpy(&obj->Q[0], &C[0], 49U * sizeof(double));
      }

      if (b_i < m) {
        iQR0 = iaii + 1;
        i = (iaii + m) - b_i;
        for (k = iQR0; k <= i; k++) {
          obj->Q[k - 1] *= -obj->tau[itau];
        }
      }

      obj->Q[iaii - 1] = 1.0 - obj->tau[itau];
      for (j = 0; j <= b_i - 2; j++) {
        obj->Q[(iaii - j) - 2] = 0.0;
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
