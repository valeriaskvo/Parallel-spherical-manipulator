/*
 * File: BFGSUpdate.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "BFGSUpdate.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : int nvar
 *                double Bk[25]
 *                const double sk[6]
 *                double yk[6]
 *                double workspace[36]
 * Return Type  : boolean_T
 */
boolean_T BFGSUpdate(int nvar, double Bk[25], const double sk[6], double yk[6],
                     double workspace[36])
{
  boolean_T success;
  double dotSY;
  int jA;
  double curvatureS;
  int ix;
  int i;
  double theta;
  int ixlast;
  int i1;
  int ia;
  int ijA;
  dotSY = 0.0;
  if (nvar >= 1) {
    for (jA = 0; jA < nvar; jA++) {
      dotSY += sk[jA] * yk[jA];
    }
  }

  if (nvar != 0) {
    if (0 <= nvar - 1) {
      memset(&workspace[0], 0, nvar * sizeof(double));
    }

    ix = 0;
    i = 5 * (nvar - 1) + 1;
    for (jA = 1; jA <= i; jA += 5) {
      ixlast = 0;
      i1 = (jA + nvar) - 1;
      for (ia = jA; ia <= i1; ia++) {
        workspace[ixlast] += Bk[ia - 1] * sk[ix];
        ixlast++;
      }

      ix++;
    }
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

    if ((nvar >= 1) && (!(1.0 - theta == 0.0))) {
      ixlast = nvar - 1;
      for (jA = 0; jA <= ixlast; jA++) {
        yk[jA] += (1.0 - theta) * workspace[jA];
      }
    }

    dotSY = 0.0;
    if (nvar >= 1) {
      for (jA = 0; jA < nvar; jA++) {
        dotSY += sk[jA] * yk[jA];
      }
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
        jA += 5;
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
        jA += 5;
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
