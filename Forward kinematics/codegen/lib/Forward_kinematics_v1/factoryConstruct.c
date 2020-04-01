/*
 * File: factoryConstruct.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "factoryConstruct.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double objfun_tunableEnvironment_f1[5]
 *                const double objfun_tunableEnvironment_f2[3]
 *                g_struct_T *obj
 * Return Type  : void
 */
void factoryConstruct(const double objfun_tunableEnvironment_f1[5], const double
                      objfun_tunableEnvironment_f2[3], g_struct_T *obj)
{
  int i;
  for (i = 0; i < 5; i++) {
    obj->objfun.tunableEnvironment.f1[i] = objfun_tunableEnvironment_f1[i];
  }

  obj->objfun.tunableEnvironment.f2[0] = objfun_tunableEnvironment_f2[0];
  obj->objfun.tunableEnvironment.f2[1] = objfun_tunableEnvironment_f2[1];
  obj->objfun.tunableEnvironment.f2[2] = objfun_tunableEnvironment_f2[2];
  obj->f_1 = 0.0;
  obj->f_2 = 0.0;
  obj->nVar = 6;
  obj->mIneq = 0;
  obj->mEq = 0;
  obj->numEvals = 0;
  obj->SpecifyObjectiveGradient = false;
  obj->SpecifyConstraintGradient = false;
  obj->FiniteDifferenceType = 0;
  for (i = 0; i < 6; i++) {
    obj->hasLB[i] = false;
    obj->hasUB[i] = false;
  }

  obj->hasBounds = false;
}

/*
 * File trailer for factoryConstruct.c
 *
 * [EOF]
 */
