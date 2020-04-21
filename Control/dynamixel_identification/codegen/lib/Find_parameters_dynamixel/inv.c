/*
 * File: inv.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "inv.h"
#include "Find_parameters_dynamixel.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void inv(const double x_data[], const int x_size[2], double y_data[], int
         y_size[2])
{
  int n;
  int iy;
  double b_x_data[9];
  int ipiv_size_idx_1;
  int ipiv_data[3];
  int yk;
  int k;
  int ldap1;
  int u1;
  int j;
  int mmj_tmp;
  int p_data[3];
  int jj;
  int jp1j;
  int ix;
  double smax;
  int i;
  int b_i;
  double s;
  int i1;
  n = x_size[0];
  y_size[0] = x_size[0];
  y_size[1] = x_size[1];
  iy = x_size[0] * x_size[1];
  if (0 <= iy - 1) {
    memset(&y_data[0], 0, iy * sizeof(double));
    memcpy(&b_x_data[0], &x_data[0], iy * sizeof(double));
  }

  iy = x_size[0];
  ipiv_size_idx_1 = x_size[0];
  ipiv_data[0] = 1;
  yk = 1;
  for (k = 2; k <= iy; k++) {
    yk++;
    ipiv_data[k - 1] = yk;
  }

  ldap1 = x_size[0];
  iy = x_size[0] - 1;
  u1 = x_size[0];
  if (iy < u1) {
    u1 = iy;
  }

  for (j = 0; j < u1; j++) {
    mmj_tmp = n - j;
    yk = j * (n + 1);
    jj = j * (ldap1 + 1);
    jp1j = yk + 2;
    if (mmj_tmp < 1) {
      iy = -1;
    } else {
      iy = 0;
      if (mmj_tmp > 1) {
        ix = yk;
        smax = fabs(b_x_data[jj]);
        for (k = 2; k <= mmj_tmp; k++) {
          ix++;
          s = fabs(b_x_data[ix]);
          if (s > smax) {
            iy = k - 1;
            smax = s;
          }
        }
      }
    }

    if (b_x_data[jj + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv_data[j] = iy + 1;
        ix = j;
        for (k = 0; k < n; k++) {
          smax = b_x_data[ix];
          b_x_data[ix] = b_x_data[iy];
          b_x_data[iy] = smax;
          ix += n;
          iy += n;
        }
      }

      i = jj + mmj_tmp;
      for (b_i = jp1j; b_i <= i; b_i++) {
        b_x_data[b_i - 1] /= b_x_data[jj];
      }
    }

    yk += n;
    iy = jj + ldap1;
    for (jp1j = 0; jp1j <= mmj_tmp - 2; jp1j++) {
      smax = b_x_data[yk];
      if (b_x_data[yk] != 0.0) {
        ix = jj + 1;
        i = iy + 2;
        i1 = mmj_tmp + iy;
        for (b_i = i; b_i <= i1; b_i++) {
          b_x_data[b_i - 1] += b_x_data[ix] * -smax;
          ix++;
        }
      }

      yk += n;
      iy += n;
    }
  }

  iy = x_size[0];
  p_data[0] = 1;
  yk = 1;
  for (k = 2; k <= iy; k++) {
    yk++;
    p_data[k - 1] = yk;
  }

  for (k = 0; k < ipiv_size_idx_1; k++) {
    if (ipiv_data[k] > k + 1) {
      iy = p_data[ipiv_data[k] - 1];
      p_data[ipiv_data[k] - 1] = p_data[k];
      p_data[k] = iy;
    }
  }

  for (k = 0; k < n; k++) {
    i = p_data[k];
    iy = y_size[0] * (p_data[k] - 1);
    y_data[k + iy] = 1.0;
    for (j = k + 1; j <= n; j++) {
      if (y_data[(j + iy) - 1] != 0.0) {
        i1 = j + 1;
        for (b_i = i1; b_i <= n; b_i++) {
          yk = (b_i + y_size[0] * (i - 1)) - 1;
          y_data[yk] -= y_data[(j + y_size[0] * (i - 1)) - 1] * b_x_data[(b_i +
            x_size[0] * (j - 1)) - 1];
        }
      }
    }
  }

  for (j = 0; j < n; j++) {
    iy = n * j - 1;
    for (k = n; k >= 1; k--) {
      yk = n * (k - 1) - 1;
      i = k + iy;
      if (y_data[i] != 0.0) {
        y_data[i] /= b_x_data[k + yk];
        for (b_i = 0; b_i <= k - 2; b_i++) {
          i1 = (b_i + iy) + 1;
          y_data[i1] -= y_data[i] * b_x_data[(b_i + yk) + 1];
        }
      }
    }
  }
}

/*
 * File trailer for inv.c
 *
 * [EOF]
 */
