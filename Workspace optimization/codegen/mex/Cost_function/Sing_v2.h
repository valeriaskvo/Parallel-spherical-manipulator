/*
 * Sing_v2.h
 *
 * Code generation for function 'Sing_v2'
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
void Sing_v2(const emlrtStack *sp, const real_T system_parameters[5], const
             real_T phi_ee[3], boolean_T *flag_ser, boolean_T *flag_par);

/* End of code generation (Sing_v2.h) */
