/*
 * File: computeFiniteDifferences.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "computeFiniteDifferences.h"
#include "Forward_kinematics_v1.h"
#include "Weighted_error.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : g_struct_T *obj
 *                double fCurrent
 *                double xk[6]
 *                double gradf[7]
 * Return Type  : boolean_T
 */
boolean_T computeFiniteDifferences(g_struct_T *obj, double fCurrent, double xk[6],
  double gradf[7])
{
  boolean_T evalOK;
  int idx;
  boolean_T exitg1;
  double deltaX;
  int i;
  double b_xk[6];
  double b_obj[3];
  double c_obj[3];
  double d_obj[3];
  double fplus;
  boolean_T guard1 = false;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 6)) {
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (double)(xk[idx] < 0.0)) *
      fmax(fabs(xk[idx]), 1.0);
    for (i = 0; i < 6; i++) {
      b_xk[i] = xk[i];
    }

    b_xk[idx] = xk[idx] + deltaX;
    b_obj[0] = obj->objfun.tunableEnvironment.f2[0];
    b_obj[1] = b_xk[0];
    b_obj[2] = b_xk[1];
    c_obj[0] = obj->objfun.tunableEnvironment.f2[1];
    c_obj[1] = b_xk[2];
    c_obj[2] = b_xk[3];
    d_obj[0] = obj->objfun.tunableEnvironment.f2[2];
    d_obj[1] = b_xk[4];
    d_obj[2] = b_xk[5];
    fplus = Weighted_error(obj->objfun.tunableEnvironment.f1, b_obj, c_obj,
      d_obj);
    evalOK = ((!rtIsInf(fplus)) && (!rtIsNaN(fplus)));
    if (evalOK) {
      b_xk[idx] = xk[idx];
    }

    obj->f_1 = fplus;
    for (i = 0; i < 6; i++) {
      xk[i] = b_xk[i];
    }

    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      deltaX = -deltaX;
      xk[idx] = b_xk[idx] + deltaX;
      b_obj[0] = obj->objfun.tunableEnvironment.f2[0];
      b_obj[1] = xk[0];
      b_obj[2] = xk[1];
      c_obj[0] = obj->objfun.tunableEnvironment.f2[1];
      c_obj[1] = xk[2];
      c_obj[2] = xk[3];
      d_obj[0] = obj->objfun.tunableEnvironment.f2[2];
      d_obj[1] = xk[4];
      d_obj[2] = xk[5];
      fplus = Weighted_error(obj->objfun.tunableEnvironment.f1, b_obj, c_obj,
        d_obj);
      evalOK = ((!rtIsInf(fplus)) && (!rtIsNaN(fplus)));
      if (evalOK) {
        xk[idx] = b_xk[idx];
      }

      obj->f_1 = fplus;
      obj->numEvals++;
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      gradf[idx] = (obj->f_1 - fCurrent) / deltaX;
      idx++;
    }
  }

  return evalOK;
}

/*
 * File trailer for computeFiniteDifferences.c
 *
 * [EOF]
 */
