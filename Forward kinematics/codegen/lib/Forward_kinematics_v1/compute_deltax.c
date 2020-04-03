/*
 * File: compute_deltax.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "compute_deltax.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "xpotrf.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double H[36]
 *                d_struct_T *solution
 *                c_struct_T *memspace
 *                const i_struct_T *qrmanager
 *                k_struct_T *cholmanager
 *                const j_struct_T *objective
 * Return Type  : void
 */
void compute_deltax(const double H[36], d_struct_T *solution, c_struct_T
                    *memspace, const i_struct_T *qrmanager, k_struct_T
                    *cholmanager, const j_struct_T *objective)
{
  int nVar_tmp_tmp;
  int mNull_tmp;
  int mNull;
  int ix;
  int nullStartIdx_tmp;
  int nVars;
  int idx_col;
  int k;
  int i;
  int idx_row;
  double c;
  double rhs[49];
  nVar_tmp_tmp = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  mNull = mNull_tmp - 1;
  if (mNull + 1 <= 0) {
    if (0 <= nVar_tmp_tmp) {
      memset(&solution->searchDir[0], 0, (nVar_tmp_tmp + 1) * sizeof(double));
    }
  } else {
    for (ix = 0; ix <= nVar_tmp_tmp; ix++) {
      solution->searchDir[ix] = -objective->grad[ix];
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        cholmanager->ndims = qrmanager->mrows;
        for (ix = 0; ix <= nVar_tmp_tmp; ix++) {
          mNull_tmp = qrmanager->mrows * ix;
          idx_col = 7 * ix;
          for (k = 0; k <= nVar_tmp_tmp; k++) {
            idx_row = k + 1;
            cholmanager->UU[(idx_col + idx_row) - 1] = H[(mNull_tmp + idx_row) -
              1];
          }
        }

        cholmanager->info = xpotrf(qrmanager->mrows, cholmanager->UU);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          solve(cholmanager, solution->searchDir);
        }
        break;

       case 4:
        nVars = objective->nvar - 1;
        cholmanager->ndims = objective->nvar;
        for (ix = 0; ix <= nVars; ix++) {
          mNull_tmp = objective->nvar * ix;
          idx_col = 7 * ix;
          for (k = 0; k <= nVars; k++) {
            idx_row = k + 1;
            cholmanager->UU[(idx_col + idx_row) - 1] = H[(mNull_tmp + idx_row) -
              1];
          }
        }

        cholmanager->info = xpotrf(objective->nvar, cholmanager->UU);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          solve(cholmanager, solution->searchDir);
          c = 1.0 / objective->beta;
          mNull_tmp = objective->nvar + 1;
          i = qrmanager->mrows;
          for (k = mNull_tmp; k <= i; k++) {
            solution->searchDir[k - 1] *= c;
          }
        }
        break;
      }
    } else {
      nullStartIdx_tmp = 7 * qrmanager->ncols + 1;
      switch (objective->objtype) {
       case 5:
        for (ix = 0; ix <= mNull; ix++) {
          memspace->workspace_double[ix] = -qrmanager->Q[nVar_tmp_tmp + 7 *
            (qrmanager->ncols + ix)];
        }

        if (qrmanager->mrows != 0) {
          if (0 <= nVar_tmp_tmp) {
            memset(&solution->searchDir[0], 0, (nVar_tmp_tmp + 1) * sizeof
                   (double));
          }

          ix = 0;
          i = nullStartIdx_tmp + 7 * mNull;
          for (idx_row = nullStartIdx_tmp; idx_row <= i; idx_row += 7) {
            idx_col = 0;
            k = idx_row + nVar_tmp_tmp;
            for (mNull_tmp = idx_row; mNull_tmp <= k; mNull_tmp++) {
              solution->searchDir[idx_col] += qrmanager->Q[mNull_tmp - 1] *
                memspace->workspace_double[ix];
              idx_col++;
            }

            ix++;
          }
        }
        break;

       default:
        switch (objective->objtype) {
         case 3:
          xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp,
                memspace->workspace_double);
          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double, cholmanager->UU);
          break;

         default:
          nVars = qrmanager->mrows;
          xgemm(objective->nvar, mNull_tmp, objective->nvar, H, objective->nvar,
                qrmanager->Q, nullStartIdx_tmp, memspace->workspace_double);
          for (idx_col = 0; idx_col < mNull_tmp; idx_col++) {
            i = objective->nvar + 1;
            for (idx_row = i; idx_row <= nVars; idx_row++) {
              memspace->workspace_double[(idx_row + 7 * idx_col) - 1] =
                objective->beta * qrmanager->Q[(idx_row + 7 * (idx_col +
                qrmanager->ncols)) - 1];
            }
          }

          b_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp, memspace->workspace_double, cholmanager->UU);
          break;
        }

        cholmanager->ndims = mNull + 1;
        cholmanager->info = xpotrf(mNull + 1, cholmanager->UU);
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            if (0 <= mNull) {
              memset(&memspace->workspace_double[0], 0, (mNull + 1) * sizeof
                     (double));
            }

            idx_col = 0;
            i = nullStartIdx_tmp + 7 * mNull;
            for (idx_row = nullStartIdx_tmp; idx_row <= i; idx_row += 7) {
              ix = 0;
              c = 0.0;
              k = idx_row + nVar_tmp_tmp;
              for (mNull_tmp = idx_row; mNull_tmp <= k; mNull_tmp++) {
                c += qrmanager->Q[mNull_tmp - 1] * objective->grad[ix];
                ix++;
              }

              memspace->workspace_double[idx_col] += -c;
              idx_col++;
            }
          }

          for (i = 0; i < 49; i++) {
            rhs[i] = memspace->workspace_double[i];
          }

          for (idx_col = 0; idx_col <= mNull; idx_col++) {
            nVars = idx_col * 7;
            c = rhs[idx_col];
            for (idx_row = 0; idx_row < idx_col; idx_row++) {
              c -= cholmanager->UU[nVars + idx_row] * rhs[idx_row];
            }

            rhs[idx_col] = c / cholmanager->UU[nVars + idx_col];
          }

          memcpy(&memspace->workspace_double[0], &rhs[0], 49U * sizeof(double));
          for (idx_col = mNull + 1; idx_col >= 1; idx_col--) {
            nVars = (idx_col + (idx_col - 1) * 7) - 1;
            memspace->workspace_double[idx_col - 1] /= cholmanager->UU[nVars];
            for (idx_row = 0; idx_row <= idx_col - 2; idx_row++) {
              ix = (idx_col - idx_row) - 2;
              memspace->workspace_double[ix] -= memspace->
                workspace_double[idx_col - 1] * cholmanager->UU[(nVars - idx_row)
                - 1];
            }
          }

          nVars = qrmanager->mrows - 1;
          if (qrmanager->mrows != 0) {
            if (0 <= nVars) {
              memset(&solution->searchDir[0], 0, (nVars + 1) * sizeof(double));
            }

            ix = 0;
            i = nullStartIdx_tmp + 7 * mNull;
            for (idx_row = nullStartIdx_tmp; idx_row <= i; idx_row += 7) {
              idx_col = 0;
              k = idx_row + nVars;
              for (mNull_tmp = idx_row; mNull_tmp <= k; mNull_tmp++) {
                solution->searchDir[idx_col] += qrmanager->Q[mNull_tmp - 1] *
                  memspace->workspace_double[ix];
                idx_col++;
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
