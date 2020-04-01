/*
 * Cost_function.h
 *
 * Code generation for function 'Cost_function'
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
real_T Cost_function(const emlrtStack *sp, const real_T x[3], real_T
                     system_parameters[5], const emxArray_real_T *phi_set,
                     real_T allowed_radius, real_T version);

/* End of code generation (Cost_function.h) */
