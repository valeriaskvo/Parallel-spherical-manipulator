/*
 * File: RemoveDependentIneq_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "RemoveDependentIneq_.h"
#include "Forward_kinematics_v2.h"
#include "countsort.h"
#include "factorQRE.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : g_struct_T *workingset
 *                i_struct_T *qrmanager
 *                c_struct_T *memspace
 *                double tolfactor
 * Return Type  : void
 */
void RemoveDependentIneq_(g_struct_T *workingset, i_struct_T *qrmanager,
  c_struct_T *memspace, double tolfactor)
{
  int nActiveConstr;
  int nFixedConstr;
  double tol;
  int idx;
  int nDepIneq;
  nActiveConstr = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[1] + workingset->nWConstr[0];
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = tolfactor * (double)workingset->nVar * 2.2204460492503131E-16;
    for (idx = 0; idx < nFixedConstr; idx++) {
      qrmanager->jpvt[idx] = 1;
    }

    nDepIneq = nFixedConstr + 1;
    if (nDepIneq <= nActiveConstr) {
      memset(&qrmanager->jpvt[nDepIneq + -1], 0, ((nActiveConstr - nDepIneq) + 1)
             * sizeof(int));
    }

    factorQRE(qrmanager, workingset->ATwset, workingset->nVar,
              workingset->nActiveConstr);
    nDepIneq = 0;
    for (idx = workingset->nActiveConstr; idx > workingset->nVar; idx--) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
    }

    if (idx <= workingset->nVar) {
      while ((idx > nFixedConstr) && (fabs(qrmanager->QR[(idx + 6 * (idx - 1)) -
               1]) < tol)) {
        nDepIneq++;
        memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[idx - 1];
        idx--;
      }
    }

    countsort(memspace->workspace_int, nDepIneq, memspace->workspace_sort,
              nFixedConstr + 1, workingset->nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      removeConstr(workingset);
    }
  }
}

/*
 * File trailer for RemoveDependentIneq_.c
 *
 * [EOF]
 */
