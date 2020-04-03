/*
 * File: computeCentralDifferences.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "computeCentralDifferences.h"
#include "Forward_kinematics_v2.h"
#include "finDiffEvalAndChkErr.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : f_struct_T *obj
 *                double fCurrent
 *                double xk[5]
 *                double gradf[6]
 * Return Type  : boolean_T
 */
boolean_T computeCentralDifferences(f_struct_T *obj, double fCurrent, double xk
  [5], double gradf[6])
{
  boolean_T evalOK;
  int idx;
  boolean_T exitg1;
  double deltaX;
  int formulaType;
  double delta1;
  double delta2;
  boolean_T stop;
  int i;
  double t0_objfun_tunableEnvironment_f2[4];
  double t0_objfun_tunableEnvironment_f1[5];
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= obj->nVar - 1)) {
    deltaX = 1.4901161193847656E-8 * fmax(fabs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        abort();
      } else {
        abort();
      }
    } else {
      formulaType = 0;
    }

    delta1 = -deltaX;
    delta2 = deltaX;
    stop = false;
    while (!stop) {
      stop = true;
      for (i = 0; i < 5; i++) {
        t0_objfun_tunableEnvironment_f1[i] = obj->objfun.tunableEnvironment.f1[i];
      }

      t0_objfun_tunableEnvironment_f2[0] = obj->objfun.tunableEnvironment.f2[0];
      t0_objfun_tunableEnvironment_f2[1] = obj->objfun.tunableEnvironment.f2[1];
      t0_objfun_tunableEnvironment_f2[2] = obj->objfun.tunableEnvironment.f2[2];
      t0_objfun_tunableEnvironment_f2[3] = obj->objfun.tunableEnvironment.f2[3];
      evalOK = finDiffEvalAndChkErr(t0_objfun_tunableEnvironment_f1,
        t0_objfun_tunableEnvironment_f2, obj->SpecifyObjectiveGradient,
        &obj->f_1, idx + 1, delta1, xk);
      obj->numEvals++;
      if (!evalOK) {
        if (formulaType == 0) {
          if (!obj->hasBounds) {
            formulaType = 1;
            delta1 = deltaX;
            delta2 = 2.0 * deltaX;
            stop = false;
          } else {
            if (obj->hasUB[idx]) {
              abort();
            }
          }
        }
      } else {
        for (i = 0; i < 5; i++) {
          t0_objfun_tunableEnvironment_f1[i] = obj->
            objfun.tunableEnvironment.f1[i];
        }

        t0_objfun_tunableEnvironment_f2[0] = obj->objfun.tunableEnvironment.f2[0];
        t0_objfun_tunableEnvironment_f2[1] = obj->objfun.tunableEnvironment.f2[1];
        t0_objfun_tunableEnvironment_f2[2] = obj->objfun.tunableEnvironment.f2[2];
        t0_objfun_tunableEnvironment_f2[3] = obj->objfun.tunableEnvironment.f2[3];
        evalOK = finDiffEvalAndChkErr(t0_objfun_tunableEnvironment_f1,
          t0_objfun_tunableEnvironment_f2, obj->SpecifyObjectiveGradient,
          &obj->f_2, idx + 1, delta2, xk);
        obj->numEvals++;
        if ((!evalOK) && (formulaType == 0)) {
          if (!obj->hasBounds) {
            formulaType = -1;
            delta1 = -2.0 * deltaX;
            delta2 = -deltaX;
            stop = false;
          } else {
            if (obj->hasLB[idx]) {
              abort();
            }
          }
        }
      }
    }

    if (!evalOK) {
      exitg1 = true;
    } else {
      if (!obj->SpecifyObjectiveGradient) {
        delta1 = obj->f_1;
        delta2 = obj->f_2;
        switch (formulaType) {
         case 0:
          gradf[idx] = (-delta1 + delta2) / (2.0 * deltaX);
          break;

         case 1:
          gradf[idx] = ((-3.0 * fCurrent + 4.0 * delta1) - delta2) / (2.0 *
            deltaX);
          break;

         default:
          gradf[idx] = ((delta1 - 4.0 * delta2) + 3.0 * fCurrent) / (2.0 *
            deltaX);
          break;
        }
      }

      idx++;
    }
  }

  return evalOK;
}

/*
 * File trailer for computeCentralDifferences.c
 *
 * [EOF]
 */
