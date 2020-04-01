/*
 * File: step.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "step.h"
#include "Forward_kinematics_v2.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : int *STEP_TYPE
 *                double Hessian[25]
 *                d_struct_T *TrialState
 *                h_struct_T *MeritFunction
 *                c_struct_T *memspace
 *                g_struct_T *WorkingSet
 *                i_struct_T *QRManager
 *                k_struct_T *CholManager
 *                j_struct_T *QPObjective
 *                b_struct_T qpoptions
 * Return Type  : boolean_T
 */
boolean_T step(int *STEP_TYPE, double Hessian[25], d_struct_T *TrialState,
               h_struct_T *MeritFunction, c_struct_T *memspace, g_struct_T
               *WorkingSet, i_struct_T *QRManager, k_struct_T *CholManager,
               j_struct_T *QPObjective, b_struct_T qpoptions)
{
  boolean_T stepSuccess;
  int nVar_tmp_tmp;
  int exitg1;
  boolean_T guard1 = false;
  int i;
  d_struct_T b_TrialState;
  int nWIneq_old;
  double grad[6];
  int nWLower_old;
  double oldDirIdx;
  int nWUpper_old;
  double linearizedConstrViolPrev;
  int b_i;
  int mConstrMax;
  int idx;
  int k;
  int mIneq;
  int idxIneqOffset;
  stepSuccess = true;
  nVar_tmp_tmp = WorkingSet->nVar - 1;
  if (*STEP_TYPE != 3) {
    if (0 <= nVar_tmp_tmp) {
      memcpy(&TrialState->xstar[0], &TrialState->xstarsqp[0], (nVar_tmp_tmp + 1)
             * sizeof(double));
    }
  } else {
    if (0 <= nVar_tmp_tmp) {
      memcpy(&TrialState->searchDir[0], &TrialState->xstar[0], (nVar_tmp_tmp + 1)
             * sizeof(double));
    }
  }

  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
     case 1:
      b_TrialState = *TrialState;
      b_driver(Hessian, TrialState->grad, &b_TrialState, memspace, WorkingSet,
               QRManager, CholManager, QPObjective, qpoptions);
      if (b_TrialState.state > 0) {
        oldDirIdx = MeritFunction->penaltyParam;
        linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
        MeritFunction->linearizedConstrViol = 0.0;
        if ((linearizedConstrViolPrev > 2.2204460492503131E-16) &&
            (b_TrialState.fstar > 0.0)) {
          if (b_TrialState.sqpFval == 0.0) {
            oldDirIdx = 1.0;
          } else {
            oldDirIdx = 1.5;
          }

          oldDirIdx = oldDirIdx * b_TrialState.fstar / linearizedConstrViolPrev;
        }

        if (oldDirIdx < MeritFunction->penaltyParam) {
          MeritFunction->phi = b_TrialState.sqpFval + oldDirIdx * 0.0;
          if ((MeritFunction->initFval + oldDirIdx *
               (MeritFunction->initConstrViolationEq +
                MeritFunction->initConstrViolationIneq)) - MeritFunction->phi >
              (double)MeritFunction->nPenaltyDecreases *
              MeritFunction->threshold) {
            MeritFunction->nPenaltyDecreases++;
            if ((MeritFunction->nPenaltyDecreases << 1) >
                b_TrialState.sqpIterations) {
              MeritFunction->threshold *= 10.0;
            }

            MeritFunction->penaltyParam = fmax(oldDirIdx, 1.0E-10);
          } else {
            MeritFunction->phi = b_TrialState.sqpFval +
              MeritFunction->penaltyParam * 0.0;
          }
        } else {
          MeritFunction->penaltyParam = fmax(oldDirIdx, 1.0E-10);
          MeritFunction->phi = b_TrialState.sqpFval +
            MeritFunction->penaltyParam * 0.0;
        }

        MeritFunction->phiPrimePlus = fmin(b_TrialState.fstar -
          MeritFunction->penaltyParam * 0.0, 0.0);
      }

      sortLambdaQP(&b_TrialState.lambda, WorkingSet->nActiveConstr,
                   WorkingSet->sizes, WorkingSet->Wid,
                   memspace->workspace_double);
      if (WorkingSet->mEqRemoved > 0) {
        b_i = b_TrialState.mNonlinEq;
        for (idx = 0; idx < b_i; idx++) {
          WorkingSet->Wlocalidx = b_TrialState.iNonEq0 + idx;
        }
      }

      *TrialState = b_TrialState;
      if ((b_TrialState.state <= 0) && (b_TrialState.state != -6)) {
        *STEP_TYPE = 2;
      } else {
        for (i = 0; i < 6; i++) {
          TrialState->delta_x[i] = b_TrialState.delta_x[i];
        }

        if (0 <= nVar_tmp_tmp) {
          memcpy(&TrialState->delta_x[0], &b_TrialState.xstar[0], (nVar_tmp_tmp
                  + 1) * sizeof(double));
        }

        guard1 = true;
      }
      break;

     case 2:
      b_TrialState = *TrialState;
      relaxed(Hessian, TrialState->grad, &b_TrialState, MeritFunction, memspace,
              WorkingSet, QRManager, CholManager, QPObjective, &qpoptions);
      *TrialState = b_TrialState;
      for (i = 0; i < 6; i++) {
        TrialState->delta_x[i] = b_TrialState.delta_x[i];
      }

      if (0 <= nVar_tmp_tmp) {
        memcpy(&TrialState->delta_x[0], &b_TrialState.xstar[0], (nVar_tmp_tmp +
                1) * sizeof(double));
      }

      guard1 = true;
      break;

     default:
      for (i = 0; i < 6; i++) {
        grad[i] = TrialState->grad[i];
      }

      nWIneq_old = WorkingSet->nWConstr[2];
      nWLower_old = WorkingSet->nWConstr[3];
      nWUpper_old = WorkingSet->nWConstr[4];
      b_i = WorkingSet->nVar - 1;
      mConstrMax = WorkingSet->mConstrMax - 1;
      if (0 <= b_i) {
        memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0], (b_i + 1)
               * sizeof(double));
        memcpy(&TrialState->socDirection[0], &TrialState->xstar[0], (b_i + 1) *
               sizeof(double));
      }

      oldDirIdx = TrialState->lambda_old;
      for (k = 0; k <= mConstrMax; k++) {
        oldDirIdx = TrialState->lambda;
      }

      TrialState->lambda_old = oldDirIdx;
      k = TrialState->workingset_old;
      i = WorkingSet->sizes[1];
      mIneq = WorkingSet->sizes[2];
      idxIneqOffset = WorkingSet->isActiveIdx[2];
      if (WorkingSet->sizes[1] > 0) {
        for (idx = 0; idx < i; idx++) {
          abort();
        }
      }

      if (WorkingSet->sizes[2] > 0) {
        for (idx = 0; idx < mIneq; idx++) {
          abort();
        }

        i = WorkingSet->nActiveConstr;
        for (idx = idxIneqOffset; idx <= i; idx++) {
          k = WorkingSet->Wlocalidx;
        }
      }

      TrialState->workingset_old = k;
      if (0 <= b_i) {
        memcpy(&TrialState->xstar[0], &TrialState->xstarsqp[0], (b_i + 1) *
               sizeof(double));
      }

      b_driver(Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
               CholManager, QPObjective, qpoptions);
      for (idx = 0; idx <= b_i; idx++) {
        oldDirIdx = TrialState->socDirection[idx];
        TrialState->socDirection[idx] = TrialState->xstar[idx] -
          TrialState->socDirection[idx];
        TrialState->xstar[idx] = oldDirIdx;
      }

      stepSuccess = (b_xnrm2(b_i + 1, TrialState->socDirection) <= 2.0 * b_xnrm2
                     (b_i + 1, TrialState->xstar));
      idxIneqOffset = TrialState->workingset_old;
      i = WorkingSet->sizes[1];
      mIneq = WorkingSet->sizes[2];
      if (WorkingSet->sizes[1] > 0) {
        for (idx = 0; idx < i; idx++) {
          abort();
        }
      }

      if (WorkingSet->sizes[2] > 0) {
        for (idx = 0; idx < mIneq; idx++) {
          abort();
        }

        if (!stepSuccess) {
          i = (WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1]) + 1;
          mIneq = WorkingSet->nActiveConstr;
          for (k = i; k <= mIneq; k++) {
            WorkingSet->isActiveConstr = false;
          }

          WorkingSet->nWConstr[2] = 0;
          WorkingSet->nWConstr[3] = 0;
          WorkingSet->nWConstr[4] = 0;
          WorkingSet->nActiveConstr = WorkingSet->nWConstr[0] +
            WorkingSet->nWConstr[1];
          for (idx = 0; idx < nWIneq_old; idx++) {
            WorkingSet->nWConstr[2]++;
            WorkingSet->isActiveConstr = true;
            WorkingSet->nActiveConstr++;
            WorkingSet->Wid = 3;
            WorkingSet->Wlocalidx = idxIneqOffset;
            abort();
          }

          for (idx = 0; idx < nWLower_old; idx++) {
            addBoundToActiveSetMatrix_(WorkingSet, 4, idxIneqOffset);
          }

          for (idx = 0; idx < nWUpper_old; idx++) {
            addBoundToActiveSetMatrix_(WorkingSet, 5, idxIneqOffset);
          }
        }
      }

      if (!stepSuccess) {
        oldDirIdx = TrialState->lambda;
        for (k = 0; k <= mConstrMax; k++) {
          oldDirIdx = TrialState->lambda_old;
        }

        TrialState->lambda = oldDirIdx;
      } else {
        sortLambdaQP(&TrialState->lambda, WorkingSet->nActiveConstr,
                     WorkingSet->sizes, WorkingSet->Wid,
                     memspace->workspace_double);
      }

      if (stepSuccess && (TrialState->state != -6)) {
        for (idx = 0; idx <= nVar_tmp_tmp; idx++) {
          TrialState->delta_x[idx] = TrialState->xstar[idx] +
            TrialState->socDirection[idx];
        }
      }

      guard1 = true;
      break;
    }

    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        oldDirIdx = 0.0;
        linearizedConstrViolPrev = 1.0;
        for (idx = 0; idx < 5; idx++) {
          oldDirIdx = fmax(oldDirIdx, fabs(TrialState->grad[idx]));
          linearizedConstrViolPrev = fmax(linearizedConstrViolPrev, fabs
            (TrialState->xstar[idx]));
        }

        oldDirIdx = fmax(2.2204460492503131E-16, oldDirIdx /
                         linearizedConstrViolPrev);
        for (mIneq = 0; mIneq < 5; mIneq++) {
          i = 5 * mIneq;
          for (k = 0; k < mIneq; k++) {
            Hessian[i + k] = 0.0;
          }

          Hessian[mIneq + 5 * mIneq] = oldDirIdx;
          i += mIneq;
          k = 3 - mIneq;
          if (0 <= k) {
            memset(&Hessian[i + 1], 0, (((k + i) - i) + 1) * sizeof(double));
          }
        }
      }
    }
  } while (exitg1 == 0);

  return stepSuccess;
}

/*
 * File trailer for step.c
 *
 * [EOF]
 */
