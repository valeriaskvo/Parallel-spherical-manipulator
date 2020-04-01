/*
 * File: computeGrad_StoreHx.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/* Include Files */
#include "computeGrad_StoreHx.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : j_struct_T *obj
 *                const double H[25]
 *                const double f[6]
 *                const double x[6]
 * Return Type  : void
 */
void computeGrad_StoreHx(j_struct_T *obj, const double H[25], const double f[6],
  const double x[6])
{
  int n;
  int maxRegVar;
  int lda;
  int ix;
  int i;
  int iac;
  int iy;
  int i1;
  int ia;
  switch (obj->objtype) {
   case 5:
    n = obj->nvar;
    if (0 <= n - 2) {
      memset(&obj->grad[0], 0, (n + -1) * sizeof(double));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    n = obj->nvar - 1;
    lda = obj->nvar;
    if (obj->nvar != 0) {
      if (0 <= n) {
        memset(&obj->Hx[0], 0, (n + 1) * sizeof(double));
      }

      ix = 0;
      i = obj->nvar * (obj->nvar - 1) + 1;
      for (iac = 1; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        iy = 0;
        i1 = iac + n;
        for (ia = iac; ia <= i1; ia++) {
          obj->Hx[iy] += H[ia - 1] * x[ix];
          iy++;
        }

        ix++;
      }
    }

    n = obj->nvar;
    if (0 <= n - 1) {
      memcpy(&obj->grad[0], &obj->Hx[0], n * sizeof(double));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      i = obj->nvar - 1;
      for (n = 0; n <= i; n++) {
        obj->grad[n] += f[n];
      }
    }
    break;

   case 4:
    maxRegVar = obj->maxVar - 1;
    n = obj->nvar - 1;
    lda = obj->nvar;
    if (obj->nvar != 0) {
      if (0 <= n) {
        memset(&obj->Hx[0], 0, (n + 1) * sizeof(double));
      }

      ix = 0;
      i = obj->nvar * (obj->nvar - 1) + 1;
      for (iac = 1; lda < 0 ? iac >= i : iac <= i; iac += lda) {
        iy = 0;
        i1 = iac + n;
        for (ia = iac; ia <= i1; ia++) {
          obj->Hx[iy] += H[ia - 1] * x[ix];
          iy++;
        }

        ix++;
      }
    }

    i = obj->nvar + 1;
    for (n = i; n <= maxRegVar; n++) {
      obj->Hx[n - 1] = obj->beta * x[n - 1];
    }

    if (0 <= maxRegVar - 1) {
      memcpy(&obj->grad[0], &obj->Hx[0], maxRegVar * sizeof(double));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      i = obj->nvar - 1;
      for (n = 0; n <= i; n++) {
        obj->grad[n] += f[n];
      }
    }

    n = (obj->maxVar - obj->nvar) - 1;
    if (n >= 1) {
      iy = obj->nvar;
      i = n - 1;
      for (n = 0; n <= i; n++) {
        obj->grad[iy] += obj->rho;
        iy++;
      }
    }
    break;
  }
}

/*
 * File trailer for computeGrad_StoreHx.c
 *
 * [EOF]
 */
