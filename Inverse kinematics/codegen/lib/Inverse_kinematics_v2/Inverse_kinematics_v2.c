/*
 * File: Inverse_kinematics_v2.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:39:04
 */

/* Include Files */
#include "Inverse_kinematics_v2.h"
#include "Inverse_kinematics.h"
#include "Inverse_kinematics_v2_data.h"
#include "Inverse_kinematics_v2_initialize.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double system_parameters[5]
 *                const double phi_ee[3]
 *                double q_v2[4]
 * Return Type  : void
 */
void Inverse_kinematics_v2(const double system_parameters[5], const double
  phi_ee[3], double q_v2[4])
{
  double q[3];
  if (isInitialized_Inverse_kinematics_v2 == false) {
    Inverse_kinematics_v2_initialize();
  }

  Inverse_kinematics(0.0, system_parameters, phi_ee, q);
  q_v2[0] = q[0];
  q_v2[1] = q[1];
  Inverse_kinematics(2.0943951023931953, system_parameters, phi_ee, q);
  q_v2[2] = q[1];
  Inverse_kinematics(4.1887902047863905, system_parameters, phi_ee, q);
  q_v2[3] = q[1];
}

/*
 * File trailer for Inverse_kinematics_v2.c
 *
 * [EOF]
 */
