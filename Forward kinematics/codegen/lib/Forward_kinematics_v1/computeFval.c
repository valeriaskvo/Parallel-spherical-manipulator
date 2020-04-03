/*
 * File: computeFval.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

/* Include Files */
#include "computeFval.h"
#include "Forward_kinematics_v1.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const j_struct_T *obj
 *                double workspace[49]
 *                const double H[36]
 *                const double f[7]
 *                const double x[7]
 * Return Type  : double
 */
double computeFval(const j_struct_T *obj, double workspace[49], const double H
                   [36], const double f[7], const double x[7])
{
  double val;
  int ixlast;
  int k;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    val = obj->gammaScalar * x[obj->nvar - 1];
    break;

   case 3:
    linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (k = 0; k < ixlast; k++) {
        val += x[k] * workspace[k];
      }
    }
    break;

   case 4:
    linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    ixlast = obj->nvar + 1;
    for (k = ixlast; k < 7; k++) {
      workspace[k - 1] = 0.5 * obj->beta * x[k - 1] + obj->rho;
    }

    for (k = 0; k < 6; k++) {
      val += x[k] * workspace[k];
    }
    break;
  }

  return val;
}

/*
 * File trailer for computeFval.c
 *
 * [EOF]
 */
