/*
 * File: RemoveDependentIneq_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "RemoveDependentIneq_.h"
#include "Forward_kinematics_v1.h"
#include "countsort.h"
#include "factorQRE.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : f_struct_T *workingset
 *                i_struct_T *qrmanager
 *                c_struct_T *memspace
 *                double tolfactor
 * Return Type  : void
 */
void RemoveDependentIneq_(f_struct_T *workingset, i_struct_T *qrmanager,
  c_struct_T *memspace, double tolfactor)
{
  int nActiveConstr;
  int nFixedConstr;
  double tol;
  int idx;
  int i;
  nActiveConstr = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[1] + workingset->nWConstr[0];
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = tolfactor * (double)workingset->nVar * 2.2204460492503131E-16;
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager->jpvt[idx] = 1;
    }

    i = nFixedConstr + 1;
    if (i <= nActiveConstr) {
      memset(&qrmanager->jpvt[i + -1], 0, ((nActiveConstr - i) + 1) * sizeof(int));
    }

    factorQRE(qrmanager, workingset->ATwset, workingset->nVar,
              workingset->nActiveConstr);
    nActiveConstr = 0;
    for (idx = workingset->nActiveConstr; idx > workingset->nVar; idx--) {
      nActiveConstr++;
      memspace->workspace_int[nActiveConstr - 1] = qrmanager->jpvt[idx - 1];
    }

    if (idx <= workingset->nVar) {
      while ((idx > nFixedConstr) && (fabs(qrmanager->QR[(idx + 7 * (idx - 1)) -
               1]) < tol)) {
        nActiveConstr++;
        memspace->workspace_int[nActiveConstr - 1] = qrmanager->jpvt[idx - 1];
        idx--;
      }
    }

    countsort(memspace->workspace_int, nActiveConstr, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (idx = nActiveConstr; idx >= 1; idx--) {
      workingset->isActiveConstr = false;
      workingset->nActiveConstr--;
      i = workingset->Wid - 1;
      workingset->nWConstr[i]--;
    }
  }
}

/*
 * File trailer for RemoveDependentIneq_.c
 *
 * [EOF]
 */
