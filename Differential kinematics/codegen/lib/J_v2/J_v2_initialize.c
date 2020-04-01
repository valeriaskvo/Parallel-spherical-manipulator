/*
 * File: J_v2_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:04:06
 */

/* Include Files */
#include "J_v2_initialize.h"
#include "J_v2.h"
#include "J_v2_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void J_v2_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_J_v2 = true;
}

/*
 * File trailer for J_v2_initialize.c
 *
 * [EOF]
 */
