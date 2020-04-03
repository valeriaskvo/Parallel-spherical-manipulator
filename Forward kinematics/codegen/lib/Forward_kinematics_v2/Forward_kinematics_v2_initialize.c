/*
 * File: Forward_kinematics_v2_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:52:15
 */

/* Include Files */
#include "Forward_kinematics_v2_initialize.h"
#include "Forward_kinematics_v2.h"
#include "Forward_kinematics_v2_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void Forward_kinematics_v2_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_Forward_kinematics_v2 = true;
}

/*
 * File trailer for Forward_kinematics_v2_initialize.c
 *
 * [EOF]
 */
