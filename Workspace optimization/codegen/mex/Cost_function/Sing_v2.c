/*
 * Sing_v2.c
 *
 * Code generation for function 'Sing_v2'
 *
 */

/* Include files */
#include "Sing_v2.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "Inverse_kinematics.h"
#include "J_leg.h"
#include "eps.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 10, /* lineNo */
  "Sing_v2",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v2.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 13, /* lineNo */
  "Sing_v2",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v2.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 21, /* lineNo */
  "Sing_v2",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v2.m"/* pathName */
};

/* Function Definitions */
void Sing_v2(const emlrtStack *sp, const real_T system_parameters[5], const
             real_T phi_ee[3], boolean_T *flag_ser, boolean_T *flag_par)
{
  int32_T i;
  real_T J_pass[30];
  real_T J_gen[27];
  real_T eta_i;
  real_T q[3];
  real_T J_i[9];
  int32_T irank;
  int32_T b_i;
  int32_T J_gen_tmp;
  boolean_T x[9];
  boolean_T p;
  boolean_T b_x[25];
  real_T S[25];
  real_T s[5];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;

  /*  Compute the matix for singularity checking in PSM which controlled by */
  /*  intermediate links actuators */
  /*  Created by Valeria Skvo */
  *flag_ser = false;
  for (i = 0; i < 3; i++) {
    eta_i = (((real_T)i + 1.0) - 1.0) * 2.0 / 3.0 * 3.1415926535897931;
    st.site = &nb_emlrtRSI;
    Inverse_kinematics(&st, eta_i, system_parameters, phi_ee, q);
    J_leg(eta_i, system_parameters, q, J_i);
    irank = 3 * i;
    for (b_i = 0; b_i < 3; b_i++) {
      J_gen_tmp = 3 * (b_i + irank);
      J_gen[J_gen_tmp] = J_i[3 * b_i];
      J_gen[J_gen_tmp + 1] = J_i[3 * b_i + 1];
      J_gen[J_gen_tmp + 2] = J_i[3 * b_i + 2];
    }

    for (irank = 0; irank < 9; irank++) {
      x[irank] = muDoubleScalarIsNaN(J_i[irank]);
    }

    eta_i = x[0];
    for (J_gen_tmp = 0; J_gen_tmp < 8; J_gen_tmp++) {
      eta_i += (real_T)x[J_gen_tmp + 1];
    }

    if (eta_i != 0.0) {
      *flag_ser = true;
    } else {
      st.site = &ob_emlrtRSI;
      b_st.site = &x_emlrtRSI;
      irank = 0;
      c_st.site = &y_emlrtRSI;
      p = true;
      for (J_gen_tmp = 0; J_gen_tmp < 9; J_gen_tmp++) {
        if ((!p) || (muDoubleScalarIsInf(J_i[J_gen_tmp]) || muDoubleScalarIsNaN
                     (J_i[J_gen_tmp]))) {
          p = false;
        }
      }

      if (p) {
        d_st.site = &bb_emlrtRSI;
        e_st.site = &cb_emlrtRSI;
        f_st.site = &db_emlrtRSI;
        g_st.site = &eb_emlrtRSI;
        xzsvdc(&g_st, J_i, q);
      } else {
        q[0] = rtNaN;
        q[1] = rtNaN;
        q[2] = rtNaN;
      }

      c_st.site = &ab_emlrtRSI;
      eta_i = 3.0 * eps(q[0]);
      J_gen_tmp = 0;
      while ((J_gen_tmp < 3) && (q[J_gen_tmp] > eta_i)) {
        irank++;
        J_gen_tmp++;
      }

      if (irank != 3) {
        *flag_ser = true;
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

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
  J_pass[8] = -J_gen[11];
  J_pass[14] = -J_gen[17];
  J_pass[20] = 0.0;
  J_pass[26] = 0.0;
  J_pass[5] = 0.0;
  J_pass[11] = -J_gen[11];
  J_pass[17] = -J_gen[17];
  J_pass[23] = J_gen[20];
  J_pass[29] = J_gen[26];
  for (irank = 0; irank < 5; irank++) {
    for (b_i = 0; b_i < 5; b_i++) {
      eta_i = 0.0;
      for (J_gen_tmp = 0; J_gen_tmp < 6; J_gen_tmp++) {
        eta_i += J_pass[J_gen_tmp + 6 * irank] * J_pass[J_gen_tmp + 6 * b_i];
      }

      S[irank + 5 * b_i] = eta_i;
    }
  }

  for (irank = 0; irank < 25; irank++) {
    b_x[irank] = muDoubleScalarIsNaN(S[irank]);
  }

  eta_i = b_x[0];
  for (J_gen_tmp = 0; J_gen_tmp < 24; J_gen_tmp++) {
    eta_i += (real_T)b_x[J_gen_tmp + 1];
  }

  if (eta_i != 0.0) {
    *flag_par = true;
  } else {
    st.site = &pb_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    irank = 0;
    c_st.site = &y_emlrtRSI;
    p = true;
    for (J_gen_tmp = 0; J_gen_tmp < 25; J_gen_tmp++) {
      if ((!p) || (muDoubleScalarIsInf(S[J_gen_tmp]) || muDoubleScalarIsNaN
                   (S[J_gen_tmp]))) {
        p = false;
      }
    }

    if (p) {
      d_st.site = &bb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      f_st.site = &db_emlrtRSI;
      g_st.site = &eb_emlrtRSI;
      c_xzsvdc(&g_st, S, s);
    } else {
      for (i = 0; i < 5; i++) {
        s[i] = rtNaN;
      }
    }

    c_st.site = &ab_emlrtRSI;
    eta_i = 5.0 * eps(s[0]);
    J_gen_tmp = 0;
    while ((J_gen_tmp < 5) && (s[J_gen_tmp] > eta_i)) {
      irank++;
      J_gen_tmp++;
    }

    if (irank != 5) {
      *flag_par = true;
    } else {
      *flag_par = false;
    }
  }
}

/* End of code generation (Sing_v2.c) */
