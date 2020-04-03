/*
 * File: computeDualFeasError.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "computeDualFeasError.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : int nVar
 *                const double gradLag[36]
 *                boolean_T *gradOK
 *                double *val
 * Return Type  : void
 */
void b_computeDualFeasError(int nVar, const double gradLag[36], boolean_T
  *gradOK, double *val)
{
  int idx;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    *gradOK = ((!rtIsInf(gradLag[idx])) && (!rtIsNaN(gradLag[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      *val = fmax(*val, fabs(gradLag[idx]));
      idx++;
    }
  }
}

/*
 * Arguments    : int nVar
 *                const double gradLag[6]
 *                boolean_T *gradOK
 *                double *val
 * Return Type  : void
 */
void computeDualFeasError(int nVar, const double gradLag[6], boolean_T *gradOK,
  double *val)
{
  int idx;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    *gradOK = ((!rtIsInf(gradLag[idx])) && (!rtIsNaN(gradLag[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      *val = fmax(*val, fabs(gradLag[idx]));
      idx++;
    }
  }
}

/*
 * File trailer for computeDualFeasError.c
 *
 * [EOF]
 */
