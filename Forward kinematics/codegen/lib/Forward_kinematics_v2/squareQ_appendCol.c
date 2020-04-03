/*
 * File: squareQ_appendCol.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "squareQ_appendCol.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : i_struct_T *obj
 *                const double vec[6]
 *                int iv0
 * Return Type  : void
 */
void squareQ_appendCol(i_struct_T *obj, const double vec[6], int iv0)
{
  int iyend;
  int u1;
  int iy;
  int lda;
  int i;
  double temp;
  double c;
  double s;
  int Qk0;
  int ia;
  double x[36];
  iyend = obj->mrows;
  u1 = obj->ncols + 1;
  if (iyend < u1) {
    u1 = iyend;
  }

  obj->minRowCol = u1;
  iy = obj->ldq * obj->ncols;
  lda = obj->ldq;
  if (obj->mrows != 0) {
    iyend = iy + obj->mrows;
    if (iy + 1 <= iyend) {
      memset(&obj->QR[iy], 0, (iyend - iy) * sizeof(double));
    }

    i = obj->ldq * (obj->mrows - 1) + 1;
    for (u1 = 1; lda < 0 ? u1 >= i : u1 <= i; u1 += lda) {
      iyend = iv0;
      c = 0.0;
      Qk0 = (u1 + obj->mrows) - 1;
      for (ia = u1; ia <= Qk0; ia++) {
        c += obj->Q[ia - 1] * vec[iyend - 1];
        iyend++;
      }

      obj->QR[iy] += c;
      iy++;
    }
  }

  obj->ncols++;
  obj->jpvt[obj->ncols - 1] = obj->ncols;
  for (iyend = obj->mrows - 1; iyend + 1 > obj->ncols; iyend--) {
    temp = obj->QR[iyend + 6 * (obj->ncols - 1)];
    xrotg(&obj->QR[(iyend + 6 * (obj->ncols - 1)) - 1], &temp, &c, &s);
    obj->QR[iyend + 6 * (obj->ncols - 1)] = temp;
    Qk0 = obj->ldq * (iyend - 1);
    ia = obj->mrows;
    for (i = 0; i < 36; i++) {
      x[i] = obj->Q[i];
    }

    if (obj->mrows >= 1) {
      iy = obj->ldq + Qk0;
      for (u1 = 0; u1 < ia; u1++) {
        temp = c * x[Qk0] + s * x[iy];
        x[iy] = c * x[iy] - s * x[Qk0];
        x[Qk0] = temp;
        iy++;
        Qk0++;
      }
    }

    memcpy(&obj->Q[0], &x[0], 36U * sizeof(double));
  }
}

/*
 * File trailer for squareQ_appendCol.c
 *
 * [EOF]
 */
