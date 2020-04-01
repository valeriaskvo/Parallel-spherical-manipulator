/*
 * Inverse_kinematics.h
 *
 * Code generation for function 'Inverse_kinematics'
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
void Inverse_kinematics(const emlrtStack *sp, real_T eta_i, const real_T
  system_parameters[5], const real_T phi_ee[3], real_T q[3]);

/* End of code generation (Inverse_kinematics.h) */
