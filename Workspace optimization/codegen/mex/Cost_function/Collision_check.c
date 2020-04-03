/*
 * Collision_check.c
 *
 * Code generation for function 'Collision_check'
 *
 */

/* Include files */
#include "Collision_check.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "Inverse_kinematics.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 17, /* lineNo */
  "Collision_check",                   /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Collision_check.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 32, /* lineNo */
  "Collision_check",                   /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Collision_check.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 33, /* lineNo */
  "Collision_check",                   /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Collision_check.m"/* pathName */
};

/* Function Definitions */
boolean_T Collision_check(const emlrtStack *sp, const real_T system_parameters[5],
  const real_T phi_ee[3], real_T allowed_rad)
{
  boolean_T flag;
  real_T L_base;
  real_T L_l1;
  real_T L_l2;
  real_T Rx_tmp;
  real_T b_Rx_tmp;
  real_T eta_i;
  real_T c_Rx_tmp;
  real_T d_Rx_tmp;
  real_T e_Rx_tmp;
  real_T f_Rx_tmp;
  int32_T i;
  real_T d;
  real_T O_w[9];
  real_T O_v[9];
  real_T q[3];
  real_T Rz_tmp;
  boolean_T condition_1;
  real_T b_Rz_tmp;
  real_T c_Rz_tmp;
  boolean_T condition_2;
  real_T H_link_1_tmp[16];
  real_T d_Rz_tmp;
  real_T e_Rz_tmp;
  real_T f_Rz_tmp[16];
  real_T g_Rz_tmp[16];
  int32_T b_i;
  real_T d1;
  real_T d2;
  int32_T i1;
  int32_T i2;
  real_T H[16];
  real_T b_H_link_1_tmp[16];
  real_T c_H_link_1_tmp[16];
  static const int8_T iv[4] = { 0, 0, 0, 1 };

  int32_T O_w_tmp;
  int32_T b_O_w_tmp;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  L_base = system_parameters[4] * muDoubleScalarSin(system_parameters[0]);
  L_l1 = 2.0 * system_parameters[4] * muDoubleScalarSin(system_parameters[2] /
    2.0);
  L_l2 = 2.0 * system_parameters[4] * muDoubleScalarSin(system_parameters[3] /
    2.0);
  Rx_tmp = muDoubleScalarSin(system_parameters[0] + 3.1415926535897931);
  b_Rx_tmp = muDoubleScalarCos(system_parameters[0] + 3.1415926535897931);
  eta_i = system_parameters[2] / 2.0;
  c_Rx_tmp = muDoubleScalarSin(eta_i);
  d_Rx_tmp = muDoubleScalarCos(eta_i);
  eta_i = system_parameters[3] / 2.0;
  e_Rx_tmp = muDoubleScalarSin(eta_i);
  f_Rx_tmp = muDoubleScalarCos(eta_i);
  for (i = 0; i < 3; i++) {
    eta_i = (((real_T)i + 1.0) - 1.0) * 2.0 * 3.1415926535897931 / 3.0;
    st.site = &ub_emlrtRSI;
    Inverse_kinematics(&st, eta_i, system_parameters, phi_ee, q);

    /*  Rotation matrix around z-axis */
    /*  Created by Valeria Skvo */
    Rz_tmp = muDoubleScalarSin(-eta_i);
    eta_i = muDoubleScalarCos(-eta_i);

    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    /*  Translation matrix by y-axis */
    /*  Created by Valeria Skvo */
    /*  Rotation matrix around x-axis */
    /*  Created by Valeria Skvo */
    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    /*  Rotation matrix around z-axis */
    /*  Created by Valeria Skvo */
    b_Rz_tmp = muDoubleScalarSin(q[0]);
    c_Rz_tmp = muDoubleScalarCos(q[0]);

    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    /*  Rotation matrix around x-axis */
    /*  Created by Valeria Skvo */
    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    H_link_1_tmp[1] = 0.0;
    H_link_1_tmp[5] = d_Rx_tmp;
    H_link_1_tmp[9] = -c_Rx_tmp;
    H_link_1_tmp[2] = 0.0;
    H_link_1_tmp[6] = c_Rx_tmp;
    H_link_1_tmp[10] = d_Rx_tmp;
    H_link_1_tmp[0] = 1.0;
    H_link_1_tmp[12] = 0.0;
    H_link_1_tmp[4] = 0.0;
    H_link_1_tmp[13] = 0.0;
    H_link_1_tmp[8] = 0.0;
    H_link_1_tmp[14] = 0.0;
    H_link_1_tmp[3] = 0.0;
    H_link_1_tmp[7] = 0.0;
    H_link_1_tmp[11] = 0.0;
    H_link_1_tmp[15] = 1.0;

    /*  Translation matrix by y-axis */
    /*  Created by Valeria Skvo */
    /*  Rotation matrix around z-axis */
    /*  Created by Valeria Skvo */
    d_Rz_tmp = muDoubleScalarSin(q[1]);
    e_Rz_tmp = muDoubleScalarCos(q[1]);

    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    f_Rz_tmp[0] = eta_i;
    f_Rz_tmp[4] = -Rz_tmp;
    f_Rz_tmp[8] = 0.0;
    f_Rz_tmp[1] = Rz_tmp;
    f_Rz_tmp[5] = eta_i;
    f_Rz_tmp[9] = 0.0;
    f_Rz_tmp[2] = 0.0;
    f_Rz_tmp[12] = 0.0;
    f_Rz_tmp[6] = 0.0;
    f_Rz_tmp[13] = 0.0;
    f_Rz_tmp[10] = 1.0;
    f_Rz_tmp[14] = 0.0;
    g_Rz_tmp[1] = 0.0;
    g_Rz_tmp[5] = 1.0;
    g_Rz_tmp[9] = 0.0;
    g_Rz_tmp[13] = L_base;
    f_Rz_tmp[3] = 0.0;
    g_Rz_tmp[0] = 1.0;
    g_Rz_tmp[2] = 0.0;
    g_Rz_tmp[3] = 0.0;
    f_Rz_tmp[7] = 0.0;
    g_Rz_tmp[4] = 0.0;
    g_Rz_tmp[6] = 0.0;
    g_Rz_tmp[7] = 0.0;
    f_Rz_tmp[11] = 0.0;
    g_Rz_tmp[8] = 0.0;
    g_Rz_tmp[10] = 1.0;
    g_Rz_tmp[11] = 0.0;
    f_Rz_tmp[15] = 1.0;
    g_Rz_tmp[12] = 0.0;
    g_Rz_tmp[14] = 0.0;
    g_Rz_tmp[15] = 1.0;
    for (b_i = 0; b_i < 4; b_i++) {
      d = f_Rz_tmp[b_i + 4];
      d1 = f_Rz_tmp[b_i + 8];
      d2 = f_Rz_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        H[b_i + i2] = ((f_Rz_tmp[b_i] * g_Rz_tmp[i2] + d * g_Rz_tmp[i2 + 1]) +
                       d1 * g_Rz_tmp[i2 + 2]) + d2 * g_Rz_tmp[i2 + 3];
      }
    }

    g_Rz_tmp[1] = 0.0;
    g_Rz_tmp[5] = b_Rx_tmp;
    g_Rz_tmp[9] = -Rx_tmp;
    g_Rz_tmp[2] = 0.0;
    g_Rz_tmp[6] = Rx_tmp;
    g_Rz_tmp[10] = b_Rx_tmp;
    g_Rz_tmp[0] = 1.0;
    g_Rz_tmp[12] = 0.0;
    g_Rz_tmp[4] = 0.0;
    g_Rz_tmp[13] = 0.0;
    g_Rz_tmp[8] = 0.0;
    g_Rz_tmp[14] = 0.0;
    g_Rz_tmp[3] = 0.0;
    g_Rz_tmp[7] = 0.0;
    g_Rz_tmp[11] = 0.0;
    g_Rz_tmp[15] = 1.0;
    for (b_i = 0; b_i < 4; b_i++) {
      d = H[b_i + 4];
      d1 = H[b_i + 8];
      d2 = H[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        f_Rz_tmp[b_i + i2] = ((H[b_i] * g_Rz_tmp[i2] + d * g_Rz_tmp[i2 + 1]) +
                              d1 * g_Rz_tmp[i2 + 2]) + d2 * g_Rz_tmp[i2 + 3];
      }
    }

    H[0] = c_Rz_tmp;
    H[4] = -b_Rz_tmp;
    H[8] = 0.0;
    H[1] = b_Rz_tmp;
    H[5] = c_Rz_tmp;
    H[9] = 0.0;
    H[2] = 0.0;
    H[12] = 0.0;
    H[6] = 0.0;
    H[13] = 0.0;
    H[10] = 1.0;
    H[14] = 0.0;
    g_Rz_tmp[1] = 0.0;
    g_Rz_tmp[5] = 1.0;
    g_Rz_tmp[9] = 0.0;
    g_Rz_tmp[13] = -L_l1;
    H[3] = 0.0;
    g_Rz_tmp[0] = 1.0;
    g_Rz_tmp[2] = 0.0;
    g_Rz_tmp[3] = 0.0;
    H[7] = 0.0;
    g_Rz_tmp[4] = 0.0;
    g_Rz_tmp[6] = 0.0;
    g_Rz_tmp[7] = 0.0;
    H[11] = 0.0;
    g_Rz_tmp[8] = 0.0;
    g_Rz_tmp[10] = 1.0;
    g_Rz_tmp[11] = 0.0;
    H[15] = 1.0;
    g_Rz_tmp[12] = 0.0;
    g_Rz_tmp[14] = 0.0;
    g_Rz_tmp[15] = 1.0;
    for (b_i = 0; b_i < 4; b_i++) {
      d = H_link_1_tmp[b_i + 4];
      d1 = H_link_1_tmp[b_i + 8];
      d2 = H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        b_H_link_1_tmp[b_i + i2] = ((H_link_1_tmp[b_i] * g_Rz_tmp[i2] + d *
          g_Rz_tmp[i2 + 1]) + d1 * g_Rz_tmp[i2 + 2]) + d2 * g_Rz_tmp[i2 + 3];
      }

      d = b_H_link_1_tmp[b_i + 4];
      d1 = b_H_link_1_tmp[b_i + 8];
      d2 = b_H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        c_H_link_1_tmp[b_i + i2] = ((b_H_link_1_tmp[b_i] * H_link_1_tmp[i2] + d *
          H_link_1_tmp[i2 + 1]) + d1 * H_link_1_tmp[i2 + 2]) + d2 *
          H_link_1_tmp[i2 + 3];
      }
    }

    g_Rz_tmp[0] = e_Rz_tmp;
    g_Rz_tmp[4] = -d_Rz_tmp;
    g_Rz_tmp[8] = 0.0;
    g_Rz_tmp[1] = d_Rz_tmp;
    g_Rz_tmp[5] = e_Rz_tmp;
    g_Rz_tmp[9] = 0.0;
    g_Rz_tmp[2] = 0.0;
    g_Rz_tmp[12] = 0.0;
    g_Rz_tmp[6] = 0.0;
    g_Rz_tmp[13] = 0.0;
    g_Rz_tmp[10] = 1.0;
    g_Rz_tmp[14] = 0.0;
    for (b_i = 0; b_i < 4; b_i++) {
      g_Rz_tmp[(b_i << 2) + 3] = iv[b_i];
      d = f_Rz_tmp[b_i + 4];
      d1 = f_Rz_tmp[b_i + 8];
      d2 = f_Rz_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        b_H_link_1_tmp[b_i + i2] = ((f_Rz_tmp[b_i] * H[i2] + d * H[i2 + 1]) + d1
          * H[i2 + 2]) + d2 * H[i2 + 3];
      }
    }

    for (b_i = 0; b_i < 4; b_i++) {
      d = c_H_link_1_tmp[b_i + 4];
      d1 = c_H_link_1_tmp[b_i + 8];
      d2 = c_H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        H_link_1_tmp[b_i + i2] = ((c_H_link_1_tmp[b_i] * g_Rz_tmp[i2] + d *
          g_Rz_tmp[i2 + 1]) + d1 * g_Rz_tmp[i2 + 2]) + d2 * g_Rz_tmp[i2 + 3];
      }
    }

    for (b_i = 0; b_i < 4; b_i++) {
      d = b_H_link_1_tmp[b_i + 4];
      d1 = b_H_link_1_tmp[b_i + 8];
      d2 = b_H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        H[b_i + i2] = ((b_H_link_1_tmp[b_i] * H_link_1_tmp[i2] + d *
                        H_link_1_tmp[i2 + 1]) + d1 * H_link_1_tmp[i2 + 2]) + d2 *
          H_link_1_tmp[i2 + 3];
      }
    }

    /*  Rotation matrix around x-axis */
    /*  Created by Valeria Skvo */
    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    H_link_1_tmp[1] = 0.0;
    H_link_1_tmp[5] = f_Rx_tmp;
    H_link_1_tmp[9] = -e_Rx_tmp;
    H_link_1_tmp[2] = 0.0;
    H_link_1_tmp[6] = e_Rx_tmp;
    H_link_1_tmp[10] = f_Rx_tmp;
    O_w[3 * i] = H[12];
    H_link_1_tmp[0] = 1.0;
    H_link_1_tmp[12] = 0.0;
    O_w_tmp = 3 * i + 1;
    O_w[O_w_tmp] = H[13];
    H_link_1_tmp[4] = 0.0;
    H_link_1_tmp[13] = 0.0;
    b_O_w_tmp = 3 * i + 2;
    O_w[b_O_w_tmp] = H[14];
    H_link_1_tmp[8] = 0.0;
    H_link_1_tmp[14] = 0.0;

    /*  Translation matrix by y-axis */
    /*  Created by Valeria Skvo */
    /*  Rotation matrix around z-axis */
    /*  Created by Valeria Skvo */
    Rz_tmp = muDoubleScalarSin(q[2]);
    eta_i = muDoubleScalarCos(q[2]);

    /*  Transform the rotation matrix in type which includes the translation part */
    /*  Created by Valeria Skvo */
    g_Rz_tmp[1] = 0.0;
    g_Rz_tmp[5] = 1.0;
    g_Rz_tmp[9] = 0.0;
    g_Rz_tmp[13] = -L_l2;
    H_link_1_tmp[3] = 0.0;
    g_Rz_tmp[0] = 1.0;
    g_Rz_tmp[2] = 0.0;
    g_Rz_tmp[3] = 0.0;
    H_link_1_tmp[7] = 0.0;
    g_Rz_tmp[4] = 0.0;
    g_Rz_tmp[6] = 0.0;
    g_Rz_tmp[7] = 0.0;
    H_link_1_tmp[11] = 0.0;
    g_Rz_tmp[8] = 0.0;
    g_Rz_tmp[10] = 1.0;
    g_Rz_tmp[11] = 0.0;
    H_link_1_tmp[15] = 1.0;
    g_Rz_tmp[12] = 0.0;
    g_Rz_tmp[14] = 0.0;
    g_Rz_tmp[15] = 1.0;
    for (b_i = 0; b_i < 4; b_i++) {
      d = H_link_1_tmp[b_i + 4];
      d1 = H_link_1_tmp[b_i + 8];
      d2 = H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        b_H_link_1_tmp[b_i + i2] = ((H_link_1_tmp[b_i] * g_Rz_tmp[i2] + d *
          g_Rz_tmp[i2 + 1]) + d1 * g_Rz_tmp[i2 + 2]) + d2 * g_Rz_tmp[i2 + 3];
      }

      d = b_H_link_1_tmp[b_i + 4];
      d1 = b_H_link_1_tmp[b_i + 8];
      d2 = b_H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        c_H_link_1_tmp[b_i + i2] = ((b_H_link_1_tmp[b_i] * H_link_1_tmp[i2] + d *
          H_link_1_tmp[i2 + 1]) + d1 * H_link_1_tmp[i2 + 2]) + d2 *
          H_link_1_tmp[i2 + 3];
      }
    }

    f_Rz_tmp[0] = eta_i;
    f_Rz_tmp[4] = -Rz_tmp;
    f_Rz_tmp[8] = 0.0;
    f_Rz_tmp[1] = Rz_tmp;
    f_Rz_tmp[5] = eta_i;
    f_Rz_tmp[9] = 0.0;
    f_Rz_tmp[2] = 0.0;
    f_Rz_tmp[12] = 0.0;
    f_Rz_tmp[6] = 0.0;
    f_Rz_tmp[13] = 0.0;
    f_Rz_tmp[10] = 1.0;
    f_Rz_tmp[14] = 0.0;
    f_Rz_tmp[3] = 0.0;
    f_Rz_tmp[7] = 0.0;
    f_Rz_tmp[11] = 0.0;
    f_Rz_tmp[15] = 1.0;
    for (b_i = 0; b_i < 4; b_i++) {
      d = c_H_link_1_tmp[b_i + 4];
      d1 = c_H_link_1_tmp[b_i + 8];
      d2 = c_H_link_1_tmp[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        H_link_1_tmp[b_i + i2] = ((c_H_link_1_tmp[b_i] * f_Rz_tmp[i2] + d *
          f_Rz_tmp[i2 + 1]) + d1 * f_Rz_tmp[i2 + 2]) + d2 * f_Rz_tmp[i2 + 3];
      }
    }

    for (b_i = 0; b_i < 4; b_i++) {
      d = H[b_i + 4];
      d1 = H[b_i + 8];
      d2 = H[b_i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        i2 = i1 << 2;
        g_Rz_tmp[b_i + i2] = ((H[b_i] * H_link_1_tmp[i2] + d * H_link_1_tmp[i2 +
          1]) + d1 * H_link_1_tmp[i2 + 2]) + d2 * H_link_1_tmp[i2 + 3];
      }
    }

    memcpy(&H[0], &g_Rz_tmp[0], 16U * sizeof(real_T));
    O_v[3 * i] = H[12];
    O_v[O_w_tmp] = H[13];
    O_v[b_O_w_tmp] = H[14];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  d = O_w[0] - O_v[3];
  eta_i = d * d;
  d = O_w[1] - O_v[4];
  eta_i += d * d;
  d = O_w[2] - O_v[5];
  eta_i += d * d;
  st.site = &vb_emlrtRSI;
  if (eta_i < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  if (muDoubleScalarSqrt(eta_i) < allowed_rad) {
    condition_1 = true;
  } else {
    d = O_w[3] - O_v[6];
    eta_i = d * d;
    d = O_w[4] - O_v[7];
    eta_i += d * d;
    d = O_w[5] - O_v[8];
    eta_i += d * d;
    st.site = &vb_emlrtRSI;
    if (eta_i < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    if (muDoubleScalarSqrt(eta_i) < allowed_rad) {
      condition_1 = true;
    } else {
      d = O_w[6] - O_v[0];
      eta_i = d * d;
      d = O_w[7] - O_v[1];
      eta_i += d * d;
      d = O_w[8] - O_v[2];
      eta_i += d * d;
      st.site = &vb_emlrtRSI;
      if (eta_i < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      if (muDoubleScalarSqrt(eta_i) < allowed_rad) {
        condition_1 = true;
      } else {
        condition_1 = false;
      }
    }
  }

  d = O_w[0] - O_w[3];
  eta_i = d * d;
  d = O_w[1] - O_w[4];
  eta_i += d * d;
  d = O_w[2] - O_w[5];
  eta_i += d * d;
  st.site = &wb_emlrtRSI;
  if (eta_i < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  if (muDoubleScalarSqrt(eta_i) < allowed_rad) {
    condition_2 = true;
  } else {
    d = O_w[3] - O_w[6];
    eta_i = d * d;
    d = O_w[4] - O_w[7];
    eta_i += d * d;
    d = O_w[5] - O_w[8];
    eta_i += d * d;
    st.site = &wb_emlrtRSI;
    if (eta_i < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    if (muDoubleScalarSqrt(eta_i) < allowed_rad) {
      condition_2 = true;
    } else {
      d = O_w[0] - O_w[6];
      eta_i = d * d;
      d = O_w[1] - O_w[7];
      eta_i += d * d;
      d = O_w[2] - O_w[8];
      eta_i += d * d;
      st.site = &wb_emlrtRSI;
      if (eta_i < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 4, "sqrt");
      }

      if (muDoubleScalarSqrt(eta_i) < allowed_rad) {
        condition_2 = true;
      } else {
        condition_2 = false;
      }
    }
  }

  if (condition_1 || condition_2) {
    flag = true;
  } else {
    flag = false;
  }

  return flag;
}

/* End of code generation (Collision_check.c) */
