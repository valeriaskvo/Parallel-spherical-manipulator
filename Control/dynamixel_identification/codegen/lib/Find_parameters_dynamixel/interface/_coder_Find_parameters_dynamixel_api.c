/*
 * File: _coder_Find_parameters_dynamixel_api.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "_coder_Find_parameters_dynamixel_api.h"
#include "_coder_Find_parameters_dynamixel_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "Find_parameters_dynamixel",         /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const real_T u[9]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dtype, const
  char_T *identifier, rtString *y);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *N, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u[3]);
static void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFreeStruct_rtString(rtString *pStruct);
static void emxFree_char_T(emxArray_char_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInitStruct_rtString(const emlrtStack *sp, rtString *pStruct,
  boolean_T doPush);
static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, rtString *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *t
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(t), &thisId, y);
  emlrtDestroyArray(&t);
}

/*
 * Arguments    : const real_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u[9])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 3, 3 };

  y = NULL;
  m = emlrtCreateNumericArray(2, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  y = NULL;
  m = emlrtCreateNumericArray(1, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *dtype
 *                const char_T *identifier
 *                rtString *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *dtype, const
  char_T *identifier, rtString *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(dtype), &thisId, y);
  emlrtDestroyArray(&dtype);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *N
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *N, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(N), &thisId);
  emlrtDestroyArray(&N);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[3])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 3 };

  y = NULL;
  m = emlrtCreateNumericArray(1, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : emxArray_char_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : rtString *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_rtString(rtString *pStruct)
{
  emxFree_char_T(&pStruct->Value);
}

/*
 * Arguments    : emxArray_char_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                rtString *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_rtString(const emlrtStack *sp, rtString *pStruct,
  boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->Value, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_char_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocMex(sizeof(emxArray_char_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_char_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                rtString *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, rtString *y)
{
  const mxArray *propValues[1];
  emlrtMsgIdentifier thisId;
  const char * propNames[1] = { "Value" };

  const char * propClasses[1] = { "coder.internal.string" };

  propValues[0] = NULL;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(sp, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(sp, u, 0,
    "coder.internal.string"));
  emlrtCheckMcosClass2017a(sp, parentId, u, "coder.internal.string");
  emlrtGetAllProperties(sp, u, 0, 1, propNames, propClasses, propValues);
  thisId.fIdentifier = "Value";
  g_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y->Value);
  emlrtDestroyArrays(1, (const mxArray **)&propValues);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_char_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  ret->allocatedSize = iv[0];
  i = ret->size[0];
  ret->size[0] = iv[0];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_char_T *ret
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv[0], iv);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(ret, i);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[5]
 * Return Type  : void
 */
void Find_parameters_dynamixel_api(const mxArray * const prhs[8], int32_T nlhs,
  const mxArray *plhs[5])
{
  real_T (*p)[3];
  real_T (*R)[9];
  emxArray_real_T *t;
  emxArray_real_T *dtheta;
  emxArray_real_T *ddtheta;
  emxArray_real_T *b_I;
  rtString dtype;
  emxArray_real_T *p_s;
  emxArray_real_T *R_s;
  emxArray_real_T *time;
  real_T N;
  real_T k_dtheta;
  real_T K_m;
  rtString b_dtype;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  p = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  R = (real_T (*)[9])mxMalloc(sizeof(real_T [9]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &t, 1, true);
  emxInit_real_T(&st, &dtheta, 1, true);
  emxInit_real_T(&st, &ddtheta, 1, true);
  emxInit_real_T(&st, &b_I, 1, true);
  emxInitStruct_rtString(&st, &dtype, true);
  emxInit_real_T(&st, &p_s, 2, true);
  emxInit_real_T(&st, &R_s, 2, true);
  emxInit_real_T(&st, &time, 1, true);

  /* Marshall function inputs */
  N = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "N");
  t->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "t", t);
  dtheta->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "dtheta", dtheta);
  ddtheta->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "ddtheta", ddtheta);
  b_I->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "I", b_I);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "dtype", &dtype);
  k_dtheta = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "k_dtheta");
  K_m = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "K_m");

  /* Invoke the target function */
  b_dtype = dtype;
  Find_parameters_dynamixel(N, t, dtheta, ddtheta, b_I, &b_dtype, k_dtheta, K_m,
    *p, p_s, *R, R_s, time);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*p);
  emxFreeStruct_rtString(&dtype);
  emxFree_real_T(&b_I);
  emxFree_real_T(&ddtheta);
  emxFree_real_T(&dtheta);
  emxFree_real_T(&t);
  if (nlhs > 1) {
    p_s->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(p_s);
  }

  emxFree_real_T(&p_s);
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(*R);
  }

  if (nlhs > 3) {
    R_s->canFreeData = false;
    plhs[3] = b_emlrt_marshallOut(R_s);
  }

  emxFree_real_T(&R_s);
  if (nlhs > 4) {
    time->canFreeData = false;
    plhs[4] = d_emlrt_marshallOut(time);
  }

  emxFree_real_T(&time);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Find_parameters_dynamixel_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  Find_parameters_dynamixel_xil_terminate();
  Find_parameters_dynamixel_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Find_parameters_dynamixel_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Find_parameters_dynamixel_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_Find_parameters_dynamixel_api.c
 *
 * [EOF]
 */
