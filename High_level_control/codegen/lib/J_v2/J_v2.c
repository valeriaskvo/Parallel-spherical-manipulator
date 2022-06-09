/*
 * File: J_v2.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:04:06
 */

/* Include Files */
#include "J_v2.h"
#include "Inverse_kinematics.h"
#include "J_v2_data.h"
#include "J_v2_initialize.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double system_parameters[5]
 *                const double phi_ee[3]
 *                double J[12]
 * Return Type  : void
 */
void J_v2(const double system_parameters[5], const double phi_ee[3], double J[12])
{
  double t2;
  double t3;
  double t4;
  double t8;
  double t9;
  double t10;
  double q[3];
  double t6;
  double t7;
  double t12;
  double t13;
  double J_gen[27];
  double J_gen_tmp;
  double b_J_gen_tmp;
  double c_J_gen_tmp;
  double d_J_gen_tmp;
  double e_J_gen_tmp;
  double J_gen_tmp_tmp;
  double f_J_gen_tmp;
  double g_J_gen_tmp;
  double h_J_gen_tmp;
  double i_J_gen_tmp;
  double j_J_gen_tmp;
  double k_J_gen_tmp;
  double J_pass[30];
  boolean_T p;
  int br;
  double X[30];
  double U[30];
  double s[5];
  double V[25];
  int i;
  int vcol;
  int r;
  double J_end[9];
  int p3;
  int ar;
  int ib;
  int ia;
  int i1;
  int ic;
  double b_J_gen[24];
  double dv[12];
  double b_X[20];
  double b_J[9];
  if (isInitialized_J_v2 == false) {
    J_v2_initialize();
  }

  /*  Jacobian for case when PSM controlled by intermediate links actuators */
  /*  Created by Valeria Skvo */
  t2 = cos(system_parameters[2]);
  t3 = cos(system_parameters[3]);
  t4 = cos(system_parameters[0]);
  t8 = sin(system_parameters[2]);
  t9 = sin(system_parameters[3]);
  t10 = sin(system_parameters[0]);
  Inverse_kinematics(0.0, system_parameters, phi_ee, q);

  /* J_LEG */
  /*     J = J_LEG(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:33:44 */
  t6 = cos(q[0]);
  t7 = cos(q[1]);
  t12 = sin(q[0]);
  t13 = sin(q[1]);
  J_gen[0] = t10 * 0.0;
  J_gen[1] = t10;
  J_gen[2] = -t4;
  J_gen_tmp = t2 * t10;
  J_gen[3] = (J_gen_tmp * 0.0 + t8 * t12) + t4 * t6 * t8 * 0.0;
  J_gen[4] = (t2 * t10 - t8 * 0.0 * t12) + t4 * t6 * t8;
  b_J_gen_tmp = -t2 * t4;
  J_gen[5] = b_J_gen_tmp + t6 * t8 * t10;
  c_J_gen_tmp = t2 * t3;
  d_J_gen_tmp = t3 * t4;
  e_J_gen_tmp = t2 * t4;
  J_gen_tmp_tmp = c_J_gen_tmp * t10;
  f_J_gen_tmp = t4 * t9;
  g_J_gen_tmp = t3 * t8;
  h_J_gen_tmp = t6 * t9;
  i_J_gen_tmp = d_J_gen_tmp * t6 * t8;
  j_J_gen_tmp = t7 * t8 * t9 * t10;
  k_J_gen_tmp = e_J_gen_tmp * t6 * t7 * t9;
  J_gen[6] = ((((((J_gen_tmp_tmp * 0.0 + g_J_gen_tmp * t12) + h_J_gen_tmp * t13)
                 + i_J_gen_tmp * 0.0) + t2 * t7 * t9 * t12) - j_J_gen_tmp * 0.0)
              - f_J_gen_tmp * 0.0 * t12 * t13) + k_J_gen_tmp * 0.0;
  J_gen[7] = ((((((J_gen_tmp_tmp - g_J_gen_tmp * 0.0 * t12) - h_J_gen_tmp * 0.0 *
                  t13) + i_J_gen_tmp) - j_J_gen_tmp) - t2 * t7 * t9 * 0.0 * t12)
              - t4 * t9 * t12 * t13) + k_J_gen_tmp;
  h_J_gen_tmp = -t2 * t3 * t4;
  i_J_gen_tmp = t9 * t10;
  J_gen[8] = (((h_J_gen_tmp + t3 * t6 * t8 * t10) + t4 * t7 * t8 * t9) -
              i_J_gen_tmp * t12 * t13) + t2 * t6 * t7 * t9 * t10;
  Inverse_kinematics(2.0943951023931953, system_parameters, phi_ee, q);

  /* J_LEG */
  /*     J = J_LEG(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:33:44 */
  t6 = cos(q[0]);
  t7 = cos(q[1]);
  t12 = sin(q[0]);
  t13 = sin(q[1]);
  J_gen[9] = t10 * 0.86602540378443871;
  J_gen[10] = -0.49999999999999978 * t10;
  J_gen[11] = -t4;
  J_gen[12] = (J_gen_tmp * 0.86602540378443871 + -0.49999999999999978 * t8 * t12)
    + t4 * t6 * t8 * 0.86602540378443871;
  j_J_gen_tmp = t2 * -0.49999999999999978;
  k_J_gen_tmp = t4 * -0.49999999999999978;
  J_gen[13] = (j_J_gen_tmp * t10 - t8 * 0.86602540378443871 * t12) + k_J_gen_tmp
    * t6 * t8;
  J_gen[14] = b_J_gen_tmp + t6 * t8 * t10;
  J_gen[15] = ((((((J_gen_tmp_tmp * 0.86602540378443871 + t3 *
                    -0.49999999999999978 * t8 * t12) + -0.49999999999999978 * t6
                   * t9 * t13) + d_J_gen_tmp * t6 * t8 * 0.86602540378443871) +
                 j_J_gen_tmp * t7 * t9 * t12) - t7 * t8 * t9 * t10 *
                0.86602540378443871) - f_J_gen_tmp * 0.86602540378443871 * t12 *
               t13) + e_J_gen_tmp * t6 * t7 * t9 * 0.86602540378443871;
  J_gen[16] = ((((((c_J_gen_tmp * -0.49999999999999978 * t10 - g_J_gen_tmp *
                    0.86602540378443871 * t12) - t6 * t9 * 0.86602540378443871 *
                   t13) + d_J_gen_tmp * -0.49999999999999978 * t6 * t8) -
                 -0.49999999999999978 * t7 * t8 * t9 * t10) - t2 * t7 * t9 *
                0.86602540378443871 * t12) - k_J_gen_tmp * t9 * t12 * t13) +
    e_J_gen_tmp * -0.49999999999999978 * t6 * t7 * t9;
  J_gen[17] = (((h_J_gen_tmp + t3 * t6 * t8 * t10) + t4 * t7 * t8 * t9) -
               i_J_gen_tmp * t12 * t13) + t2 * t6 * t7 * t9 * t10;
  Inverse_kinematics(4.1887902047863905, system_parameters, phi_ee, q);

  /* J_LEG */
  /*     J = J_LEG(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:33:44 */
  t6 = cos(q[0]);
  t7 = cos(q[1]);
  t12 = sin(q[0]);
  t13 = sin(q[1]);
  J_gen[18] = t10 * -0.86602540378443849;
  J_gen[19] = -0.50000000000000044 * t10;
  J_gen[20] = -t4;
  J_gen[21] = (J_gen_tmp * -0.86602540378443849 + -0.50000000000000044 * t8 *
               t12) + t4 * t6 * t8 * -0.86602540378443849;
  J_gen_tmp = t2 * -0.50000000000000044;
  j_J_gen_tmp = t4 * -0.50000000000000044;
  J_gen[22] = (J_gen_tmp * t10 - t8 * -0.86602540378443849 * t12) + j_J_gen_tmp *
    t6 * t8;
  J_gen[23] = b_J_gen_tmp + t6 * t8 * t10;
  J_gen[24] = ((((((J_gen_tmp_tmp * -0.86602540378443849 + t3 *
                    -0.50000000000000044 * t8 * t12) + -0.50000000000000044 * t6
                   * t9 * t13) + d_J_gen_tmp * t6 * t8 * -0.86602540378443849) +
                 J_gen_tmp * t7 * t9 * t12) - t7 * t8 * t9 * t10 *
                -0.86602540378443849) - f_J_gen_tmp * -0.86602540378443849 * t12
               * t13) + e_J_gen_tmp * t6 * t7 * t9 * -0.86602540378443849;
  J_gen[25] = ((((((c_J_gen_tmp * -0.50000000000000044 * t10 - g_J_gen_tmp *
                    -0.86602540378443849 * t12) - t6 * t9 * -0.86602540378443849
                   * t13) + d_J_gen_tmp * -0.50000000000000044 * t6 * t8) -
                 -0.50000000000000044 * t7 * t8 * t9 * t10) - t2 * t7 * t9 *
                -0.86602540378443849 * t12) - j_J_gen_tmp * t9 * t12 * t13) +
    e_J_gen_tmp * -0.50000000000000044 * t6 * t7 * t9;
  J_gen[26] = (((h_J_gen_tmp + t3 * t6 * t8 * t10) + t4 * t7 * t8 * t9) -
               i_J_gen_tmp * t12 * t13) + t2 * t6 * t7 * t9 * t10;
  J_pass[0] = J_gen[6];
  J_pass[6] = -J_gen[9];
  J_pass[12] = -J_gen[15];
  J_pass[18] = 0.0;
  J_pass[24] = 0.0;
  J_pass[3] = 0.0;
  J_pass[9] = -J_gen[9];
  J_pass[15] = -J_gen[15];
  J_pass[21] = J_gen[18];
  J_pass[27] = J_gen[24];
  J_pass[1] = J_gen[7];
  J_pass[7] = -J_gen[10];
  J_pass[13] = -J_gen[16];
  J_pass[19] = 0.0;
  J_pass[25] = 0.0;
  J_pass[4] = 0.0;
  J_pass[10] = -J_gen[10];
  J_pass[16] = -J_gen[16];
  J_pass[22] = J_gen[19];
  J_pass[28] = J_gen[25];
  J_pass[2] = J_gen[8];
  J_pass[8] = t4;
  J_pass[14] = -J_gen[17];
  J_pass[20] = 0.0;
  J_pass[26] = 0.0;
  J_pass[5] = 0.0;
  J_pass[11] = t4;
  J_pass[17] = -J_gen[17];
  J_pass[23] = -t4;
  J_pass[29] = J_gen[26];
  p = true;
  for (br = 0; br < 30; br++) {
    X[br] = 0.0;
    if ((!p) || rtIsNaN(J_pass[br])) {
      p = false;
    }
  }

  if (!p) {
    for (i = 0; i < 30; i++) {
      X[i] = rtNaN;
    }
  } else {
    svd(J_pass, U, s, V);
    t8 = fabs(s[0]);
    if ((!rtIsInf(t8)) && (!rtIsNaN(t8))) {
      if (t8 <= 2.2250738585072014E-308) {
        t9 = 4.94065645841247E-324;
      } else {
        frexp(t8, &vcol);
        t9 = ldexp(1.0, vcol - 53);
      }
    } else {
      t9 = rtNaN;
    }

    t9 *= 6.0;
    r = -1;
    br = 0;
    while ((br < 5) && (s[br] > t9)) {
      r++;
      br++;
    }

    if (r + 1 > 0) {
      vcol = 1;
      for (p3 = 0; p3 <= r; p3++) {
        t8 = 1.0 / s[p3];
        i = vcol + 4;
        for (br = vcol; br <= i; br++) {
          V[br - 1] *= t8;
        }

        vcol += 5;
      }

      for (p3 = 0; p3 <= 25; p3 += 5) {
        i = p3 + 1;
        vcol = p3 + 5;
        if (i <= vcol) {
          memset(&X[i + -1], 0, ((vcol - i) + 1) * sizeof(double));
        }
      }

      br = 0;
      for (p3 = 0; p3 <= 25; p3 += 5) {
        ar = -1;
        br++;
        i = br + 6 * r;
        for (ib = br; ib <= i; ib += 6) {
          ia = ar;
          vcol = p3 + 1;
          i1 = p3 + 5;
          for (ic = vcol; ic <= i1; ic++) {
            ia++;
            X[ic - 1] += U[ib - 1] * V[ia];
          }

          ar += 5;
        }
      }
    }
  }

  /* J_EE */
  /*     J = J_EE(IN1) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:33:47 */
  t2 = cos(phi_ee[0]);
  t3 = cos(phi_ee[1]);
  t8 = sin(phi_ee[0]);
  J_end[4] = t2;
  J_end[5] = t8;
  t13 = sin(phi_ee[1]);
  J_end[6] = t13;
  J_end[7] = -t3 * t8;
  J_end[8] = t2 * t3;
  vcol = 3;
  p3 = 6;
  t9 = J_end[4];
  t6 = J_end[5];
  t7 = J_end[7] - 0.0 * J_end[6];
  t12 = J_end[8] - 0.0 * J_end[6];
  if (fabs(t6) > fabs(t9)) {
    vcol = 6;
    p3 = 3;
    t8 = t9;
    t9 = t6;
    t6 = t8;
    t8 = t7;
    t7 = t12;
    t12 = t8;
  }

  t6 /= t9;
  t12 -= t6 * t7;
  t3 = t6 * 0.0 / t12;
  t2 = -(t7 * t3) / t9;
  J_end[0] = (1.0 - 0.0 * t2) - t13 * t3;
  J_end[1] = t2;
  J_end[2] = t3;
  t3 = -t6 / t12;
  t2 = (1.0 - t7 * t3) / t9;
  J_end[vcol] = -(0.0 * t2 + t13 * t3);
  J_end[vcol + 1] = t2;
  J_end[vcol + 2] = t3;
  t3 = 1.0 / t12;
  t2 = -t7 * t3 / t9;
  J_end[p3] = -(0.0 * t2 + t13 * t3);
  J_end[p3 + 1] = t2;
  J_end[p3 + 2] = t3;
  for (i = 0; i < 30; i++) {
    X[i] = -X[i];
  }

  b_J_gen[0] = J_gen[0];
  b_J_gen[6] = J_gen[3];
  b_J_gen[12] = -J_gen[12];
  b_J_gen[18] = 0.0;
  b_J_gen[3] = 0.0;
  b_J_gen[9] = 0.0;
  b_J_gen[15] = -J_gen[12];
  b_J_gen[21] = J_gen[21];
  b_J_gen[1] = t10;
  b_J_gen[7] = J_gen[4];
  b_J_gen[13] = -J_gen[13];
  b_J_gen[19] = 0.0;
  b_J_gen[4] = 0.0;
  b_J_gen[10] = 0.0;
  b_J_gen[16] = -J_gen[13];
  b_J_gen[22] = J_gen[22];
  b_J_gen[2] = -t4;
  b_J_gen[8] = J_gen[5];
  b_J_gen[14] = -J_gen[14];
  b_J_gen[20] = 0.0;
  b_J_gen[5] = 0.0;
  b_J_gen[11] = 0.0;
  b_J_gen[17] = -J_gen[14];
  b_J_gen[23] = J_gen[23];
  for (i = 0; i < 5; i++) {
    for (vcol = 0; vcol < 4; vcol++) {
      t9 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        t9 += X[i + 5 * i1] * b_J_gen[i1 + 6 * vcol];
      }

      b_X[i + 5 * vcol] = t9;
    }
  }

  for (i = 0; i < 3; i++) {
    t9 = J_end[i + 3];
    t8 = J_end[i + 6];
    for (vcol = 0; vcol < 3; vcol++) {
      b_J[i + 3 * vcol] = (J_end[i] * J_gen[3 * vcol] + t9 * J_gen[3 * vcol + 1])
        + t8 * J_gen[3 * vcol + 2];
    }
  }

  dv[0] = 1.0;
  dv[1] = 0.0;
  dv[2] = b_X[0];
  dv[3] = 0.0;
  dv[4] = 1.0;
  dv[5] = b_X[5];
  dv[6] = 0.0;
  dv[7] = 0.0;
  dv[8] = b_X[10];
  dv[9] = 0.0;
  dv[10] = 0.0;
  dv[11] = b_X[15];
  for (i = 0; i < 3; i++) {
    t9 = b_J[i + 3];
    t8 = b_J[i + 6];
    for (vcol = 0; vcol < 4; vcol++) {
      J[i + 3 * vcol] = (b_J[i] * dv[3 * vcol] + t9 * dv[3 * vcol + 1]) + t8 *
        dv[3 * vcol + 2];
    }
  }
}

/*
 * File trailer for J_v2.c
 *
 * [EOF]
 */
