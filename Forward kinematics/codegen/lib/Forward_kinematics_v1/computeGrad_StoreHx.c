/*
 * File: computeGrad_StoreHx.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "computeGrad_StoreHx.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : j_struct_T *obj
 *                const double H[36]
 *                const double f[7]
 *                const double x[7]
 * Return Type  : void
 */
void computeGrad_StoreHx(j_struct_T *obj, const double H[36], const double f[7],
  const double x[7])
{
  int n;
  int lda;
  int i;
  int ix;
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
    for (n = i; n < 7; n++) {
      obj->Hx[n - 1] = obj->beta * x[n - 1];
    }

    for (n = 0; n < 6; n++) {
      obj->grad[n] = obj->Hx[n];
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      i = obj->nvar - 1;
      for (n = 0; n <= i; n++) {
        obj->grad[n] += f[n];
      }
    }

    if (6 - obj->nvar >= 1) {
      iy = obj->nvar;
      i = 5 - obj->nvar;
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
