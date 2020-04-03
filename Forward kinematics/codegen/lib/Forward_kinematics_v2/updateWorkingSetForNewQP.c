/*
 * File: updateWorkingSetForNewQP.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "updateWorkingSetForNewQP.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : g_struct_T *WorkingSet
 *                int mIneq
 *                int mEq
 *                int mFixed
 * Return Type  : void
 */
void updateWorkingSetForNewQP(g_struct_T *WorkingSet, int mIneq, int mEq, int
  mFixed)
{
  int idx;
  int i;
  int ineqStart;
  for (idx = 0; idx < mEq; idx++) {
    abort();
  }

  for (idx = 0; idx < mIneq; idx++) {
    abort();
  }

  i = mFixed + mEq;
  if (WorkingSet->nActiveConstr > i) {
    ineqStart = i + 1;
    i = WorkingSet->nActiveConstr;
    for (idx = ineqStart; idx <= i; idx++) {
      switch (WorkingSet->Wid) {
       case 4:
        WorkingSet->bwset = WorkingSet->lb[WorkingSet->Wlocalidx - 1];
        break;

       case 5:
        WorkingSet->bwset = WorkingSet->ub[WorkingSet->Wlocalidx - 1];
        break;
      }
    }
  }
}

/*
 * File trailer for updateWorkingSetForNewQP.c
 *
 * [EOF]
 */
