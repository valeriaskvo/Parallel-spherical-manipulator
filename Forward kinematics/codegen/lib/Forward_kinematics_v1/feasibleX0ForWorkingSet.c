/*
 * File: feasibleX0ForWorkingSet.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "feasibleX0ForWorkingSet.h"
#include "Forward_kinematics_v1.h"
#include "computeQ_.h"
#include "factorQR.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : double workspace[49]
 *                double xCurrent[7]
 *                const f_struct_T *workingset
 *                i_struct_T *qrmanager
 * Return Type  : boolean_T
 */
boolean_T feasibleX0ForWorkingSet(double workspace[49], double xCurrent[7],
  const f_struct_T *workingset, i_struct_T *qrmanager)
{
  boolean_T nonDegenerateWset;
  int mWConstr_tmp;
  int nVar;
  int iy;
  int i;
  int iac;
  int ix;
  double c;
  int i1;
  int ia;
  double B[49];
  int k;
  int exitg1;
  double constrViolation_basicX;
  mWConstr_tmp = workingset->nActiveConstr - 1;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (iy = 0; iy <= mWConstr_tmp; iy++) {
      workspace[0] = workingset->bwset;
      workspace[7] = workingset->bwset;
    }

    if ((workingset->nVar != 0) && (workingset->nActiveConstr != 0)) {
      iy = 0;
      i = 7 * mWConstr_tmp + 1;
      for (iac = 1; iac <= i; iac += 7) {
        ix = 0;
        c = 0.0;
        i1 = (iac + nVar) - 1;
        for (ia = iac; ia <= i1; ia++) {
          c += workingset->ATwset[ia - 1] * xCurrent[ix];
          ix++;
        }

        workspace[iy] += -c;
        iy++;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      for (iy = 0; iy < nVar; iy++) {
        for (iac = 0; iac <= mWConstr_tmp; iac++) {
          qrmanager->QR[7 * iy] = workingset->ATwset[iy];
        }
      }

      if (workingset->nActiveConstr * workingset->nVar == 0) {
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = false;
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        i = workingset->nVar;
        for (iy = 0; iy < i; iy++) {
          qrmanager->jpvt[iy] = iy + 1;
        }

        iy = workingset->nActiveConstr;
        iac = workingset->nVar;
        if (iy < iac) {
          iac = iy;
        }

        qrmanager->minRowCol = iac;
        for (i = 0; i < 49; i++) {
          B[i] = qrmanager->QR[i];
        }

        for (ix = 0; ix < 7; ix++) {
          qrmanager->tau[ix] = 0.0;
        }

        if (iac >= 1) {
          for (ix = 0; ix < 7; ix++) {
            qrmanager->tau[ix] = 0.0;
          }

          qrf(B, workingset->nActiveConstr, workingset->nVar, iac,
              qrmanager->tau);
        }

        memcpy(&qrmanager->QR[0], &B[0], 49U * sizeof(double));
      }

      computeQ_(qrmanager, qrmanager->mrows);
      memcpy(&B[0], &workspace[0], 49U * sizeof(double));
      if (workingset->nVar != 0) {
        if (1 <= nVar) {
          memset(&workspace[0], 0, nVar * sizeof(double));
        }

        i = nVar + 7;
        if (8 <= i) {
          memset(&workspace[7], 0, (i + -7) * sizeof(double));
        }

        ix = -1;
        for (k = 1; k <= nVar; k++) {
          c = 0.0;
          for (iy = 0; iy <= mWConstr_tmp; iy++) {
            iac = iy + 1;
            c += qrmanager->Q[iac + ix] * B[iac + -1];
          }

          workspace[k - 1] += c;
          ix += 7;
        }

        ix = -1;
        i = nVar + 7;
        for (k = 8; k <= i; k++) {
          c = 0.0;
          for (iy = 0; iy <= mWConstr_tmp; iy++) {
            iac = iy + 1;
            c += qrmanager->Q[iac + ix] * B[iac + 6];
          }

          workspace[k - 1] += c;
          ix += 7;
        }
      }

      for (k = nVar; k >= 1; k--) {
        iy = 7 * (k - 1) - 1;
        i = k + -1;
        if (workspace[i] != 0.0) {
          workspace[i] /= qrmanager->QR[k + iy];
          for (ix = 0; ix <= k - 2; ix++) {
            workspace[ix] -= workspace[i] * qrmanager->QR[(ix + iy) + 1];
          }
        }
      }

      for (k = nVar; k >= 1; k--) {
        iy = 7 * (k - 1) - 1;
        i = k + 6;
        if (workspace[i] != 0.0) {
          workspace[i] /= qrmanager->QR[k + iy];
          for (ix = 0; ix <= k - 2; ix++) {
            i1 = ix + 7;
            workspace[i1] -= workspace[i] * qrmanager->QR[(ix + iy) + 1];
          }
        }
      }
    } else {
      factorQR(qrmanager, workingset->ATwset, workingset->nVar,
               workingset->nActiveConstr);
      computeQ_(qrmanager, qrmanager->minRowCol);
      for (ix = 0; ix <= mWConstr_tmp; ix++) {
        iy = 7 * ix;
        c = workspace[ix];
        for (k = 0; k < ix; k++) {
          c -= qrmanager->QR[k + iy] * workspace[k];
        }

        workspace[ix] = c / qrmanager->QR[ix + iy];
      }

      for (ix = 0; ix <= mWConstr_tmp; ix++) {
        iy = 7 * ix;
        iac = ix + 7;
        c = workspace[iac];
        for (k = 0; k < ix; k++) {
          c -= qrmanager->QR[k + iy] * workspace[k + 7];
        }

        workspace[iac] = c / qrmanager->QR[ix + iy];
      }

      memcpy(&B[0], &workspace[0], 49U * sizeof(double));
      if (workingset->nVar != 0) {
        if (1 <= nVar) {
          memset(&workspace[0], 0, nVar * sizeof(double));
        }

        i = nVar + 7;
        if (8 <= i) {
          memset(&workspace[7], 0, (i + -7) * sizeof(double));
        }

        ix = -1;
        i = mWConstr_tmp + 1;
        for (iy = 1; iy <= i; iy++) {
          ia = ix;
          for (k = 1; k <= nVar; k++) {
            ia++;
            workspace[k - 1] += B[iy - 1] * qrmanager->Q[ia];
          }

          ix += 7;
        }

        ix = -1;
        i = mWConstr_tmp + 8;
        for (iy = 8; iy <= i; iy++) {
          ia = ix;
          i1 = nVar + 7;
          for (k = 8; k <= i1; k++) {
            ia++;
            workspace[k - 1] += B[iy - 1] * qrmanager->Q[ia];
          }

          ix += 7;
        }
      }
    }

    iy = 0;
    do {
      exitg1 = 0;
      if (iy <= nVar - 1) {
        if (rtIsInf(workspace[iy]) || rtIsNaN(workspace[iy])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace[iy + 7];
          if (rtIsInf(c) || rtIsNaN(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            iy++;
          }
        }
      } else {
        if (nVar >= 1) {
          iy = nVar - 1;
          for (k = 0; k <= iy; k++) {
            workspace[k] += xCurrent[k];
          }
        }

        c = maxConstraintViolation(workingset, workspace, 1);
        constrViolation_basicX = maxConstraintViolation(workingset, workspace, 8);
        if ((c <= 2.2204460492503131E-16) || (c < constrViolation_basicX)) {
          if (0 <= nVar - 1) {
            memcpy(&xCurrent[0], &workspace[0], nVar * sizeof(double));
          }
        } else {
          if (0 <= nVar - 1) {
            memcpy(&xCurrent[0], &workspace[7], nVar * sizeof(double));
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

/*
 * File trailer for feasibleX0ForWorkingSet.c
 *
 * [EOF]
 */
