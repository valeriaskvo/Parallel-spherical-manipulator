/*
 * File: computeDualFeasError.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

#ifndef COMPUTEDUALFEASERROR_H
#define COMPUTEDUALFEASERROR_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void b_computeDualFeasError(int nVar, const double gradLag[36], boolean_T
  *gradOK, double *val);
extern void computeDualFeasError(int nVar, const double gradLag[6], boolean_T
  *gradOK, double *val);

#endif

/*
 * File trailer for computeDualFeasError.h
 *
 * [EOF]
 */
