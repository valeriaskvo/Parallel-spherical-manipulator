/*
 * Cost_function.c
 *
 * Code generation for function 'Cost_function'
 *
 */

/* Include files */
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "Cost_function_emxutil.h"
#include "Inverse_kinematics.h"
#include "J_leg.h"
#include "Sing_v2.h"
#include "Workspace_calculation.h"
#include "eml_int_forloop_overflow_check.h"
#include "eps.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 4,     /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 6,   /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 12,  /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 13,  /* lineNo */
  "Cost_function",                     /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 15, /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 39, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 106,/* lineNo */
  "applyToMultipleDims",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\applyToMultipleDims.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 39, /* lineNo */
  "function_handle/parenReference",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 35, /* lineNo */
  "@(x)sumprod(op,x,coder.internal.indexInt(1),varargin{2:end})",/* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 96, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 124,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 184,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 21, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 13,/* lineNo */
  41,                                  /* colNo */
  "Cost_function",                     /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 12,/* lineNo */
  6,                                   /* colNo */
  "Cost_function",                     /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Cost_function.m"/* pName */
};

/* Function Definitions */
real_T Cost_function(const emlrtStack *sp, const real_T x[3], real_T
                     system_parameters[5], const emxArray_real_T *phi_set,
                     real_T allowed_radius, real_T version)
{
  real_T singular_coints;
  boolean_T flag_par;
  real_T dv[3];
  boolean_T flag_ser;
  emxArray_real_T *workspace;
  int32_T i;
  emxArray_boolean_T *b_x;
  real_T J_pass[36];
  real_T J_gen[27];
  real_T eta_i;
  int32_T b_i;
  real_T q[3];
  real_T J_i[9];
  int32_T irank;
  int32_T k;
  boolean_T c_x[9];
  boolean_T p;
  boolean_T d_x[36];
  real_T S[36];
  real_T s[6];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  flag_par = false;
  system_parameters[1] = x[0];
  system_parameters[2] = x[1];
  system_parameters[3] = x[2];
  if (version == 1.0) {
    st.site = &emlrtRSI;

    /*  Compute the matix for singularity checking in PSM which controlled by low */
    /*  links actuators */
    /*  Created by Valeria Skvo */
    flag_ser = false;
    for (i = 0; i < 3; i++) {
      eta_i = (((real_T)i + 1.0) - 1.0) * 2.0 / 3.0 * 3.1415926535897931;
      if (!flag_par) {
        dv[0] = 0.0;
        dv[1] = 0.0;
        dv[2] = 0.0;
        flag_par = true;
      }

      b_st.site = &u_emlrtRSI;
      Inverse_kinematics(&b_st, eta_i, system_parameters, dv, q);
      J_leg(eta_i, system_parameters, q, J_i);
      b_i = 3 * i;
      for (k = 0; k < 3; k++) {
        irank = 3 * (k + b_i);
        J_gen[irank] = J_i[3 * k];
        J_gen[irank + 1] = J_i[3 * k + 1];
        J_gen[irank + 2] = J_i[3 * k + 2];
      }

      for (b_i = 0; b_i < 9; b_i++) {
        c_x[b_i] = muDoubleScalarIsNaN(J_i[b_i]);
      }

      eta_i = c_x[0];
      for (k = 0; k < 8; k++) {
        eta_i += (real_T)c_x[k + 1];
      }

      if (eta_i != 0.0) {
        flag_ser = true;
      } else {
        b_st.site = &v_emlrtRSI;
        c_st.site = &x_emlrtRSI;
        irank = 0;
        d_st.site = &y_emlrtRSI;
        p = true;
        for (k = 0; k < 9; k++) {
          if ((!p) || (muDoubleScalarIsInf(J_i[k]) || muDoubleScalarIsNaN(J_i[k])))
          {
            p = false;
          }
        }

        if (p) {
          e_st.site = &bb_emlrtRSI;
          f_st.site = &cb_emlrtRSI;
          g_st.site = &db_emlrtRSI;
          h_st.site = &eb_emlrtRSI;
          xzsvdc(&h_st, J_i, q);
        } else {
          q[0] = rtNaN;
          q[1] = rtNaN;
          q[2] = rtNaN;
        }

        d_st.site = &ab_emlrtRSI;
        eta_i = 3.0 * eps(q[0]);
        k = 0;
        while ((k < 3) && (q[k] > eta_i)) {
          irank++;
          k++;
        }

        if (irank != 3) {
          flag_ser = true;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    J_pass[0] = J_gen[3];
    J_pass[6] = J_gen[6];
    J_pass[12] = -J_gen[12];
    J_pass[18] = -J_gen[15];
    J_pass[24] = 0.0;
    J_pass[30] = 0.0;
    J_pass[3] = 0.0;
    J_pass[9] = 0.0;
    J_pass[15] = -J_gen[12];
    J_pass[21] = -J_gen[15];
    J_pass[27] = J_gen[21];
    J_pass[33] = J_gen[24];
    J_pass[1] = J_gen[4];
    J_pass[7] = J_gen[7];
    J_pass[13] = -J_gen[13];
    J_pass[19] = -J_gen[16];
    J_pass[25] = 0.0;
    J_pass[31] = 0.0;
    J_pass[4] = 0.0;
    J_pass[10] = 0.0;
    J_pass[16] = -J_gen[13];
    J_pass[22] = -J_gen[16];
    J_pass[28] = J_gen[22];
    J_pass[34] = J_gen[25];
    J_pass[2] = J_gen[5];
    J_pass[8] = J_gen[8];
    J_pass[14] = -J_gen[14];
    J_pass[20] = -J_gen[17];
    J_pass[26] = 0.0;
    J_pass[32] = 0.0;
    J_pass[5] = 0.0;
    J_pass[11] = 0.0;
    J_pass[17] = -J_gen[14];
    J_pass[23] = -J_gen[17];
    J_pass[29] = J_gen[23];
    J_pass[35] = J_gen[26];
    for (b_i = 0; b_i < 6; b_i++) {
      for (k = 0; k < 6; k++) {
        eta_i = 0.0;
        for (irank = 0; irank < 6; irank++) {
          eta_i += J_pass[irank + 6 * b_i] * J_pass[irank + 6 * k];
        }

        S[b_i + 6 * k] = eta_i;
      }
    }

    for (b_i = 0; b_i < 36; b_i++) {
      d_x[b_i] = muDoubleScalarIsNaN(S[b_i]);
    }

    eta_i = d_x[0];
    for (k = 0; k < 35; k++) {
      eta_i += (real_T)d_x[k + 1];
    }

    if (eta_i != 0.0) {
      flag_par = true;
    } else {
      b_st.site = &w_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      irank = 0;
      d_st.site = &y_emlrtRSI;
      p = true;
      for (k = 0; k < 36; k++) {
        if ((!p) || (muDoubleScalarIsInf(S[k]) || muDoubleScalarIsNaN(S[k]))) {
          p = false;
        }
      }

      if (p) {
        e_st.site = &bb_emlrtRSI;
        f_st.site = &cb_emlrtRSI;
        g_st.site = &db_emlrtRSI;
        h_st.site = &eb_emlrtRSI;
        b_xzsvdc(&h_st, S, s);
      } else {
        for (i = 0; i < 6; i++) {
          s[i] = rtNaN;
        }
      }

      d_st.site = &ab_emlrtRSI;
      eta_i = 6.0 * eps(s[0]);
      k = 0;
      while ((k < 6) && (s[k] > eta_i)) {
        irank++;
        k++;
      }

      if (irank != 6) {
        flag_par = true;
      } else {
        flag_par = false;
      }
    }
  } else {
    dv[0] = 0.0;
    dv[1] = 0.0;
    dv[2] = 0.0;
    st.site = &b_emlrtRSI;
    Sing_v2(&st, system_parameters, dv, &flag_ser, &flag_par);
  }

  emxInit_real_T(sp, &workspace, 1, &f_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_x, 1, &e_emlrtRTEI, true);
  if (flag_ser || flag_par) {
    if (phi_set->size[0] == 0) {
      singular_coints = 0.0;
    } else {
      singular_coints = muIntScalarMax_sint32(phi_set->size[0], 3);
    }
  } else {
    st.site = &c_emlrtRSI;
    Workspace_calculation(&st, system_parameters, phi_set, allowed_radius,
                          version, workspace);
    st.site = &d_emlrtRSI;
    b_i = b_x->size[0];
    b_x->size[0] = workspace->size[0];
    emxEnsureCapacity_boolean_T(&st, b_x, b_i, &e_emlrtRTEI);
    irank = workspace->size[0];
    for (b_i = 0; b_i < irank; b_i++) {
      b_x->data[b_i] = (workspace->data[b_i] == 0.0);
    }

    b_st.site = &wb_emlrtRSI;
    c_st.site = &xb_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    e_st.site = &ac_emlrtRSI;
    f_st.site = &bc_emlrtRSI;
    g_st.site = &cc_emlrtRSI;
    irank = b_x->size[0];
    if (b_x->size[0] == 0) {
      eta_i = 0.0;
    } else {
      h_st.site = &dc_emlrtRSI;
      eta_i = b_x->data[0];
      i_st.site = &ec_emlrtRSI;
      if ((2 <= b_x->size[0]) && (b_x->size[0] > 2147483646)) {
        j_st.site = &fc_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }

      for (k = 2; k <= irank; k++) {
        eta_i += (real_T)b_x->data[k - 1];
      }
    }

    if (phi_set->size[0] == 0) {
      i = 0;
    } else {
      i = muIntScalarMax_sint32(phi_set->size[0], 3);
    }

    singular_coints = (real_T)i - eta_i;
  }

  emxFree_boolean_T(&b_x);
  emxFree_real_T(&workspace);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return singular_coints;
}

/* End of code generation (Cost_function.c) */
