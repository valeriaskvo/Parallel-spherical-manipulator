/*
 * Workspace_calculation.c
 *
 * Code generation for function 'Workspace_calculation'
 *
 */

/* Include files */
#include "Workspace_calculation.h"
#include "Collision_check.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "Cost_function_emxutil.h"
#include "Inverse_kinematics.h"
#include "J_leg.h"
#include "Sing_v2.h"
#include "eps.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qb_emlrtRSI = { 7,  /* lineNo */
  "Workspace_calculation",             /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 9,  /* lineNo */
  "Workspace_calculation",             /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 11, /* lineNo */
  "Workspace_calculation",             /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  20,                                  /* colNo */
  "phi_set",                           /* aName */
  "Workspace_calculation",             /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  9,                                   /* colNo */
  "workspace",                         /* aName */
  "Workspace_calculation",             /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  9,                                   /* colNo */
  "workspace",                         /* aName */
  "Workspace_calculation",             /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  9,                                   /* colNo */
  "workspace",                         /* aName */
  "Workspace_calculation",             /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 3, /* lineNo */
  1,                                   /* colNo */
  "Workspace_calculation",             /* fName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Workspace_calculation.m"/* pName */
};

/* Function Definitions */
void Workspace_calculation(const emlrtStack *sp, const real_T system_parameters
  [5], const emxArray_real_T *phi_set, real_T allowed_radius, real_T version,
  emxArray_real_T *workspace)
{
  int32_T n;
  int32_T irank;
  int32_T i;
  real_T b_phi_set[3];
  boolean_T flag_ser;
  boolean_T flag_par;
  int32_T b_i;
  real_T J_pass[36];
  real_T J_gen[27];
  real_T eta_i;
  boolean_T flag;
  real_T q[3];
  real_T J_i[9];
  int32_T c_i;
  int32_T J_gen_tmp;
  boolean_T x[9];
  boolean_T b_x[36];
  real_T S[36];
  real_T s[6];
  real_T b_S[36];
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
  if (phi_set->size[0] == 0) {
    n = 0;
  } else {
    n = muIntScalarMax_sint32(phi_set->size[0], 3);
  }

  irank = workspace->size[0];
  workspace->size[0] = n;
  emxEnsureCapacity_real_T(sp, workspace, irank, &g_emlrtRTEI);
  for (irank = 0; irank < n; irank++) {
    workspace->data[irank] = 0.0;
  }

  if (phi_set->size[0] == 0) {
    n = 0;
  } else {
    n = muIntScalarMax_sint32(phi_set->size[0], 3);
  }

  for (i = 0; i < n; i++) {
    irank = i + 1;
    if (irank > phi_set->size[0]) {
      emlrtDynamicBoundsCheckR2012b(irank, 1, phi_set->size[0], &emlrtBCI, sp);
    }

    if (version == 1.0) {
      st.site = &qb_emlrtRSI;

      /*  Compute the matix for singularity checking in PSM which controlled by low */
      /*  links actuators */
      /*  Created by Valeria Skvo */
      flag_ser = false;
      for (b_i = 0; b_i < 3; b_i++) {
        eta_i = (((real_T)b_i + 1.0) - 1.0) * 2.0 / 3.0 * 3.1415926535897931;
        b_phi_set[0] = phi_set->data[i];
        b_phi_set[1] = phi_set->data[i + phi_set->size[0]];
        b_phi_set[2] = phi_set->data[i + phi_set->size[0] * 2];
        b_st.site = &u_emlrtRSI;
        Inverse_kinematics(&b_st, eta_i, system_parameters, b_phi_set, q);
        J_leg(eta_i, system_parameters, q, J_i);
        irank = 3 * b_i;
        for (c_i = 0; c_i < 3; c_i++) {
          J_gen_tmp = 3 * (c_i + irank);
          J_gen[J_gen_tmp] = J_i[3 * c_i];
          J_gen[J_gen_tmp + 1] = J_i[3 * c_i + 1];
          J_gen[J_gen_tmp + 2] = J_i[3 * c_i + 2];
        }

        for (irank = 0; irank < 9; irank++) {
          x[irank] = muDoubleScalarIsNaN(J_i[irank]);
        }

        eta_i = x[0];
        for (J_gen_tmp = 0; J_gen_tmp < 8; J_gen_tmp++) {
          eta_i += (real_T)x[J_gen_tmp + 1];
        }

        if (eta_i != 0.0) {
          flag_ser = true;
        } else {
          b_st.site = &v_emlrtRSI;
          c_st.site = &x_emlrtRSI;
          irank = 0;
          d_st.site = &y_emlrtRSI;
          flag_par = true;
          for (J_gen_tmp = 0; J_gen_tmp < 9; J_gen_tmp++) {
            if ((!flag_par) || (muDoubleScalarIsInf(J_i[J_gen_tmp]) ||
                                muDoubleScalarIsNaN(J_i[J_gen_tmp]))) {
              flag_par = false;
            }
          }

          if (flag_par) {
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
      for (irank = 0; irank < 6; irank++) {
        for (c_i = 0; c_i < 6; c_i++) {
          eta_i = 0.0;
          for (J_gen_tmp = 0; J_gen_tmp < 6; J_gen_tmp++) {
            eta_i += J_pass[J_gen_tmp + 6 * irank] * J_pass[J_gen_tmp + 6 * c_i];
          }

          S[irank + 6 * c_i] = eta_i;
        }
      }

      for (irank = 0; irank < 36; irank++) {
        b_x[irank] = muDoubleScalarIsNaN(S[irank]);
      }

      eta_i = b_x[0];
      for (J_gen_tmp = 0; J_gen_tmp < 35; J_gen_tmp++) {
        eta_i += (real_T)b_x[J_gen_tmp + 1];
      }

      if (eta_i != 0.0) {
        flag_par = true;
      } else {
        b_st.site = &w_emlrtRSI;
        c_st.site = &x_emlrtRSI;
        irank = 0;
        d_st.site = &y_emlrtRSI;
        flag_par = true;
        for (J_gen_tmp = 0; J_gen_tmp < 36; J_gen_tmp++) {
          if ((!flag_par) || (muDoubleScalarIsInf(S[J_gen_tmp]) ||
                              muDoubleScalarIsNaN(S[J_gen_tmp]))) {
            flag_par = false;
          }
        }

        if (flag_par) {
          e_st.site = &bb_emlrtRSI;
          f_st.site = &cb_emlrtRSI;
          g_st.site = &db_emlrtRSI;
          memcpy(&b_S[0], &S[0], 36U * sizeof(real_T));
          h_st.site = &eb_emlrtRSI;
          b_xzsvdc(&h_st, b_S, s);
        } else {
          for (b_i = 0; b_i < 6; b_i++) {
            s[b_i] = rtNaN;
          }
        }

        d_st.site = &ab_emlrtRSI;
        eta_i = 6.0 * eps(s[0]);
        J_gen_tmp = 0;
        while ((J_gen_tmp < 6) && (s[J_gen_tmp] > eta_i)) {
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
      b_phi_set[0] = phi_set->data[i];
      b_phi_set[1] = phi_set->data[i + phi_set->size[0]];
      b_phi_set[2] = phi_set->data[i + phi_set->size[0] * 2];
      st.site = &rb_emlrtRSI;
      Sing_v2(&st, system_parameters, b_phi_set, &flag_ser, &flag_par);
    }

    b_phi_set[0] = phi_set->data[i];
    b_phi_set[1] = phi_set->data[i + phi_set->size[0]];
    b_phi_set[2] = phi_set->data[i + phi_set->size[0] * 2];
    st.site = &sb_emlrtRSI;
    flag = Collision_check(&st, system_parameters, b_phi_set, allowed_radius);
    if (flag_ser) {
      irank = i + 1;
      if (irank > workspace->size[0]) {
        emlrtDynamicBoundsCheckR2012b(irank, 1, workspace->size[0], &b_emlrtBCI,
          sp);
      }

      workspace->data[irank - 1] = 1.0;
    } else if (flag_par) {
      irank = i + 1;
      if (irank > workspace->size[0]) {
        emlrtDynamicBoundsCheckR2012b(irank, 1, workspace->size[0], &c_emlrtBCI,
          sp);
      }

      workspace->data[irank - 1] = 2.0;
    } else {
      if (flag) {
        irank = i + 1;
        if (irank > workspace->size[0]) {
          emlrtDynamicBoundsCheckR2012b(irank, 1, workspace->size[0],
            &d_emlrtBCI, sp);
        }

        workspace->data[irank - 1] = 3.0;
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (Workspace_calculation.c) */
