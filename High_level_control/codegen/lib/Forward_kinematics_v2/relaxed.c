/*
 * File: relaxed.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "relaxed.h"
#include "Forward_kinematics_v2.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "xgemv.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double Hessian[25]
 *                const double grad[6]
 *                d_struct_T *TrialState
 *                h_struct_T *MeritFunction
 *                c_struct_T *memspace
 *                g_struct_T *WorkingSet
 *                i_struct_T *QRManager
 *                k_struct_T *CholManager
 *                j_struct_T *QPObjective
 *                b_struct_T *qpoptions
 * Return Type  : void
 */
void relaxed(const double Hessian[25], const double grad[6], d_struct_T
             *TrialState, h_struct_T *MeritFunction, c_struct_T *memspace,
             g_struct_T *WorkingSet, i_struct_T *QRManager, k_struct_T
             *CholManager, j_struct_T *QPObjective, b_struct_T *qpoptions)
{
  int nVarOrig;
  int nVarMax;
  double beta;
  int idx;
  double rho;
  int idx_negative;
  int i;
  int ix;
  int mIneq;
  double s;
  double xCurrent[6];
  int mEq;
  double workspace[36];
  int nActiveLBArtificial;
  double qpfvalQuadExcess;
  boolean_T isAeqActive;
  nVarOrig = WorkingSet->nVar;
  nVarMax = WorkingSet->nVarMax;
  beta = 0.0;
  for (idx = 0; idx < nVarOrig; idx++) {
    beta += Hessian[idx + 5 * idx];
  }

  beta /= (double)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    idx_negative = QPObjective->nvar;
    if (QPObjective->nvar < 1) {
      i = 0;
    } else {
      i = 1;
      if (QPObjective->nvar > 1) {
        ix = 0;
        rho = fabs(grad[0]);
        for (mIneq = 2; mIneq <= idx_negative; mIneq++) {
          ix++;
          s = fabs(grad[ix]);
          if (s > rho) {
            i = mIneq;
            rho = s;
          }
        }
      }
    }

    rho = 100.0 * fmax(1.0, fabs(grad[i - 1]));
  } else {
    rho = fabs(TrialState->lambdasqp);
  }

  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  setProblemType(WorkingSet, 2);
  for (i = 0; i < 6; i++) {
    xCurrent[i] = TrialState->xstar[i];
  }

  mIneq = WorkingSet->sizes[2] + 1;
  mEq = WorkingSet->sizes[1];
  ix = (WorkingSet->sizes[3] - (WorkingSet->sizes[1] << 1)) - WorkingSet->sizes
    [2];
  for (idx_negative = 0; idx_negative < 36; idx_negative++) {
    workspace[idx_negative] = memspace->workspace_double[idx_negative];
  }

  b_xgemv(nVarOrig, WorkingSet->sizes[2], WorkingSet->ldA, TrialState->xstar,
          workspace);
  for (idx = 0; idx <= mIneq - 2; idx++) {
    xCurrent[nVarOrig + idx] = (double)(workspace[idx] > 0.0) * workspace[idx];
    if (workspace[idx] <= 1.0E-6) {
      addBoundToActiveSetMatrix_(WorkingSet, 4, (ix + idx) + 1);
    }
  }

  b_xgemv(nVarOrig, mEq, WorkingSet->ldA, xCurrent, workspace);
  for (idx = 0; idx < mEq; idx++) {
    i = mIneq + idx;
    idx_negative = (mIneq + mEq) + idx;
    if (workspace[idx] <= 0.0) {
      xCurrent[(nVarOrig + i) - 1] = 0.0;
      xCurrent[(nVarOrig + idx_negative) - 1] = -workspace[idx];
      addBoundToActiveSetMatrix_(WorkingSet, 4, ix + i);
      if (workspace[idx] >= -1.0E-6) {
        addBoundToActiveSetMatrix_(WorkingSet, 4, ix + idx_negative);
      }
    } else {
      xCurrent[(nVarOrig + i) - 1] = workspace[idx];
      xCurrent[(nVarOrig + idx_negative) - 1] = 0.0;
      addBoundToActiveSetMatrix_(WorkingSet, 4, ix + idx_negative);
      if (workspace[idx] <= 1.0E-6) {
        addBoundToActiveSetMatrix_(WorkingSet, 4, ix + i);
      }
    }
  }

  for (i = 0; i < 6; i++) {
    TrialState->xstar[i] = xCurrent[i];
  }

  memcpy(&memspace->workspace_double[0], &workspace[0], 36U * sizeof(double));
  i = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations + WorkingSet->nVar) -
    nVarOrig;
  b_driver(Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, *qpoptions);
  qpoptions->MaxIterations = i;
  mIneq = WorkingSet->sizes[2];
  mEq = WorkingSet->sizes[1];
  i = WorkingSet->sizes[1] << 1;
  nActiveLBArtificial = 0;
  for (idx = 0; idx < mEq; idx++) {
    idx_negative = WorkingSet->isActiveConstr;
    memspace->workspace_int[idx] = idx_negative;
    memspace->workspace_int[idx + mEq] = idx_negative;
    nActiveLBArtificial = (nActiveLBArtificial + idx_negative) + idx_negative;
  }

  for (idx = 0; idx < mIneq; idx++) {
    idx_negative = WorkingSet->isActiveConstr;
    memspace->workspace_int[idx + i] = idx_negative;
    nActiveLBArtificial += idx_negative;
  }

  if (TrialState->state != -6) {
    idx_negative = (WorkingSet->nVarMax - nVarOrig) - 1;
    ix = nVarOrig + 1;
    s = 0.0;
    if (idx_negative >= 1) {
      i = nVarOrig + idx_negative;
      for (mIneq = ix; mIneq <= i; mIneq++) {
        s += fabs(TrialState->xstar[mIneq - 1]);
      }
    }

    qpfvalQuadExcess = 0.0;
    if (idx_negative >= 1) {
      ix = nVarOrig;
      i = nVarOrig;
      for (mIneq = 0; mIneq < idx_negative; mIneq++) {
        qpfvalQuadExcess += TrialState->xstar[ix] * TrialState->xstar[i];
        ix++;
        i++;
      }
    }

    qpfvalQuadExcess = (TrialState->fstar - rho * s) - beta / 2.0 *
      qpfvalQuadExcess;
    mEq = WorkingSet->sizes[1];
    ix = nVarOrig + 1;
    idx_negative = (nVarMax - nVarOrig) - 1;
    beta = MeritFunction->penaltyParam;
    s = MeritFunction->linearizedConstrViol;
    rho = 0.0;
    if (idx_negative >= 1) {
      i = nVarOrig + idx_negative;
      for (mIneq = ix; mIneq <= i; mIneq++) {
        rho += fabs(TrialState->xstar[mIneq - 1]);
      }
    }

    MeritFunction->linearizedConstrViol = rho;
    rho = s - rho;
    if ((rho > 2.2204460492503131E-16) && (qpfvalQuadExcess > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        beta = 1.0;
      } else {
        beta = 1.5;
      }

      beta = beta * qpfvalQuadExcess / rho;
    }

    if (beta < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + beta * 0.0;
      if ((MeritFunction->initFval + beta *
           (MeritFunction->initConstrViolationEq +
            MeritFunction->initConstrViolationIneq)) - MeritFunction->phi >
          (double)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        MeritFunction->penaltyParam = fmax(beta, 1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
          0.0;
      }
    } else {
      MeritFunction->penaltyParam = fmax(beta, 1.0E-10);
      MeritFunction->phi = TrialState->sqpFval + MeritFunction->penaltyParam *
        0.0;
    }

    MeritFunction->phiPrimePlus = fmin(qpfvalQuadExcess -
      MeritFunction->penaltyParam * 0.0, 0.0);
    for (idx = 0; idx < mEq; idx++) {
      if ((memspace->workspace_int[idx] != 0) && (memspace->workspace_int[idx +
           mEq] != 0)) {
        isAeqActive = true;
      } else {
        isAeqActive = false;
      }

      TrialState->lambda *= (double)isAeqActive;
    }

    i = WorkingSet->isActiveIdx[2];
    idx_negative = WorkingSet->nActiveConstr;
    for (idx = i; idx <= idx_negative; idx++) {
      if (WorkingSet->Wid == 3) {
        TrialState->lambda *= (double)memspace->workspace_int
          [(WorkingSet->Wlocalidx + (mEq << 1)) - 1];
      }
    }
  }

  i = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  idx_negative = (WorkingSet->sizes[3] - (WorkingSet->sizes[1] << 1)) -
    WorkingSet->sizes[2];
  idx = WorkingSet->nActiveConstr;
  while ((idx > i + mEq) && (nActiveLBArtificial > 0)) {
    if ((WorkingSet->Wid == 4) && (WorkingSet->Wlocalidx > idx_negative)) {
      removeConstr(WorkingSet);
      nActiveLBArtificial--;
    }

    idx = 0;
  }

  QPObjective->nvar = nVarOrig;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  setProblemType(WorkingSet, 3);
  sortLambdaQP(&TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->Wid, memspace->workspace_double);
}

/*
 * File trailer for relaxed.c
 *
 * [EOF]
 */
