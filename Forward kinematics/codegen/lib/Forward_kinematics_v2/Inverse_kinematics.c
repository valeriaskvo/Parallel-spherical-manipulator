/*
 * File: Inverse_kinematics.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "Inverse_kinematics.h"
#include "Forward_kinematics_v2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double Inverse_kinematic_solver(double A, double B, double C, double mu_1);

/* Function Definitions */

/*
 * Arguments    : double A
 *                double B
 *                double C
 *                double mu_1
 * Return Type  : double
 */
static double Inverse_kinematic_solver(double A, double B, double C, double mu_1)
{
  double theta;
  double d;
  double d1;
  if ((A == 0.0) && (B == 0.0)) {
    theta = rtInf;
  } else if (A == 0.0) {
    theta = 2.0 * atan(-B / C);
  } else {
    d = B * B;
    d1 = 4.0 * A * C;
    if (d < d1) {
      theta = rtInf;
    } else if (d == d1) {
      theta = 2.0 * atan(-B / (2.0 * A));
    } else if (mu_1 != 0.0) {
      theta = 2.0 * atan((-B - sqrt(B * B - 4.0 * A * C)) / (2.0 * A));
    } else {
      theta = 2.0 * atan((-B + sqrt(d - d1)) / (2.0 * A));
    }
  }

  return theta;
}

/*
 * Step 1: Find the theta angle without translation part
 * Arguments    : double eta_i
 *                const double system_parameters[5]
 *                const double phi_ee[3]
 *                double q[3]
 * Return Type  : void
 */
void Inverse_kinematics(double eta_i, const double system_parameters[5], const
  double phi_ee[3], double q[3])
{
  double t2_tmp;
  double t3_tmp;
  double t4_tmp;
  double t5_tmp;
  double t6_tmp;
  double t7_tmp;
  double t8_tmp;
  double t9_tmp;
  double t10_tmp;
  double q_3;
  double t12_tmp;
  double t13_tmp;
  double t14_tmp;
  double t15_tmp;
  double t77;
  double t74;
  double t67;
  double q_1_tmp_tmp;
  double q_1_tmp_tmp_tmp;
  double t51;
  double t24;
  double t22;
  double b_q_1_tmp_tmp;
  double t9;
  double t17;
  double t19;
  double c_q_1_tmp_tmp;
  double t20;
  double t21;
  double q_2;
  double d_q_1_tmp_tmp;
  double q_1_tmp;
  double e_q_1_tmp_tmp;
  double b_q_1_tmp;
  double c_q_1_tmp;
  double f_q_1_tmp_tmp;
  double q_1;
  double d_q_1_tmp;
  double g_q_1_tmp_tmp;
  double e_q_1_tmp;
  double f_q_1_tmp;
  double h_q_1_tmp_tmp;
  double g_q_1_tmp;
  double h_q_1_tmp;
  double i_q_1_tmp;

  /*  Compute each angles of joints in legs in PSM */
  /*  phi_ee=[phi_1; phi_2; phi_3] - Angles in XYZ Euler angles parametrization */
  /*  system_parameters=[beta_1; beta_2; alpha_1; alpha_2, system_radius] - Parameters of PSM */
  /*  Created by Valeria Skvo */
  /* A_Q1 */
  /*     A_THETA = A_Q1(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:21:33 */
  t2_tmp = cos(system_parameters[2]);
  t3_tmp = cos(system_parameters[0]);
  t4_tmp = cos(system_parameters[1]);
  t5_tmp = cos(eta_i);
  t6_tmp = cos(phi_ee[0]);
  t7_tmp = cos(phi_ee[1]);
  t8_tmp = cos(phi_ee[2]);
  t9_tmp = sin(system_parameters[2]);
  t10_tmp = sin(system_parameters[0]);
  q_3 = sin(system_parameters[1]);
  t12_tmp = sin(eta_i);
  t13_tmp = sin(phi_ee[0]);
  t14_tmp = sin(phi_ee[1]);
  t15_tmp = sin(phi_ee[2]);
  t77 = t5_tmp * t5_tmp;

  /* B_Q1 */
  /*     B_THETA = B_Q1(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:21:34 */
  /* C_Q1 */
  /*     C_THETA = C_Q1(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:21:35 */
  t74 = t2_tmp * t4_tmp;
  t67 = t3_tmp * t4_tmp;
  q_1_tmp_tmp = t2_tmp * t3_tmp;
  q_1_tmp_tmp_tmp = t2_tmp * t7_tmp;
  t51 = q_1_tmp_tmp_tmp * t8_tmp * t10_tmp * q_3;
  t24 = t3_tmp * t7_tmp * t8_tmp * t9_tmp * q_3;
  t22 = q_1_tmp_tmp * t5_tmp;
  b_q_1_tmp_tmp = t2_tmp * t5_tmp;
  t9 = t3_tmp * t5_tmp;
  t17 = t6_tmp * q_3 * t15_tmp;
  t19 = t8_tmp * q_3 * t13_tmp * t14_tmp;
  c_q_1_tmp_tmp = cos(system_parameters[3]);
  t20 = q_1_tmp_tmp * t5_tmp;
  t21 = t5_tmp * t6_tmp;
  q_2 = t4_tmp * t6_tmp * t7_tmp * t9_tmp * t10_tmp;
  d_q_1_tmp_tmp = t2_tmp * t6_tmp;
  q_1_tmp = d_q_1_tmp_tmp * t8_tmp * t10_tmp * q_3;
  e_q_1_tmp_tmp = t3_tmp * t6_tmp;
  b_q_1_tmp = e_q_1_tmp_tmp * t8_tmp * t9_tmp * q_3;
  c_q_1_tmp = t5_tmp * t8_tmp * t9_tmp * t10_tmp * q_3 * t13_tmp;
  f_q_1_tmp_tmp = t9_tmp * t10_tmp;
  q_1 = f_q_1_tmp_tmp * q_3 * t12_tmp * t13_tmp * t15_tmp;
  d_q_1_tmp = t21 * t9_tmp * t10_tmp * q_3 * t14_tmp * t15_tmp;
  g_q_1_tmp_tmp = t6_tmp * t8_tmp;
  e_q_1_tmp = g_q_1_tmp_tmp * t9_tmp * t10_tmp * q_3 * t12_tmp * t14_tmp;
  f_q_1_tmp = t2_tmp * t10_tmp * q_3 * t13_tmp * t14_tmp * t15_tmp;
  h_q_1_tmp_tmp = t3_tmp * t9_tmp;
  g_q_1_tmp = h_q_1_tmp_tmp * q_3 * t13_tmp * t14_tmp * t15_tmp;
  h_q_1_tmp = t5_tmp * t7_tmp;
  i_q_1_tmp = h_q_1_tmp * t8_tmp;
  q_1 = Inverse_kinematic_solver((((((((((((((((((((((((((((-c_q_1_tmp_tmp -
    q_1_tmp_tmp * t4_tmp * t6_tmp * t7_tmp) - q_2) + t51) - t24) + t74 * t10_tmp
    * t12_tmp * t14_tmp) - t67 * t9_tmp * t12_tmp * t14_tmp) - t74 * t5_tmp *
    t7_tmp * t10_tmp * t13_tmp) + t67 * t5_tmp * t7_tmp * t9_tmp * t13_tmp) -
    t22 * t8_tmp * q_3 * t13_tmp) + q_1_tmp * t77) - b_q_1_tmp * t77) - t51 *
    t77) + t24 * t77) - q_1_tmp_tmp * q_3 * t12_tmp * t13_tmp * t15_tmp) -
    c_q_1_tmp) - q_1) - t22 * t6_tmp * q_3 * t14_tmp * t15_tmp) + q_1_tmp_tmp *
    t6_tmp * t8_tmp * q_3 * t12_tmp * t14_tmp) + b_q_1_tmp_tmp * t6_tmp *
    t10_tmp * q_3 * t12_tmp * t15_tmp) - t9 * t6_tmp * t9_tmp * q_3 * t12_tmp *
    t15_tmp) - b_q_1_tmp_tmp * t7_tmp * t10_tmp * q_3 * t12_tmp * t15_tmp) + t9 *
    t7_tmp * t9_tmp * q_3 * t12_tmp * t15_tmp) - d_q_1_tmp) + e_q_1_tmp) -
    f_q_1_tmp * t77) + g_q_1_tmp * t77) + b_q_1_tmp_tmp * t8_tmp * t10_tmp * q_3
    * t12_tmp * t13_tmp * t14_tmp) - t9 * t8_tmp * t9_tmp * q_3 * t12_tmp *
    t13_tmp * t14_tmp, t9_tmp * (((((((((t4_tmp * t5_tmp * t14_tmp - t17) +
    t4_tmp * t7_tmp * t12_tmp * t13_tmp) - t19) + t17 * t77) - t7_tmp * q_3 *
    t15_tmp * t77) - t21 * t8_tmp * q_3 * t12_tmp) + i_q_1_tmp * q_3 * t12_tmp)
    + t19 * t77) + t5_tmp * q_3 * t12_tmp * t13_tmp * t14_tmp * t15_tmp) * 2.0,
    (((((((((((((((((((((((((((-c_q_1_tmp_tmp - q_1_tmp_tmp * t4_tmp * t6_tmp *
    t7_tmp) + q_2) + t51) + t24) + t74 * t10_tmp * t12_tmp * t14_tmp) + t67 *
    t9_tmp * t12_tmp * t14_tmp) - t74 * t5_tmp * t7_tmp * t10_tmp * t13_tmp) -
    t67 * t5_tmp * t7_tmp * t9_tmp * t13_tmp) - t20 * t8_tmp * q_3 * t13_tmp) +
                      q_1_tmp * t77) + b_q_1_tmp * t77) - t51 * t77) - t24 * t77)
                  - q_1_tmp_tmp * q_3 * t12_tmp * t13_tmp * t15_tmp) + c_q_1_tmp)
                + q_1) - t20 * t6_tmp * q_3 * t14_tmp * t15_tmp) + q_1_tmp_tmp *
              t6_tmp * t8_tmp * q_3 * t12_tmp * t14_tmp) + b_q_1_tmp_tmp *
             t6_tmp * t10_tmp * q_3 * t12_tmp * t15_tmp) + t9 * t6_tmp * t9_tmp *
            q_3 * t12_tmp * t15_tmp) - b_q_1_tmp_tmp * t7_tmp * t10_tmp * q_3 *
           t12_tmp * t15_tmp) - t9 * t7_tmp * t9_tmp * q_3 * t12_tmp * t15_tmp)
         + d_q_1_tmp) - e_q_1_tmp) - f_q_1_tmp * t77) - g_q_1_tmp * t77) +
     b_q_1_tmp_tmp * t8_tmp * t10_tmp * q_3 * t12_tmp * t13_tmp * t14_tmp) + t9 *
    t8_tmp * t9_tmp * q_3 * t12_tmp * t13_tmp * t14_tmp, 0.0);
  if (q_1 != rtInf) {
    /* A_Q2 */
    /*     A_MU_1 = A_Q2(ETA_I,IN2,IN3,Q_1) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
    /*     31-Mar-2020 18:21:38 */
    b_q_1_tmp = cos(q_1);
    t19 = sin(system_parameters[3]);
    c_q_1_tmp = sin(q_1);

    /* B_Q2 */
    /*     B_MU_1 = B_Q2(ETA_I,IN2,IN3,Q_1) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
    /*     31-Mar-2020 18:21:39 */
    /* C_Q2 */
    /*     C_MU_1 = C_Q2(ETA_I,IN2,IN3,Q_1) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
    /*     31-Mar-2020 18:21:39 */
    t20 = t2_tmp * c_q_1_tmp_tmp;
    t21 = c_q_1_tmp_tmp * t3_tmp;
    t17 = e_q_1_tmp_tmp * t7_tmp * t9_tmp * t19;
    t24 = b_q_1_tmp_tmp * t19 * t14_tmp * c_q_1_tmp;
    t22 = c_q_1_tmp_tmp * t5_tmp * t9_tmp * t14_tmp * c_q_1_tmp;
    t9 = t9_tmp * t19 * t10_tmp * t12_tmp * t14_tmp;
    t67 = d_q_1_tmp_tmp * t7_tmp * b_q_1_tmp * t19 * t10_tmp;
    t51 = c_q_1_tmp_tmp * t6_tmp * t7_tmp * b_q_1_tmp * t9_tmp * t10_tmp;
    t74 = h_q_1_tmp * t9_tmp * t19 * t10_tmp * t13_tmp;
    t77 = q_1_tmp_tmp_tmp * t19 * t12_tmp * t13_tmp * c_q_1_tmp;
    q_3 = c_q_1_tmp_tmp * t7_tmp * t9_tmp * t12_tmp * t13_tmp * c_q_1_tmp;
    q_1_tmp = t5_tmp * b_q_1_tmp;
    q_2 = Inverse_kinematic_solver((((((((((((((((-t4_tmp - t20 * t3_tmp *
      t6_tmp * t7_tmp) - t17) + t20 * t10_tmp * t12_tmp * t14_tmp) - t24) + t22)
      + t9) - t20 * t5_tmp * t7_tmp * t10_tmp * t13_tmp) - t67) + t51) -
      q_1_tmp_tmp * b_q_1_tmp * t19 * t12_tmp * t14_tmp) + t21 * b_q_1_tmp *
      t9_tmp * t12_tmp * t14_tmp) - t74) - t77) + q_3) + q_1_tmp_tmp * t5_tmp *
      t7_tmp * b_q_1_tmp * t19 * t13_tmp) - t21 * t5_tmp * t7_tmp * b_q_1_tmp *
      t9_tmp * t13_tmp, t19 * ((((q_1_tmp * t14_tmp + t7_tmp * b_q_1_tmp *
      t12_tmp * t13_tmp) - t3_tmp * t12_tmp * t14_tmp * c_q_1_tmp) - t7_tmp *
      c_q_1_tmp * t6_tmp * t10_tmp) + t3_tmp * t5_tmp * t7_tmp * t13_tmp *
      c_q_1_tmp) * 2.0, (((((((((((((((-cos(system_parameters[1]) - t20 * t3_tmp
      * t6_tmp * t7_tmp) + t17) + t20 * t10_tmp * t12_tmp * t14_tmp) + t24) +
      t22) - t9) - t20 * t5_tmp * t7_tmp * t10_tmp * t13_tmp) + t67) + t51) +
      q_1_tmp_tmp * b_q_1_tmp * t19 * t12_tmp * t14_tmp) + t21 * b_q_1_tmp *
      t9_tmp * t12_tmp * t14_tmp) + t74) + t77) + q_3) - q_1_tmp_tmp * t5_tmp *
                         t7_tmp * b_q_1_tmp * t19 * t13_tmp) - t21 * t5_tmp *
      t7_tmp * b_q_1_tmp * t9_tmp * t13_tmp, 1.0);
    if (q_2 != rtInf) {
      /* Q3_FIND */
      /*     Q_3 = Q3_FIND(ETA_I,IN2,IN3,Q_1,Q_2) */
      /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
      /*     31-Mar-2020 18:21:45 */
      t9 = cos(q_2);
      t17 = sin(q_2);
      t19 = t5_tmp * c_q_1_tmp;
      t20 = b_q_1_tmp * t12_tmp;
      t21 = t6_tmp * t15_tmp;
      t22 = t8_tmp * t13_tmp;
      q_3 = t12_tmp * c_q_1_tmp;
      t24 = t13_tmp * t15_tmp;
      t51 = i_q_1_tmp + t7_tmp * t12_tmp * t15_tmp;
      t67 = t9 * t10_tmp * c_q_1_tmp + t17 * (h_q_1_tmp_tmp + t2_tmp * b_q_1_tmp
        * t10_tmp);
      t77 = t9 * (q_1_tmp + -(t3_tmp * q_3)) + t17 * (f_q_1_tmp_tmp * t12_tmp -
        t2_tmp * (t19 + t3_tmp * t20));
      t74 = t5_tmp * (t21 + t14_tmp * t22) + -(t12_tmp * (g_q_1_tmp_tmp +
        -(t14_tmp * t24)));
      t9 = t9 * (t20 + t3_tmp * t19) + -(t17 * (t5_tmp * t9_tmp * t10_tmp +
        t2_tmp * (q_3 + -(t3_tmp * q_1_tmp))));
      q_3 = t12_tmp * (t22 + t14_tmp * t21) - t5_tmp * (t24 + -(t14_tmp *
        g_q_1_tmp_tmp));
      q_3 = -1.0 / sqrt((q_3 * q_3 + t51 * t51) + t74 * t74) * ((t51 * t77 - t74
        * t9) + t67 * q_3) / sqrt((t67 * t67 + t9 * t9) + t77 * t77);
      if (fabs(q_3) > 1.0) {
        if (q_3 < 0.0) {
          q_3 = -1.0;
        } else if (q_3 > 0.0) {
          q_3 = 1.0;
        } else {
          if (q_3 == 0.0) {
            q_3 = 0.0;
          }
        }
      }

      q_3 = acos(q_3) + -3.1415926535897931;
    } else {
      q_3 = rtInf;
    }
  } else {
    q_2 = rtInf;
    q_3 = rtInf;
  }

  q[0] = q_1;
  q[1] = q_2;
  q[2] = q_3;
}

/*
 * File trailer for Inverse_kinematics.c
 *
 * [EOF]
 */
