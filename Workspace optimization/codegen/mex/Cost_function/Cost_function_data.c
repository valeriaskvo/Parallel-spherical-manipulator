/*
 * Cost_function_data.c
 *
 * Code generation for function 'Cost_function_data'
 *
 */

/* Include files */
#include "Cost_function_data.h"
#include "Cost_function.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "Cost_function",                     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo k_emlrtRSI = { 29,         /* lineNo */
  "A_q1",                              /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\A_q1.m"/* pathName */
};

emlrtRSInfo l_emlrtRSI = { 55,         /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

emlrtRSInfo m_emlrtRSI = { 23,         /* lineNo */
  "B_q1",                              /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\B_q1.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 29,         /* lineNo */
  "C_q1",                              /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\C_q1.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 35,         /* lineNo */
  "Inverse_kinematic_solver",          /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 37,         /* lineNo */
  "Inverse_kinematic_solver",          /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Inverse kinematics\\Inverse_kinematics.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 45,         /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 10,         /* lineNo */
  "Sing_v1",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v1.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 13,         /* lineNo */
  "Sing_v1",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v1.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 21,         /* lineNo */
  "Sing_v1",                           /* fcnName */
  "C:\\Users\\valer\\Documents\\Innopolis\\Diploma work\\PSM git\\Workspace optimization\\Sing_v1.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 11,         /* lineNo */
  "rank",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 20,         /* lineNo */
  "local_rank",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 22,        /* lineNo */
  "local_rank",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 15,        /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 29,        /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 101,       /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 34,        /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 407,       /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 394,       /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 353,       /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 334,       /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 28,        /* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 27,        /* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 46,        /* lineNo */
  "eps",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m"/* pathName */
};

emlrtRTEInfo emlrtRTEI = { 13,         /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* End of code generation (Cost_function_data.c) */
