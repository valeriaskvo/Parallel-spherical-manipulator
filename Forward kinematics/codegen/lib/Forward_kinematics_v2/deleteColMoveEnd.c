/*
 * File: deleteColMoveEnd.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "deleteColMoveEnd.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : i_struct_T *obj
 *                int idx
 * Return Type  : void
 */
void deleteColMoveEnd(i_struct_T *obj, int idx)
{
  int i;
  int b_i;
  int k;
  int QRk0;
  int endIdx;
  double temp;
  double c;
  double s;
  int n;
  double x[36];
  int b_k;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    b_i = obj->minRowCol;
    for (k = 0; k < b_i; k++) {
      obj->QR[k + 6 * (idx - 1)] = obj->QR[k + 6 * (obj->ncols - 1)];
    }

    obj->ncols--;
    QRk0 = obj->mrows;
    i = obj->ncols;
    if (QRk0 < i) {
      i = QRk0;
    }

    obj->minRowCol = i;
    if (idx < obj->mrows) {
      QRk0 = obj->mrows - 1;
      endIdx = obj->ncols;
      if (QRk0 < endIdx) {
        endIdx = QRk0;
      }

      for (k = endIdx; k >= idx; k--) {
        b_i = k + 6 * (idx - 1);
        temp = obj->QR[b_i];
        xrotg(&obj->QR[(k + 6 * (idx - 1)) - 1], &temp, &c, &s);
        obj->QR[b_i] = temp;
        obj->QR[k + 6 * (k - 1)] = 0.0;
        QRk0 = k + obj->ldq * idx;
        n = obj->ncols - idx;
        for (b_i = 0; b_i < 36; b_i++) {
          x[b_i] = obj->QR[b_i];
        }

        if (n >= 1) {
          i = QRk0 - 1;
          for (b_k = 0; b_k < n; b_k++) {
            temp = c * x[i] + s * x[QRk0];
            x[QRk0] = c * x[QRk0] - s * x[i];
            x[i] = temp;
            QRk0 += obj->ldq;
            i += obj->ldq;
          }
        }

        QRk0 = obj->ldq * (k - 1);
        n = obj->mrows;
        for (b_i = 0; b_i < 36; b_i++) {
          obj->QR[b_i] = x[b_i];
          x[b_i] = obj->Q[b_i];
        }

        if (obj->mrows >= 1) {
          i = obj->ldq + QRk0;
          for (b_k = 0; b_k < n; b_k++) {
            temp = c * x[QRk0] + s * x[i];
            x[i] = c * x[i] - s * x[QRk0];
            x[QRk0] = temp;
            i++;
            QRk0++;
          }
        }

        memcpy(&obj->Q[0], &x[0], 36U * sizeof(double));
      }

      b_i = idx + 1;
      for (k = b_i; k <= endIdx; k++) {
        i = k + 6 * (k - 1);
        temp = obj->QR[i];
        xrotg(&obj->QR[(k + 6 * (k - 1)) - 1], &temp, &c, &s);
        obj->QR[i] = temp;
        QRk0 = k * (obj->ldq + 1);
        n = obj->ncols - k;
        for (i = 0; i < 36; i++) {
          x[i] = obj->QR[i];
        }

        if (n >= 1) {
          i = QRk0 - 1;
          for (b_k = 0; b_k < n; b_k++) {
            temp = c * x[i] + s * x[QRk0];
            x[QRk0] = c * x[QRk0] - s * x[i];
            x[i] = temp;
            QRk0 += obj->ldq;
            i += obj->ldq;
          }
        }

        QRk0 = obj->ldq * (k - 1);
        n = obj->mrows;
        for (i = 0; i < 36; i++) {
          obj->QR[i] = x[i];
          x[i] = obj->Q[i];
        }

        if (obj->mrows >= 1) {
          i = obj->ldq + QRk0;
          for (b_k = 0; b_k < n; b_k++) {
            temp = c * x[QRk0] + s * x[i];
            x[i] = c * x[i] - s * x[QRk0];
            x[QRk0] = temp;
            i++;
            QRk0++;
          }
        }

        memcpy(&obj->Q[0], &x[0], 36U * sizeof(double));
      }
    }
  }
}

/*
 * File trailer for deleteColMoveEnd.c
 *
 * [EOF]
 */
