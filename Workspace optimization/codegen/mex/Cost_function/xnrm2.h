/*
 * xnrm2.h
 *
 * Code generation for function 'xnrm2'
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
real_T b_xnrm2(int32_T n, const real_T x[6], int32_T ix0);
real_T c_xnrm2(int32_T n, const real_T x[5], int32_T ix0);
real_T xnrm2(const real_T x[3], int32_T ix0);

/* End of code generation (xnrm2.h) */
