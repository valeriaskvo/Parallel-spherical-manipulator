/*
 * File: addBoundToActiveSetMatrix_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "addBoundToActiveSetMatrix_.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : f_struct_T *obj
 *                int TYPE
 *                int idx_local
 * Return Type  : void
 */
void addBoundToActiveSetMatrix_(f_struct_T *obj, int TYPE, int idx_local)
{
  int idx_bnd_local;
  int i;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr = true;
  obj->nActiveConstr++;
  obj->Wid = TYPE;
  obj->Wlocalidx = idx_local;
  switch (TYPE) {
   case 5:
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset = obj->ub[idx_bnd_local - 1];
    break;

   default:
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset = obj->lb[idx_bnd_local - 1];
    break;
  }

  if (0 <= idx_bnd_local - 2) {
    memset(&obj->ATwset[0], 0, (idx_bnd_local + -1) * sizeof(double));
  }

  obj->ATwset[idx_bnd_local - 1] = 2.0 * (double)(TYPE == 5) - 1.0;
  idx_bnd_local++;
  i = obj->nVar;
  if (idx_bnd_local <= i) {
    memset(&obj->ATwset[idx_bnd_local + -1], 0, ((i - idx_bnd_local) + 1) *
           sizeof(double));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar - 1] = -1.0;
    break;
  }
}

/*
 * File trailer for addBoundToActiveSetMatrix_.c
 *
 * [EOF]
 */
