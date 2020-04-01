/*
 * File: driver.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "driver.h"
#include "BFGSUpdate.h"
#include "Forward_kinematics_v1.h"
#include "Weighted_error.h"
#include "computeFiniteDifferences.h"
#include "computeGradLag.h"
#include "rt_nonfinite.h"
#include "step.h"
#include "test_exit.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : d_struct_T *TrialState
 *                h_struct_T *MeritFunction
 *                const e_struct_T *FcnEvaluator
 *                g_struct_T *FiniteDifferences
 *                c_struct_T *memspace
 *                f_struct_T *WorkingSet
 *                i_struct_T *QRManager
 *                j_struct_T *QPObjective
 *                double Hessian[36]
 *                k_struct_T *CholManager
 * Return Type  : void
 */
void driver(d_struct_T *TrialState, h_struct_T *MeritFunction, const e_struct_T *
            FcnEvaluator, g_struct_T *FiniteDifferences, c_struct_T *memspace,
            f_struct_T *WorkingSet, i_struct_T *QRManager, j_struct_T
            *QPObjective, double Hessian[36], k_struct_T *CholManager)
{
  int i;
  int u1;
  int nVar_tmp_tmp;
  static const signed char iv[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  int mLB;
  int qpoptions_MaxIterations;
  struct_T Flags;
  int ix;
  double smax;
  int k;
  double s;
  boolean_T gradOK;
  boolean_T exitg1;
  b_struct_T expl_temp;
  double b_FcnEvaluator[3];
  boolean_T evalWellDefined;
  double c_FcnEvaluator[3];
  double d_FcnEvaluator[3];
  int exitg2;
  boolean_T tooSmallX;
  memset(&CholManager->UU[0], 0, 49U * sizeof(double));
  for (i = 0; i < 7; i++) {
    CholManager->x[i] = 0.0;
  }

  CholManager->ldu = 7;
  CholManager->ndims = 0;
  CholManager->info = 0;
  for (u1 = 0; u1 < 36; u1++) {
    Hessian[u1] = iv[u1];
  }

  nVar_tmp_tmp = WorkingSet->nVar - 1;
  mLB = WorkingSet->sizes[3];
  i = WorkingSet->nVar;
  u1 = WorkingSet->sizes[3];
  if (i > u1) {
    u1 = i;
  }

  qpoptions_MaxIterations = 10 * u1;
  TrialState->steplength = 1.0;
  Flags.fevalOK = true;
  Flags.stepAccepted = false;
  Flags.failedLineSearch = false;
  Flags.stepType = 1;
  computeGradLag(TrialState->gradLag, 7, WorkingSet->nVar, TrialState->grad, 0,
                 0, WorkingSet->indexFixed, 0, WorkingSet->indexLB,
                 WorkingSet->sizes[3], WorkingSet->indexUB, 0, 0.0);
  i = WorkingSet->nVar;
  if (WorkingSet->nVar < 1) {
    u1 = 0;
  } else {
    u1 = 1;
    if (WorkingSet->nVar > 1) {
      ix = 0;
      smax = fabs(TrialState->grad[0]);
      for (k = 2; k <= i; k++) {
        ix++;
        s = fabs(TrialState->grad[ix]);
        if (s > smax) {
          u1 = k;
          smax = s;
        }
      }
    }
  }

  smax = fmax(1.0, fabs(TrialState->grad[u1 - 1]));
  if (rtIsInf(smax)) {
    smax = 1.0;
  }

  i = -TrialState->mNonlinIneq;
  u1 = -TrialState->mNonlinEq;
  ix = WorkingSet->sizes[3];
  for (k = 0; k < u1; k++) {
    abort();
  }

  for (k = 0; k < i; k++) {
    abort();
  }

  for (k = 0; k < ix; k++) {
    abort();
  }

  MeritFunction->nlpPrimalFeasError = 0.0;
  MeritFunction->feasRelativeFactor = 1.0;
  gradOK = true;
  s = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= nVar_tmp_tmp)) {
    gradOK = ((!rtIsInf(TrialState->gradLag[k])) && (!rtIsNaN
               (TrialState->gradLag[k])));
    if (!gradOK) {
      exitg1 = true;
    } else {
      s = fmax(s, fabs(TrialState->gradLag[k]));
      k++;
    }
  }

  Flags.gradOK = gradOK;
  MeritFunction->nlpDualFeasError = s;
  if (!gradOK) {
    Flags.done = true;
    TrialState->sqpExitFlag = 2;
  } else {
    ix = WorkingSet->sizes[3];
    if (ix > 0) {
      for (k = 0; k < ix; k++) {
        abort();
      }
    }

    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt = s;
    TrialState->lambdasqp_old = 0.0;
    if (s <= 1.0E-6 * smax) {
      Flags.done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags.done = false;
      if (TrialState->sqpFval < -1.0E+20) {
        Flags.done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        if (TrialState->FunctionEvaluations >= 600) {
          Flags.done = true;
          TrialState->sqpExitFlag = 0;
        }
      }
    }
  }

  TrialState->sqpFval_old = TrialState->sqpFval;
  for (k = 0; k < 6; k++) {
    TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
    TrialState->grad_old[k] = TrialState->grad[k];
  }

  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }

  while (!Flags.done) {
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      if (WorkingSet->nActiveConstr > 0) {
        u1 = WorkingSet->nActiveConstr;
        for (k = 1; k <= u1; k++) {
          switch (WorkingSet->Wid) {
           case 4:
            WorkingSet->bwset = WorkingSet->lb[WorkingSet->Wlocalidx - 1];
            break;

           case 5:
            WorkingSet->bwset = WorkingSet->ub[WorkingSet->Wlocalidx - 1];
            break;

           default:
            abort();
            break;
          }
        }
      }

      expl_temp.DisplayQP = false;
      expl_temp.ObjectiveLimit = -1.0E+20;
      expl_temp.ConstraintTolerance = 1.0E-6;
      expl_temp.OptimalityTolerance = 2.2204460492503131E-14;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      Flags.stepAccepted = step(&Flags.stepType, Hessian, TrialState,
        MeritFunction, memspace, WorkingSet, QRManager, CholManager, QPObjective,
        expl_temp);
      if (Flags.stepAccepted) {
        for (k = 0; k <= nVar_tmp_tmp; k++) {
          TrialState->xstarsqp[k] += TrialState->delta_x[k];
        }

        b_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[0];
        b_FcnEvaluator[1] = TrialState->xstarsqp[0];
        b_FcnEvaluator[2] = TrialState->xstarsqp[1];
        c_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[1];
        c_FcnEvaluator[1] = TrialState->xstarsqp[2];
        c_FcnEvaluator[2] = TrialState->xstarsqp[3];
        d_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[2];
        d_FcnEvaluator[1] = TrialState->xstarsqp[4];
        d_FcnEvaluator[2] = TrialState->xstarsqp[5];
        smax = Weighted_error(FcnEvaluator->objfun.tunableEnvironment.f1,
                              b_FcnEvaluator, c_FcnEvaluator, d_FcnEvaluator);
        i = 1;
        if (rtIsInf(smax) || rtIsNaN(smax)) {
          if (rtIsNaN(smax)) {
            i = -6;
          } else if (smax < 0.0) {
            i = -4;
          } else {
            i = -5;
          }
        }

        TrialState->sqpFval = smax;
        if (i == 1) {
          i = 1;
        }

        Flags.fevalOK = (i == 1);
        TrialState->FunctionEvaluations++;
        if (Flags.fevalOK) {
          MeritFunction->phiFullStep = smax + MeritFunction->penaltyParam * 0.0;
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }

      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          gradOK = true;
        } else {
          gradOK = false;
        }

        evalWellDefined = Flags.fevalOK;
        u1 = WorkingSet->nVar - 1;
        s = 1.0;
        ix = 1;
        smax = MeritFunction->phiFullStep;
        if (0 <= u1) {
          memcpy(&TrialState->searchDir[0], &TrialState->delta_x[0], (u1 + 1) *
                 sizeof(double));
        }

        do {
          exitg2 = 0;
          if (TrialState->FunctionEvaluations < 600) {
            if (evalWellDefined && (smax <= MeritFunction->phi + s * 0.0001 *
                                    MeritFunction->phiPrimePlus)) {
              exitg2 = 1;
            } else {
              s *= 0.7;
              for (k = 0; k <= u1; k++) {
                TrialState->delta_x[k] = s * TrialState->searchDir[k];
              }

              if (gradOK) {
                smax = s * s;
                if ((u1 + 1 >= 1) && (!(smax == 0.0))) {
                  for (k = 0; k <= u1; k++) {
                    TrialState->delta_x[k] += smax * TrialState->socDirection[k];
                  }
                }
              }

              tooSmallX = true;
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k <= u1)) {
                if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[k])) <= fabs
                    (TrialState->delta_x[k])) {
                  tooSmallX = false;
                  exitg1 = true;
                } else {
                  k++;
                }
              }

              if (tooSmallX) {
                ix = -2;
                exitg2 = 1;
              } else {
                for (k = 0; k <= u1; k++) {
                  TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k] +
                    TrialState->delta_x[k];
                }

                b_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[0];
                b_FcnEvaluator[1] = TrialState->xstarsqp[0];
                b_FcnEvaluator[2] = TrialState->xstarsqp[1];
                c_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[1];
                c_FcnEvaluator[1] = TrialState->xstarsqp[2];
                c_FcnEvaluator[2] = TrialState->xstarsqp[3];
                d_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[2];
                d_FcnEvaluator[1] = TrialState->xstarsqp[4];
                d_FcnEvaluator[2] = TrialState->xstarsqp[5];
                smax = Weighted_error(FcnEvaluator->objfun.tunableEnvironment.f1,
                                      b_FcnEvaluator, c_FcnEvaluator,
                                      d_FcnEvaluator);
                i = 1;
                if (rtIsInf(smax) || rtIsNaN(smax)) {
                  if (rtIsNaN(smax)) {
                    i = -6;
                  } else if (smax < 0.0) {
                    i = -4;
                  } else {
                    i = -5;
                  }
                }

                TrialState->sqpFval = smax;
                if (i == 1) {
                  i = 1;
                }

                TrialState->FunctionEvaluations++;
                evalWellDefined = (i == 1);
                if (evalWellDefined) {
                  smax += MeritFunction->penaltyParam * 0.0;
                } else {
                  smax = rtInf;
                }
              }
            }
          } else {
            ix = 0;
            exitg2 = 1;
          }
        } while (exitg2 == 0);

        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = s;
        if (ix > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }

    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      for (k = 0; k <= nVar_tmp_tmp; k++) {
        TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k] +
          TrialState->delta_x[k];
      }

      for (k = 0; k < mLB; k++) {
        TrialState->lambdasqp += TrialState->steplength * (TrialState->lambda -
          TrialState->lambdasqp);
      }

      TrialState->sqpFval_old = TrialState->sqpFval;
      for (k = 0; k < 6; k++) {
        TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
        TrialState->grad_old[k] = TrialState->grad[k];
      }

      Flags.gradOK = computeFiniteDifferences(FiniteDifferences,
        TrialState->sqpFval, TrialState->xstarsqp, TrialState->grad);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      for (k = 0; k < 6; k++) {
        TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k];
      }
    }

    test_exit(&Flags, memspace, MeritFunction, WorkingSet, TrialState, QRManager);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      if (0 <= nVar_tmp_tmp) {
        memcpy(&TrialState->delta_gradLag[0], &TrialState->grad[0],
               (nVar_tmp_tmp + 1) * sizeof(double));
      }

      if (nVar_tmp_tmp + 1 >= 1) {
        for (k = 0; k <= nVar_tmp_tmp; k++) {
          TrialState->delta_gradLag[k] += -TrialState->grad_old[k];
        }
      }

      BFGSUpdate(nVar_tmp_tmp + 1, Hessian, TrialState->delta_x,
                 TrialState->delta_gradLag, memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

/*
 * File trailer for driver.c
 *
 * [EOF]
 */
