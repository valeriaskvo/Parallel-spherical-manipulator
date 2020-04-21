/*
 * File: cumtrapz.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "cumtrapz.h"
#include "Find_parameters_dynamixel.h"
#include "Find_parameters_dynamixel_emxutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void cumtrapz(const emxArray_real_T *x, const emxArray_real_T *y,
              emxArray_real_T *z)
{
  emxArray_real_T *b_x;
  int j;
  int iystart;
  int dim;
  int vlen;
  int vstride;
  int k;
  double s;
  int iyz;
  double ylast;
  emxInit_real_T(&b_x, 1);
  j = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity_real_T(b_x, j);
  iystart = x->size[0];
  for (j = 0; j < iystart; j++) {
    b_x->data[j] = x->data[j];
  }

  dim = 0;
  if (y->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    vlen = y->size[0] - 2;
  } else {
    vlen = -1;
  }

  for (iystart = 0; iystart <= vlen; iystart++) {
    b_x->data[iystart] = b_x->data[iystart + 1] - b_x->data[iystart];
  }

  j = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity_real_T(z, j);
  if (y->size[0] != 0) {
    vstride = 1;
    for (k = 0; k <= dim; k++) {
      vstride *= y->size[0];
    }

    iystart = -1;
    for (j = 0; j < vstride; j++) {
      iystart++;
      s = 0.0;
      dim = -1;
      iyz = iystart;
      ylast = y->data[iystart];
      z->data[iystart] = 0.0;
      for (k = 0; k <= vlen; k++) {
        iyz += vstride;
        if (b_x->size[0] == 0) {
          s += (ylast + y->data[iyz]) / 2.0;
        } else {
          dim++;
          s += b_x->data[dim] * ((ylast + y->data[iyz]) / 2.0);
        }

        ylast = y->data[iyz];
        z->data[iyz] = s;
      }
    }
  }

  emxFree_real_T(&b_x);
}

/*
 * File trailer for cumtrapz.c
 *
 * [EOF]
 */
