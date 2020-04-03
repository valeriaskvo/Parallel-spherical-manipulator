/*
 * File: BFGSUpdate.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef BFGSUPDATE_H
#define BFGSUPDATE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern boolean_T BFGSUpdate(int nvar, double Bk[25], const double sk[6], double
  yk[6], double workspace[36]);

#endif

/*
 * File trailer for BFGSUpdate.h
 *
 * [EOF]
 */
