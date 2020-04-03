/*
 * File: PresolveWorkingSet.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "PresolveWorkingSet.h"
#include "Forward_kinematics_v1.h"
#include "RemoveDependentIneq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "factorQRE.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : d_struct_T *solution
 *                c_struct_T *memspace
 *                f_struct_T *workingset
 *                i_struct_T *qrmanager
 * Return Type  : void
 */
void PresolveWorkingSet(d_struct_T *solution, c_struct_T *memspace, f_struct_T
  *workingset, i_struct_T *qrmanager)
{
  int nVar;
  int mWorkingFixed;
  int mTotalWorkingEq_tmp;
  int nDepInd;
  int ix;
  boolean_T okWorkingSet;
  boolean_T guard1 = false;
  int idxEndIneq;
  int idx;
  double tol;
  boolean_T exitg1;
  double qtb;
  solution->state = 82;
  nVar = workingset->nVar - 1;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[1] + workingset->nWConstr[0];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    for (ix = 0; ix <= nVar; ix++) {
      qrmanager->QR[7 * ix] = workingset->ATwset[ix];
    }

    nDepInd = mTotalWorkingEq_tmp - workingset->nVar;
    if (0 > nDepInd) {
      nDepInd = 0;
    }

    if (0 <= nVar) {
      memset(&qrmanager->jpvt[0], 0, (nVar + 1) * sizeof(int));
    }

    if (mTotalWorkingEq_tmp * workingset->nVar == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      ix = workingset->nVar;
      if (mTotalWorkingEq_tmp < ix) {
        ix = mTotalWorkingEq_tmp;
      }

      qrmanager->minRowCol = ix;
      xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
             qrmanager->jpvt, qrmanager->tau);
    }

    tol = 100.0 * (double)workingset->nVar * 2.2204460492503131E-16;
    ix = workingset->nVar;
    if (ix >= mTotalWorkingEq_tmp) {
      ix = mTotalWorkingEq_tmp;
    }

    while ((ix > 0) && (fabs(qrmanager->QR[(ix + 7 * (ix - 1)) - 1]) < tol)) {
      ix--;
      nDepInd++;
    }

    if (nDepInd > 0) {
      computeQ_(qrmanager, qrmanager->mrows);
      idx = 0;
      exitg1 = false;
      while ((!exitg1) && (idx <= nDepInd - 1)) {
        ix = 7 * ((mTotalWorkingEq_tmp - idx) - 1);
        qtb = 0.0;
        for (idxEndIneq = 0; idxEndIneq < mTotalWorkingEq_tmp; idxEndIneq++) {
          qtb += qrmanager->Q[ix] * workingset->bwset;
          ix++;
        }

        if (fabs(qtb) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idx++;
        }
      }
    }

    if (nDepInd > 0) {
      for (idx = 0; idx < mWorkingFixed; idx++) {
        qrmanager->jpvt[idx] = 1;
      }

      idxEndIneq = workingset->nWConstr[0] + 1;
      if (idxEndIneq <= mTotalWorkingEq_tmp) {
        memset(&qrmanager->jpvt[idxEndIneq + -1], 0, ((mTotalWorkingEq_tmp -
                 idxEndIneq) + 1) * sizeof(int));
      }

      factorQRE(qrmanager, workingset->ATwset, workingset->nVar,
                mTotalWorkingEq_tmp);
      for (idx = 0; idx < nDepInd; idx++) {
        memspace->workspace_int[idx] = qrmanager->jpvt[(mTotalWorkingEq_tmp -
          nDepInd) + idx];
      }

      countsort(memspace->workspace_int, nDepInd, memspace->workspace_sort, 1,
                mTotalWorkingEq_tmp);
      for (idx = nDepInd; idx >= 1; idx--) {
        idxEndIneq = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (idxEndIneq != 0) {
          ix = memspace->workspace_int[idx - 1];
          if (ix <= idxEndIneq) {
            if ((workingset->nActiveConstr == idxEndIneq) || (ix == idxEndIneq))
            {
              workingset->mEqRemoved++;
              workingset->isActiveConstr = false;
              workingset->nActiveConstr--;
              idxEndIneq = workingset->Wid - 1;
              workingset->nWConstr[idxEndIneq]--;
            } else {
              workingset->mEqRemoved++;
              workingset->isActiveConstr = false;
              workingset->nActiveConstr--;
              idxEndIneq = workingset->Wid - 1;
              workingset->nWConstr[idxEndIneq]--;
            }
          }
        }
      }
    }
  }

  if (nDepInd != -1) {
    RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      tol = b_maxConstraintViolation(workingset, solution->xstar);
      if (tol > 1.0E-6) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    ix = workingset->nWConstr[0] + workingset->nWConstr[1];
    nVar = ix + 1;
    idxEndIneq = workingset->nActiveConstr;
    for (idx = nVar; idx <= idxEndIneq; idx++) {
      workingset->isActiveConstr = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = ix;
  }
}

/*
 * File trailer for PresolveWorkingSet.c
 *
 * [EOF]
 */
