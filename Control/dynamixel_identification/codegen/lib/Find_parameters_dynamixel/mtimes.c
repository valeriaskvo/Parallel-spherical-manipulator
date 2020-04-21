/*
 * File: mtimes.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "mtimes.h"
#include "Find_parameters_dynamixel.h"
#include "Find_parameters_dynamixel_emxutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *C
 * Return Type  : void
 */
void mtimes(const emxArray_real_T *A, const emxArray_real_T *B, emxArray_real_T *
            C)
{
  int m;
  int inner;
  int n;
  int i;
  int j;
  int coffset;
  int boffset;
  int b_i;
  int k;
  int aoffset;
  double temp;
  m = A->size[0];
  inner = A->size[1];
  n = B->size[1];
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = B->size[1];
  emxEnsureCapacity_real_T(C, i);
  for (j = 0; j < n; j++) {
    coffset = j * m;
    boffset = j * inner;
    for (b_i = 0; b_i < m; b_i++) {
      C->data[coffset + b_i] = 0.0;
    }

    for (k = 0; k < inner; k++) {
      aoffset = k * m;
      temp = B->data[boffset + k];
      for (b_i = 0; b_i < m; b_i++) {
        i = coffset + b_i;
        C->data[i] += temp * A->data[aoffset + b_i];
      }
    }
  }
}

/*
 * File trailer for mtimes.c
 *
 * [EOF]
 */
