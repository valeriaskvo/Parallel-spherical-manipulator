/*
 * File: countsort.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "countsort.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : int x[6]
 *                int xLen
 *                int workspace[6]
 *                int xMin
 *                int xMax
 * Return Type  : void
 */
void countsort(int x[6], int xLen, int workspace[6], int xMin, int xMax)
{
  int idxW;
  int maxOffset;
  int idx;
  int idxStart;
  int idxEnd;
  if ((xLen > 1) && (xMax > xMin)) {
    idxW = xMax - xMin;
    if (0 <= idxW) {
      memset(&workspace[0], 0, (idxW + 1) * sizeof(int));
    }

    maxOffset = idxW - 1;
    for (idx = 0; idx < xLen; idx++) {
      idxW = x[idx] - xMin;
      workspace[idxW]++;
    }

    for (idx = 2; idx <= maxOffset + 2; idx++) {
      workspace[idx - 1] += workspace[idx - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (idxW = 0; idxW <= maxOffset; idxW++) {
      for (idx = idxStart; idx <= idxEnd; idx++) {
        x[idx - 1] = idxW + xMin;
      }

      idxStart = workspace[idxW] + 1;
      idxEnd = workspace[idxW + 1];
    }

    for (idx = idxStart; idx <= idxEnd; idx++) {
      x[idx - 1] = xMax;
    }
  }
}

/*
 * File trailer for countsort.c
 *
 * [EOF]
 */
