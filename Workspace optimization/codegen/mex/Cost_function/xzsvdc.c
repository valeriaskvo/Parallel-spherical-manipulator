/*
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "Cost_function.h"
#include "Cost_function_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xrotg.h"

/* Variable Definitions */
static emlrtRSInfo ib_emlrtRSI = { 380,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = { 269,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pName */
};

/* Function Definitions */
void b_xzsvdc(const emlrtStack *sp, real_T A[36], real_T S[6])
{
  int32_T i;
  int32_T q;
  real_T s[6];
  real_T e[6];
  int32_T iy;
  int32_T qp1;
  real_T work[6];
  int32_T qq_tmp;
  int32_T qq;
  boolean_T apply_transform;
  int32_T ix;
  real_T nrm;
  real_T snorm;
  real_T scale;
  int32_T k;
  boolean_T exitg1;
  real_T absxk;
  real_T t;
  int32_T jj;
  int32_T exitg2;
  int32_T qjj;
  boolean_T exitg3;
  real_T sm;
  real_T sqds;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 6; i++) {
    s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }

  for (q = 0; q < 5; q++) {
    qp1 = q + 2;
    qq_tmp = q + 6 * q;
    qq = qq_tmp + 1;
    apply_transform = false;
    nrm = 0.0;
    scale = 3.3121686421112381E-170;
    i = (qq - q) + 5;
    for (k = qq; k <= i; k++) {
      absxk = muDoubleScalarAbs(A[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        nrm = nrm * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        nrm += t * t;
      }
    }

    nrm = scale * muDoubleScalarSqrt(nrm);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      s[q] = nrm;
      if (muDoubleScalarAbs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        for (k = qq; k <= i; k++) {
          A[k - 1] *= nrm;
        }
      } else {
        for (k = qq; k <= i; k++) {
          A[k - 1] /= s[q];
        }
      }

      A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (jj = qp1; jj < 7; jj++) {
      qjj = q + 6 * (jj - 1);
      if (apply_transform) {
        i = 5 - q;
        ix = qq;
        iy = qjj;
        nrm = 0.0;
        for (k = 0; k <= i; k++) {
          nrm += A[ix - 1] * A[iy];
          ix++;
          iy++;
        }

        nrm = -(nrm / A[qq_tmp]);
        if (!(nrm == 0.0)) {
          ix = qq - 1;
          iy = qjj;
          i = 5 - q;
          for (k = 0; k <= i; k++) {
            A[iy] += nrm * A[ix];
            ix++;
            iy++;
          }
        }
      }

      e[jj - 1] = A[qjj];
    }

    if (q + 1 <= 4) {
      nrm = b_xnrm2(5 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 7; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 7; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (jj = qp1; jj < 7; jj++) {
          work[jj - 1] = 0.0;
        }

        for (jj = qp1; jj < 7; jj++) {
          nrm = e[jj - 1];
          if (!(nrm == 0.0)) {
            ix = q + 6 * (jj - 1);
            iy = q + 1;
            i = 4 - q;
            for (k = 0; k <= i; k++) {
              work[iy] += nrm * A[ix + 1];
              ix++;
              iy++;
            }
          }
        }

        for (jj = qp1; jj < 7; jj++) {
          nrm = -e[jj - 1] / e[q + 1];
          if (!(nrm == 0.0)) {
            ix = q;
            iy = (q + 6 * (jj - 1)) + 1;
            i = 4 - q;
            for (k = 0; k <= i; k++) {
              A[iy] += nrm * work[ix + 1];
              ix++;
              iy++;
            }
          }
        }
      }
    }
  }

  iy = 4;
  s[5] = A[35];
  e[4] = A[34];
  e[5] = 0.0;
  ix = 0;
  snorm = 0.0;
  for (q = 0; q < 6; q++) {
    nrm = s[q];
    if (s[q] != 0.0) {
      absxk = muDoubleScalarAbs(s[q]);
      t = s[q] / absxk;
      nrm = absxk;
      s[q] = absxk;
      if (q + 1 < 6) {
        e[q] /= t;
      }
    }

    if ((q + 1 < 6) && (e[q] != 0.0)) {
      absxk = muDoubleScalarAbs(e[q]);
      t = absxk / e[q];
      e[q] = absxk;
      s[q + 1] *= t;
    }

    snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(nrm),
      muDoubleScalarAbs(e[q])));
  }

  exitg1 = false;
  while ((!exitg1) && (iy + 2 > 0)) {
    if (ix >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      jj = iy;
      do {
        exitg2 = 0;
        q = jj + 1;
        if (jj + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[jj]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[jj]) +
                muDoubleScalarAbs(s[jj + 1]))) || (nrm <=
               1.0020841800044864E-292) || ((ix > 20) && (nrm <=
                2.2204460492503131E-16 * snorm))) {
            e[jj] = 0.0;
            exitg2 = 1;
          } else {
            jj--;
          }
        }
      } while (exitg2 == 0);

      if (jj + 1 == iy + 1) {
        i = 4;
      } else {
        qjj = iy + 2;
        i = iy + 2;
        exitg3 = false;
        while ((!exitg3) && (i >= jj + 1)) {
          qjj = i;
          if (i == jj + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (i < iy + 2) {
              nrm = muDoubleScalarAbs(e[i - 1]);
            }

            if (i > jj + 2) {
              nrm += muDoubleScalarAbs(e[i - 2]);
            }

            absxk = muDoubleScalarAbs(s[i - 1]);
            if ((absxk <= 2.2204460492503131E-16 * nrm) || (absxk <=
                 1.0020841800044864E-292)) {
              s[i - 1] = 0.0;
              exitg3 = true;
            } else {
              i--;
            }
          }
        }

        if (qjj == jj + 1) {
          i = 3;
        } else if (qjj == iy + 2) {
          i = 1;
        } else {
          i = 2;
          q = qjj;
        }
      }

      switch (i) {
       case 1:
        absxk = e[iy];
        e[iy] = 0.0;
        i = iy + 1;
        for (k = i; k >= q + 1; k--) {
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          if (k > q + 1) {
            t = e[k - 2];
            absxk = -sqds * t;
            e[k - 2] = t * sm;
          }
        }
        break;

       case 2:
        absxk = e[q - 1];
        e[q - 1] = 0.0;
        for (k = q + 1; k <= iy + 2; k++) {
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          t = e[k - 1];
          absxk = -sqds * t;
          e[k - 1] = t * sm;
        }
        break;

       case 3:
        i = iy + 1;
        nrm = s[iy + 1];
        scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
          (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[iy])),
           muDoubleScalarAbs(e[iy])), muDoubleScalarAbs(s[q])),
          muDoubleScalarAbs(e[q]));
        sm = nrm / scale;
        nrm = s[iy] / scale;
        absxk = e[iy] / scale;
        sqds = s[q] / scale;
        t = ((nrm + sm) * (nrm - sm) + absxk * absxk) / 2.0;
        nrm = sm * absxk;
        nrm *= nrm;
        if ((t != 0.0) || (nrm != 0.0)) {
          absxk = t * t + nrm;
          st.site = &ib_emlrtRSI;
          if (absxk < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          absxk = muDoubleScalarSqrt(absxk);
          if (t < 0.0) {
            absxk = -absxk;
          }

          absxk = nrm / (t + absxk);
        } else {
          absxk = 0.0;
        }

        absxk += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        for (k = q + 1; k <= i; k++) {
          xrotg(&absxk, &nrm, &sm, &sqds);
          if (k > q + 1) {
            e[k - 2] = absxk;
          }

          nrm = e[k - 1];
          t = s[k - 1];
          e[k - 1] = sm * nrm - sqds * t;
          absxk = sqds * s[k];
          s[k] *= sm;
          s[k - 1] = sm * t + sqds * nrm;
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          absxk = sm * e[k - 1] + sqds * s[k];
          s[k] = -sqds * e[k - 1] + sm * s[k];
          nrm = sqds * e[k];
          e[k] *= sm;
        }

        e[iy] = absxk;
        ix++;
        break;

       default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
        }

        qp1 = q + 1;
        while ((q + 1 < 6) && (s[q] < s[qp1])) {
          absxk = s[q];
          s[q] = s[qp1];
          s[qp1] = absxk;
          q = qp1;
          qp1++;
        }

        ix = 0;
        iy--;
        break;
      }
    }
  }

  for (k = 0; k < 6; k++) {
    S[k] = s[k];
  }
}

void c_xzsvdc(const emlrtStack *sp, real_T A[25], real_T S[5])
{
  int32_T i;
  boolean_T apply_transform;
  real_T e[5];
  real_T nrm;
  real_T work[5];
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T s[5];
  real_T t;
  int32_T qjj;
  int32_T ix;
  int32_T iy;
  int32_T m;
  real_T snorm;
  int32_T q;
  boolean_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  real_T sm;
  real_T sqds;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 5; i++) {
    e[i] = 0.0;
    work[i] = 0.0;
  }

  apply_transform = false;
  nrm = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 1; k < 6; k++) {
    absxk = muDoubleScalarAbs(A[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrm = nrm * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrm += t * t;
    }
  }

  nrm = scale * muDoubleScalarSqrt(nrm);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[0] < 0.0) {
      t = -nrm;
    } else {
      t = nrm;
    }

    if (muDoubleScalarAbs(t) >= 1.0020841800044864E-292) {
      nrm = 1.0 / t;
      for (k = 1; k < 6; k++) {
        A[k - 1] *= nrm;
      }
    } else {
      for (k = 1; k < 6; k++) {
        A[k - 1] /= t;
      }
    }

    A[0]++;
    s[0] = -t;
  } else {
    s[0] = 0.0;
  }

  for (i = 2; i < 6; i++) {
    qjj = 5 * (i - 1);
    if (apply_transform) {
      ix = 1;
      iy = qjj;
      nrm = 0.0;
      for (k = 0; k < 5; k++) {
        nrm += A[ix - 1] * A[iy];
        ix++;
        iy++;
      }

      nrm = -(nrm / A[0]);
      if (!(nrm == 0.0)) {
        ix = 0;
        iy = qjj;
        for (k = 0; k < 5; k++) {
          A[iy] += nrm * A[ix];
          ix++;
          iy++;
        }
      }
    }

    e[i - 1] = A[qjj];
  }

  nrm = c_xnrm2(4, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }

    nrm = e[0];
    if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
      nrm = 1.0 / e[0];
      for (k = 2; k < 6; k++) {
        e[k - 1] *= nrm;
      }
    } else {
      for (k = 2; k < 6; k++) {
        e[k - 1] /= nrm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (i = 2; i < 6; i++) {
      work[i - 1] = 0.0;
    }

    for (i = 2; i < 6; i++) {
      t = e[i - 1];
      if (!(t == 0.0)) {
        ix = 5 * (i - 1);
        iy = 1;
        for (k = 0; k < 4; k++) {
          work[iy] += t * A[ix + 1];
          ix++;
          iy++;
        }
      }
    }

    for (i = 2; i < 6; i++) {
      nrm = -e[i - 1] / e[1];
      if (!(nrm == 0.0)) {
        ix = 0;
        iy = 5 * (i - 1) + 1;
        for (k = 0; k < 4; k++) {
          A[iy] += nrm * work[ix + 1];
          ix++;
          iy++;
        }
      }
    }
  }

  apply_transform = false;
  nrm = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 7; k < 11; k++) {
    absxk = muDoubleScalarAbs(A[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrm = nrm * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrm += t * t;
    }
  }

  nrm = scale * muDoubleScalarSqrt(nrm);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[6] < 0.0) {
      t = -nrm;
    } else {
      t = nrm;
    }

    if (muDoubleScalarAbs(t) >= 1.0020841800044864E-292) {
      nrm = 1.0 / t;
      for (k = 7; k < 11; k++) {
        A[k - 1] *= nrm;
      }
    } else {
      for (k = 7; k < 11; k++) {
        A[k - 1] /= t;
      }
    }

    A[6]++;
    s[1] = -t;
  } else {
    s[1] = 0.0;
  }

  for (i = 3; i < 6; i++) {
    qjj = 5 * (i - 1) + 1;
    if (apply_transform) {
      ix = 7;
      iy = qjj;
      nrm = 0.0;
      for (k = 0; k < 4; k++) {
        nrm += A[ix - 1] * A[iy];
        ix++;
        iy++;
      }

      nrm = -(nrm / A[6]);
      if (!(nrm == 0.0)) {
        ix = 6;
        iy = qjj;
        for (k = 0; k < 4; k++) {
          A[iy] += nrm * A[ix];
          ix++;
          iy++;
        }
      }
    }

    e[i - 1] = A[qjj];
  }

  nrm = c_xnrm2(3, e, 3);
  if (nrm == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -nrm;
    } else {
      e[1] = nrm;
    }

    nrm = e[1];
    if (muDoubleScalarAbs(e[1]) >= 1.0020841800044864E-292) {
      nrm = 1.0 / e[1];
      for (k = 3; k < 6; k++) {
        e[k - 1] *= nrm;
      }
    } else {
      for (k = 3; k < 6; k++) {
        e[k - 1] /= nrm;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (i = 3; i < 6; i++) {
      work[i - 1] = 0.0;
    }

    for (i = 3; i < 6; i++) {
      t = e[i - 1];
      if (!(t == 0.0)) {
        ix = 5 * (i - 1) + 1;
        iy = 2;
        for (k = 0; k < 3; k++) {
          work[iy] += t * A[ix + 1];
          ix++;
          iy++;
        }
      }
    }

    for (i = 3; i < 6; i++) {
      nrm = -e[i - 1] / e[2];
      if (!(nrm == 0.0)) {
        ix = 1;
        iy = 5 * (i - 1) + 2;
        for (k = 0; k < 3; k++) {
          A[iy] += nrm * work[ix + 1];
          ix++;
          iy++;
        }
      }
    }
  }

  apply_transform = false;
  nrm = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 13; k < 16; k++) {
    absxk = muDoubleScalarAbs(A[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrm = nrm * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrm += t * t;
    }
  }

  nrm = scale * muDoubleScalarSqrt(nrm);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[12] < 0.0) {
      t = -nrm;
    } else {
      t = nrm;
    }

    if (muDoubleScalarAbs(t) >= 1.0020841800044864E-292) {
      nrm = 1.0 / t;
      for (k = 13; k < 16; k++) {
        A[k - 1] *= nrm;
      }
    } else {
      for (k = 13; k < 16; k++) {
        A[k - 1] /= t;
      }
    }

    A[12]++;
    s[2] = -t;
  } else {
    s[2] = 0.0;
  }

  for (i = 4; i < 6; i++) {
    qjj = 5 * (i - 1) + 2;
    if (apply_transform) {
      ix = 13;
      iy = qjj;
      nrm = 0.0;
      for (k = 0; k < 3; k++) {
        nrm += A[ix - 1] * A[iy];
        ix++;
        iy++;
      }

      nrm = -(nrm / A[12]);
      if (!(nrm == 0.0)) {
        ix = 12;
        iy = qjj;
        for (k = 0; k < 3; k++) {
          A[iy] += nrm * A[ix];
          ix++;
          iy++;
        }
      }
    }

    e[i - 1] = A[qjj];
  }

  nrm = c_xnrm2(2, e, 4);
  if (nrm == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -nrm;
    } else {
      e[2] = nrm;
    }

    nrm = e[2];
    if (muDoubleScalarAbs(e[2]) >= 1.0020841800044864E-292) {
      nrm = 1.0 / e[2];
      for (k = 4; k < 6; k++) {
        e[k - 1] *= nrm;
      }
    } else {
      for (k = 4; k < 6; k++) {
        e[k - 1] /= nrm;
      }
    }

    e[3]++;
    e[2] = -e[2];
    for (i = 4; i < 6; i++) {
      work[i - 1] = 0.0;
    }

    for (i = 4; i < 6; i++) {
      t = e[i - 1];
      if (!(t == 0.0)) {
        ix = 5 * (i - 1) + 2;
        iy = 3;
        for (k = 0; k < 2; k++) {
          work[iy] += t * A[ix + 1];
          ix++;
          iy++;
        }
      }
    }

    for (i = 4; i < 6; i++) {
      nrm = -e[i - 1] / e[3];
      if (!(nrm == 0.0)) {
        ix = 2;
        iy = 5 * (i - 1) + 3;
        for (k = 0; k < 2; k++) {
          A[iy] += nrm * work[ix + 1];
          ix++;
          iy++;
        }
      }
    }
  }

  apply_transform = false;
  nrm = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 19; k < 21; k++) {
    absxk = muDoubleScalarAbs(A[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrm = nrm * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrm += t * t;
    }
  }

  nrm = scale * muDoubleScalarSqrt(nrm);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[18] < 0.0) {
      t = -nrm;
    } else {
      t = nrm;
    }

    if (muDoubleScalarAbs(t) >= 1.0020841800044864E-292) {
      nrm = 1.0 / t;
      for (k = 19; k < 21; k++) {
        A[k - 1] *= nrm;
      }
    } else {
      for (k = 19; k < 21; k++) {
        A[k - 1] /= t;
      }
    }

    A[18]++;
    s[3] = -t;
  } else {
    s[3] = 0.0;
  }

  for (i = 5; i < 6; i++) {
    if (apply_transform) {
      ix = 19;
      iy = 23;
      nrm = 0.0;
      for (k = 0; k < 2; k++) {
        nrm += A[ix - 1] * A[iy];
        ix++;
        iy++;
      }

      nrm = -(nrm / A[18]);
      if (!(nrm == 0.0)) {
        ix = 18;
        iy = 23;
        for (k = 0; k < 2; k++) {
          A[iy] += nrm * A[ix];
          ix++;
          iy++;
        }
      }
    }
  }

  m = 3;
  s[4] = A[24];
  e[3] = A[23];
  e[4] = 0.0;
  iy = 0;
  snorm = 0.0;
  for (q = 0; q < 5; q++) {
    t = s[q];
    if (s[q] != 0.0) {
      nrm = muDoubleScalarAbs(s[q]);
      absxk = s[q] / nrm;
      t = nrm;
      s[q] = nrm;
      if (q + 1 < 5) {
        e[q] /= absxk;
      }
    }

    if ((q + 1 < 5) && (e[q] != 0.0)) {
      nrm = muDoubleScalarAbs(e[q]);
      absxk = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= absxk;
    }

    snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(t),
      muDoubleScalarAbs(e[q])));
  }

  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iy >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      i = m;
      do {
        exitg2 = 0;
        q = i + 1;
        if (i + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[i]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[i]) +
                muDoubleScalarAbs(s[i + 1]))) || (nrm <= 1.0020841800044864E-292)
              || ((iy > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
            e[i] = 0.0;
            exitg2 = 1;
          } else {
            i--;
          }
        }
      } while (exitg2 == 0);

      if (i + 1 == m + 1) {
        i = 4;
      } else {
        ix = m + 2;
        qjj = m + 2;
        exitg3 = false;
        while ((!exitg3) && (qjj >= i + 1)) {
          ix = qjj;
          if (qjj == i + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 2) {
              nrm = muDoubleScalarAbs(e[qjj - 1]);
            }

            if (qjj > i + 2) {
              nrm += muDoubleScalarAbs(e[qjj - 2]);
            }

            absxk = muDoubleScalarAbs(s[qjj - 1]);
            if ((absxk <= 2.2204460492503131E-16 * nrm) || (absxk <=
                 1.0020841800044864E-292)) {
              s[qjj - 1] = 0.0;
              exitg3 = true;
            } else {
              qjj--;
            }
          }
        }

        if (ix == i + 1) {
          i = 3;
        } else if (ix == m + 2) {
          i = 1;
        } else {
          i = 2;
          q = ix;
        }
      }

      switch (i) {
       case 1:
        absxk = e[m];
        e[m] = 0.0;
        i = m + 1;
        for (k = i; k >= q + 1; k--) {
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          if (k > q + 1) {
            t = e[k - 2];
            absxk = -sqds * t;
            e[k - 2] = t * sm;
          }
        }
        break;

       case 2:
        absxk = e[q - 1];
        e[q - 1] = 0.0;
        for (k = q + 1; k <= m + 2; k++) {
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          t = e[k - 1];
          absxk = -sqds * t;
          e[k - 1] = t * sm;
        }
        break;

       case 3:
        i = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
          (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
           muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])), muDoubleScalarAbs
          (e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        absxk = e[m] / scale;
        sqds = s[q] / scale;
        t = ((nrm + sm) * (nrm - sm) + absxk * absxk) / 2.0;
        nrm = sm * absxk;
        nrm *= nrm;
        if ((t != 0.0) || (nrm != 0.0)) {
          absxk = t * t + nrm;
          st.site = &ib_emlrtRSI;
          if (absxk < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          absxk = muDoubleScalarSqrt(absxk);
          if (t < 0.0) {
            absxk = -absxk;
          }

          absxk = nrm / (t + absxk);
        } else {
          absxk = 0.0;
        }

        absxk += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        for (k = q + 1; k <= i; k++) {
          xrotg(&absxk, &nrm, &sm, &sqds);
          if (k > q + 1) {
            e[k - 2] = absxk;
          }

          nrm = e[k - 1];
          t = s[k - 1];
          e[k - 1] = sm * nrm - sqds * t;
          absxk = sqds * s[k];
          s[k] *= sm;
          s[k - 1] = sm * t + sqds * nrm;
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          absxk = sm * e[k - 1] + sqds * s[k];
          s[k] = -sqds * e[k - 1] + sm * s[k];
          nrm = sqds * e[k];
          e[k] *= sm;
        }

        e[m] = absxk;
        iy++;
        break;

       default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
        }

        i = q + 1;
        while ((q + 1 < 5) && (s[q] < s[i])) {
          nrm = s[q];
          s[q] = s[i];
          s[i] = nrm;
          q = i;
          i++;
        }

        iy = 0;
        m--;
        break;
      }
    }
  }

  for (k = 0; k < 5; k++) {
    S[k] = s[k];
  }
}

void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3])
{
  real_T e[3];
  real_T work[3];
  boolean_T apply_transform;
  real_T nrm;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T s[3];
  real_T t;
  int32_T kase;
  int32_T qjj;
  int32_T ix;
  int32_T iy;
  int32_T m;
  int32_T iter;
  real_T snorm;
  boolean_T exitg1;
  int32_T exitg2;
  int32_T q;
  boolean_T exitg3;
  real_T sm;
  real_T sqds;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  e[0] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  apply_transform = false;
  nrm = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 1; k < 4; k++) {
    absxk = muDoubleScalarAbs(A[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrm = nrm * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrm += t * t;
    }
  }

  nrm = scale * muDoubleScalarSqrt(nrm);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[0] < 0.0) {
      t = -nrm;
    } else {
      t = nrm;
    }

    if (muDoubleScalarAbs(t) >= 1.0020841800044864E-292) {
      nrm = 1.0 / t;
      for (k = 1; k < 4; k++) {
        A[k - 1] *= nrm;
      }
    } else {
      for (k = 1; k < 4; k++) {
        A[k - 1] /= t;
      }
    }

    A[0]++;
    s[0] = -t;
  } else {
    s[0] = 0.0;
  }

  for (kase = 2; kase < 4; kase++) {
    qjj = 3 * (kase - 1);
    if (apply_transform) {
      ix = 1;
      iy = qjj;
      nrm = 0.0;
      for (k = 0; k < 3; k++) {
        nrm += A[ix - 1] * A[iy];
        ix++;
        iy++;
      }

      nrm = -(nrm / A[0]);
      if (!(nrm == 0.0)) {
        ix = 0;
        iy = qjj;
        for (k = 0; k < 3; k++) {
          A[iy] += nrm * A[ix];
          ix++;
          iy++;
        }
      }
    }

    e[kase - 1] = A[qjj];
  }

  nrm = xnrm2(e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }

    nrm = e[0];
    if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
      nrm = 1.0 / e[0];
      for (k = 2; k < 4; k++) {
        e[k - 1] *= nrm;
      }
    } else {
      for (k = 2; k < 4; k++) {
        e[k - 1] /= nrm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (qjj = 2; qjj < 4; qjj++) {
      work[qjj - 1] = 0.0;
    }

    for (kase = 2; kase < 4; kase++) {
      t = e[kase - 1];
      if (!(t == 0.0)) {
        ix = 3 * (kase - 1);
        work[1] += t * A[ix + 1];
        ix++;
        work[2] += t * A[ix + 1];
      }
    }

    for (kase = 2; kase < 4; kase++) {
      nrm = -e[kase - 1] / e[1];
      if (!(nrm == 0.0)) {
        iy = 3 * (kase - 1) + 1;
        A[iy] += nrm * work[1];
        iy++;
        A[iy] += nrm * work[2];
      }
    }
  }

  apply_transform = false;
  nrm = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 5; k < 7; k++) {
    absxk = muDoubleScalarAbs(A[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrm = nrm * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrm += t * t;
    }
  }

  nrm = scale * muDoubleScalarSqrt(nrm);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[4] < 0.0) {
      t = -nrm;
    } else {
      t = nrm;
    }

    if (muDoubleScalarAbs(t) >= 1.0020841800044864E-292) {
      nrm = 1.0 / t;
      for (k = 5; k < 7; k++) {
        A[k - 1] *= nrm;
      }
    } else {
      for (k = 5; k < 7; k++) {
        A[k - 1] /= t;
      }
    }

    A[4]++;
    s[1] = -t;
  } else {
    s[1] = 0.0;
  }

  for (kase = 3; kase < 4; kase++) {
    if (apply_transform) {
      ix = 5;
      iy = 7;
      nrm = 0.0;
      for (k = 0; k < 2; k++) {
        nrm += A[ix - 1] * A[iy];
        ix++;
        iy++;
      }

      nrm = -(nrm / A[4]);
      if (!(nrm == 0.0)) {
        ix = 4;
        iy = 7;
        for (k = 0; k < 2; k++) {
          A[iy] += nrm * A[ix];
          ix++;
          iy++;
        }
      }
    }
  }

  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  iter = 0;
  t = s[0];
  if (s[0] != 0.0) {
    nrm = muDoubleScalarAbs(s[0]);
    absxk = s[0] / nrm;
    t = nrm;
    s[0] = nrm;
    e[0] /= absxk;
  }

  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    absxk = nrm / e[0];
    e[0] = nrm;
    s[1] *= absxk;
  }

  snorm = muDoubleScalarMax(muDoubleScalarAbs(t), e[0]);
  t = s[1];
  if (s[1] != 0.0) {
    nrm = muDoubleScalarAbs(s[1]);
    absxk = s[1] / nrm;
    t = nrm;
    s[1] = nrm;
    e[1] = A[7] / absxk;
  }

  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    absxk = nrm / e[1];
    e[1] = nrm;
    s[2] = A[8] * absxk;
  }

  snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(t), e[1]));
  t = s[2];
  if (s[2] != 0.0) {
    nrm = muDoubleScalarAbs(s[2]);
    t = nrm;
    s[2] = nrm;
  }

  snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(t), 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      qjj = m;
      do {
        exitg2 = 0;
        q = qjj + 1;
        if (qjj + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[qjj]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[qjj]) +
                muDoubleScalarAbs(s[qjj + 1]))) || (nrm <=
               1.0020841800044864E-292) || ((iter > 20) && (nrm <=
                2.2204460492503131E-16 * snorm))) {
            e[qjj] = 0.0;
            exitg2 = 1;
          } else {
            qjj--;
          }
        }
      } while (exitg2 == 0);

      if (qjj + 1 == m + 1) {
        kase = 4;
      } else {
        iy = m + 2;
        ix = m + 2;
        exitg3 = false;
        while ((!exitg3) && (ix >= qjj + 1)) {
          iy = ix;
          if (ix == qjj + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (ix < m + 2) {
              nrm = muDoubleScalarAbs(e[ix - 1]);
            }

            if (ix > qjj + 2) {
              nrm += muDoubleScalarAbs(e[ix - 2]);
            }

            absxk = muDoubleScalarAbs(s[ix - 1]);
            if ((absxk <= 2.2204460492503131E-16 * nrm) || (absxk <=
                 1.0020841800044864E-292)) {
              s[ix - 1] = 0.0;
              exitg3 = true;
            } else {
              ix--;
            }
          }
        }

        if (iy == qjj + 1) {
          kase = 3;
        } else if (iy == m + 2) {
          kase = 1;
        } else {
          kase = 2;
          q = iy;
        }
      }

      switch (kase) {
       case 1:
        absxk = e[m];
        e[m] = 0.0;
        qjj = m + 1;
        for (k = qjj; k >= q + 1; k--) {
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          if (k > q + 1) {
            absxk = -sqds * e[0];
            e[0] *= sm;
          }
        }
        break;

       case 2:
        absxk = e[q - 1];
        e[q - 1] = 0.0;
        for (k = q + 1; k <= m + 2; k++) {
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          t = e[k - 1];
          absxk = -sqds * t;
          e[k - 1] = t * sm;
        }
        break;

       case 3:
        qjj = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
          (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
           muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])), muDoubleScalarAbs
          (e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        absxk = e[m] / scale;
        sqds = s[q] / scale;
        t = ((nrm + sm) * (nrm - sm) + absxk * absxk) / 2.0;
        nrm = sm * absxk;
        nrm *= nrm;
        if ((t != 0.0) || (nrm != 0.0)) {
          absxk = t * t + nrm;
          st.site = &ib_emlrtRSI;
          if (absxk < 0.0) {
            emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
              "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
              3, 4, 4, "sqrt");
          }

          absxk = muDoubleScalarSqrt(absxk);
          if (t < 0.0) {
            absxk = -absxk;
          }

          absxk = nrm / (t + absxk);
        } else {
          absxk = 0.0;
        }

        absxk += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        for (k = q + 1; k <= qjj; k++) {
          xrotg(&absxk, &nrm, &sm, &sqds);
          if (k > q + 1) {
            e[0] = absxk;
          }

          nrm = e[k - 1];
          t = s[k - 1];
          e[k - 1] = sm * nrm - sqds * t;
          absxk = sqds * s[k];
          s[k] *= sm;
          s[k - 1] = sm * t + sqds * nrm;
          xrotg(&s[k - 1], &absxk, &sm, &sqds);
          absxk = sm * e[k - 1] + sqds * s[k];
          s[k] = -sqds * e[k - 1] + sm * s[k];
          nrm = sqds * e[k];
          e[k] *= sm;
        }

        e[m] = absxk;
        iter++;
        break;

       default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
        }

        kase = q + 1;
        while ((q + 1 < 3) && (s[q] < s[kase])) {
          nrm = s[q];
          s[q] = s[kase];
          s[kase] = nrm;
          q = kase;
          kase++;
        }

        iter = 0;
        m--;
        break;
      }
    }
  }

  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

/* End of code generation (xzsvdc.c) */
