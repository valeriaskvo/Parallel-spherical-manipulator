/*
 * File: compute_deltax.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "compute_deltax.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "xpotrf.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double H[25]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                const i_struct_T *qrmanager
 *                k_struct_T *cholmanager
 *                const j_struct_T *objective
 * Return Type  : void
 */
void compute_deltax(const double H[25], d_struct_T *solution, c_struct_T
                    *memspace, const i_struct_T *qrmanager, k_struct_T
                    *cholmanager, const j_struct_T *objective)
{
  int nVar_tmp_tmp;
  int mNull_tmp;
  int mNull;
  int idx;
  int nullStartIdx_tmp;
  int nVars;
  int idx_col;
  int iac;
  int i;
  int idx_row;
  int ix;
  double c;
  double rhs[36];
  nVar_tmp_tmp = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  mNull = mNull_tmp - 1;
  if (mNull + 1 <= 0) {
    if (0 <= nVar_tmp_tmp) {
      memset(&solution->searchDir[0], 0, (nVar_tmp_tmp + 1) * sizeof(double));
    }
  } else {
    for (idx = 0; idx <= nVar_tmp_tmp; idx++) {
      solution->searchDir[idx] = -objective->grad[idx];
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        cholmanager->ndims = qrmanager->mrows;
        for (idx = 0; idx <= nVar_tmp_tmp; idx++) {
          mNull_tmp = qrmanager->mrows * idx;
          idx_col = cholmanager->ldu * idx;
          for (iac = 0; iac <= nVar_tmp_tmp; iac++) {
            idx_row = iac + 1;
            cholmanager->UU[(idx_col + idx_row) - 1] = H[(mNull_tmp + idx_row) -
              1];
          }
        }

        cholmanager->info = xpotrf(qrmanager->mrows, cholmanager->UU,
          cholmanager->ldu);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          solve(cholmanager, solution->searchDir);
        }
        break;

       case 4:
        nVars = objective->nvar - 1;
        cholmanager->ndims = objective->nvar;
        for (idx = 0; idx <= nVars; idx++) {
          mNull_tmp = objective->nvar * idx;
          idx_col = cholmanager->ldu * idx;
          for (iac = 0; iac <= nVars; iac++) {
            idx_row = iac + 1;
            cholmanager->UU[(idx_col + idx_row) - 1] = H[(mNull_tmp + idx_row) -
              1];
          }
        }

        cholmanager->info = xpotrf(objective->nvar, cholmanager->UU,
          cholmanager->ldu);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          solve(cholmanager, solution->searchDir);
          c = 1.0 / objective->beta;
          mNull_tmp = objective->nvar + 1;
          i = qrmanager->mrows;
          for (iac = mNull_tmp; iac <= i; iac++) {
            solution->searchDir[iac - 1] *= c;
          }
        }
        break;
      }
    } else {
      nullStartIdx_tmp = qrmanager->ldq * qrmanager->ncols + 1;
      switch (objective->objtype) {
       case 5:
        for (idx = 0; idx <= mNull; idx++) {
          memspace->workspace_double[idx] = -qrmanager->Q[nVar_tmp_tmp + 6 *
            (qrmanager->ncols + idx)];
        }

        idx_col = qrmanager->ldq;
        if (qrmanager->mrows != 0) {
          if (0 <= nVar_tmp_tmp) {
            memset(&solution->searchDir[0], 0, (nVar_tmp_tmp + 1) * sizeof
                   (double));
          }

          ix = 0;
          i = nullStartIdx_tmp + qrmanager->ldq * mNull;
          for (iac = nullStartIdx_tmp; idx_col < 0 ? iac >= i : iac <= i; iac +=
               idx_col) {
            idx_row = 0;
            mNull_tmp = iac + nVar_tmp_tmp;
            for (idx = iac; idx <= mNull_tmp; idx++) {
              solution->searchDir[idx_row] += qrmanager->Q[idx - 1] *
                memspace->workspace_double[ix];
              idx_row++;
            }

            ix++;
          }
        }
        break;

       default:
        switch (objective->objtype) {
         case 3:
          xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp, qrmanager->ldq,
                memspace->workspace_double);
          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, qrmanager->ldq, memspace->workspace_double,
                  cholmanager->UU, cholmanager->ldu);
          break;

         default:
          nVars = qrmanager->mrows;
          xgemm(objective->nvar, mNull_tmp, objective->nvar, H, objective->nvar,
                qrmanager->Q, nullStartIdx_tmp, qrmanager->ldq,
                memspace->workspace_double);
          for (idx_col = 0; idx_col < mNull_tmp; idx_col++) {
            i = objective->nvar + 1;
            for (idx_row = i; idx_row <= nVars; idx_row++) {
              memspace->workspace_double[(idx_row + 6 * idx_col) - 1] =
                objective->beta * qrmanager->Q[(idx_row + 6 * (idx_col +
                qrmanager->ncols)) - 1];
            }
          }

          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, qrmanager->ldq, memspace->workspace_double,
                  cholmanager->UU, cholmanager->ldu);
          break;
        }

        cholmanager->ndims = mNull + 1;
        cholmanager->info = xpotrf(mNull + 1, cholmanager->UU, cholmanager->ldu);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          idx_col = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            if (0 <= mNull) {
              memset(&memspace->workspace_double[0], 0, (mNull + 1) * sizeof
                     (double));
            }

            idx_row = 0;
            i = nullStartIdx_tmp + qrmanager->ldq * mNull;
            for (iac = nullStartIdx_tmp; idx_col < 0 ? iac >= i : iac <= i; iac +=
                 idx_col) {
              ix = 0;
              c = 0.0;
              mNull_tmp = iac + nVar_tmp_tmp;
              for (idx = iac; idx <= mNull_tmp; idx++) {
                c += qrmanager->Q[idx - 1] * objective->grad[ix];
                ix++;
              }

              memspace->workspace_double[idx_row] += -c;
              idx_row++;
            }
          }

          for (i = 0; i < 36; i++) {
            rhs[i] = memspace->workspace_double[i];
          }

          for (idx_col = 0; idx_col <= mNull; idx_col++) {
            nVars = idx_col * cholmanager->ldu;
            c = rhs[idx_col];
            for (idx_row = 0; idx_row < idx_col; idx_row++) {
              c -= cholmanager->UU[nVars + idx_row] * rhs[idx_row];
            }

            rhs[idx_col] = c / cholmanager->UU[nVars + idx_col];
          }

          memcpy(&memspace->workspace_double[0], &rhs[0], 36U * sizeof(double));
          for (idx_col = mNull + 1; idx_col >= 1; idx_col--) {
            nVars = (idx_col + (idx_col - 1) * cholmanager->ldu) - 1;
            memspace->workspace_double[idx_col - 1] /= cholmanager->UU[nVars];
            for (idx_row = 0; idx_row <= idx_col - 2; idx_row++) {
              ix = (idx_col - idx_row) - 2;
              memspace->workspace_double[ix] -= memspace->
                workspace_double[idx_col - 1] * cholmanager->UU[(nVars - idx_row)
                - 1];
            }
          }

          nVars = qrmanager->mrows - 1;
          idx_col = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            if (0 <= nVars) {
              memset(&solution->searchDir[0], 0, (nVars + 1) * sizeof(double));
            }

            ix = 0;
            i = nullStartIdx_tmp + qrmanager->ldq * mNull;
            for (iac = nullStartIdx_tmp; idx_col < 0 ? iac >= i : iac <= i; iac +=
                 idx_col) {
              idx_row = 0;
              mNull_tmp = iac + nVars;
              for (idx = iac; idx <= mNull_tmp; idx++) {
                solution->searchDir[idx_row] += qrmanager->Q[idx - 1] *
                  memspace->workspace_double[ix];
                idx_row++;
              }

              ix++;
            }
          }
        }
        break;
      }
    }
  }
}

/*
 * File trailer for compute_deltax.c
 *
 * [EOF]
 */
