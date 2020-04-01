/*
 * File: Inverse_kinematics_v1_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:37:01
 */

/* Include Files */
#include "Inverse_kinematics_v1_initialize.h"
#include "Inverse_kinematics_v1.h"
#include "Inverse_kinematics_v1_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void Inverse_kinematics_v1_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_Inverse_kinematics_v1 = true;
}

/*
 * File trailer for Inverse_kinematics_v1_initialize.c
 *
 * [EOF]
 */
