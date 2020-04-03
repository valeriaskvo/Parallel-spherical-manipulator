/*
 * File: iterate.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "iterate.h"
#include "Forward_kinematics_v1.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "xrotg.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void c_local_checkStoppingAndUpdateF(int *activeSetChangeID, const double
  f[7], d_struct_T *solution, c_struct_T *memspace, const j_struct_T *objective,
  const f_struct_T *workingset, i_struct_T *qrmanager, int options_MaxIterations,
  double options_ObjectiveLimit, boolean_T updateFval);

/* Function Definitions */

/*
 * Arguments    : int *activeSetChangeID
 *                const double f[7]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                const j_struct_T *objective
 *                const f_struct_T *workingset
 *                i_struct_T *qrmanager
 *                int options_MaxIterations
 *                double options_ObjectiveLimit
 *                boolean_T updateFval
 * Return Type  : void
 */
static void c_local_checkStoppingAndUpdateF(int *activeSetChangeID, const double
  f[7], d_struct_T *solution, c_struct_T *memspace, const j_struct_T *objective,
  const f_struct_T *workingset, i_struct_T *qrmanager, int options_MaxIterations,
  double options_ObjectiveLimit, boolean_T updateFval)
{
  int nVar;
  boolean_T nonDegenerateWset;
  double constrViolation_new;
  solution->iterations++;
  nVar = objective->nvar - 1;
  if (solution->iterations > options_MaxIterations) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    solution->maxConstr = b_maxConstraintViolation(workingset, solution->xstar);
    if (solution->maxConstr > 1.0E-6) {
      if (0 <= nVar) {
        memcpy(&solution->searchDir[0], &solution->xstar[0], (nVar + 1) * sizeof
               (double));
      }

      nonDegenerateWset = feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->searchDir, workingset, qrmanager);
      if (!nonDegenerateWset) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      constrViolation_new = b_maxConstraintViolation(workingset,
        solution->searchDir);
      if (constrViolation_new < solution->maxConstr) {
        if (0 <= nVar) {
          memcpy(&solution->xstar[0], &solution->searchDir[0], (nVar + 1) *
                 sizeof(double));
        }

        solution->maxConstr = constrViolation_new;
      }
    }
  }

  if (updateFval) {
    solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_double,
      f, solution->xstar);
    if (solution->fstar <= options_ObjectiveLimit) {
      solution->state = 2;
    }
  }
}

/*
 * Arguments    : const double H[36]
 *                const double f[7]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                f_struct_T *workingset
 *                i_struct_T *qrmanager
 *                k_struct_T *cholmanager
 *                j_struct_T *objective
 *                int options_MaxIterations
 *                double options_StepTolerance
 *                double options_ObjectiveLimit
 * Return Type  : void
 */
void iterate(const double H[36], const double f[7], d_struct_T *solution,
             c_struct_T *memspace, f_struct_T *workingset, i_struct_T *qrmanager,
             k_struct_T *cholmanager, j_struct_T *objective, int
             options_MaxIterations, double options_StepTolerance, double
             options_ObjectiveLimit)
{
  boolean_T subProblemChanged;
  boolean_T updateFval;
  int activeSetChangeID;
  int nVar;
  int mFixed;
  int mEq;
  int activeConstrIdx;
  int n;
  int jjA;
  int exitg1;
  boolean_T guard1 = false;
  int iyend;
  int i;
  int nActiveConstr;
  double x[49];
  int iy;
  double s;
  double temp;
  boolean_T newBlocking;
  int ia;
  int ix;
  double denomTol;
  boolean_T b_guard1 = false;
  double phaseOneCorrectionX;
  double c;
  double phaseOneCorrectionP;
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
  for (jjA = 0; jjA < n; jjA++) {
    solution->lambda = 0.0;
  }

  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          n = workingset->ldA * (workingset->nActiveConstr - 1);
          iyend = qrmanager->mrows;
          jjA = qrmanager->ncols + 1;
          if (iyend < jjA) {
            jjA = iyend;
          }

          qrmanager->minRowCol = jjA;
          iy = 7 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            iyend = iy + qrmanager->mrows;
            if (iy + 1 <= iyend) {
              memset(&qrmanager->QR[iy], 0, (iyend - iy) * sizeof(double));
            }

            i = 7 * (qrmanager->mrows - 1) + 1;
            for (iyend = 1; iyend <= i; iyend += 7) {
              ix = n;
              c = 0.0;
              nActiveConstr = (iyend + qrmanager->mrows) - 1;
              for (ia = iyend; ia <= nActiveConstr; ia++) {
                c += qrmanager->Q[ia - 1] * workingset->ATwset[ix];
                ix++;
              }

              qrmanager->QR[iy] += c;
              iy++;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          for (ix = qrmanager->mrows - 1; ix + 1 > qrmanager->ncols; ix--) {
            temp = qrmanager->QR[ix + 7 * (qrmanager->ncols - 1)];
            xrotg(&qrmanager->QR[(ix + 7 * (qrmanager->ncols - 1)) - 1], &temp,
                  &c, &s);
            qrmanager->QR[ix + 7 * (qrmanager->ncols - 1)] = temp;
            iyend = 7 * (ix - 1);
            n = qrmanager->mrows;
            for (i = 0; i < 49; i++) {
              x[i] = qrmanager->Q[i];
            }

            if (qrmanager->mrows >= 1) {
              iy = iyend + 7;
              for (jjA = 0; jjA < n; jjA++) {
                temp = c * x[iyend] + s * x[iy];
                x[iy] = c * x[iy] - s * x[iyend];
                x[iyend] = temp;
                iy++;
                iyend++;
              }
            }

            memcpy(&qrmanager->Q[0], &x[0], 49U * sizeof(double));
          }
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
          guard1 = true;
        } else {
          updateFval = (objective->objtype == 5);
          iyend = workingset->sizes[4];
          s = 1.0E+30;
          newBlocking = false;
          ia = 0;
          activeConstrIdx = 0;
          denomTol = 2.2204460492503131E-13 * b_xnrm2(workingset->nVar,
            solution->searchDir);
          if (workingset->nWConstr[3] < workingset->sizes[3]) {
            jjA = workingset->nVar - 1;
            phaseOneCorrectionX = (double)updateFval * solution->xstar[jjA];
            phaseOneCorrectionP = (double)updateFval * solution->searchDir[jjA];
            i = workingset->sizes[3];
            for (ix = 0; ix <= i - 2; ix++) {
              temp = -solution->searchDir[workingset->indexLB[ix] - 1] -
                phaseOneCorrectionP;
              if ((temp > denomTol) && (!workingset->isActiveConstr)) {
                c = (-solution->xstar[workingset->indexLB[ix] - 1] -
                     workingset->lb[workingset->indexLB[ix] - 1]) -
                  phaseOneCorrectionX;
                temp = fmin(fabs(c), 1.0E-6 - c) / temp;
                if (temp < s) {
                  s = temp;
                  ia = 4;
                  activeConstrIdx = ix + 1;
                  newBlocking = true;
                }
              }
            }

            i = workingset->indexLB[workingset->sizes[3] - 1] - 1;
            if ((-solution->searchDir[i] > denomTol) &&
                (!workingset->isActiveConstr)) {
              c = -solution->xstar[i] - workingset->lb[i];
              temp = fmin(fabs(c), 1.0E-6 - c) / -solution->searchDir[i];
              if (temp < s) {
                s = temp;
                ia = 4;
                activeConstrIdx = workingset->sizes[3];
                newBlocking = true;
              }
            }
          }

          if (workingset->nWConstr[4] < workingset->sizes[4]) {
            jjA = workingset->nVar - 1;
            phaseOneCorrectionX = (double)updateFval * solution->xstar[jjA];
            phaseOneCorrectionP = (double)updateFval * solution->searchDir[jjA];
            for (ix = 0; ix < iyend; ix++) {
              temp = solution->searchDir[workingset->indexUB[ix] - 1] -
                phaseOneCorrectionP;
              if ((temp > denomTol) && (!workingset->isActiveConstr)) {
                c = (solution->xstar[workingset->indexUB[ix] - 1] -
                     workingset->ub[workingset->indexUB[ix] - 1]) -
                  phaseOneCorrectionX;
                temp = fmin(fabs(c), 1.0E-6 - c) / temp;
                if (temp < s) {
                  s = temp;
                  ia = 5;
                  activeConstrIdx = ix + 1;
                  newBlocking = true;
                }
              }
            }
          }

          if (!updateFval) {
            if (newBlocking && (s > 1.0)) {
              newBlocking = false;
            }

            s = fmin(s, 1.0);
          }

          if (newBlocking) {
            switch (ia) {
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

          if ((nVar >= 1) && (!(s == 0.0))) {
            iyend = nVar - 1;
            for (jjA = 0; jjA <= iyend; jjA++) {
              solution->xstar[jjA] += s * solution->searchDir[jjA];
            }
          }

          computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
          c_local_checkStoppingAndUpdateF(&activeSetChangeID, f, solution,
            memspace, objective, workingset, qrmanager, options_MaxIterations,
            options_ObjectiveLimit, updateFval);
        }
      } else {
        if (0 <= nVar - 1) {
          memset(&solution->searchDir[0], 0, nVar * sizeof(double));
        }

        guard1 = true;
      }

      if (guard1) {
        for (i = 0; i < 49; i++) {
          x[i] = memspace->workspace_double[i];
        }

        nActiveConstr = qrmanager->ncols;
        if (qrmanager->ncols > 0) {
          temp = 100.0 * (double)qrmanager->mrows * 2.2204460492503131E-16;
          if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
            updateFval = true;
          } else {
            updateFval = false;
          }

          if (updateFval) {
            ix = qrmanager->ncols;
            b_guard1 = false;
            if (qrmanager->mrows < qrmanager->ncols) {
              while ((ix > qrmanager->mrows) && (fabs(qrmanager->QR
                       [(qrmanager->mrows + 7 * (ix - 1)) - 1]) >= temp)) {
                ix--;
              }

              updateFval = (ix == qrmanager->mrows);
              if (updateFval) {
                b_guard1 = true;
              }
            } else {
              b_guard1 = true;
            }

            if (b_guard1) {
              while ((ix >= 1) && (fabs(qrmanager->QR[(ix + 7 * (ix - 1)) - 1]) >=
                                   temp)) {
                ix--;
              }

              updateFval = (ix == 0);
            }
          }

          if (!updateFval) {
            solution->state = -7;
          } else {
            n = qrmanager->ncols;
            xgemv(qrmanager->mrows, qrmanager->ncols, qrmanager->Q,
                  objective->grad, x);
            if (qrmanager->ncols != 0) {
              for (iyend = n; iyend >= 1; iyend--) {
                jjA = (iyend + (iyend - 1) * 7) - 1;
                x[iyend - 1] /= qrmanager->QR[jjA];
                for (ia = 0; ia <= iyend - 2; ia++) {
                  ix = (iyend - ia) - 2;
                  x[ix] -= x[iyend - 1] * qrmanager->QR[(jjA - ia) - 1];
                }
              }
            }

            for (ix = 0; ix < nActiveConstr; ix++) {
              solution->lambda = -x[0];
            }
          }
        }

        memcpy(&memspace->workspace_double[0], &x[0], 49U * sizeof(double));
        if (solution->state != -7) {
          temp = 0.0;
          jjA = 0;
          i = (mFixed + mEq) + 1;
          nActiveConstr = workingset->nActiveConstr;
          for (ix = i; ix <= nActiveConstr; ix++) {
            if (solution->lambda < temp) {
              temp = solution->lambda;
              jjA = 1;
            }
          }

          if (jjA == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            activeConstrIdx = 1;
            subProblemChanged = true;
            workingset->isActiveConstr = false;
            workingset->nActiveConstr--;
            i = workingset->Wid - 1;
            workingset->nWConstr[i]--;
            solution->lambda = 0.0;
          }
        }

        updateFval = false;
        c_local_checkStoppingAndUpdateF(&activeSetChangeID, f, solution,
          memspace, objective, workingset, qrmanager, options_MaxIterations,
          options_ObjectiveLimit, updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(objective,
          memspace->workspace_double, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/*
 * File trailer for iterate.c
 *
 * [EOF]
 */
