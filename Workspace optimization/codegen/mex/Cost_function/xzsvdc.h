/*
 * xzsvdc.h
 *
 * Code generation for function 'xzsvdc'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Cost_function_types.h"

/* Function Declarations */
void b_xzsvdc(const emlrtStack *sp, real_T A[36], real_T S[6]);
void c_xzsvdc(const emlrtStack *sp, real_T A[25], real_T S[5]);
void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3]);

/* End of code generation (xzsvdc.h) */
