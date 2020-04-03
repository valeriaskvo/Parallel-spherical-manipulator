/*
 * File: test_exit.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "test_exit.h"
#include "Forward_kinematics_v1.h"
#include "computeGradLag.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xgemv.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : struct_T *Flags
 *                c_struct_T *memspace
 *                h_struct_T *MeritFunction
 *                const f_struct_T *WorkingSet
 *                d_struct_T *TrialState
 *                i_struct_T *QRManager
 * Return Type  : void
 */
void test_exit(struct_T *Flags, c_struct_T *memspace, h_struct_T *MeritFunction,
               const f_struct_T *WorkingSet, d_struct_T *TrialState, i_struct_T *
               QRManager)
{
  int mLambda_tmp;
  int mLambda;
  int nActiveConstr;
  int jjA;
  int ix;
  double optimRelativeFactor;
  double smax;
  int k;
  double s;
  int rankR;
  boolean_T dxTooSmall;
  int exitg1;
  int i;
  boolean_T guard1 = false;
  boolean_T exitg2;
  int fullRank_R;
  double workspace[49];
  mLambda_tmp = WorkingSet->sizes[0] + WorkingSet->sizes[1];
  mLambda = (((mLambda_tmp + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
             WorkingSet->sizes[4]) - 1;
  computeGradLag(TrialState->gradLag, WorkingSet->ldA, WorkingSet->nVar,
                 TrialState->grad, WorkingSet->sizes[2], WorkingSet->sizes[1],
                 WorkingSet->indexFixed, WorkingSet->sizes[0],
                 WorkingSet->indexLB, WorkingSet->sizes[3], WorkingSet->indexUB,
                 WorkingSet->sizes[4], TrialState->lambdasqp);
  nActiveConstr = WorkingSet->nVar;
  if (WorkingSet->nVar < 1) {
    jjA = 0;
  } else {
    jjA = 1;
    if (WorkingSet->nVar > 1) {
      ix = 0;
      smax = fabs(TrialState->grad[0]);
      for (k = 2; k <= nActiveConstr; k++) {
        ix++;
        s = fabs(TrialState->grad[ix]);
        if (s > smax) {
          jjA = k;
          smax = s;
        }
      }
    }
  }

  optimRelativeFactor = fmax(1.0, fabs(TrialState->grad[jjA - 1]));
  if (rtIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }

  nActiveConstr = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  jjA = WorkingSet->sizes[1] - TrialState->mNonlinEq;
  k = WorkingSet->sizes[3];
  rankR = WorkingSet->sizes[4];
  for (ix = 0; ix < jjA; ix++) {
    abort();
  }

  for (ix = 0; ix < nActiveConstr; ix++) {
    abort();
  }

  for (ix = 0; ix < k; ix++) {
    abort();
  }

  for (ix = 0; ix < rankR; ix++) {
    abort();
  }

  MeritFunction->nlpPrimalFeasError = 0.0;
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor = 1.0;
  }

  dxTooSmall = true;
  smax = 0.0;
  ix = 0;
  do {
    exitg1 = 0;
    i = WorkingSet->nVar - 1;
    if (ix <= i) {
      dxTooSmall = ((!rtIsInf(TrialState->gradLag[ix])) && (!rtIsNaN
        (TrialState->gradLag[ix])));
      if (!dxTooSmall) {
        exitg1 = 1;
      } else {
        smax = fmax(smax, fabs(TrialState->gradLag[ix]));
        ix++;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  Flags->gradOK = dxTooSmall;
  MeritFunction->nlpDualFeasError = smax;
  if (!dxTooSmall) {
    Flags->done = true;
    TrialState->sqpExitFlag = 2;
  } else {
    k = WorkingSet->sizes[3];
    rankR = WorkingSet->sizes[4];
    if ((WorkingSet->sizes[2] + k) + rankR > 0) {
      for (ix = 0; ix < k; ix++) {
        abort();
      }

      for (ix = 0; ix < rankR; ix++) {
        abort();
      }
    }

    MeritFunction->nlpComplError = 0.0;
    MeritFunction->firstOrderOpt = smax;
    if (TrialState->sqpIterations > 1) {
      b_computeGradLag(memspace->workspace_double, WorkingSet->ldA,
                       WorkingSet->nVar, TrialState->grad, WorkingSet->sizes[2],
                       WorkingSet->sizes[1], WorkingSet->indexFixed,
                       WorkingSet->sizes[0], WorkingSet->indexLB,
                       WorkingSet->sizes[3], WorkingSet->indexUB,
                       WorkingSet->sizes[4], TrialState->lambdasqp_old);
      s = 0.0;
      ix = 0;
      while ((ix <= i) && ((!rtIsInf(memspace->workspace_double[ix])) &&
                           (!rtIsNaN(memspace->workspace_double[ix])))) {
        s = fmax(s, fabs(memspace->workspace_double[ix]));
        ix++;
      }

      k = WorkingSet->sizes[3];
      rankR = WorkingSet->sizes[4];
      if ((WorkingSet->sizes[2] + k) + rankR > 0) {
        for (ix = 0; ix < k; ix++) {
          abort();
        }

        for (ix = 0; ix < rankR; ix++) {
          abort();
        }
      }

      if (s < smax) {
        MeritFunction->nlpDualFeasError = s;
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

    if (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (TrialState->sqpFval < -1.0E+20) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          dxTooSmall = true;
          ix = 0;
          exitg2 = false;
          while ((!exitg2) && (ix <= i)) {
            if (1.0E-6 * fmax(1.0, fabs(TrialState->xstarsqp[ix])) <= fabs
                (TrialState->delta_x[ix])) {
              dxTooSmall = false;
              exitg2 = true;
            } else {
              ix++;
            }
          }

          if (dxTooSmall) {
            nActiveConstr = WorkingSet->nActiveConstr;
            if (WorkingSet->nActiveConstr > 0) {
              smax = TrialState->lambda;
              for (k = 0; k < nActiveConstr; k++) {
                smax = 0.0;
              }

              factorQRE(QRManager, WorkingSet->ATwset, WorkingSet->nVar,
                        WorkingSet->nActiveConstr);
              computeQ_(QRManager, QRManager->mrows);
              jjA = WorkingSet->nVar;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (jjA > nActiveConstr) {
                nActiveConstr = jjA;
              }

              s = fabs(QRManager->QR[0]) * fmin(1.4901161193847656E-8, (double)
                nActiveConstr * 2.2204460492503131E-16);
              jjA = WorkingSet->nVar;
              fullRank_R = WorkingSet->nActiveConstr;
              if (jjA < fullRank_R) {
                fullRank_R = jjA;
              }

              rankR = 0;
              nActiveConstr = 0;
              while ((rankR < fullRank_R) && (fabs(QRManager->QR[nActiveConstr])
                      > s)) {
                rankR++;
                nActiveConstr += 8;
              }

              for (nActiveConstr = 0; nActiveConstr < 49; nActiveConstr++) {
                workspace[nActiveConstr] = memspace->
                  workspace_double[nActiveConstr];
              }

              xgemv(WorkingSet->nVar, WorkingSet->nVar, QRManager->Q,
                    TrialState->grad, workspace);
              if (rankR != 0) {
                for (nActiveConstr = rankR; nActiveConstr >= 1; nActiveConstr--)
                {
                  jjA = (nActiveConstr + (nActiveConstr - 1) * 7) - 1;
                  workspace[nActiveConstr - 1] /= QRManager->QR[jjA];
                  for (k = 0; k <= nActiveConstr - 2; k++) {
                    ix = (nActiveConstr - k) - 2;
                    workspace[ix] -= workspace[nActiveConstr - 1] *
                      QRManager->QR[(jjA - k) - 1];
                  }
                }
              }

              jjA = WorkingSet->nActiveConstr;
              if (jjA < fullRank_R) {
                fullRank_R = jjA;
              }

              for (ix = 0; ix < fullRank_R; ix++) {
                smax = workspace[ix];
              }

              TrialState->lambda = smax;
              nActiveConstr = WorkingSet->sizes[0] + 1;
              for (ix = nActiveConstr; ix <= mLambda_tmp; ix++) {
                TrialState->lambda = -TrialState->lambda;
              }

              memcpy(&memspace->workspace_double[0], &workspace[0], 49U * sizeof
                     (double));
              sortLambdaQP(&TrialState->lambda, WorkingSet->nActiveConstr,
                           WorkingSet->sizes, WorkingSet->Wid,
                           memspace->workspace_double);
              b_computeGradLag(memspace->workspace_double, WorkingSet->ldA,
                               WorkingSet->nVar, TrialState->grad,
                               WorkingSet->sizes[2], WorkingSet->sizes[1],
                               WorkingSet->indexFixed, WorkingSet->sizes[0],
                               WorkingSet->indexLB, WorkingSet->sizes[3],
                               WorkingSet->indexUB, WorkingSet->sizes[4],
                               TrialState->lambda);
              smax = 0.0;
              ix = 0;
              while ((ix <= i) && ((!rtIsInf(memspace->workspace_double[ix])) &&
                                   (!rtIsNaN(memspace->workspace_double[ix]))))
              {
                smax = fmax(smax, fabs(memspace->workspace_double[ix]));
                ix++;
              }

              k = WorkingSet->sizes[3];
              rankR = WorkingSet->sizes[4];
              if ((WorkingSet->sizes[2] + k) + rankR > 0) {
                for (ix = 0; ix < k; ix++) {
                  abort();
                }

                for (ix = 0; ix < rankR; ix++) {
                  abort();
                }
              }

              if (smax <= 1.0E-6 * optimRelativeFactor) {
                MeritFunction->nlpDualFeasError = smax;
                MeritFunction->nlpComplError = 0.0;
                MeritFunction->firstOrderOpt = smax;
                smax = TrialState->lambdasqp;
                for (k = 0; k <= mLambda; k++) {
                  smax = TrialState->lambda;
                }

                TrialState->lambdasqp = smax;
                Flags->done = true;
                TrialState->sqpExitFlag = 1;
              } else {
                if (smax <= MeritFunction->nlpDualFeasError) {
                  MeritFunction->nlpDualFeasError = smax;
                  MeritFunction->nlpComplError = 0.0;
                  MeritFunction->firstOrderOpt = smax;
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
            if (TrialState->FunctionEvaluations >= 600) {
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
 * File trailer for test_exit.c
 *
 * [EOF]
 */
