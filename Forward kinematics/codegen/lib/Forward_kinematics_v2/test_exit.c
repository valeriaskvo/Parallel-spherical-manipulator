/*
 * File: test_exit.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "test_exit.h"
#include "Forward_kinematics_v2.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computeLambdaLSQ.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : struct_T *Flags
 *                c_struct_T *memspace
 *                h_struct_T *MeritFunction
 *                g_struct_T *WorkingSet
 *                d_struct_T *TrialState
 *                i_struct_T *QRManager
 * Return Type  : void
 */
void b_test_exit(struct_T *Flags, c_struct_T *memspace, h_struct_T
                 *MeritFunction, g_struct_T *WorkingSet, d_struct_T *TrialState,
                 i_struct_T *QRManager)
{
  int nVar;
  int mFixed;
  int mEq;
  int mIneq;
  int mLB;
  int mUB;
  int mLambda;
  int nActiveConstr;
  int idxmax;
  int ix;
  double optimRelativeFactor;
  double smax;
  int k;
  double s;
  boolean_T isFeasible;
  boolean_T dxTooSmall;
  boolean_T guard1 = false;
  boolean_T exitg1;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda = ((((WorkingSet->sizes[0] + WorkingSet->sizes[1]) + WorkingSet->
               sizes[2]) + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) - 1;
  computeGradLag(TrialState->gradLag, WorkingSet->ldA, WorkingSet->nVar,
                 TrialState->grad, WorkingSet->sizes[2], WorkingSet->sizes[1],
                 WorkingSet->indexFixed, WorkingSet->sizes[0],
                 WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdasqp);
  nActiveConstr = WorkingSet->nVar;
  if (WorkingSet->nVar < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (WorkingSet->nVar > 1) {
      ix = 0;
      smax = fabs(TrialState->grad[0]);
      for (k = 2; k <= nActiveConstr; k++) {
        ix++;
        s = fabs(TrialState->grad[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  optimRelativeFactor = fmax(1.0, fabs(TrialState->grad[idxmax - 1]));
  if (rtIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = 0.0;
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor = fmax(1.0,
      MeritFunction->nlpPrimalFeasError);
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  computeDualFeasError(WorkingSet->nVar, TrialState->gradLag, &Flags->gradOK,
                       &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt = fmax(MeritFunction->nlpDualFeasError,
      MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      b_computeGradLag(memspace->workspace_double, WorkingSet->ldA,
                       WorkingSet->nVar, TrialState->grad, WorkingSet->sizes[2],
                       WorkingSet->sizes[1], WorkingSet->indexFixed,
                       WorkingSet->sizes[0], WorkingSet->indexLB,
                       WorkingSet->sizes[3], WorkingSet->indexUB,
                       WorkingSet->sizes[4], TrialState->lambdasqp_old);
      b_computeDualFeasError(WorkingSet->nVar, memspace->workspace_double,
        &dxTooSmall, &smax);
      s = fmax(smax, 0.0);
      if (s < fmax(MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError))
      {
        MeritFunction->nlpDualFeasError = smax;
        MeritFunction->nlpComplError = 0.0;
        MeritFunction->firstOrderOpt = s;
      } else {
        smax = TrialState->lambdasqp_old;
        for (k = 0; k <= mLambda; k++) {
          smax = TrialState->lambdasqp;
        }

        TrialState->lambdasqp_old = smax;
      }
    } else {
      smax = TrialState->lambdasqp_old;
      for (k = 0; k <= mLambda; k++) {
        smax = TrialState->lambdasqp;
      }

      TrialState->lambdasqp_old = smax;
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       optimRelativeFactor) && (MeritFunction->nlpComplError <=
         1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          dxTooSmall = true;
          nActiveConstr = 0;
          exitg1 = false;
          while ((!exitg1) && (nActiveConstr <= nVar - 1)) {
            if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[nActiveConstr])) <=
                fabs(TrialState->delta_x[nActiveConstr])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              nActiveConstr++;
            }
          }

          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType != 2) {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              }
            } else {
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr > 0) {
                if (TrialState->mNonlinEq + TrialState->mNonlinIneq > 0) {
                  updateWorkingSetForNewQP(WorkingSet, WorkingSet->sizes[2],
                    WorkingSet->sizes[1], WorkingSet->sizes[0]);
                }

                computeLambdaLSQ(nVar, nActiveConstr, QRManager,
                                 WorkingSet->ATwset, TrialState->grad,
                                 &TrialState->lambda, memspace->workspace_double);
                idxmax = mFixed + 1;
                ix = mFixed + mEq;
                for (nActiveConstr = idxmax; nActiveConstr <= ix; nActiveConstr
                     ++) {
                  TrialState->lambda = -TrialState->lambda;
                }

                sortLambdaQP(&TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->Wid,
                             memspace->workspace_double);
                b_computeGradLag(memspace->workspace_double, WorkingSet->ldA,
                                 nVar, TrialState->grad, mIneq, mEq,
                                 WorkingSet->indexFixed, mFixed,
                                 WorkingSet->indexLB, mLB, WorkingSet->indexUB,
                                 mUB, TrialState->lambda);
                b_computeDualFeasError(nVar, memspace->workspace_double,
                  &dxTooSmall, &smax);
                if (smax <= 1.0E-6 * optimRelativeFactor) {
                  MeritFunction->nlpDualFeasError = smax;
                  MeritFunction->nlpComplError = 0.0;
                  MeritFunction->firstOrderOpt = fmax(smax, 0.0);
                  smax = TrialState->lambdasqp;
                  for (k = 0; k <= mLambda; k++) {
                    smax = TrialState->lambda;
                  }

                  TrialState->lambdasqp = smax;
                  Flags->done = true;
                  TrialState->sqpExitFlag = 1;
                } else {
                  if ((smax <= MeritFunction->nlpDualFeasError) && (0.0 <=
                       MeritFunction->nlpComplError)) {
                    MeritFunction->nlpDualFeasError = smax;
                    MeritFunction->nlpComplError = 0.0;
                    MeritFunction->firstOrderOpt = fmax(smax, 0.0);
                    smax = TrialState->lambdasqp;
                    for (k = 0; k <= mLambda; k++) {
                      smax = TrialState->lambda;
                    }

                    TrialState->lambdasqp = smax;
                  }

                  Flags->done = true;
                  TrialState->sqpExitFlag = 2;
                }
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          if (TrialState->sqpIterations >= 400) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else {
            if (TrialState->FunctionEvaluations >= 500) {
              Flags->done = true;
              TrialState->sqpExitFlag = 0;
            }
          }
        }
      }
    }
  }
}

/*
 * Arguments    : c_struct_T *memspace
 *                h_struct_T *MeritFunction
 *                g_struct_T *WorkingSet
 *                d_struct_T *TrialState
 *                i_struct_T *QRManager
 *                boolean_T *Flags_gradOK
 *                boolean_T *Flags_fevalOK
 *                boolean_T *Flags_done
 *                boolean_T *Flags_stepAccepted
 *                boolean_T *Flags_failedLineSearch
 *                int *Flags_stepType
 * Return Type  : void
 */
void test_exit(c_struct_T *memspace, h_struct_T *MeritFunction, g_struct_T
               *WorkingSet, d_struct_T *TrialState, i_struct_T *QRManager,
               boolean_T *Flags_gradOK, boolean_T *Flags_fevalOK, boolean_T
               *Flags_done, boolean_T *Flags_stepAccepted, boolean_T
               *Flags_failedLineSearch, int *Flags_stepType)
{
  int nVar;
  int mFixed;
  int mEq;
  int mIneq;
  int mLB;
  int mUB;
  int mLambda;
  int nActiveConstr;
  int idxmax;
  int ix;
  double optimRelativeFactor;
  double smax;
  int k;
  double s;
  boolean_T isFeasible;
  boolean_T dxTooSmall;
  boolean_T guard1 = false;
  boolean_T exitg1;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda = ((((WorkingSet->sizes[0] + WorkingSet->sizes[1]) + WorkingSet->
               sizes[2]) + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) - 1;
  computeGradLag(TrialState->gradLag, WorkingSet->ldA, WorkingSet->nVar,
                 TrialState->grad, WorkingSet->sizes[2], WorkingSet->sizes[1],
                 WorkingSet->indexFixed, WorkingSet->sizes[0],
                 WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdasqp);
  nActiveConstr = WorkingSet->nVar;
  if (WorkingSet->nVar < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (WorkingSet->nVar > 1) {
      ix = 0;
      smax = fabs(TrialState->grad[0]);
      for (k = 2; k <= nActiveConstr; k++) {
        ix++;
        s = fabs(TrialState->grad[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  optimRelativeFactor = fmax(1.0, fabs(TrialState->grad[idxmax - 1]));
  if (rtIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = 0.0;
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor = fmax(1.0,
      MeritFunction->nlpPrimalFeasError);
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  computeDualFeasError(WorkingSet->nVar, TrialState->gradLag, Flags_gradOK,
                       &MeritFunction->nlpDualFeasError);
  if (!*Flags_gradOK) {
    *Flags_done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt = fmax(MeritFunction->nlpDualFeasError,
      MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      b_computeGradLag(memspace->workspace_double, WorkingSet->ldA,
                       WorkingSet->nVar, TrialState->grad, WorkingSet->sizes[2],
                       WorkingSet->sizes[1], WorkingSet->indexFixed,
                       WorkingSet->sizes[0], WorkingSet->indexLB,
                       WorkingSet->sizes[3], WorkingSet->indexUB,
                       WorkingSet->sizes[4], TrialState->lambdasqp_old);
      b_computeDualFeasError(WorkingSet->nVar, memspace->workspace_double,
        &dxTooSmall, &smax);
      s = fmax(smax, 0.0);
      if (s < fmax(MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError))
      {
        MeritFunction->nlpDualFeasError = smax;
        MeritFunction->nlpComplError = 0.0;
        MeritFunction->firstOrderOpt = s;
      } else {
        smax = TrialState->lambdasqp_old;
        for (k = 0; k <= mLambda; k++) {
          smax = TrialState->lambdasqp;
        }

        TrialState->lambdasqp_old = smax;
      }
    } else {
      smax = TrialState->lambdasqp_old;
      for (k = 0; k <= mLambda; k++) {
        smax = TrialState->lambdasqp;
      }

      TrialState->lambdasqp_old = smax;
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       optimRelativeFactor) && (MeritFunction->nlpComplError <=
         1.0E-6 * optimRelativeFactor)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 1;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = -3;
    } else {
      guard1 = false;
      if (TrialState->sqpIterations > 0) {
        dxTooSmall = true;
        nActiveConstr = 0;
        exitg1 = false;
        while ((!exitg1) && (nActiveConstr <= nVar - 1)) {
          if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[nActiveConstr])) <=
              fabs(TrialState->delta_x[nActiveConstr])) {
            dxTooSmall = false;
            exitg1 = true;
          } else {
            nActiveConstr++;
          }
        }

        if (dxTooSmall) {
          if (!isFeasible) {
            *Flags_stepType = 2;
            guard1 = true;
          } else {
            nActiveConstr = WorkingSet->nActiveConstr;
            if (WorkingSet->nActiveConstr > 0) {
              if (TrialState->mNonlinEq + TrialState->mNonlinIneq > 0) {
                updateWorkingSetForNewQP(WorkingSet, WorkingSet->sizes[2],
                  WorkingSet->sizes[1], WorkingSet->sizes[0]);
              }

              computeLambdaLSQ(nVar, nActiveConstr, QRManager,
                               WorkingSet->ATwset, TrialState->grad,
                               &TrialState->lambda, memspace->workspace_double);
              idxmax = mFixed + 1;
              ix = mFixed + mEq;
              for (nActiveConstr = idxmax; nActiveConstr <= ix; nActiveConstr++)
              {
                TrialState->lambda = -TrialState->lambda;
              }

              sortLambdaQP(&TrialState->lambda, WorkingSet->nActiveConstr,
                           WorkingSet->sizes, WorkingSet->Wid,
                           memspace->workspace_double);
              b_computeGradLag(memspace->workspace_double, WorkingSet->ldA, nVar,
                               TrialState->grad, mIneq, mEq,
                               WorkingSet->indexFixed, mFixed,
                               WorkingSet->indexLB, mLB, WorkingSet->indexUB,
                               mUB, TrialState->lambda);
              b_computeDualFeasError(nVar, memspace->workspace_double,
                &dxTooSmall, &smax);
              if (smax <= 1.0E-6 * optimRelativeFactor) {
                MeritFunction->nlpDualFeasError = smax;
                MeritFunction->nlpComplError = 0.0;
                MeritFunction->firstOrderOpt = fmax(smax, 0.0);
                smax = TrialState->lambdasqp;
                for (k = 0; k <= mLambda; k++) {
                  smax = TrialState->lambda;
                }

                TrialState->lambdasqp = smax;
                *Flags_done = true;
                TrialState->sqpExitFlag = 1;
              } else {
                if ((smax <= MeritFunction->nlpDualFeasError) && (0.0 <=
                     MeritFunction->nlpComplError)) {
                  MeritFunction->nlpDualFeasError = smax;
                  MeritFunction->nlpComplError = 0.0;
                  MeritFunction->firstOrderOpt = fmax(smax, 0.0);
                  smax = TrialState->lambdasqp;
                  for (k = 0; k <= mLambda; k++) {
                    smax = TrialState->lambda;
                  }

                  TrialState->lambdasqp = smax;
                }

                *Flags_done = true;
                TrialState->sqpExitFlag = 2;
              }
            } else {
              *Flags_done = true;
              TrialState->sqpExitFlag = 2;
            }
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        if (TrialState->sqpIterations >= 400) {
          *Flags_done = true;
          TrialState->sqpExitFlag = 0;
        } else {
          if (TrialState->FunctionEvaluations >= 500) {
            *Flags_done = true;
            TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

/*
 * File trailer for test_exit.c
 *
 * [EOF]
 */
