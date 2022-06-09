/*
 * File: removeConstr.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "removeConstr.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : g_struct_T *obj
 * Return Type  : void
 */
void removeConstr(g_struct_T *obj)
{
  int i;
  obj->isActiveConstr = false;
  obj->nActiveConstr--;
  i = obj->Wid - 1;
  obj->nWConstr[i]--;
}

/*
 * File trailer for removeConstr.c
 *
 * [EOF]
 */
