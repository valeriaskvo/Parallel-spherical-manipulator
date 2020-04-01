/*
 * File: computeLambdaLSQ.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

#ifndef COMPUTELAMBDALSQ_H
#define COMPUTELAMBDALSQ_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void computeLambdaLSQ(int nVar, int mConstr, i_struct_T *QRManager, const
  double ATwset[6], const double grad[6], double *lambdaLSQ, double workspace[36]);

#endif

/*
 * File trailer for computeLambdaLSQ.h
 *
 * [EOF]
 */
