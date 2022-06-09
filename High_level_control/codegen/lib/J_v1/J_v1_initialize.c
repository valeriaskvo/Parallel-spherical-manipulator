/*
 * File: J_v1_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:02:07
 */

/* Include Files */
#include "J_v1_initialize.h"
#include "J_v1.h"
#include "J_v1_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void J_v1_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_J_v1 = true;
}

/*
 * File trailer for J_v1_initialize.c
 *
 * [EOF]
 */
