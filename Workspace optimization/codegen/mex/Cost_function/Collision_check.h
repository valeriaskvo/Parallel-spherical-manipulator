/*
 * Collision_check.h
 *
 * Code generation for function 'Collision_check'
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
boolean_T Collision_check(const emlrtStack *sp, const real_T system_parameters[5],
  const real_T phi_ee[3], real_T allowed_rad);

/* End of code generation (Collision_check.h) */
