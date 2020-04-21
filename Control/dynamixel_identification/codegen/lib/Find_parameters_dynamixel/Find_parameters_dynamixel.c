/*
 * File: Find_parameters_dynamixel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "Find_parameters_dynamixel.h"
#include "Find_parameters_dynamixel_data.h"
#include "Find_parameters_dynamixel_emxutil.h"
#include "Find_parameters_dynamixel_initialize.h"
#include "generate_model_vectors.h"
#include "inv.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : double N
 *                const emxArray_real_T *t
 *                const emxArray_real_T *dtheta
 *                const emxArray_real_T *ddtheta
 *                const emxArray_real_T *b_I
 *                const rtString *dtype
 *                double k_dtheta
 *                double K_m
 *                double p[3]
 *                emxArray_real_T *p_s
 *                double R[9]
 *                emxArray_real_T *R_s
 *                emxArray_real_T *time
 * Return Type  : void
 */
void Find_parameters_dynamixel(double N, const emxArray_real_T *t, const
  emxArray_real_T *dtheta, const emxArray_real_T *ddtheta, const emxArray_real_T
  *b_I, const rtString *dtype, double k_dtheta, double K_m, double p[3],
  emxArray_real_T *p_s, double R[9], emxArray_real_T *R_s, emxArray_real_T *time)
{
  int i;
  int loop_ub;
  emxArray_real_T *x_k;
  emxArray_real_T *Y_k;
  emxArray_real_T *unusedU0;
  emxArray_real_T *y;
  emxArray_real_T *a;
  emxArray_real_T *b_dtheta;
  emxArray_real_T *b_ddtheta;
  emxArray_real_T *c_I;
  int b_i;
  double c_i;
  double temp;
  int i1;
  int i2;
  int i3;
  int m;
  int inner;
  int boffset;
  int k;
  int aoffset;
  emxArray_real_T *b_y;
  emxArray_real_T *c_y;
  emxArray_real_T *b;
  double y_data[9];
  int tmp_size[2];
  double d_y[3];
  if (isInitialized_Find_parameters_dynamixel == false) {
    Find_parameters_dynamixel_initialize();
  }

  memset(&R[0], 0, 9U * sizeof(double));
  i = R_s->size[0] * R_s->size[1];
  R_s->size[0] = (int)((double)t->size[0] - N);
  R_s->size[1] = 9;
  emxEnsureCapacity_real_T(R_s, i);
  loop_ub = (int)((double)t->size[0] - N) * 9;
  for (i = 0; i < loop_ub; i++) {
    R_s->data[i] = 0.0;
  }

  i = time->size[0];
  time->size[0] = (int)((double)t->size[0] - N);
  emxEnsureCapacity_real_T(time, i);
  loop_ub = (int)((double)t->size[0] - N);
  for (i = 0; i < loop_ub; i++) {
    time->data[i] = 0.0;
  }

  i = (int)((double)t->size[0] + (1.0 - (N + 1.0)));
  emxInit_real_T(&x_k, 1);
  emxInit_real_T(&Y_k, 2);
  emxInit_real_T(&unusedU0, 1);
  emxInit_real_T(&y, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&b_dtheta, 1);
  emxInit_real_T(&b_ddtheta, 1);
  emxInit_real_T(&c_I, 1);
  for (b_i = 0; b_i < i; b_i++) {
    c_i = (N + 1.0) + (double)b_i;
    temp = c_i - N;
    if (temp > c_i) {
      i1 = 0;
      i2 = 0;
      i3 = 0;
      m = 0;
      inner = 0;
      boffset = 0;
      k = 0;
      aoffset = 0;
    } else {
      i1 = (int)temp - 1;
      i2 = (int)c_i;
      i3 = i1;
      m = i2;
      inner = i1;
      boffset = i2;
      k = (int)temp - 1;
      aoffset = (int)c_i;
    }

    loop_ub = i2 - i1;
    i2 = x_k->size[0];
    x_k->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x_k, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      x_k->data[i2] = t->data[i1 + i2];
    }

    loop_ub = m - i3;
    i1 = b_dtheta->size[0];
    b_dtheta->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_dtheta, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_dtheta->data[i1] = dtheta->data[i3 + i1];
    }

    loop_ub = boffset - inner;
    i1 = b_ddtheta->size[0];
    b_ddtheta->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_ddtheta, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_ddtheta->data[i1] = ddtheta->data[inner + i1];
    }

    loop_ub = aoffset - k;
    i1 = c_I->size[0];
    c_I->size[0] = loop_ub;
    emxEnsureCapacity_real_T(c_I, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_I->data[i1] = b_I->data[k + i1];
    }

    generate_model_vectors(x_k, b_dtheta, b_ddtheta, c_I, dtype->Value, k_dtheta,
      K_m, Y_k, unusedU0);
    i1 = a->size[0] * a->size[1];
    a->size[0] = Y_k->size[1];
    loop_ub = Y_k->size[0];
    a->size[1] = Y_k->size[0];
    emxEnsureCapacity_real_T(a, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      m = Y_k->size[1];
      for (i2 = 0; i2 < m; i2++) {
        a->data[i2 + a->size[0] * i1] = Y_k->data[i1 + Y_k->size[0] * i2];
      }
    }

    if ((a->size[1] == 1) || (Y_k->size[0] == 1)) {
      loop_ub = a->size[0];
      i1 = y->size[0] * y->size[1];
      y->size[0] = a->size[0];
      y->size[1] = Y_k->size[1];
      emxEnsureCapacity_real_T(y, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        m = Y_k->size[1];
        for (i2 = 0; i2 < m; i2++) {
          y->data[i1 + y->size[0] * i2] = 0.0;
          inner = a->size[1];
          for (i3 = 0; i3 < inner; i3++) {
            y->data[i1 + y->size[0] * i2] += a->data[i1 + a->size[0] * i3] *
              Y_k->data[i3 + Y_k->size[0] * i2];
          }
        }
      }
    } else {
      mtimes(a, Y_k, y);
    }

    i1 = (int)(c_i - N) - 1;
    loop_ub = y->size[1];
    m = y->size[1];
    inner = y->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      y_data[i2] = y->data[y->size[0] * i2];
    }

    for (i2 = 0; i2 < m; i2++) {
      y_data[i2 + loop_ub] = y->data[y->size[0] * i2 + 1];
    }

    for (i2 = 0; i2 < inner; i2++) {
      y_data[(i2 + loop_ub) + m] = y->data[y->size[0] * i2 + 2];
    }

    for (i2 = 0; i2 < 9; i2++) {
      R_s->data[i1 + R_s->size[0] * i2] = y_data[i2];
      R[i2] += y->data[i2];
    }

    time->data[i1] = t->data[(int)c_i - 1];
  }

  for (i = 0; i < 9; i++) {
    R[i] /= (double)time->size[0];
  }

  p[0] = 0.0;
  p[1] = 0.0;
  p[2] = 0.0;
  i = p_s->size[0] * p_s->size[1];
  p_s->size[0] = (int)((double)t->size[0] - N);
  p_s->size[1] = 3;
  emxEnsureCapacity_real_T(p_s, i);
  loop_ub = (int)((double)t->size[0] - N) * 3;
  for (i = 0; i < loop_ub; i++) {
    p_s->data[i] = 0.0;
  }

  i = (int)((double)t->size[0] + (1.0 - (N + 1.0)));
  emxInit_real_T(&b_y, 2);
  emxInit_real_T(&c_y, 2);
  emxInit_real_T(&b, 2);
  for (b_i = 0; b_i < i; b_i++) {
    c_i = (N + 1.0) + (double)b_i;
    temp = c_i - N;
    if (temp > c_i) {
      i1 = 0;
      i2 = 0;
      i3 = 0;
      m = 0;
      inner = 0;
      boffset = 0;
      k = 0;
      aoffset = 0;
    } else {
      i1 = (int)temp - 1;
      i2 = (int)c_i;
      i3 = i1;
      m = i2;
      inner = i1;
      boffset = i2;
      k = i1;
      aoffset = i2;
    }

    loop_ub = i2 - i1;
    i2 = x_k->size[0];
    x_k->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x_k, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      x_k->data[i2] = t->data[i1 + i2];
    }

    loop_ub = m - i3;
    i1 = b_dtheta->size[0];
    b_dtheta->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_dtheta, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_dtheta->data[i1] = dtheta->data[i3 + i1];
    }

    loop_ub = boffset - inner;
    i1 = b_ddtheta->size[0];
    b_ddtheta->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_ddtheta, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_ddtheta->data[i1] = ddtheta->data[inner + i1];
    }

    loop_ub = aoffset - k;
    i1 = c_I->size[0];
    c_I->size[0] = loop_ub;
    emxEnsureCapacity_real_T(c_I, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_I->data[i1] = b_I->data[k + i1];
    }

    generate_model_vectors(x_k, b_dtheta, b_ddtheta, c_I, dtype->Value, k_dtheta,
      K_m, Y_k, unusedU0);
    i1 = a->size[0] * a->size[1];
    a->size[0] = Y_k->size[1];
    loop_ub = Y_k->size[0];
    a->size[1] = Y_k->size[0];
    emxEnsureCapacity_real_T(a, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      m = Y_k->size[1];
      for (i2 = 0; i2 < m; i2++) {
        a->data[i2 + a->size[0] * i1] = Y_k->data[i1 + Y_k->size[0] * i2];
      }
    }

    if ((a->size[1] == 1) || (Y_k->size[0] == 1)) {
      loop_ub = a->size[0];
      i1 = y->size[0] * y->size[1];
      y->size[0] = a->size[0];
      y->size[1] = Y_k->size[1];
      emxEnsureCapacity_real_T(y, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        m = Y_k->size[1];
        for (i2 = 0; i2 < m; i2++) {
          y->data[i1 + y->size[0] * i2] = 0.0;
          inner = a->size[1];
          for (i3 = 0; i3 < inner; i3++) {
            y->data[i1 + y->size[0] * i2] += a->data[i1 + a->size[0] * i3] *
              Y_k->data[i3 + Y_k->size[0] * i2];
          }
        }
      }
    } else {
      mtimes(a, Y_k, y);
    }

    inv(y->data, y->size, y_data, tmp_size);
    i1 = c_y->size[0] * c_y->size[1];
    c_y->size[0] = tmp_size[0];
    c_y->size[1] = tmp_size[1];
    emxEnsureCapacity_real_T(c_y, i1);
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_y->data[i1] = y_data[i1];
    }

    i1 = a->size[0] * a->size[1];
    a->size[0] = Y_k->size[1];
    loop_ub = Y_k->size[0];
    a->size[1] = Y_k->size[0];
    emxEnsureCapacity_real_T(a, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      m = Y_k->size[1];
      for (i2 = 0; i2 < m; i2++) {
        a->data[i2 + a->size[0] * i1] = Y_k->data[i1 + Y_k->size[0] * i2];
      }
    }

    inv(y->data, y->size, y_data, tmp_size);
    if ((tmp_size[1] == 1) || (a->size[0] == 1)) {
      loop_ub = c_y->size[0];
      i1 = y->size[0] * y->size[1];
      y->size[0] = c_y->size[0];
      y->size[1] = a->size[1];
      emxEnsureCapacity_real_T(y, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        m = a->size[1];
        for (i2 = 0; i2 < m; i2++) {
          y->data[i1 + y->size[0] * i2] = 0.0;
          inner = c_y->size[1];
          for (i3 = 0; i3 < inner; i3++) {
            y->data[i1 + y->size[0] * i2] += c_y->data[i1 + c_y->size[0] * i3] *
              a->data[i3 + a->size[0] * i2];
          }
        }
      }
    } else {
      mtimes(c_y, a, y);
    }

    if ((y->size[1] == 1) || (unusedU0->size[0] == 1)) {
      i1 = x_k->size[0];
      x_k->size[0] = y->size[0];
      emxEnsureCapacity_real_T(x_k, i1);
      loop_ub = y->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x_k->data[i1] = 0.0;
        m = y->size[1];
        for (i2 = 0; i2 < m; i2++) {
          x_k->data[i1] += y->data[i1 + y->size[0] * i2] * unusedU0->data[i2];
        }
      }
    } else {
      m = y->size[0];
      inner = y->size[1];
      i1 = x_k->size[0];
      x_k->size[0] = y->size[0];
      emxEnsureCapacity_real_T(x_k, i1);
      for (boffset = 0; boffset < m; boffset++) {
        x_k->data[boffset] = 0.0;
      }

      for (k = 0; k < inner; k++) {
        aoffset = k * m;
        for (boffset = 0; boffset < m; boffset++) {
          x_k->data[boffset] += unusedU0->data[k] * y->data[aoffset + boffset];
        }
      }
    }

    i1 = Y_k->size[1];
    if ((Y_k->size[1] == 1) || (x_k->size[0] == 1)) {
      loop_ub = Y_k->size[0];
      i1 = b_dtheta->size[0];
      b_dtheta->size[0] = Y_k->size[0];
      emxEnsureCapacity_real_T(b_dtheta, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_dtheta->data[i1] = 0.0;
        m = Y_k->size[1];
        for (i2 = 0; i2 < m; i2++) {
          b_dtheta->data[i1] += Y_k->data[i1 + Y_k->size[0] * i2] * x_k->data[i2];
        }
      }
    } else {
      i2 = Y_k->size[0];
      i3 = b_dtheta->size[0];
      b_dtheta->size[0] = Y_k->size[0];
      emxEnsureCapacity_real_T(b_dtheta, i3);
      for (boffset = 0; boffset < i2; boffset++) {
        b_dtheta->data[boffset] = 0.0;
      }

      for (k = 0; k < i1; k++) {
        aoffset = k * i2;
        for (boffset = 0; boffset < i2; boffset++) {
          b_dtheta->data[boffset] += x_k->data[k] * Y_k->data[aoffset + boffset];
        }
      }
    }

    i1 = b->size[0] * b->size[1];
    b->size[0] = Y_k->size[1];
    loop_ub = Y_k->size[0];
    b->size[1] = Y_k->size[0];
    emxEnsureCapacity_real_T(b, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      m = Y_k->size[1];
      for (i2 = 0; i2 < m; i2++) {
        b->data[i2 + b->size[0] * i1] = Y_k->data[i1 + Y_k->size[0] * i2];
      }
    }

    if (b->size[0] == 1) {
      i1 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 3;
      loop_ub = b->size[1];
      b_y->size[1] = b->size[1];
      emxEnsureCapacity_real_T(b_y, i1);
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_y->data[i1 + 3 * i2] = (R[i1] * b->data[b->size[0] * i2] + R[i1 + 3]
            * b->data[b->size[0] * i2 + 1]) + R[i1 + 6] * b->data[b->size[0] *
            i2 + 2];
        }
      }
    } else {
      i1 = b->size[1];
      i2 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 3;
      b_y->size[1] = b->size[1];
      emxEnsureCapacity_real_T(b_y, i2);
      for (m = 0; m < i1; m++) {
        inner = m * 3;
        boffset = m * 3;
        b_y->data[inner] = 0.0;
        b_y->data[inner + 1] = 0.0;
        b_y->data[inner + 2] = 0.0;
        for (k = 0; k < 3; k++) {
          aoffset = k * 3;
          temp = b->data[boffset + k];
          b_y->data[inner] += temp * R[aoffset];
          b_y->data[inner + 1] += temp * R[aoffset + 1];
          b_y->data[inner + 2] += temp * R[aoffset + 2];
        }
      }
    }

    loop_ub = unusedU0->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      unusedU0->data[i1] -= b_dtheta->data[i1];
    }

    if ((b_y->size[1] == 1) || (unusedU0->size[0] == 1)) {
      loop_ub = b_y->size[1];
      for (i1 = 0; i1 < 3; i1++) {
        d_y[i1] = 0.0;
        for (i2 = 0; i2 < loop_ub; i2++) {
          d_y[i1] += b_y->data[i1 + 3 * i2] * unusedU0->data[i2];
        }
      }
    } else {
      inner = b_y->size[1];
      d_y[0] = 0.0;
      d_y[1] = 0.0;
      d_y[2] = 0.0;
      for (k = 0; k < inner; k++) {
        aoffset = k * 3;
        d_y[0] += unusedU0->data[k] * b_y->data[aoffset];
        d_y[1] += unusedU0->data[k] * b_y->data[aoffset + 1];
        d_y[2] += unusedU0->data[k] * b_y->data[aoffset + 2];
      }
    }

    boffset = (int)(c_i - N);
    temp = p[0] + d_y[0];
    p[0] = temp;
    p_s->data[boffset - 1] = temp;
    temp = p[1] + d_y[1];
    p[1] = temp;
    p_s->data[(boffset + p_s->size[0]) - 1] = temp;
    temp = p[2] + d_y[2];
    p[2] = temp;
    p_s->data[(boffset + p_s->size[0] * 2) - 1] = temp;
  }

  emxFree_real_T(&c_I);
  emxFree_real_T(&b_ddtheta);
  emxFree_real_T(&b_dtheta);
  emxFree_real_T(&b);
  emxFree_real_T(&c_y);
  emxFree_real_T(&a);
  emxFree_real_T(&y);
  emxFree_real_T(&b_y);
  emxFree_real_T(&unusedU0);
  emxFree_real_T(&Y_k);
  emxFree_real_T(&x_k);
}

/*
 * File trailer for Find_parameters_dynamixel.c
 *
 * [EOF]
 */
