/*
 * File: computeLambdaLSQ.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "computeLambdaLSQ.h"
#include "Forward_kinematics_v2.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : int nVar
 *                int mConstr
 *                i_struct_T *QRManager
 *                const double ATwset[6]
 *                const double grad[6]
 *                double *lambdaLSQ
 *                double workspace[36]
 * Return Type  : void
 */
void computeLambdaLSQ(int nVar, int mConstr, i_struct_T *QRManager, const double
                      ATwset[6], const double grad[6], double *lambdaLSQ, double
                      workspace[36])
{
  int iQR_diag;
  double tol;
  int fullRank_R;
  int rankR;
  int jjA;
  int i;
  int ix;
  for (iQR_diag = 0; iQR_diag < mConstr; iQR_diag++) {
    *lambdaLSQ = 0.0;
  }

  factorQRE(QRManager, ATwset, nVar, mConstr);
  computeQ_(QRManager, QRManager->mrows);
  xgemv(nVar, nVar, QRManager->Q, QRManager->ldq, grad, workspace);
  if (nVar > mConstr) {
    iQR_diag = nVar;
  } else {
    iQR_diag = mConstr;
  }

  tol = fabs(QRManager->QR[0]) * fmin(1.4901161193847656E-8, (double)iQR_diag *
    2.2204460492503131E-16);
  if (nVar < mConstr) {
    fullRank_R = nVar;
  } else {
    fullRank_R = mConstr;
  }

  rankR = 0;
  iQR_diag = 0;
  while ((rankR < fullRank_R) && (fabs(QRManager->QR[iQR_diag]) > tol)) {
    rankR++;
    iQR_diag = (iQR_diag + QRManager->ldq) + 1;
  }

  if (rankR != 0) {
    for (iQR_diag = rankR; iQR_diag >= 1; iQR_diag--) {
      jjA = (iQR_diag + (iQR_diag - 1) * QRManager->ldq) - 1;
      workspace[iQR_diag - 1] /= QRManager->QR[jjA];
      for (i = 0; i <= iQR_diag - 2; i++) {
        ix = (iQR_diag - i) - 2;
        workspace[ix] -= workspace[iQR_diag - 1] * QRManager->QR[(jjA - i) - 1];
      }
    }
  }

  if (mConstr < fullRank_R) {
    fullRank_R = mConstr;
  }

  for (iQR_diag = 0; iQR_diag < fullRank_R; iQR_diag++) {
    *lambdaLSQ = workspace[iQR_diag];
  }
}

/*
 * File trailer for computeLambdaLSQ.c
 *
 * [EOF]
 */
