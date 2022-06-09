/*
 * File: Inverse_kinematics.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 11:57:13
 */

#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Inverse_kinematics_v2_types.h"

/* Function Declarations */
extern void Inverse_kinematics(double eta_i, const double system_parameters[5],
  const double phi_ee[3], double q[3]);

#endif

/*
 * File trailer for Inverse_kinematics.h
 *
 * [EOF]
 */
