/*
 * File: phaseone.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "phaseone.h"
#include "Forward_kinematics_v1.h"
#include "computeFval.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"

/* Function Definitions */

/*
 * Arguments    : const double H[36]
 *                const double f[7]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                f_struct_T *workingset
 *                i_struct_T *qrmanager
 *                k_struct_T *cholmanager
 *                j_struct_T *objective
 *                b_struct_T *options
 * Return Type  : void
 */
void phaseone(const double H[36], const double f[7], d_struct_T *solution,
              c_struct_T *memspace, f_struct_T *workingset, i_struct_T
              *qrmanager, k_struct_T *cholmanager, j_struct_T *objective,
              b_struct_T *options)
{
  int PROBTYPE_ORIG;
  f_struct_T b_workingset;
  int PHASEONE;
  int idxStartIneq;
  int idxEndIneq;
  int idx_global;
  boolean_T exitg1;
  PROBTYPE_ORIG = workingset->probType;
  b_workingset = *workingset;
  solution->maxConstr = b_maxConstraintViolation(&b_workingset, solution->xstar);
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
  options->ObjectiveLimit = 1.0E-6;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->iterations = 0;
  solution->fstar = computeFval(objective, memspace->workspace_double, H, f,
    solution->xstar);
  solution->state = 5;
  iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
          objective, options->MaxIterations, options->StepTolerance,
          options->ObjectiveLimit);
  if (workingset->isActiveConstr) {
    PHASEONE = (workingset->sizes[0] + workingset->sizes[1]) + 1;
    exitg1 = false;
    while ((!exitg1) && (PHASEONE <= workingset->nActiveConstr)) {
      if ((workingset->Wid == 4) && (workingset->Wlocalidx == workingset->sizes
           [3])) {
        workingset->isActiveConstr = false;
        workingset->nActiveConstr--;
        PHASEONE = workingset->Wid - 1;
        workingset->nWConstr[PHASEONE]--;
        exitg1 = true;
      } else {
        PHASEONE = 2;
      }
    }
  }

  PHASEONE = workingset->nActiveConstr;
  idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
  while ((PHASEONE > idxStartIneq) && (PHASEONE > b_workingset.nVar)) {
    workingset->isActiveConstr = false;
    workingset->nActiveConstr--;
    PHASEONE = workingset->Wid - 1;
    workingset->nWConstr[PHASEONE]--;
    PHASEONE = 0;
  }

  solution->maxConstr = solution->xstar[b_workingset.nVar];
  setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-6;
}

/*
 * File trailer for phaseone.c
 *
 * [EOF]
 */
