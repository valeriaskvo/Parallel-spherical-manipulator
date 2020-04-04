/*
 * Cost_function.c
 *
 * Code generation for function 'Cost_function'
 *
 */

/* Include files */
#include "Cost_function.h"
#include "Collision_check.h"
#include "Cost_function_data.h"
#include "Cost_function_emxutil.h"
#include "Inverse_kinematics.h"
#include "J_leg.h"
#include "eps.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 5,     /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 6,   /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 7,   /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 9,   /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 10,  /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 103, /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 288, /* lineNo */
  "eml_float_colon",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 26,  /* lineNo */
  "Calculate_extreme_angle",           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 28,  /* lineNo */
  "Calculate_extreme_angle",           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 30,  /* lineNo */
  "Calculate_extreme_angle",           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 10,  /* lineNo */
  "Sing_v1",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v1.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 13,  /* lineNo */
  "Sing_v1",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v1.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 21,  /* lineNo */
  "Sing_v1",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v1.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 11, /* lineNo */
  "rank",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 20, /* lineNo */
  "local_rank",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 22, /* lineNo */
  "local_rank",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 15, /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 29, /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 101,/* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 34, /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 10, /* lineNo */
  "Sing_v2",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v2.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 13, /* lineNo */
  "Sing_v2",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v2.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 21, /* lineNo */
  "Sing_v2",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v2.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 405, /* lineNo */
  15,                                  /* colNo */
  "assert_pmaxsize",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  19,                                  /* colNo */
  "angles",                            /* aName */
  "Calculate_extreme_angle",           /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  17,                                  /* colNo */
  "angles",                            /* aName */
  "Calculate_extreme_angle",           /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  23,                                  /* colNo */
  "angles",                            /* aName */
  "Calculate_extreme_angle",           /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 5, /* lineNo */
  1,                                   /* colNo */
  "Cost_function",                     /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 9, /* lineNo */
  43,                                  /* colNo */
  "Cost_function",                     /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 10,/* lineNo */
  43,                                  /* colNo */
  "Cost_function",                     /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 103,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

/* Function Declarations */
static real_T Calculate_extreme_angle(const emlrtStack *sp, const
  emxArray_real_T *angles, boolean_T x, const real_T system_parameters[5],
  real_T allowed_radius, real_T version);

/* Function Definitions */
static real_T Calculate_extreme_angle(const emlrtStack *sp, const
  emxArray_real_T *angles, boolean_T x, const real_T system_parameters[5],
  real_T allowed_radius, real_T version)
{
  real_T extreme_angle;
  int32_T i;
  boolean_T exitg1;
  real_T phi_ee[3];
  boolean_T flag_ser;
  int32_T b_i;
  real_T J_pass[30];
  real_T J_gen[27];
  real_T eta_i;
  real_T b_J_pass[36];
  real_T q[3];
  real_T J_i[9];
  int32_T irank;
  int32_T c_i;
  int32_T J_gen_tmp;
  boolean_T b_x[9];
  boolean_T flag_par;
  boolean_T c_x[25];
  real_T S[25];
  boolean_T d_x[36];
  real_T b_S[36];
  boolean_T flag;
  real_T s[5];
  real_T c_S[25];
  real_T b_s[6];
  real_T d_S[36];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  extreme_angle = 0.0;
  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i - 1 <= angles->size[1] - 1)) {
    if (x) {
      if ((i < 1) || (i > angles->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, angles->size[1], &b_emlrtBCI, sp);
      }

      phi_ee[0] = angles->data[i - 1];
      phi_ee[1] = 0.0;
      phi_ee[2] = 0.0;
    } else {
      phi_ee[0] = 0.0;
      if ((i < 1) || (i > angles->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, angles->size[1], &emlrtBCI, sp);
      }

      phi_ee[1] = angles->data[i - 1];
      phi_ee[2] = 0.0;
    }

    if (version == 1.0) {
      st.site = &h_emlrtRSI;

      /*  Compute the matix for singularity checking in PSM which controlled by low */
      /*  links actuators */
      /*  Created by Valeria Skvo */
      flag_ser = false;
      for (b_i = 0; b_i < 3; b_i++) {
        eta_i = (((real_T)b_i + 1.0) - 1.0) * 2.0 / 3.0 * 3.1415926535897931;
        b_st.site = &k_emlrtRSI;
        Inverse_kinematics(&b_st, eta_i, system_parameters, phi_ee, q);
        J_leg(eta_i, system_parameters, q, J_i);
        irank = 3 * b_i;
        for (c_i = 0; c_i < 3; c_i++) {
          J_gen_tmp = 3 * (c_i + irank);
          J_gen[J_gen_tmp] = J_i[3 * c_i];
          J_gen[J_gen_tmp + 1] = J_i[3 * c_i + 1];
          J_gen[J_gen_tmp + 2] = J_i[3 * c_i + 2];
        }

        for (irank = 0; irank < 9; irank++) {
          b_x[irank] = muDoubleScalarIsNaN(J_i[irank]);
        }

        eta_i = b_x[0];
        for (J_gen_tmp = 0; J_gen_tmp < 8; J_gen_tmp++) {
          eta_i += (real_T)b_x[J_gen_tmp + 1];
        }

        if (eta_i != 0.0) {
          flag_ser = true;
        } else {
          b_st.site = &l_emlrtRSI;
          c_st.site = &gb_emlrtRSI;
          irank = 0;
          d_st.site = &hb_emlrtRSI;
          flag_par = true;
          for (J_gen_tmp = 0; J_gen_tmp < 9; J_gen_tmp++) {
            if ((!flag_par) || (muDoubleScalarIsInf(J_i[J_gen_tmp]) ||
                                muDoubleScalarIsNaN(J_i[J_gen_tmp]))) {
              flag_par = false;
            }
          }

          if (flag_par) {
            e_st.site = &jb_emlrtRSI;
            f_st.site = &kb_emlrtRSI;
            g_st.site = &lb_emlrtRSI;
            h_st.site = &mb_emlrtRSI;
            xzsvdc(&h_st, J_i, q);
          } else {
            q[0] = rtNaN;
            q[1] = rtNaN;
            q[2] = rtNaN;
          }

          d_st.site = &ib_emlrtRSI;
          eta_i = 3.0 * eps(q[0]);
          J_gen_tmp = 0;
          while ((J_gen_tmp < 3) && (q[J_gen_tmp] > eta_i)) {
            irank++;
            J_gen_tmp++;
          }

          if (irank != 3) {
            flag_ser = true;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_J_pass[0] = J_gen[3];
      b_J_pass[6] = J_gen[6];
      b_J_pass[12] = -J_gen[12];
      b_J_pass[18] = -J_gen[15];
      b_J_pass[24] = 0.0;
      b_J_pass[30] = 0.0;
      b_J_pass[3] = 0.0;
      b_J_pass[9] = 0.0;
      b_J_pass[15] = -J_gen[12];
      b_J_pass[21] = -J_gen[15];
      b_J_pass[27] = J_gen[21];
      b_J_pass[33] = J_gen[24];
      b_J_pass[1] = J_gen[4];
      b_J_pass[7] = J_gen[7];
      b_J_pass[13] = -J_gen[13];
      b_J_pass[19] = -J_gen[16];
      b_J_pass[25] = 0.0;
      b_J_pass[31] = 0.0;
      b_J_pass[4] = 0.0;
      b_J_pass[10] = 0.0;
      b_J_pass[16] = -J_gen[13];
      b_J_pass[22] = -J_gen[16];
      b_J_pass[28] = J_gen[22];
      b_J_pass[34] = J_gen[25];
      b_J_pass[2] = J_gen[5];
      b_J_pass[8] = J_gen[8];
      b_J_pass[14] = -J_gen[14];
      b_J_pass[20] = -J_gen[17];
      b_J_pass[26] = 0.0;
      b_J_pass[32] = 0.0;
      b_J_pass[5] = 0.0;
      b_J_pass[11] = 0.0;
      b_J_pass[17] = -J_gen[14];
      b_J_pass[23] = -J_gen[17];
      b_J_pass[29] = J_gen[23];
      b_J_pass[35] = J_gen[26];
      for (irank = 0; irank < 6; irank++) {
        for (c_i = 0; c_i < 6; c_i++) {
          eta_i = 0.0;
          for (J_gen_tmp = 0; J_gen_tmp < 6; J_gen_tmp++) {
            eta_i += b_J_pass[J_gen_tmp + 6 * irank] * b_J_pass[J_gen_tmp + 6 *
              c_i];
          }

          b_S[irank + 6 * c_i] = eta_i;
        }
      }

      for (irank = 0; irank < 36; irank++) {
        d_x[irank] = muDoubleScalarIsNaN(b_S[irank]);
      }

      eta_i = d_x[0];
      for (J_gen_tmp = 0; J_gen_tmp < 35; J_gen_tmp++) {
        eta_i += (real_T)d_x[J_gen_tmp + 1];
      }

      if (eta_i != 0.0) {
        flag_par = true;
      } else {
        b_st.site = &m_emlrtRSI;
        c_st.site = &gb_emlrtRSI;
        irank = 0;
        d_st.site = &hb_emlrtRSI;
        flag_par = true;
        for (J_gen_tmp = 0; J_gen_tmp < 36; J_gen_tmp++) {
          if ((!flag_par) || (muDoubleScalarIsInf(b_S[J_gen_tmp]) ||
                              muDoubleScalarIsNaN(b_S[J_gen_tmp]))) {
            flag_par = false;
          }
        }

        if (flag_par) {
          e_st.site = &jb_emlrtRSI;
          f_st.site = &kb_emlrtRSI;
          g_st.site = &lb_emlrtRSI;
          memcpy(&d_S[0], &b_S[0], 36U * sizeof(real_T));
          h_st.site = &mb_emlrtRSI;
          b_xzsvdc(&h_st, d_S, b_s);
        } else {
          for (b_i = 0; b_i < 6; b_i++) {
            b_s[b_i] = rtNaN;
          }
        }

        d_st.site = &ib_emlrtRSI;
        eta_i = 6.0 * eps(b_s[0]);
        J_gen_tmp = 0;
        while ((J_gen_tmp < 6) && (b_s[J_gen_tmp] > eta_i)) {
          irank++;
          J_gen_tmp++;
        }

        if (irank != 6) {
          flag_par = true;
        } else {
          flag_par = false;
        }
      }
    } else {
      st.site = &i_emlrtRSI;

      /*  Compute the matix for singularity checking in PSM which controlled by */
      /*  intermediate links actuators */
      /*  Created by Valeria Skvo */
      flag_ser = false;
      for (b_i = 0; b_i < 3; b_i++) {
        eta_i = (((real_T)b_i + 1.0) - 1.0) * 2.0 / 3.0 * 3.1415926535897931;
        b_st.site = &vb_emlrtRSI;
        Inverse_kinematics(&b_st, eta_i, system_parameters, phi_ee, q);
        J_leg(eta_i, system_parameters, q, J_i);
        irank = 3 * b_i;
        for (c_i = 0; c_i < 3; c_i++) {
          J_gen_tmp = 3 * (c_i + irank);
          J_gen[J_gen_tmp] = J_i[3 * c_i];
          J_gen[J_gen_tmp + 1] = J_i[3 * c_i + 1];
          J_gen[J_gen_tmp + 2] = J_i[3 * c_i + 2];
        }

        for (irank = 0; irank < 9; irank++) {
          b_x[irank] = muDoubleScalarIsNaN(J_i[irank]);
        }

        eta_i = b_x[0];
        for (J_gen_tmp = 0; J_gen_tmp < 8; J_gen_tmp++) {
          eta_i += (real_T)b_x[J_gen_tmp + 1];
        }

        if (eta_i != 0.0) {
          flag_ser = true;
        } else {
          b_st.site = &wb_emlrtRSI;
          c_st.site = &gb_emlrtRSI;
          irank = 0;
          d_st.site = &hb_emlrtRSI;
          flag_par = true;
          for (J_gen_tmp = 0; J_gen_tmp < 9; J_gen_tmp++) {
            if ((!flag_par) || (muDoubleScalarIsInf(J_i[J_gen_tmp]) ||
                                muDoubleScalarIsNaN(J_i[J_gen_tmp]))) {
              flag_par = false;
            }
          }

          if (flag_par) {
            e_st.site = &jb_emlrtRSI;
            f_st.site = &kb_emlrtRSI;
            g_st.site = &lb_emlrtRSI;
            h_st.site = &mb_emlrtRSI;
            xzsvdc(&h_st, J_i, q);
          } else {
            q[0] = rtNaN;
            q[1] = rtNaN;
            q[2] = rtNaN;
          }

          d_st.site = &ib_emlrtRSI;
          eta_i = 3.0 * eps(q[0]);
          J_gen_tmp = 0;
          while ((J_gen_tmp < 3) && (q[J_gen_tmp] > eta_i)) {
            irank++;
            J_gen_tmp++;
          }

          if (irank != 3) {
            flag_ser = true;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
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
        for (c_i = 0; c_i < 5; c_i++) {
          eta_i = 0.0;
          for (J_gen_tmp = 0; J_gen_tmp < 6; J_gen_tmp++) {
            eta_i += J_pass[J_gen_tmp + 6 * irank] * J_pass[J_gen_tmp + 6 * c_i];
          }

          S[irank + 5 * c_i] = eta_i;
        }
      }

      for (irank = 0; irank < 25; irank++) {
        c_x[irank] = muDoubleScalarIsNaN(S[irank]);
      }

      eta_i = c_x[0];
      for (J_gen_tmp = 0; J_gen_tmp < 24; J_gen_tmp++) {
        eta_i += (real_T)c_x[J_gen_tmp + 1];
      }

      if (eta_i != 0.0) {
        flag_par = true;
      } else {
        b_st.site = &xb_emlrtRSI;
        c_st.site = &gb_emlrtRSI;
        irank = 0;
        d_st.site = &hb_emlrtRSI;
        flag_par = true;
        for (J_gen_tmp = 0; J_gen_tmp < 25; J_gen_tmp++) {
          if ((!flag_par) || (muDoubleScalarIsInf(S[J_gen_tmp]) ||
                              muDoubleScalarIsNaN(S[J_gen_tmp]))) {
            flag_par = false;
          }
        }

        if (flag_par) {
          e_st.site = &jb_emlrtRSI;
          f_st.site = &kb_emlrtRSI;
          g_st.site = &lb_emlrtRSI;
          memcpy(&c_S[0], &S[0], 25U * sizeof(real_T));
          h_st.site = &mb_emlrtRSI;
          c_xzsvdc(&h_st, c_S, s);
        } else {
          for (b_i = 0; b_i < 5; b_i++) {
            s[b_i] = rtNaN;
          }
        }

        d_st.site = &ib_emlrtRSI;
        eta_i = 5.0 * eps(s[0]);
        J_gen_tmp = 0;
        while ((J_gen_tmp < 5) && (s[J_gen_tmp] > eta_i)) {
          irank++;
          J_gen_tmp++;
        }

        if (irank != 5) {
          flag_par = true;
        } else {
          flag_par = false;
        }
      }
    }

    st.site = &j_emlrtRSI;
    flag = Collision_check(&st, system_parameters, phi_ee, allowed_radius);
    if (flag || flag_ser || flag_par) {
      if (i > angles->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, angles->size[1], &c_emlrtBCI, sp);
      }

      extreme_angle = angles->data[i - 1];
      exitg1 = true;
    } else {
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  return extreme_angle;
}

real_T Cost_function(const emlrtStack *sp, const real_T x[3], real_T
                     system_parameters[5], real_T step, real_T allowed_radius,
                     real_T version)
{
  real_T cost;
  emxArray_real_T *angles;
  int32_T i;
  real_T ndbl;
  real_T apnd;
  int32_T nm1d2;
  emxArray_real_T *b_angles;
  real_T cdiff;
  int32_T n;
  real_T extreme_angles_idx_3;
  real_T varargin_1[4];
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  system_parameters[1] = x[0];
  system_parameters[2] = x[1];
  system_parameters[3] = x[2];
  st.site = &emlrtRSI;
  emxInit_real_T(&st, &angles, 2, &f_emlrtRTEI, true);
  if (muDoubleScalarIsNaN(step)) {
    i = angles->size[0] * angles->size[1];
    angles->size[0] = 1;
    angles->size[1] = 1;
    emxEnsureCapacity_real_T(&st, angles, i, &f_emlrtRTEI);
    angles->data[0] = rtNaN;
  } else if ((step == 0.0) || (step < 0.0)) {
    angles->size[0] = 1;
    angles->size[1] = 0;
  } else if (muDoubleScalarIsInf(step)) {
    i = angles->size[0] * angles->size[1];
    angles->size[0] = 1;
    angles->size[1] = 1;
    emxEnsureCapacity_real_T(&st, angles, i, &f_emlrtRTEI);
    angles->data[0] = 0.0;
  } else if (muDoubleScalarFloor(step) == step) {
    i = angles->size[0] * angles->size[1];
    angles->size[0] = 1;
    nm1d2 = (int32_T)muDoubleScalarFloor(1.5707963267948966 / step);
    angles->size[1] = nm1d2 + 1;
    emxEnsureCapacity_real_T(&st, angles, i, &f_emlrtRTEI);
    for (i = 0; i <= nm1d2; i++) {
      angles->data[i] = step * (real_T)i;
    }
  } else {
    b_st.site = &f_emlrtRSI;
    ndbl = muDoubleScalarFloor(1.5707963267948966 / step + 0.5);
    apnd = ndbl * step;
    if (step > 0.0) {
      cdiff = apnd - 1.5707963267948966;
    } else {
      cdiff = 1.5707963267948966 - apnd;
    }

    if (muDoubleScalarAbs(cdiff) < 6.9757369960172635E-16) {
      ndbl++;
      apnd = 1.5707963267948966;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * step;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }

    c_st.site = &g_emlrtRSI;
    if (ndbl > 2.147483647E+9) {
      emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI, "Coder:MATLAB:pmaxsize",
        "Coder:MATLAB:pmaxsize", 0);
    }

    i = angles->size[0] * angles->size[1];
    angles->size[0] = 1;
    angles->size[1] = n;
    emxEnsureCapacity_real_T(&b_st, angles, i, &i_emlrtRTEI);
    if (n > 0) {
      angles->data[0] = 0.0;
      if (n > 1) {
        angles->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          ndbl = ((real_T)k + 1.0) * step;
          angles->data[k + 1] = ndbl;
          angles->data[(n - k) - 2] = apnd - ndbl;
        }

        if (nm1d2 << 1 == n - 1) {
          angles->data[nm1d2] = apnd / 2.0;
        } else {
          ndbl = (real_T)nm1d2 * step;
          angles->data[nm1d2] = ndbl;
          angles->data[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }
  }

  emxInit_real_T(&st, &b_angles, 2, &g_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  ndbl = Calculate_extreme_angle(&st, angles, true, system_parameters,
    allowed_radius, version);
  st.site = &c_emlrtRSI;
  cdiff = Calculate_extreme_angle(&st, angles, false, system_parameters,
    allowed_radius, version);
  i = b_angles->size[0] * b_angles->size[1];
  b_angles->size[0] = 1;
  b_angles->size[1] = angles->size[1];
  emxEnsureCapacity_real_T(sp, b_angles, i, &g_emlrtRTEI);
  nm1d2 = angles->size[0] * angles->size[1];
  for (i = 0; i < nm1d2; i++) {
    b_angles->data[i] = -angles->data[i];
  }

  st.site = &d_emlrtRSI;
  apnd = Calculate_extreme_angle(&st, b_angles, true, system_parameters,
    allowed_radius, version);
  i = b_angles->size[0] * b_angles->size[1];
  b_angles->size[0] = 1;
  b_angles->size[1] = angles->size[1];
  emxEnsureCapacity_real_T(sp, b_angles, i, &h_emlrtRTEI);
  nm1d2 = angles->size[0] * angles->size[1];
  for (i = 0; i < nm1d2; i++) {
    b_angles->data[i] = -angles->data[i];
  }

  emxFree_real_T(&angles);
  st.site = &e_emlrtRSI;
  extreme_angles_idx_3 = Calculate_extreme_angle(&st, b_angles, false,
    system_parameters, allowed_radius, version);
  varargin_1[0] = muDoubleScalarAbs(ndbl);
  varargin_1[1] = muDoubleScalarAbs(cdiff);
  varargin_1[2] = muDoubleScalarAbs(apnd);
  varargin_1[3] = muDoubleScalarAbs(extreme_angles_idx_3);
  emxFree_real_T(&b_angles);
  if (!muDoubleScalarIsNaN(varargin_1[0])) {
    nm1d2 = 1;
  } else {
    nm1d2 = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        nm1d2 = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (nm1d2 == 0) {
    ndbl = varargin_1[0];
  } else {
    ndbl = varargin_1[nm1d2 - 1];
    i = nm1d2 + 1;
    for (k = i; k < 5; k++) {
      cdiff = varargin_1[k - 1];
      if (ndbl > cdiff) {
        ndbl = cdiff;
      }
    }
  }

  ndbl = muDoubleScalarCos(ndbl);
  cost = -(2.0943951023931953 * (1.0 - ndbl));
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return cost;
}

/* End of code generation (Cost_function.c) */
