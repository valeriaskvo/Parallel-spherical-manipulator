/*
 * File: driver.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "driver.h"
#include "BFGSUpdate.h"
#include "Forward_kinematics_v2.h"
#include "Weighted_error.h"
#include "computeFiniteDifferences.h"
#include "rt_nonfinite.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : d_struct_T *TrialState
 *                h_struct_T *MeritFunction
 *                const e_struct_T *FcnEvaluator
 *                f_struct_T *FiniteDifferences
 *                c_struct_T *memspace
 *                g_struct_T *WorkingSet
 *                i_struct_T *QRManager
 *                j_struct_T *QPObjective
 *                double Hessian[25]
 *                k_struct_T *CholManager
 * Return Type  : void
 */
void driver(d_struct_T *TrialState, h_struct_T *MeritFunction, const e_struct_T *
            FcnEvaluator, f_struct_T *FiniteDifferences, c_struct_T *memspace,
            g_struct_T *WorkingSet, i_struct_T *QRManager, j_struct_T
            *QPObjective, double Hessian[25], k_struct_T *CholManager)
{
  boolean_T b;
  boolean_T b1;
  int i;
  int nVar;
  static const signed char iv[25] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 };

  int mFixed;
  int mEq;
  int mIneq;
  int mConstr;
  int u1;
  int qpoptions_MaxIterations;
  struct_T Flags;
  b_struct_T expl_temp;
  boolean_T socTaken;
  double dv[2];
  double b_FcnEvaluator[3];
  boolean_T evalWellDefined;
  int b_nVar;
  double alpha;
  double b_TrialState[3];
  int exitflagLnSrch;
  double phi_alpha;
  double c_TrialState[3];
  int iy;
  int b_i;
  int exitg1;
  int ia;
  boolean_T tooSmallX;
  boolean_T exitg2;
  double dv1[2];
  b = false;
  b1 = false;
  memset(&CholManager->UU[0], 0, 36U * sizeof(double));
  for (i = 0; i < 6; i++) {
    CholManager->x[i] = 0.0;
  }

  CholManager->ldu = 6;
  CholManager->ndims = 0;
  CholManager->info = 0;
  for (i = 0; i < 25; i++) {
    Hessian[i] = iv[i];
  }

  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mIneq = WorkingSet->sizes[2];
  mConstr = (((WorkingSet->sizes[0] + WorkingSet->sizes[1]) + WorkingSet->sizes
              [2]) + WorkingSet->sizes[3]) + WorkingSet->sizes[4];
  i = WorkingSet->nVar;
  u1 = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
    (WorkingSet->sizes[0] << 1);
  if (i > u1) {
    u1 = i;
  }

  qpoptions_MaxIterations = 10 * u1;
  TrialState->steplength = 1.0;
  test_exit(memspace, MeritFunction, WorkingSet, TrialState, QRManager,
            &Flags.gradOK, &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
            &Flags.failedLineSearch, &Flags.stepType);
  TrialState->sqpFval_old = TrialState->sqpFval;
  for (u1 = 0; u1 < 5; u1++) {
    TrialState->xstarsqp_old[u1] = TrialState->xstarsqp[u1];
    TrialState->grad_old[u1] = TrialState->grad[u1];
  }

  if (!Flags.done) {
    TrialState->sqpIterations++;
  }

  while (!Flags.done) {
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      updateWorkingSetForNewQP(WorkingSet, mIneq, mEq, mFixed);
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
        if (nVar >= 1) {
          i = nVar - 1;
          for (u1 = 0; u1 <= i; u1++) {
            TrialState->xstarsqp[u1] += TrialState->delta_x[u1];
          }
        }

        if (!b1) {
          dv[0] = 1.0;
          dv[1] = 1000.0;
          b1 = true;
        }

        b_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[0];
        b_FcnEvaluator[1] = FcnEvaluator->objfun.tunableEnvironment.f2[1];
        b_FcnEvaluator[2] = TrialState->xstarsqp[0];
        b_TrialState[0] = TrialState->xstarsqp[1];
        b_TrialState[1] = FcnEvaluator->objfun.tunableEnvironment.f2[2];
        b_TrialState[2] = TrialState->xstarsqp[2];
        c_TrialState[0] = TrialState->xstarsqp[3];
        c_TrialState[1] = FcnEvaluator->objfun.tunableEnvironment.f2[3];
        c_TrialState[2] = TrialState->xstarsqp[4];
        phi_alpha = Weighted_error(FcnEvaluator->objfun.tunableEnvironment.f1,
          dv, b_FcnEvaluator, b_TrialState, c_TrialState);
        i = 1;
        if (FcnEvaluator->NonFiniteSupport && (rtIsInf(phi_alpha) || rtIsNaN
             (phi_alpha))) {
          if (rtIsNaN(phi_alpha)) {
            i = -6;
          } else if (phi_alpha < 0.0) {
            i = -4;
          } else {
            i = -5;
          }
        }

        TrialState->sqpFval = phi_alpha;
        if (i == 1) {
          i = 1;
        }

        Flags.fevalOK = (i == 1);
        TrialState->FunctionEvaluations++;
        if (Flags.fevalOK) {
          MeritFunction->phiFullStep = phi_alpha + MeritFunction->penaltyParam *
            0.0;
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
          socTaken = true;
        } else {
          socTaken = false;
        }

        evalWellDefined = Flags.fevalOK;
        b_nVar = WorkingSet->nVar - 1;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = MeritFunction->phiFullStep;
        if (0 <= b_nVar) {
          memcpy(&TrialState->searchDir[0], &TrialState->delta_x[0], (b_nVar + 1)
                 * sizeof(double));
        }

        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 500) {
            if (evalWellDefined && (phi_alpha <= MeritFunction->phi + alpha *
                                    0.0001 * MeritFunction->phiPrimePlus)) {
              exitg1 = 1;
            } else {
              alpha *= 0.7;
              for (i = 0; i <= b_nVar; i++) {
                TrialState->delta_x[i] = alpha * TrialState->searchDir[i];
              }

              if (socTaken) {
                phi_alpha = alpha * alpha;
                if ((b_nVar + 1 >= 1) && (!(phi_alpha == 0.0))) {
                  for (u1 = 0; u1 <= b_nVar; u1++) {
                    TrialState->delta_x[u1] += phi_alpha *
                      TrialState->socDirection[u1];
                  }
                }
              }

              tooSmallX = true;
              i = 0;
              exitg2 = false;
              while ((!exitg2) && (i <= b_nVar)) {
                if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[i])) <= fabs
                    (TrialState->delta_x[i])) {
                  tooSmallX = false;
                  exitg2 = true;
                } else {
                  i++;
                }
              }

              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                for (i = 0; i <= b_nVar; i++) {
                  TrialState->xstarsqp[i] = TrialState->xstarsqp_old[i] +
                    TrialState->delta_x[i];
                }

                if (!b) {
                  dv1[0] = 1.0;
                  dv1[1] = 1000.0;
                  b = true;
                }

                b_FcnEvaluator[0] = FcnEvaluator->objfun.tunableEnvironment.f2[0];
                b_FcnEvaluator[1] = FcnEvaluator->objfun.tunableEnvironment.f2[1];
                b_FcnEvaluator[2] = TrialState->xstarsqp[0];
                b_TrialState[0] = TrialState->xstarsqp[1];
                b_TrialState[1] = FcnEvaluator->objfun.tunableEnvironment.f2[2];
                b_TrialState[2] = TrialState->xstarsqp[2];
                c_TrialState[0] = TrialState->xstarsqp[3];
                c_TrialState[1] = FcnEvaluator->objfun.tunableEnvironment.f2[3];
                c_TrialState[2] = TrialState->xstarsqp[4];
                phi_alpha = Weighted_error
                  (FcnEvaluator->objfun.tunableEnvironment.f1, dv1,
                   b_FcnEvaluator, b_TrialState, c_TrialState);
                i = 1;
                if (FcnEvaluator->NonFiniteSupport && (rtIsInf(phi_alpha) ||
                     rtIsNaN(phi_alpha))) {
                  if (rtIsNaN(phi_alpha)) {
                    i = -6;
                  } else if (phi_alpha < 0.0) {
                    i = -4;
                  } else {
                    i = -5;
                  }
                }

                TrialState->sqpFval = phi_alpha;
                if (i == 1) {
                  i = 1;
                }

                TrialState->FunctionEvaluations++;
                evalWellDefined = (i == 1);
                if (evalWellDefined) {
                  phi_alpha += MeritFunction->penaltyParam * 0.0;
                } else {
                  phi_alpha = rtInf;
                }
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }

    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      for (i = 0; i < nVar; i++) {
        TrialState->xstarsqp[i] = TrialState->xstarsqp_old[i] +
          TrialState->delta_x[i];
      }

      for (i = 0; i < mConstr; i++) {
        TrialState->lambdasqp += TrialState->steplength * (TrialState->lambda -
          TrialState->lambdasqp);
      }

      TrialState->sqpFval_old = TrialState->sqpFval;
      for (u1 = 0; u1 < 5; u1++) {
        TrialState->xstarsqp_old[u1] = TrialState->xstarsqp[u1];
        TrialState->grad_old[u1] = TrialState->grad[u1];
      }

      Flags.gradOK = computeFiniteDifferences(FiniteDifferences,
        TrialState->sqpFval, TrialState->xstarsqp, TrialState->grad);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      for (u1 = 0; u1 < 5; u1++) {
        TrialState->xstarsqp[u1] = TrialState->xstarsqp_old[u1];
      }
    }

    b_test_exit(&Flags, memspace, MeritFunction, WorkingSet, TrialState,
                QRManager);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      if (0 <= nVar - 1) {
        memcpy(&TrialState->delta_gradLag[0], &TrialState->grad[0], nVar *
               sizeof(double));
      }

      if (nVar >= 1) {
        i = nVar - 1;
        for (u1 = 0; u1 <= i; u1++) {
          TrialState->delta_gradLag[u1] += -TrialState->grad_old[u1];
        }
      }

      if (TrialState->mNonlinEq > 0) {
        u1 = WorkingSet->ldA * (TrialState->iNonEq0 - 1) + 1;
        b_nVar = WorkingSet->ldA;
        if ((nVar != 0) && (TrialState->mNonlinEq != 0)) {
          i = u1 + WorkingSet->ldA * (TrialState->mNonlinEq - 1);
          for (exitflagLnSrch = u1; b_nVar < 0 ? exitflagLnSrch >= i :
               exitflagLnSrch <= i; exitflagLnSrch += b_nVar) {
            iy = 0;
            b_i = (exitflagLnSrch + nVar) - 1;
            for (ia = exitflagLnSrch; ia <= b_i; ia++) {
              TrialState->delta_gradLag[iy] += TrialState->delta_gradLag[ia - 1]
                * TrialState->lambdasqp;
              iy++;
            }
          }
        }

        b_nVar = WorkingSet->ldA;
        if ((nVar != 0) && (TrialState->mNonlinEq != 0)) {
          i = WorkingSet->ldA * (TrialState->mNonlinEq - 1) + 1;
          for (exitflagLnSrch = 1; b_nVar < 0 ? exitflagLnSrch >= i :
               exitflagLnSrch <= i; exitflagLnSrch += b_nVar) {
            iy = 0;
            b_i = (exitflagLnSrch + nVar) - 1;
            for (ia = exitflagLnSrch; ia <= b_i; ia++) {
              TrialState->delta_gradLag[iy] += TrialState->delta_gradLag[ia - 1]
                * -TrialState->lambdasqp;
              iy++;
            }
          }
        }
      }

      if (TrialState->mNonlinIneq > 0) {
        u1 = WorkingSet->ldA * (TrialState->iNonIneq0 - 1) + 1;
        b_nVar = WorkingSet->ldA;
        if ((nVar != 0) && (TrialState->mNonlinIneq != 0)) {
          i = u1 + WorkingSet->ldA * (TrialState->mNonlinIneq - 1);
          for (exitflagLnSrch = u1; b_nVar < 0 ? exitflagLnSrch >= i :
               exitflagLnSrch <= i; exitflagLnSrch += b_nVar) {
            iy = 0;
            b_i = (exitflagLnSrch + nVar) - 1;
            for (ia = exitflagLnSrch; ia <= b_i; ia++) {
              TrialState->delta_gradLag[iy] += TrialState->delta_gradLag[ia - 1]
                * TrialState->lambdasqp;
              iy++;
            }
          }
        }

        b_nVar = WorkingSet->ldA;
        if ((nVar != 0) && (TrialState->mNonlinIneq != 0)) {
          i = WorkingSet->ldA * (TrialState->mNonlinIneq - 1) + 1;
          for (exitflagLnSrch = 1; b_nVar < 0 ? exitflagLnSrch >= i :
               exitflagLnSrch <= i; exitflagLnSrch += b_nVar) {
            iy = 0;
            b_i = (exitflagLnSrch + nVar) - 1;
            for (ia = exitflagLnSrch; ia <= b_i; ia++) {
              TrialState->delta_gradLag[iy] += TrialState->delta_gradLag[ia - 1]
                * -TrialState->lambdasqp;
              iy++;
            }
          }
        }
      }

      BFGSUpdate(nVar, Hessian, TrialState->delta_x, TrialState->delta_gradLag,
                 memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

/*
 * File trailer for driver.c
 *
 * [EOF]
 */
