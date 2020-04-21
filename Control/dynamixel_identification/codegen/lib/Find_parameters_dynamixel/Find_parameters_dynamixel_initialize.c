/*
 * File: Find_parameters_dynamixel_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
 */

/* Include Files */
#include "Find_parameters_dynamixel_initialize.h"
#include "Find_parameters_dynamixel.h"
#include "Find_parameters_dynamixel_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void Find_parameters_dynamixel_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_Find_parameters_dynamixel = true;
}

/*
 * File trailer for Find_parameters_dynamixel_initialize.c
 *
 * [EOF]
 */
