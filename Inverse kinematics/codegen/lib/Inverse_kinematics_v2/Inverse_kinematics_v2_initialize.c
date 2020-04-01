/*
 * File: Inverse_kinematics_v2_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:39:04
 */

/* Include Files */
#include "Inverse_kinematics_v2_initialize.h"
#include "Inverse_kinematics_v2.h"
#include "Inverse_kinematics_v2_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void Inverse_kinematics_v2_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_Inverse_kinematics_v2 = true;
}

/*
 * File trailer for Inverse_kinematics_v2_initialize.c
 *
 * [EOF]
 */
