/*
 * File: computeFval.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "computeFval.h"
#include "Forward_kinematics_v2.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const j_struct_T *obj
 *                double workspace[36]
 *                const double H[25]
 *                const double f[6]
 *                const double x[6]
 * Return Type  : double
 */
double computeFval(const j_struct_T *obj, double workspace[36], const double H
                   [25], const double f[6], const double x[6])
{
  double val;
  int ixlast;
  int k;
  int idx;
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
    k = obj->maxVar - 1;
    for (idx = ixlast; idx <= k; idx++) {
      workspace[idx - 1] = 0.5 * obj->beta * x[idx - 1] + obj->rho;
    }

    if (k >= 1) {
      ixlast = obj->maxVar;
      for (k = 0; k <= ixlast - 2; k++) {
        val += x[k] * workspace[k];
      }
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
