/*
 * File: xgemv.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

#ifndef XGEMV_H
#define XGEMV_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern void b_xgemv(int m, int n, int lda, const double x[7], double y[49]);
extern void xgemv(int m, int n, const double A[49], const double x[7], double y
                  [49]);

#endif

/*
 * File trailer for xgemv.h
 *
 * [EOF]
 */
