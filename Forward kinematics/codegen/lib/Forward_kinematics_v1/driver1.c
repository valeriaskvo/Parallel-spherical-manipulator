/*
 * File: driver1.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "driver1.h"
#include "Forward_kinematics_v1.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include <string.h>

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
 *                b_struct_T options
 * Return Type  : void
 */
void b_driver(const double H[36], const double f[7], d_struct_T *solution,
              c_struct_T *memspace, f_struct_T *workingset, i_struct_T
              *qrmanager, k_struct_T *cholmanager, j_struct_T *objective,
              b_struct_T options)
{
  int nVar;
  double maxConstr;
  int i;
  d_struct_T b_solution;
  double maxConstr_new;
  nVar = workingset->nVar - 1;
  PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  if (solution->state >= 0) {
    maxConstr = b_maxConstraintViolation(workingset, solution->xstar);
    if (maxConstr > 1.0E-6) {
      phaseone(H, f, solution, memspace, workingset, qrmanager, cholmanager,
               objective, &options);
      maxConstr = b_maxConstraintViolation(workingset, solution->xstar);
      if (maxConstr > 1.0E-6) {
        nVar = workingset->mConstrMax;
        for (i = 0; i < nVar; i++) {
          solution->lambda = 0.0;
        }

        solution->fstar = computeFval(objective, memspace->workspace_double, H,
          f, solution->xstar);
        solution->state = -2;
      } else {
        if (maxConstr > 0.0) {
          if (0 <= nVar) {
            memcpy(&solution->searchDir[0], &solution->xstar[0], (nVar + 1) *
                   sizeof(double));
          }

          b_solution = *solution;
          PresolveWorkingSet(&b_solution, memspace, workingset, qrmanager);
          *solution = b_solution;
          maxConstr_new = b_maxConstraintViolation(workingset, b_solution.xstar);
          if (maxConstr_new >= maxConstr) {
            for (i = 0; i < 7; i++) {
              solution->xstar[i] = b_solution.xstar[i];
            }

            if (0 <= nVar) {
              memcpy(&solution->xstar[0], &b_solution.searchDir[0], (nVar + 1) *
                     sizeof(double));
            }
          }
        }

        iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                objective, options.MaxIterations, options.StepTolerance,
                options.ObjectiveLimit);
      }
    } else {
      iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options.MaxIterations, options.StepTolerance,
              options.ObjectiveLimit);
    }
  }
}

/*
 * File trailer for driver1.c
 *
 * [EOF]
 */
