/*
 * File: finDiffEvalAndChkErr.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "finDiffEvalAndChkErr.h"
#include "Forward_kinematics_v2.h"
#include "Weighted_error.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double c_obj_objfun_tunableEnvironment[5]
 *                const double d_obj_objfun_tunableEnvironment[4]
 *                boolean_T obj_SpecifyObjectiveGradient
 *                double *fplus
 *                int dim
 *                double delta
 *                double xk[5]
 * Return Type  : boolean_T
 */
boolean_T finDiffEvalAndChkErr(const double c_obj_objfun_tunableEnvironment[5],
  const double d_obj_objfun_tunableEnvironment[4], boolean_T
  obj_SpecifyObjectiveGradient, double *fplus, int dim, double delta, double xk
  [5])
{
  boolean_T evalOK;
  double temp_tmp;
  double dv[2];
  double e_obj_objfun_tunableEnvironment[3];
  double b_xk[3];
  double c_xk[3];
  evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  if (!obj_SpecifyObjectiveGradient) {
    dv[0] = 1.0;
    dv[1] = 1000.0;
    e_obj_objfun_tunableEnvironment[0] = d_obj_objfun_tunableEnvironment[0];
    e_obj_objfun_tunableEnvironment[1] = d_obj_objfun_tunableEnvironment[1];
    e_obj_objfun_tunableEnvironment[2] = xk[0];
    b_xk[0] = xk[1];
    b_xk[1] = d_obj_objfun_tunableEnvironment[2];
    b_xk[2] = xk[2];
    c_xk[0] = xk[3];
    c_xk[1] = d_obj_objfun_tunableEnvironment[3];
    c_xk[2] = xk[4];
    *fplus = Weighted_error(c_obj_objfun_tunableEnvironment, dv,
      e_obj_objfun_tunableEnvironment, b_xk, c_xk);
    evalOK = ((!rtIsInf(*fplus)) && (!rtIsNaN(*fplus)));
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  } else {
    xk[dim - 1] = temp_tmp;
  }

  return evalOK;
}

/*
 * File trailer for finDiffEvalAndChkErr.c
 *
 * [EOF]
 */
