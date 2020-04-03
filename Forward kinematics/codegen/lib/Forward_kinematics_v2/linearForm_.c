/*
 * File: linearForm_.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

/* Include Files */
#include "linearForm_.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : boolean_T obj_hasLinear
 *                int obj_nvar
 *                double workspace[36]
 *                const double H[25]
 *                const double f[6]
 *                const double x[6]
 * Return Type  : void
 */
void linearForm_(boolean_T obj_hasLinear, int obj_nvar, double workspace[36],
                 const double H[25], const double f[6], const double x[6])
{
  int ix;
  int i;
  int iac;
  double c;
  int iy;
  int i1;
  int ia;
  ix = 0;
  if (obj_hasLinear) {
    if (0 <= obj_nvar - 1) {
      memcpy(&workspace[0], &f[0], obj_nvar * sizeof(double));
    }

    ix = 1;
  }

  if (obj_nvar != 0) {
    if ((ix != 1) && (0 <= obj_nvar - 1)) {
      memset(&workspace[0], 0, obj_nvar * sizeof(double));
    }

    ix = 0;
    i = obj_nvar * (obj_nvar - 1) + 1;
    for (iac = 1; obj_nvar < 0 ? iac >= i : iac <= i; iac += obj_nvar) {
      c = 0.5 * x[ix];
      iy = 0;
      i1 = (iac + obj_nvar) - 1;
      for (ia = iac; ia <= i1; ia++) {
        workspace[iy] += H[ia - 1] * c;
        iy++;
      }

      ix++;
    }
  }
}

/*
 * File trailer for linearForm_.c
 *
 * [EOF]
 */
