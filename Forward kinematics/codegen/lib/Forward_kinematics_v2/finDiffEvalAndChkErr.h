/*
 * File: finDiffEvalAndChkErr.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef FINDIFFEVALANDCHKERR_H
#define FINDIFFEVALANDCHKERR_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern boolean_T finDiffEvalAndChkErr(const double
  c_obj_objfun_tunableEnvironment[5], const double
  d_obj_objfun_tunableEnvironment[4], boolean_T obj_SpecifyObjectiveGradient,
  double *fplus, int dim, double delta, double xk[5]);

#endif

/*
 * File trailer for finDiffEvalAndChkErr.h
 *
 * [EOF]
 */
