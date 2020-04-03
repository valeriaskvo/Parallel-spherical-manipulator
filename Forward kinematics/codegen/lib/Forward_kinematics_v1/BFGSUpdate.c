/*
 * File: BFGSUpdate.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "BFGSUpdate.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : int nvar
 *                double Bk[36]
 *                const double sk[7]
 *                double yk[7]
 *                double workspace[49]
 * Return Type  : boolean_T
 */
boolean_T BFGSUpdate(int nvar, double Bk[36], const double sk[7], double yk[7],
                     double workspace[49])
{
  boolean_T success;
  double dotSY;
  int jA;
  int ix;
  int i;
  double curvatureS;
  int ixlast;
  int i1;
  int ia;
  double theta;
  int ijA;
  dotSY = 0.0;
  for (jA = 0; jA < nvar; jA++) {
    dotSY += sk[jA] * yk[jA];
    workspace[jA] = 0.0;
  }

  ix = 0;
  i = 6 * (nvar - 1) + 1;
  for (jA = 1; jA <= i; jA += 6) {
    ixlast = 0;
    i1 = (jA + nvar) - 1;
    for (ia = jA; ia <= i1; ia++) {
      workspace[ixlast] += Bk[ia - 1] * sk[ix];
      ixlast++;
    }

    ix++;
  }

  curvatureS = 0.0;
  if (nvar >= 1) {
    for (jA = 0; jA < nvar; jA++) {
      curvatureS += sk[jA] * workspace[jA];
    }
  }

  if (dotSY < 0.2 * curvatureS) {
    theta = 0.8 * curvatureS / (curvatureS - dotSY);
    for (jA = 0; jA < nvar; jA++) {
      yk[jA] *= theta;
    }

    if (!(1.0 - theta == 0.0)) {
      ixlast = nvar - 1;
      for (jA = 0; jA <= ixlast; jA++) {
        yk[jA] += (1.0 - theta) * workspace[jA];
      }
    }

    dotSY = 0.0;
    for (jA = 0; jA < nvar; jA++) {
      dotSY += sk[jA] * yk[jA];
    }
  }

  if ((curvatureS > 2.2204460492503131E-16) && (dotSY > 2.2204460492503131E-16))
  {
    success = true;
  } else {
    success = false;
  }

  if (success) {
    theta = -1.0 / curvatureS;
    if (!(theta == 0.0)) {
      jA = 0;
      ixlast = 0;
      for (ia = 0; ia < nvar; ia++) {
        if (workspace[ixlast] != 0.0) {
          curvatureS = workspace[ixlast] * theta;
          ix = 0;
          i = jA + 1;
          i1 = nvar + jA;
          for (ijA = i; ijA <= i1; ijA++) {
            Bk[ijA - 1] += workspace[ix] * curvatureS;
            ix++;
          }
        }

        ixlast++;
        jA += 6;
      }
    }

    theta = 1.0 / dotSY;
    if (!(theta == 0.0)) {
      jA = 0;
      ixlast = 0;
      for (ia = 0; ia < nvar; ia++) {
        if (yk[ixlast] != 0.0) {
          curvatureS = yk[ixlast] * theta;
          ix = 0;
          i = jA + 1;
          i1 = nvar + jA;
          for (ijA = i; ijA <= i1; ijA++) {
            Bk[ijA - 1] += yk[ix] * curvatureS;
            ix++;
          }
        }

        ixlast++;
        jA += 6;
      }
    }
  }

  return success;
}

/*
 * File trailer for BFGSUpdate.c
 *
 * [EOF]
 */
