/*
 * File: BFGSUpdate.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

#ifndef BFGSUPDATE_H
#define BFGSUPDATE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern boolean_T BFGSUpdate(int nvar, double Bk[36], const double sk[7], double
  yk[7], double workspace[49]);

#endif

/*
 * File trailer for BFGSUpdate.h
 *
 * [EOF]
 */
