/*
 * File: factoryConstruct.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "factoryConstruct.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double objfun_tunableEnvironment_f1[5]
 *                const double objfun_tunableEnvironment_f2[4]
 *                f_struct_T *obj
 * Return Type  : void
 */
void factoryConstruct(const double objfun_tunableEnvironment_f1[5], const double
                      objfun_tunableEnvironment_f2[4], f_struct_T *obj)
{
  int idx;
  obj->objfun.tunableEnvironment.f2[0] = objfun_tunableEnvironment_f2[0];
  obj->objfun.tunableEnvironment.f2[1] = objfun_tunableEnvironment_f2[1];
  obj->objfun.tunableEnvironment.f2[2] = objfun_tunableEnvironment_f2[2];
  obj->objfun.tunableEnvironment.f2[3] = objfun_tunableEnvironment_f2[3];
  obj->f_1 = 0.0;
  obj->f_2 = 0.0;
  obj->nVar = 5;
  obj->mIneq = 0;
  obj->mEq = 0;
  obj->numEvals = 0;
  obj->SpecifyObjectiveGradient = false;
  obj->SpecifyConstraintGradient = false;
  obj->FiniteDifferenceType = 0;
  for (idx = 0; idx < 5; idx++) {
    obj->objfun.tunableEnvironment.f1[idx] = objfun_tunableEnvironment_f1[idx];
    obj->hasLB[idx] = false;
    obj->hasUB[idx] = false;
  }

  obj->hasBounds = false;
}

/*
 * File trailer for factoryConstruct.c
 *
 * [EOF]
 */
