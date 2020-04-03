/*
 * File: computeFiniteDifferences.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "computeFiniteDifferences.h"
#include "Forward_kinematics_v2.h"
#include "computeCentralDifferences.h"
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
boolean_T computeFiniteDifferences(f_struct_T *obj, double fCurrent, double xk[5],
  double gradf[6])
{
  boolean_T evalOK;
  int idx;
  boolean_T exitg1;
  double deltaX;
  int i;
  double t1_objfun_tunableEnvironment_f2[4];
  double t1_objfun_tunableEnvironment_f1[5];
  boolean_T guard1 = false;
  switch (obj->FiniteDifferenceType) {
   case 0:
    evalOK = true;
    obj->numEvals = 0;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx <= obj->nVar - 1)) {
      deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (double)(xk[idx] < 0.0)) *
        fmax(fabs(xk[idx]), 1.0);
      if (obj->hasLB[idx] || obj->hasUB[idx]) {
        if (obj->hasLB[idx] && obj->hasUB[idx]) {
          abort();
        } else {
          abort();
        }
      }

      for (i = 0; i < 5; i++) {
        t1_objfun_tunableEnvironment_f1[i] = obj->objfun.tunableEnvironment.f1[i];
      }

      t1_objfun_tunableEnvironment_f2[0] = obj->objfun.tunableEnvironment.f2[0];
      t1_objfun_tunableEnvironment_f2[1] = obj->objfun.tunableEnvironment.f2[1];
      t1_objfun_tunableEnvironment_f2[2] = obj->objfun.tunableEnvironment.f2[2];
      t1_objfun_tunableEnvironment_f2[3] = obj->objfun.tunableEnvironment.f2[3];
      evalOK = finDiffEvalAndChkErr(t1_objfun_tunableEnvironment_f1,
        t1_objfun_tunableEnvironment_f2, obj->SpecifyObjectiveGradient,
        &obj->f_1, idx + 1, deltaX, xk);
      obj->numEvals++;
      guard1 = false;
      if (!evalOK) {
        deltaX = -deltaX;
        if (obj->hasLB[idx]) {
          abort();
        }

        if (!obj->hasBounds) {
          for (i = 0; i < 5; i++) {
            t1_objfun_tunableEnvironment_f1[i] =
              obj->objfun.tunableEnvironment.f1[i];
          }

          t1_objfun_tunableEnvironment_f2[0] = obj->
            objfun.tunableEnvironment.f2[0];
          t1_objfun_tunableEnvironment_f2[1] = obj->
            objfun.tunableEnvironment.f2[1];
          t1_objfun_tunableEnvironment_f2[2] = obj->
            objfun.tunableEnvironment.f2[2];
          t1_objfun_tunableEnvironment_f2[3] = obj->
            objfun.tunableEnvironment.f2[3];
          evalOK = finDiffEvalAndChkErr(t1_objfun_tunableEnvironment_f1,
            t1_objfun_tunableEnvironment_f2, obj->SpecifyObjectiveGradient,
            &obj->f_1, idx + 1, deltaX, xk);
          obj->numEvals++;
        }

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
    break;

   default:
    evalOK = computeCentralDifferences(obj, fCurrent, xk, gradf);
    break;
  }

  return evalOK;
}

/*
 * File trailer for computeFiniteDifferences.c
 *
 * [EOF]
 */
