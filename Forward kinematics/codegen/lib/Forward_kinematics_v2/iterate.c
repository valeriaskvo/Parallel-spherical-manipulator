/*
 * File: iterate.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "iterate.h"
#include "Forward_kinematics_v2.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xgemv.h"
#include "xnrm2.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Type Definitions */
#include <stdio.h>

/* Function Declarations */
static void iterativeDisplay(c_struct_T *memspace, const double solution_xstar[6],
  double solution_fstar, double solution_lambda, double solution_maxConstr, int
  solution_iterations, const double solution_searchDir[6], int workingset_nVar,
  int workingset_ldA, const double workingset_ATwset[6], double workingset_bwset,
  int workingset_nActiveConstr, boolean_T options_DisplayQP);

/* Function Definitions */

/*
 * Arguments    : c_struct_T *memspace
 *                const double solution_xstar[6]
 *                double solution_fstar
 *                double solution_lambda
 *                double solution_maxConstr
 *                int solution_iterations
 *                const double solution_searchDir[6]
 *                int workingset_nVar
 *                int workingset_ldA
 *                const double workingset_ATwset[6]
 *                double workingset_bwset
 *                int workingset_nActiveConstr
 *                boolean_T options_DisplayQP
 * Return Type  : void
 */
static void iterativeDisplay(c_struct_T *memspace, const double solution_xstar[6],
  double solution_fstar, double solution_lambda, double solution_maxConstr, int
  solution_iterations, const double solution_searchDir[6], int workingset_nVar,
  int workingset_ldA, const double workingset_ATwset[6], double workingset_bwset,
  int workingset_nActiveConstr, boolean_T options_DisplayQP)
{
  double errCompl;
  int k;
  int i;
  int iac;
  int ix;
  double c;
  int i1;
  int ia;
  if (options_DisplayQP) {
    errCompl = 0.0;
    if (workingset_nActiveConstr > 0) {
      for (k = 0; k < workingset_nActiveConstr; k++) {
        memspace->workspace_double[k] = workingset_bwset;
      }

      if (workingset_nVar != 0) {
        for (k = 0; k < workingset_nActiveConstr; k++) {
          memspace->workspace_double[k] = -memspace->workspace_double[k];
        }

        k = 0;
        i = workingset_ldA * (workingset_nActiveConstr - 1) + 1;
        for (iac = 1; workingset_ldA < 0 ? iac >= i : iac <= i; iac +=
             workingset_ldA) {
          ix = 0;
          c = 0.0;
          i1 = (iac + workingset_nVar) - 1;
          for (ia = iac; ia <= i1; ia++) {
            c += workingset_ATwset[ia - 1] * solution_xstar[ix];
            ix++;
          }

          memspace->workspace_double[k] += c;
          k++;
        }
      }

      for (k = 0; k < workingset_nActiveConstr; k++) {
        errCompl += fabs(memspace->workspace_double[0] * solution_lambda);
      }
    }

    printf("%5i  %14.6e        %10.3e      %10.3e         %10.3e\n",
           solution_iterations, solution_fstar, solution_maxConstr, b_xnrm2
           (workingset_nVar, solution_searchDir), errCompl);
    fflush(stdout);
  }
}

/*
 * Arguments    : const double H[25]
 *                const double f[6]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                g_struct_T *workingset
 *                i_struct_T *qrmanager
 *                k_struct_T *cholmanager
 *                j_struct_T *objective
 *                int options_MaxIterations
 *                double options_StepTolerance
 *                double options_ConstraintTolerance
 *                double options_ObjectiveLimit
 *                boolean_T options_DisplayQP
 * Return Type  : void
 */
void iterate(const double H[25], const double f[6], d_struct_T *solution,
             c_struct_T *memspace, g_struct_T *workingset, i_struct_T *qrmanager,
             k_struct_T *cholmanager, j_struct_T *objective, int
             options_MaxIterations, double options_StepTolerance, double
             options_ConstraintTolerance, double options_ObjectiveLimit,
             boolean_T options_DisplayQP)
{
  boolean_T subProblemChanged;
  boolean_T updateFval;
  int activeSetChangeID;
  int nVar;
  int mFixed;
  int mEq;
  int activeConstrIdx;
  int n;
  int totalUB;
  int exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ix;
  int nActiveConstr;
  double workspace[36];
  int ixlast;
  double alpha;
  double pk_corrected;
  boolean_T newBlocking;
  int activeConstrTYPE;
  double denomTol;
  boolean_T b_guard1 = false;
  double phaseOneCorrectionX;
  double phaseOneCorrectionP;
  double ratio;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  nVar = workingset->nVar;
  mFixed = workingset->nWConstr[0];
  mEq = workingset->nWConstr[1];
  activeConstrIdx = 0;
  computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_double, f,
    solution->xstar);
  solution->state = -5;
  solution->iterations = 0;
  n = workingset->mConstrMax;
  for (totalUB = 0; totalUB < n; totalUB++) {
    solution->lambda = 0.0;
  }

  if (options_DisplayQP) {
    printf(" Iter            Fval   First-Order Opt     Step Length    Complementarity \n");
    fflush(stdout);
  }

  do {
    exitg1 = 0;
    if (solution->state == -5) {
      iterativeDisplay(memspace, solution->xstar, solution->fstar,
                       solution->lambda, solution->maxConstr,
                       solution->iterations, solution->searchDir,
                       workingset->nVar, workingset->ldA, workingset->ATwset,
                       workingset->bwset, workingset->nActiveConstr,
                       options_DisplayQP);
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          squareQ_appendCol(qrmanager, workingset->ATwset, workingset->ldA *
                            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          deleteColMoveEnd(qrmanager, activeConstrIdx);
          break;

         default:
          factorQR(qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr);
          computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        compute_deltax(H, solution, memspace, qrmanager, cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else if (b_xnrm2(nVar, solution->searchDir) < options_StepTolerance) {
          guard2 = true;
        } else {
          updateFval = (objective->objtype == 5);
          totalUB = workingset->sizes[4];
          alpha = 1.0E+30;
          newBlocking = false;
          activeConstrTYPE = 0;
          activeConstrIdx = 0;
          denomTol = 2.2204460492503131E-13 * b_xnrm2(workingset->nVar,
            solution->searchDir);
          if (workingset->nWConstr[3] < workingset->sizes[3]) {
            ixlast = workingset->nVar - 1;
            phaseOneCorrectionX = (double)updateFval * solution->xstar[ixlast];
            phaseOneCorrectionP = (double)updateFval * solution->
              searchDir[ixlast];
            ix = workingset->sizes[3];
            for (n = 0; n <= ix - 2; n++) {
              pk_corrected = -solution->searchDir[workingset->indexLB[n] - 1] -
                phaseOneCorrectionP;
              if ((pk_corrected > denomTol) && (!workingset->isActiveConstr)) {
                ratio = (-solution->xstar[workingset->indexLB[n] - 1] -
                         workingset->lb[workingset->indexLB[n] - 1]) -
                  phaseOneCorrectionX;
                pk_corrected = fmin(fabs(ratio), options_ConstraintTolerance -
                                    ratio) / pk_corrected;
                if (pk_corrected < alpha) {
                  alpha = pk_corrected;
                  activeConstrTYPE = 4;
                  activeConstrIdx = n + 1;
                  newBlocking = true;
                }
              }
            }

            ix = workingset->indexLB[workingset->sizes[3] - 1] - 1;
            if ((-solution->searchDir[ix] > denomTol) &&
                (!workingset->isActiveConstr)) {
              ratio = -solution->xstar[ix] - workingset->lb[ix];
              pk_corrected = fmin(fabs(ratio), options_ConstraintTolerance -
                                  ratio) / -solution->searchDir[ix];
              if (pk_corrected < alpha) {
                alpha = pk_corrected;
                activeConstrTYPE = 4;
                activeConstrIdx = workingset->sizes[3];
                newBlocking = true;
              }
            }
          }

          if (workingset->nWConstr[4] < workingset->sizes[4]) {
            ixlast = workingset->nVar - 1;
            phaseOneCorrectionX = (double)updateFval * solution->xstar[ixlast];
            phaseOneCorrectionP = (double)updateFval * solution->
              searchDir[ixlast];
            for (n = 0; n < totalUB; n++) {
              pk_corrected = solution->searchDir[workingset->indexUB[n] - 1] -
                phaseOneCorrectionP;
              if ((pk_corrected > denomTol) && (!workingset->isActiveConstr)) {
                ratio = (solution->xstar[workingset->indexUB[n] - 1] -
                         workingset->ub[workingset->indexUB[n] - 1]) -
                  phaseOneCorrectionX;
                pk_corrected = fmin(fabs(ratio), options_ConstraintTolerance -
                                    ratio) / pk_corrected;
                if (pk_corrected < alpha) {
                  alpha = pk_corrected;
                  activeConstrTYPE = 5;
                  activeConstrIdx = n + 1;
                  newBlocking = true;
                }
              }
            }
          }

          if (!updateFval) {
            if (newBlocking && (alpha > 1.0)) {
              newBlocking = false;
            }

            alpha = fmin(alpha, 1.0);
          }

          if (newBlocking) {
            switch (activeConstrTYPE) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr = true;
              workingset->nActiveConstr++;
              workingset->Wid = 3;
              workingset->Wlocalidx = activeConstrIdx;
              abort();
              break;

             case 4:
              addBoundToActiveSetMatrix_(workingset, 4, activeConstrIdx);
              break;

             default:
              addBoundToActiveSetMatrix_(workingset, 5, activeConstrIdx);
              break;
            }

            activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (b_xnrm2(objective->nvar, solution->searchDir) > 100.0 *
                  (double)objective->nvar * 1.4901161193847656E-8) {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if ((nVar >= 1) && (!(alpha == 0.0))) {
            ixlast = nVar - 1;
            for (totalUB = 0; totalUB <= ixlast; totalUB++) {
              solution->xstar[totalUB] += alpha * solution->searchDir[totalUB];
            }
          }

          computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
          guard1 = true;
        }
      } else {
        if (0 <= nVar - 1) {
          memset(&solution->searchDir[0], 0, nVar * sizeof(double));
        }

        guard2 = true;
      }

      if (guard2) {
        for (ix = 0; ix < 36; ix++) {
          workspace[ix] = memspace->workspace_double[ix];
        }

        nActiveConstr = qrmanager->ncols;
        if (qrmanager->ncols > 0) {
          pk_corrected = 100.0 * (double)qrmanager->mrows *
            2.2204460492503131E-16;
          if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
            updateFval = true;
          } else {
            updateFval = false;
          }

          if (updateFval) {
            n = qrmanager->ncols;
            b_guard1 = false;
            if (qrmanager->mrows < qrmanager->ncols) {
              while ((n > qrmanager->mrows) && (fabs(qrmanager->QR
                       [(qrmanager->mrows + 6 * (n - 1)) - 1]) >= pk_corrected))
              {
                n--;
              }

              updateFval = (n == qrmanager->mrows);
              if (updateFval) {
                b_guard1 = true;
              }
            } else {
              b_guard1 = true;
            }

            if (b_guard1) {
              while ((n >= 1) && (fabs(qrmanager->QR[(n + 6 * (n - 1)) - 1]) >=
                                  pk_corrected)) {
                n--;
              }

              updateFval = (n == 0);
            }
          }

          if (!updateFval) {
            solution->state = -7;
          } else {
            n = qrmanager->ncols;
            xgemv(qrmanager->mrows, qrmanager->ncols, qrmanager->Q,
                  qrmanager->ldq, objective->grad, workspace);
            if (qrmanager->ncols != 0) {
              for (ixlast = n; ixlast >= 1; ixlast--) {
                totalUB = (ixlast + (ixlast - 1) * qrmanager->ldq) - 1;
                workspace[ixlast - 1] /= qrmanager->QR[totalUB];
                for (activeConstrTYPE = 0; activeConstrTYPE <= ixlast - 2;
                     activeConstrTYPE++) {
                  ix = (ixlast - activeConstrTYPE) - 2;
                  workspace[ix] -= workspace[ixlast - 1] * qrmanager->QR
                    [(totalUB - activeConstrTYPE) - 1];
                }
              }
            }

            for (n = 0; n < nActiveConstr; n++) {
              solution->lambda = -workspace[0];
            }
          }
        }

        memcpy(&memspace->workspace_double[0], &workspace[0], 36U * sizeof
               (double));
        if (solution->state != -7) {
          pk_corrected = 0.0;
          ixlast = 0;
          ix = (mFixed + mEq) + 1;
          totalUB = workingset->nActiveConstr;
          for (n = ix; n <= totalUB; n++) {
            if (solution->lambda < pk_corrected) {
              pk_corrected = solution->lambda;
              ixlast = 1;
            }
          }

          if (ixlast == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            activeConstrIdx = 1;
            subProblemChanged = true;
            removeConstr(workingset);
            solution->lambda = 0.0;
          }
        }

        updateFval = false;
        guard1 = true;
      }

      if (guard1) {
        solution->iterations++;
        ixlast = objective->nvar - 1;
        if (solution->iterations > options_MaxIterations) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = b_maxConstraintViolation(workingset,
            solution->xstar, 1);
          if (solution->maxConstr > options_ConstraintTolerance) {
            if (0 <= ixlast) {
              memcpy(&solution->searchDir[0], &solution->xstar[0], (ixlast + 1) *
                     sizeof(double));
            }

            newBlocking = feasibleX0ForWorkingSet(memspace->workspace_double,
              solution->searchDir, workingset, qrmanager);
            if (!newBlocking) {
              solution->state = -2;
            }

            activeSetChangeID = 0;
            pk_corrected = b_maxConstraintViolation(workingset,
              solution->searchDir, 1);
            if (pk_corrected < solution->maxConstr) {
              if (0 <= ixlast) {
                memcpy(&solution->xstar[0], &solution->searchDir[0], (ixlast + 1)
                       * sizeof(double));
              }

              solution->maxConstr = pk_corrected;
            }
          }
        }

        if ((options_ObjectiveLimit > rtMinusInf) && updateFval) {
          solution->fstar = computeFval_ReuseHx(objective,
            memspace->workspace_double, f, solution->xstar);
          if (solution->fstar <= options_ObjectiveLimit) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(objective,
          memspace->workspace_double, f, solution->xstar);
      }

      iterativeDisplay(memspace, solution->xstar, solution->fstar,
                       solution->lambda, solution->maxConstr,
                       solution->iterations, solution->searchDir,
                       workingset->nVar, workingset->ldA, workingset->ATwset,
                       workingset->bwset, workingset->nActiveConstr,
                       options_DisplayQP);
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/*
 * File trailer for iterate.c
 *
 * [EOF]
 */
