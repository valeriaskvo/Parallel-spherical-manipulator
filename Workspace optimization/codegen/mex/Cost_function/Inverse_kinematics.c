/*
 * Inverse_kinematics.c
 *
 * Code generation for function 'Inverse_kinematics'
 *
 */

/* Include files */
#include "Inverse_kinematics.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 8,   /* lineNo */
  "Inverse_kinematics",                /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 9,   /* lineNo */
  "Inverse_kinematics",                /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 10,  /* lineNo */
  "Inverse_kinematics",                /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 11,  /* lineNo */
  "Inverse_kinematics",                /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 17,  /* lineNo */
  "Inverse_kinematics",                /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 19,  /* lineNo */
  "Inverse_kinematics",                /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 40,  /* lineNo */
  "Inverse_kinematic_solver",          /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 42,  /* lineNo */
  "Inverse_kinematic_solver",          /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 89,  /* lineNo */
  "q3_find",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\q3_find.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 93,  /* lineNo */
  "q3_find",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\q3_find.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "acos",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elfun\\acos.m"/* pName */
};

/* Function Declarations */
static real_T Inverse_kinematic_solver(const emlrtStack *sp, real_T A, real_T B,
  real_T C, real_T mu_1);

/* Function Definitions */
static real_T Inverse_kinematic_solver(const emlrtStack *sp, real_T A, real_T B,
  real_T C, real_T mu_1)
{
  real_T theta;
  real_T x;
  real_T d;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((A == 0.0) && (B == 0.0)) {
    theta = rtInf;
  } else if (A == 0.0) {
    theta = 2.0 * muDoubleScalarAtan(-B / C);
  } else {
    x = B * B;
    d = 4.0 * A * C;
    if (x < d) {
      theta = rtInf;
    } else if (x == d) {
      theta = 2.0 * muDoubleScalarAtan(-B / (2.0 * A));
    } else if (mu_1 != 0.0) {
      st.site = &q_emlrtRSI;
      x = B * B - 4.0 * A * C;
      if (x < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      x = muDoubleScalarSqrt(x);
      theta = 2.0 * muDoubleScalarAtan((-B - x) / (2.0 * A));
    } else {
      st.site = &r_emlrtRSI;
      x -= d;
      if (x < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      x = muDoubleScalarSqrt(x);
      theta = 2.0 * muDoubleScalarAtan((-B + x) / (2.0 * A));
    }
  }

  return theta;
}

void Inverse_kinematics(const emlrtStack *sp, real_T eta_i, const real_T
  system_parameters[5], const real_T phi_ee[3], real_T q[3])
{
  real_T t2_tmp;
  real_T t3_tmp;
  real_T q_3;
  real_T t5_tmp;
  real_T t76;
  real_T t74;
  real_T t51;
  real_T t9_tmp;
  real_T t10_tmp;
  real_T t23;
  real_T t12_tmp;
  real_T t67;
  real_T t14_tmp;
  real_T t15_tmp;
  real_T t16_tmp;
  real_T q_1;
  real_T q_2;
  real_T t77;
  real_T t9;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t24;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  Compute each angles of joints in legs in PSM */
  /*  phi_ee=[phi_1; phi_2; phi_3] - Angles in XYZ Euler angles parametrization */
  /*  system_parameters=[beta_1; beta_2; alpha_1; alpha_2, system_radius] - Parameters of PSM */
  /*  Created by Valeria Skvo */
  /*  Step 1: Find the theta angle without translation part */
  st.site = &e_emlrtRSI;

  /* A_Q1 */
  /*     A_THETA = A_Q1(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:21:33 */
  t2_tmp = muDoubleScalarCos(system_parameters[2]);
  t3_tmp = muDoubleScalarCos(system_parameters[0]);
  q_3 = muDoubleScalarCos(system_parameters[1]);
  t5_tmp = muDoubleScalarCos(eta_i);
  t76 = muDoubleScalarCos(phi_ee[0]);
  t74 = muDoubleScalarCos(phi_ee[1]);
  t51 = muDoubleScalarCos(phi_ee[2]);
  t9_tmp = muDoubleScalarSin(system_parameters[2]);
  t10_tmp = muDoubleScalarSin(system_parameters[0]);
  t23 = muDoubleScalarSin(system_parameters[1]);
  t12_tmp = muDoubleScalarSin(eta_i);
  t67 = muDoubleScalarSin(phi_ee[0]);
  t14_tmp = muDoubleScalarSin(phi_ee[1]);
  t15_tmp = muDoubleScalarSin(phi_ee[2]);
  t16_tmp = t5_tmp * t5_tmp;
  st.site = &f_emlrtRSI;

  /* B_Q1 */
  /*     B_THETA = B_Q1(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:21:34 */
  st.site = &g_emlrtRSI;

  /* C_Q1 */
  /*     C_THETA = C_Q1(ETA_I,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     31-Mar-2020 18:21:35 */
  st.site = &h_emlrtRSI;
  q_1 = Inverse_kinematic_solver(&st,
    (((((((((((((((((((((((((((-muDoubleScalarCos(system_parameters[3]) - t2_tmp
    * t3_tmp * q_3 * t76 * t74) - q_3 * t76 * t74 * t9_tmp * t10_tmp) + t2_tmp *
    t74 * t51 * t10_tmp * t23) - t3_tmp * t74 * t51 * t9_tmp * t23) + t2_tmp *
    q_3 * t10_tmp * t12_tmp * t14_tmp) - t3_tmp * q_3 * t9_tmp * t12_tmp *
    t14_tmp) - t2_tmp * q_3 * t5_tmp * t74 * t10_tmp * t67) + t3_tmp * q_3 *
    t5_tmp * t74 * t9_tmp * t67) - t2_tmp * t3_tmp * t5_tmp * t51 * t23 * t67) +
                      t2_tmp * t76 * t51 * t10_tmp * t23 * t16_tmp) - t3_tmp *
                     t76 * t51 * t9_tmp * t23 * t16_tmp) - t2_tmp * t74 * t51 *
                    t10_tmp * t23 * t16_tmp) + t3_tmp * t74 * t51 * t9_tmp * t23
                   * t16_tmp) - t2_tmp * t3_tmp * t23 * t12_tmp * t67 * t15_tmp)
                 - t5_tmp * t51 * t9_tmp * t10_tmp * t23 * t67) - t9_tmp *
                t10_tmp * t23 * t12_tmp * t67 * t15_tmp) - t2_tmp * t3_tmp *
               t5_tmp * t76 * t23 * t14_tmp * t15_tmp) + t2_tmp * t3_tmp * t76 *
              t51 * t23 * t12_tmp * t14_tmp) + t2_tmp * t5_tmp * t76 * t10_tmp *
             t23 * t12_tmp * t15_tmp) - t3_tmp * t5_tmp * t76 * t9_tmp * t23 *
            t12_tmp * t15_tmp) - t2_tmp * t5_tmp * t74 * t10_tmp * t23 * t12_tmp
           * t15_tmp) + t3_tmp * t5_tmp * t74 * t9_tmp * t23 * t12_tmp * t15_tmp)
         - t5_tmp * t76 * t9_tmp * t10_tmp * t23 * t14_tmp * t15_tmp) + t76 *
        t51 * t9_tmp * t10_tmp * t23 * t12_tmp * t14_tmp) - t2_tmp * t10_tmp *
       t23 * t67 * t14_tmp * t15_tmp * t16_tmp) + t3_tmp * t9_tmp * t23 * t67 *
      t14_tmp * t15_tmp * t16_tmp) + t2_tmp * t5_tmp * t51 * t10_tmp * t23 *
     t12_tmp * t67 * t14_tmp) - t3_tmp * t5_tmp * t51 * t9_tmp * t23 * t12_tmp *
    t67 * t14_tmp, muDoubleScalarSin(system_parameters[2]) * (((((((((q_3 *
    t5_tmp * t14_tmp - t76 * t23 * t15_tmp) + q_3 * t74 * t12_tmp * t67) - t51 *
    t23 * t67 * t14_tmp) + t76 * t23 * t15_tmp * t16_tmp) - t74 * t23 * t15_tmp *
    t16_tmp) - t5_tmp * t76 * t51 * t23 * t12_tmp) + t5_tmp * t74 * t51 * t23 *
    t12_tmp) + t51 * t23 * t67 * t14_tmp * t16_tmp) + t5_tmp * t23 * t12_tmp *
    t67 * t14_tmp * t15_tmp) * 2.0,
    (((((((((((((((((((((((((((-muDoubleScalarCos(system_parameters[3]) - t2_tmp
    * t3_tmp * q_3 * t76 * t74) + q_3 * t76 * t74 * t9_tmp * t10_tmp) + t2_tmp *
    t74 * t51 * t10_tmp * t23) + t3_tmp * t74 * t51 * t9_tmp * t23) + t2_tmp *
    q_3 * t10_tmp * t12_tmp * t14_tmp) + t3_tmp * q_3 * t9_tmp * t12_tmp *
    t14_tmp) - t2_tmp * q_3 * t5_tmp * t74 * t10_tmp * t67) - t3_tmp * q_3 *
    t5_tmp * t74 * t9_tmp * t67) - t2_tmp * t3_tmp * t5_tmp * t51 * t23 * t67) +
                      t2_tmp * t76 * t51 * t10_tmp * t23 * t16_tmp) + t3_tmp *
                     t76 * t51 * t9_tmp * t23 * t16_tmp) - t2_tmp * t74 * t51 *
                    t10_tmp * t23 * t16_tmp) - t3_tmp * t74 * t51 * t9_tmp * t23
                   * t16_tmp) - t2_tmp * t3_tmp * t23 * t12_tmp * t67 * t15_tmp)
                 + t5_tmp * t51 * t9_tmp * t10_tmp * t23 * t67) + t9_tmp *
                t10_tmp * t23 * t12_tmp * t67 * t15_tmp) - t2_tmp * t3_tmp *
               t5_tmp * t76 * t23 * t14_tmp * t15_tmp) + t2_tmp * t3_tmp * t76 *
              t51 * t23 * t12_tmp * t14_tmp) + t2_tmp * t5_tmp * t76 * t10_tmp *
             t23 * t12_tmp * t15_tmp) + t3_tmp * t5_tmp * t76 * t9_tmp * t23 *
            t12_tmp * t15_tmp) - t2_tmp * t5_tmp * t74 * t10_tmp * t23 * t12_tmp
           * t15_tmp) - t3_tmp * t5_tmp * t74 * t9_tmp * t23 * t12_tmp * t15_tmp)
         + t5_tmp * t76 * t9_tmp * t10_tmp * t23 * t14_tmp * t15_tmp) - t76 *
        t51 * t9_tmp * t10_tmp * t23 * t12_tmp * t14_tmp) - t2_tmp * t10_tmp *
       t23 * t67 * t14_tmp * t15_tmp * t16_tmp) - t3_tmp * t9_tmp * t23 * t67 *
      t14_tmp * t15_tmp * t16_tmp) + t2_tmp * t5_tmp * t51 * t10_tmp * t23 *
     t12_tmp * t67 * t14_tmp) + t3_tmp * t5_tmp * t51 * t9_tmp * t23 * t12_tmp *
    t67 * t14_tmp, 0.0);
  if (q_1 != rtInf) {
    /* A_Q2 */
    /*     A_MU_1 = A_Q2(ETA_I,IN2,IN3,Q_1) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
    /*     31-Mar-2020 18:21:38 */
    q_3 = muDoubleScalarCos(system_parameters[3]);
    t16_tmp = muDoubleScalarCos(q_1);
    t23 = muDoubleScalarSin(system_parameters[3]);
    t77 = muDoubleScalarSin(q_1);

    /* B_Q2 */
    /*     B_MU_1 = B_Q2(ETA_I,IN2,IN3,Q_1) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
    /*     31-Mar-2020 18:21:39 */
    /* C_Q2 */
    /*     C_MU_1 = C_Q2(ETA_I,IN2,IN3,Q_1) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
    /*     31-Mar-2020 18:21:39 */
    st.site = &i_emlrtRSI;
    q_2 = Inverse_kinematic_solver(&st, (((((((((((((((-muDoubleScalarCos
      (system_parameters[1]) - t2_tmp * q_3 * t3_tmp * t76 * t74) - t3_tmp * t76
      * t74 * t9_tmp * t23) + t2_tmp * q_3 * t10_tmp * t12_tmp * t14_tmp) -
      t2_tmp * t5_tmp * t23 * t14_tmp * t77) + q_3 * t5_tmp * t9_tmp * t14_tmp *
      t77) + t9_tmp * t23 * t10_tmp * t12_tmp * t14_tmp) - t2_tmp * q_3 * t5_tmp
      * t74 * t10_tmp * t67) - t2_tmp * t76 * t74 * t16_tmp * t23 * t10_tmp) +
      q_3 * t76 * t74 * t16_tmp * t9_tmp * t10_tmp) - t2_tmp * t3_tmp * t16_tmp *
      t23 * t12_tmp * t14_tmp) + q_3 * t3_tmp * t16_tmp * t9_tmp * t12_tmp *
      t14_tmp) - t5_tmp * t74 * t9_tmp * t23 * t10_tmp * t67) - t2_tmp * t74 *
      t23 * t12_tmp * t67 * t77) + q_3 * t74 * t9_tmp * t12_tmp * t67 * t77) +
      t2_tmp * t3_tmp * t5_tmp * t74 * t16_tmp * t23 * t67) - q_3 * t3_tmp *
      t5_tmp * t74 * t16_tmp * t9_tmp * t67, muDoubleScalarSin
      (system_parameters[3]) * ((((t5_tmp * t16_tmp * t14_tmp + t74 * t16_tmp *
      t12_tmp * t67) - t3_tmp * t12_tmp * t14_tmp * t77) - t74 * t77 *
      muDoubleScalarCos(phi_ee[0]) * muDoubleScalarSin(system_parameters[0])) +
      t3_tmp * t5_tmp * t74 * t67 * t77) * 2.0,
      (((((((((((((((-muDoubleScalarCos(system_parameters[1]) - t2_tmp * q_3 *
                     t3_tmp * t76 * t74) + t3_tmp * t76 * t74 * t9_tmp * t23) +
                   t2_tmp * q_3 * t10_tmp * t12_tmp * t14_tmp) + t2_tmp * t5_tmp
                  * t23 * t14_tmp * t77) + q_3 * t5_tmp * t9_tmp * t14_tmp * t77)
                - t9_tmp * t23 * t10_tmp * t12_tmp * t14_tmp) - t2_tmp * q_3 *
               t5_tmp * t74 * t10_tmp * t67) + t2_tmp * t76 * t74 * t16_tmp *
              t23 * t10_tmp) + q_3 * t76 * t74 * t16_tmp * t9_tmp * t10_tmp) +
            t2_tmp * t3_tmp * t16_tmp * t23 * t12_tmp * t14_tmp) + q_3 * t3_tmp *
           t16_tmp * t9_tmp * t12_tmp * t14_tmp) + t5_tmp * t74 * t9_tmp * t23 *
          t10_tmp * t67) + t2_tmp * t74 * t23 * t12_tmp * t67 * t77) + q_3 * t74
        * t9_tmp * t12_tmp * t67 * t77) - t2_tmp * t3_tmp * t5_tmp * t74 *
       t16_tmp * t23 * t67) - q_3 * t3_tmp * t5_tmp * t74 * t16_tmp * t9_tmp *
      t67, 1.0);
    if (q_2 != rtInf) {
      st.site = &j_emlrtRSI;

      /* Q3_FIND */
      /*     Q_3 = Q3_FIND(ETA_I,IN2,IN3,Q_1,Q_2) */
      /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
      /*     31-Mar-2020 18:21:45 */
      t9 = muDoubleScalarCos(q_2);
      t17 = muDoubleScalarSin(q_2);
      t18 = t76 * t51;
      t19 = t5_tmp * t77;
      t20 = t16_tmp * t12_tmp;
      t21 = t76 * t15_tmp;
      t22 = t51 * t67;
      t23 = t12_tmp * t77;
      t24 = t67 * t15_tmp;
      q_3 = t5_tmp * t16_tmp;
      t51 = t5_tmp * t74 * t51 + t74 * t12_tmp * t15_tmp;
      t67 = t9 * t10_tmp * t77 + t17 * (t3_tmp * t9_tmp + t2_tmp * t16_tmp *
        t10_tmp);
      t77 = t9 * (q_3 + -(t3_tmp * t23)) + t17 * (t9_tmp * t10_tmp * t12_tmp -
        t2_tmp * (t19 + t3_tmp * t20));
      t74 = t5_tmp * (t21 + t14_tmp * t22) + -(t12_tmp * (t18 + -(t14_tmp * t24)));
      t76 = t9 * (t20 + t3_tmp * t19) + -(t17 * (t5_tmp * t9_tmp * t10_tmp +
        t2_tmp * (t23 + -(t3_tmp * q_3))));
      q_3 = t12_tmp * (t22 + t14_tmp * t21) - t5_tmp * (t24 + -(t14_tmp * t18));
      b_st.site = &t_emlrtRSI;
      t23 = (q_3 * q_3 + t51 * t51) + t74 * t74;
      if (t23 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      t23 = muDoubleScalarSqrt(t23);
      b_st.site = &t_emlrtRSI;
      t16_tmp = (t67 * t67 + t76 * t76) + t77 * t77;
      if (t16_tmp < 0.0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      t16_tmp = muDoubleScalarSqrt(t16_tmp);
      q_3 = -1.0 / t23 * ((t51 * t77 - t74 * t76) + t67 * q_3) / t16_tmp;
      if (muDoubleScalarAbs(q_3) > 1.0) {
        q_3 = muDoubleScalarSign(q_3);
      }

      b_st.site = &u_emlrtRSI;
      if ((q_3 < -1.0) || (q_3 > 1.0)) {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "acos");
      }

      q_3 = muDoubleScalarAcos(q_3) + -3.1415926535897931;
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

/* End of code generation (Inverse_kinematics.c) */
