/*
 * Workspace_calculation.h
 *
 * Code generation for function 'Workspace_calculation'
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
void Workspace_calculation(const emlrtStack *sp, const real_T system_parameters
  [5], const emxArray_real_T *phi_set, real_T allowed_radius, real_T version,
  emxArray_real_T *workspace);

/* End of code generation (Workspace_calculation.h) */
