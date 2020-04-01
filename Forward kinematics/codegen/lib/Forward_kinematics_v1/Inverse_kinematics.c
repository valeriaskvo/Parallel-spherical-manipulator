/*
 * File: Inverse_kinematics.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "Inverse_kinematics.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : double A
 *                double B
 *                double C
 *                double mu_1
 * Return Type  : double
 */
double Inverse_kinematic_solver(double A, double B, double C, double mu_1)
{
  double theta;
  double d;
  double d1;
  if ((A == 0.0) && (B == 0.0)) {
    theta = rtInf;
  } else if (A == 0.0) {
    theta = 2.0 * atan(-B / C);
  } else {
    d = B * B;
    d1 = 4.0 * A * C;
    if (d < d1) {
      theta = rtInf;
    } else if (d == d1) {
      theta = 2.0 * atan(-B / (2.0 * A));
    } else if (mu_1 != 0.0) {
      theta = 2.0 * atan((-B - sqrt(B * B - 4.0 * A * C)) / (2.0 * A));
    } else {
      theta = 2.0 * atan((-B + sqrt(d - d1)) / (2.0 * A));
    }
  }

  return theta;
}

/*
 * File trailer for Inverse_kinematics.c
 *
 * [EOF]
 */
