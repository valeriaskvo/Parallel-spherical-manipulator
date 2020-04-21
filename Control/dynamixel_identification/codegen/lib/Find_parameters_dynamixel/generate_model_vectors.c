/*
 * File: generate_model_vectors.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "generate_model_vectors.h"
#include "Find_parameters_dynamixel.h"
#include "Find_parameters_dynamixel_emxutil.h"
#include "cumtrapz.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *time
 *                const emxArray_real_T *dtheta
 *                const emxArray_real_T *ddtheta
 *                const emxArray_real_T *b_I
 *                const emxArray_char_T *dtype_Value
 *                double k_dtheta
 *                double K_m
 *                emxArray_real_T *Y_k
 *                emxArray_real_T *tau_k
 * Return Type  : void
 */
void generate_model_vectors(const emxArray_real_T *time, const emxArray_real_T
  *dtheta, const emxArray_real_T *ddtheta, const emxArray_real_T *b_I, const
  emxArray_char_T *dtype_Value, double k_dtheta, double K_m, emxArray_real_T
  *Y_k, emxArray_real_T *tau_k)
{
  boolean_T equal;
  int nx;
  emxArray_real_T *x;
  int exitg1;
  static const char cv[6] = { 'e', 'n', 'e', 'r', 'g', 'y' };

  int loop_ub;
  static const char cv1[8] = { 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's' };

  emxArray_real_T *b_tmp;
  emxArray_real_T *r;
  emxArray_real_T *b_dtheta;
  equal = false;
  if (dtype_Value->size[1] == 6) {
    nx = 0;
    do {
      exitg1 = 0;
      if (nx < 6) {
        if (dtype_Value->data[nx] != cv[nx]) {
          exitg1 = 1;
        } else {
          nx++;
        }
      } else {
        equal = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emxInit_real_T(&x, 1);
  if (equal) {
    nx = x->size[0];
    x->size[0] = dtheta->size[0];
    emxEnsureCapacity_real_T(x, nx);
    loop_ub = dtheta->size[0];
    for (nx = 0; nx < loop_ub; nx++) {
      x->data[nx] = dtheta->data[nx] / k_dtheta;
    }

    nx = x->size[0];
    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      x->data[loop_ub] = tanh(x->data[loop_ub]);
    }

    emxInit_real_T(&b_tmp, 1);
    nx = b_tmp->size[0];
    b_tmp->size[0] = dtheta->size[0];
    emxEnsureCapacity_real_T(b_tmp, nx);
    nx = dtheta->size[0];
    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      b_tmp->data[loop_ub] = dtheta->data[loop_ub] * dtheta->data[loop_ub];
    }

    emxInit_real_T(&r, 1);
    emxInit_real_T(&b_dtheta, 1);
    cumtrapz(time, b_tmp, r);
    nx = b_dtheta->size[0];
    b_dtheta->size[0] = dtheta->size[0];
    emxEnsureCapacity_real_T(b_dtheta, nx);
    loop_ub = dtheta->size[0];
    for (nx = 0; nx < loop_ub; nx++) {
      b_dtheta->data[nx] = dtheta->data[nx] * x->data[nx];
    }

    cumtrapz(time, b_dtheta, x);
    nx = Y_k->size[0] * Y_k->size[1];
    Y_k->size[0] = b_tmp->size[0];
    Y_k->size[1] = 3;
    emxEnsureCapacity_real_T(Y_k, nx);
    loop_ub = b_tmp->size[0];
    emxFree_real_T(&b_dtheta);
    for (nx = 0; nx < loop_ub; nx++) {
      Y_k->data[nx] = 0.5 * b_tmp->data[nx];
    }

    emxFree_real_T(&b_tmp);
    loop_ub = r->size[0];
    for (nx = 0; nx < loop_ub; nx++) {
      Y_k->data[nx + Y_k->size[0]] = r->data[nx];
    }

    emxFree_real_T(&r);
    loop_ub = x->size[0];
    for (nx = 0; nx < loop_ub; nx++) {
      Y_k->data[nx + Y_k->size[0] * 2] = x->data[nx];
    }

    nx = tau_k->size[0];
    tau_k->size[0] = b_I->size[0];
    emxEnsureCapacity_real_T(tau_k, nx);
    loop_ub = b_I->size[0];
    for (nx = 0; nx < loop_ub; nx++) {
      tau_k->data[nx] = b_I->data[nx] * dtheta->data[nx] * K_m;
    }
  } else {
    equal = false;
    if (dtype_Value->size[1] == 8) {
      nx = 0;
      do {
        exitg1 = 0;
        if (nx < 8) {
          if (dtype_Value->data[nx] != cv1[nx]) {
            exitg1 = 1;
          } else {
            nx++;
          }
        } else {
          equal = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (equal) {
      nx = x->size[0];
      x->size[0] = dtheta->size[0];
      emxEnsureCapacity_real_T(x, nx);
      loop_ub = dtheta->size[0];
      for (nx = 0; nx < loop_ub; nx++) {
        x->data[nx] = dtheta->data[nx] / k_dtheta;
      }

      nx = x->size[0];
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        x->data[loop_ub] = tanh(x->data[loop_ub]);
      }

      nx = Y_k->size[0] * Y_k->size[1];
      Y_k->size[0] = ddtheta->size[0];
      Y_k->size[1] = 3;
      emxEnsureCapacity_real_T(Y_k, nx);
      loop_ub = ddtheta->size[0];
      for (nx = 0; nx < loop_ub; nx++) {
        Y_k->data[nx] = ddtheta->data[nx];
      }

      loop_ub = dtheta->size[0];
      for (nx = 0; nx < loop_ub; nx++) {
        Y_k->data[nx + Y_k->size[0]] = dtheta->data[nx];
      }

      loop_ub = x->size[0];
      for (nx = 0; nx < loop_ub; nx++) {
        Y_k->data[nx + Y_k->size[0] * 2] = x->data[nx];
      }

      nx = tau_k->size[0];
      tau_k->size[0] = b_I->size[0];
      emxEnsureCapacity_real_T(tau_k, nx);
      loop_ub = b_I->size[0];
      for (nx = 0; nx < loop_ub; nx++) {
        tau_k->data[nx] = b_I->data[nx] * K_m;
      }
    } else {
      nx = Y_k->size[0] * Y_k->size[1];
      Y_k->size[0] = 1;
      Y_k->size[1] = 1;
      emxEnsureCapacity_real_T(Y_k, nx);
      Y_k->data[0] = rtNaN;
      nx = tau_k->size[0];
      tau_k->size[0] = 1;
      emxEnsureCapacity_real_T(tau_k, nx);
      tau_k->data[0] = rtNaN;
      printf("%s\n", "Incorrect model type");
      fflush(stdout);
    }
  }

  emxFree_real_T(&x);
}

/*
 * File trailer for generate_model_vectors.c
 *
 * [EOF]
 */
