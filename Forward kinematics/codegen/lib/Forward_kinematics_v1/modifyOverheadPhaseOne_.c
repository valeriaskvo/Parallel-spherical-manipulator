/*
 * File: modifyOverheadPhaseOne_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "modifyOverheadPhaseOne_.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : f_struct_T *obj
 * Return Type  : void
 */
void modifyOverheadPhaseOne_(f_struct_T *obj)
{
  int i;
  int idx;
  int idxStartIneq;
  i = obj->sizes[0];
  for (idx = 0; idx < i; idx++) {
    obj->ATwset[obj->nVar - 1] = 0.0;
  }

  i = obj->sizes[1];
  for (idx = 0; idx < i; idx++) {
    abort();
  }

  i = obj->sizes[2];
  for (idx = 0; idx < i; idx++) {
    abort();
  }

  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[obj->nVar - 1] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  i = obj->nActiveConstr;
  for (idx = idxStartIneq; idx <= i; idx++) {
    obj->ATwset[obj->nVar - 1] = -1.0;
  }
}

/*
 * File trailer for modifyOverheadPhaseOne_.c
 *
 * [EOF]
 */
