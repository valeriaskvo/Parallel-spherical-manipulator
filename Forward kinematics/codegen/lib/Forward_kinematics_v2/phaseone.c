/*
 * File: phaseone.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "phaseone.h"
#include "Forward_kinematics_v2.h"
#include "computeFval.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"

/* Function Definitions */

/*
 * Arguments    : const double H[25]
 *                const double f[6]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                g_struct_T *workingset
 *                i_struct_T *qrmanager
 *                k_struct_T *cholmanager
 *                j_struct_T *objective
 *                b_struct_T *options
 * Return Type  : void
 */
void phaseone(const double H[25], const double f[6], d_struct_T *solution,
              c_struct_T *memspace, g_struct_T *workingset, i_struct_T
              *qrmanager, k_struct_T *cholmanager, j_struct_T *objective,
              b_struct_T *options)
{
  int PROBTYPE_ORIG;
  g_struct_T b_workingset;
  int PHASEONE;
  int idxStartIneq;
  int idxEndIneq;
  int idx_global;
  double oldObjLim;
  double oldTolX;
  boolean_T exitg1;
  PROBTYPE_ORIG = workingset->probType;
  b_workingset = *workingset;
  solution->maxConstr = b_maxConstraintViolation(&b_workingset, solution->xstar,
    1);
  solution->xstar[b_workingset.nVar] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    PHASEONE = 1;
  } else {
    PHASEONE = 4;
  }

  *workingset = b_workingset;
  idxStartIneq = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
  idxEndIneq = workingset->nActiveConstr;
  for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
    workingset->isActiveConstr = false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  setProblemType(workingset, PHASEONE);
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = b_workingset.nVar + 1;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  oldObjLim = options->ObjectiveLimit;
  oldTolX = options->StepTolerance;
  options->ObjectiveLimit = options->ConstraintTolerance;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->iterations = 0;
  solution->fstar = computeFval(objective, memspace->workspace_double, H, f,
    solution->xstar);
  solution->state = 5;
  iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
          objective, options->MaxIterations, options->StepTolerance,
          options->ConstraintTolerance, options->ObjectiveLimit,
          options->DisplayQP);
  if (workingset->isActiveConstr) {
    PHASEONE = (workingset->sizes[0] + workingset->sizes[1]) + 1;
    exitg1 = false;
    while ((!exitg1) && (PHASEONE <= workingset->nActiveConstr)) {
      if ((workingset->Wid == 4) && (workingset->Wlocalidx == workingset->sizes
           [3])) {
        removeConstr(workingset);
        exitg1 = true;
      } else {
        PHASEONE = 2;
      }
    }
  }

  PHASEONE = workingset->nActiveConstr;
  idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
  while ((PHASEONE > idxStartIneq) && (PHASEONE > b_workingset.nVar)) {
    removeConstr(workingset);
    PHASEONE--;
  }

  solution->maxConstr = solution->xstar[b_workingset.nVar];
  setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = oldObjLim;
  options->StepTolerance = oldTolX;
}

/*
 * File trailer for phaseone.c
 *
 * [EOF]
 */
