/*
 * File: computeFval_ReuseHx.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "computeFval_ReuseHx.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const j_struct_T *obj
 *                double workspace[49]
 *                const double f[7]
 *                const double x[7]
 * Return Type  : double
 */
double computeFval_ReuseHx(const j_struct_T *obj, double workspace[49], const
  double f[7], const double x[7])
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
    if (obj->hasLinear) {
      ixlast = obj->nvar;
      if (0 <= ixlast - 1) {
        memcpy(&workspace[0], &f[0], ixlast * sizeof(double));
      }

      if (obj->nvar >= 1) {
        ixlast = obj->nvar - 1;
        for (k = 0; k <= ixlast; k++) {
          workspace[k] += 0.5 * obj->Hx[k];
        }

        ixlast = obj->nvar;
        for (k = 0; k < ixlast; k++) {
          val += x[k] * workspace[k];
        }
      }
    } else {
      if (obj->nvar >= 1) {
        ixlast = obj->nvar;
        for (k = 0; k < ixlast; k++) {
          val += x[k] * obj->Hx[k];
        }
      }

      val *= 0.5;
    }
    break;

   case 4:
    if (obj->hasLinear) {
      ixlast = obj->nvar;
      if (0 <= ixlast - 1) {
        memcpy(&workspace[0], &f[0], ixlast * sizeof(double));
      }

      ixlast = 5 - obj->nvar;
      for (k = 0; k <= ixlast; k++) {
        workspace[obj->nvar + k] = obj->rho;
      }

      for (k = 0; k < 6; k++) {
        workspace[k] += 0.5 * obj->Hx[k];
        val += x[k] * workspace[k];
      }
    } else {
      for (k = 0; k < 6; k++) {
        val += x[k] * obj->Hx[k];
      }

      val *= 0.5;
      ixlast = obj->nvar + 1;
      for (k = ixlast; k < 7; k++) {
        val += x[k - 1] * obj->rho;
      }
    }
    break;
  }

  return val;
}

/*
 * File trailer for computeFval_ReuseHx.c
 *
 * [EOF]
 */
