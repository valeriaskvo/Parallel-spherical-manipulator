/*
 * File: PresolveWorkingSet.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "PresolveWorkingSet.h"
#include "Forward_kinematics_v2.h"
#include "RemoveDependentIneq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "factorQRE.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : d_struct_T *solution
 *                c_struct_T *memspace
 *                g_struct_T *workingset
 *                i_struct_T *qrmanager
 *                const b_struct_T *options
 * Return Type  : void
 */
void PresolveWorkingSet(d_struct_T *solution, c_struct_T *memspace, g_struct_T
  *workingset, i_struct_T *qrmanager, const b_struct_T *options)
{
  int nVar;
  int mWorkingFixed;
  int mTotalWorkingEq_tmp;
  int nDepInd;
  int idx_row;
  int ix;
  boolean_T okWorkingSet;
  boolean_T guard1 = false;
  int k;
  double tol;
  boolean_T exitg1;
  double qtb;
  solution->state = 82;
  nVar = workingset->nVar - 1;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[1] + workingset->nWConstr[0];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    for (idx_row = 0; idx_row < mTotalWorkingEq_tmp; idx_row++) {
      for (ix = 0; ix <= nVar; ix++) {
        qrmanager->QR[idx_row + 6 * ix] = workingset->ATwset[ix];
      }
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
      idx_row = workingset->nVar;
      if (mTotalWorkingEq_tmp < idx_row) {
        idx_row = mTotalWorkingEq_tmp;
      }

      qrmanager->minRowCol = idx_row;
      xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
             qrmanager->jpvt, qrmanager->tau);
    }

    tol = 100.0 * (double)workingset->nVar * 2.2204460492503131E-16;
    idx_row = workingset->nVar;
    if (idx_row >= mTotalWorkingEq_tmp) {
      idx_row = mTotalWorkingEq_tmp;
    }

    while ((idx_row > 0) && (fabs(qrmanager->QR[(idx_row + 6 * (idx_row - 1)) -
             1]) < tol)) {
      idx_row--;
      nDepInd++;
    }

    if (nDepInd > 0) {
      computeQ_(qrmanager, qrmanager->mrows);
      nVar = 0;
      exitg1 = false;
      while ((!exitg1) && (nVar <= nDepInd - 1)) {
        qtb = 0.0;
        ix = qrmanager->ldq * ((mTotalWorkingEq_tmp - nVar) - 1);
        for (k = 0; k < mTotalWorkingEq_tmp; k++) {
          qtb += qrmanager->Q[ix] * workingset->bwset;
          ix++;
        }

        if (fabs(qtb) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          nVar++;
        }
      }
    }

    if (nDepInd > 0) {
      for (nVar = 0; nVar < mWorkingFixed; nVar++) {
        qrmanager->jpvt[nVar] = 1;
      }

      ix = workingset->nWConstr[0] + 1;
      if (ix <= mTotalWorkingEq_tmp) {
        memset(&qrmanager->jpvt[ix + -1], 0, ((mTotalWorkingEq_tmp - ix) + 1) *
               sizeof(int));
      }

      factorQRE(qrmanager, workingset->ATwset, workingset->nVar,
                mTotalWorkingEq_tmp);
      for (nVar = 0; nVar < nDepInd; nVar++) {
        memspace->workspace_int[nVar] = qrmanager->jpvt[(mTotalWorkingEq_tmp -
          nDepInd) + nVar];
      }

      countsort(memspace->workspace_int, nDepInd, memspace->workspace_sort, 1,
                mTotalWorkingEq_tmp);
      for (nVar = nDepInd; nVar >= 1; nVar--) {
        ix = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (ix != 0) {
          idx_row = memspace->workspace_int[nVar - 1];
          if (idx_row <= ix) {
            if ((workingset->nActiveConstr == ix) || (idx_row == ix)) {
              workingset->mEqRemoved++;
              removeConstr(workingset);
            } else {
              workingset->mEqRemoved++;
              workingset->isActiveConstr = false;
              workingset->nActiveConstr--;
              ix = workingset->Wid - 1;
              workingset->nWConstr[ix]--;
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
      tol = b_maxConstraintViolation(workingset, solution->xstar, 1);
      if (tol > options->ConstraintTolerance) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    idx_row = workingset->nWConstr[0] + workingset->nWConstr[1];
    ix = idx_row + 1;
    nVar = workingset->nActiveConstr;
    for (k = ix; k <= nVar; k++) {
      workingset->isActiveConstr = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = idx_row;
  }
}

/*
 * File trailer for PresolveWorkingSet.c
 *
 * [EOF]
 */
