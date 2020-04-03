/*
 * File: xgemm.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

#ifndef XGEMM_H
#define XGEMM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v1_types.h"

/* Function Declarations */
extern void b_xgemm(int m, int n, int k, const double A[49], int ia0, const
                    double B[49], double C[49]);
extern void xgemm(int m, int n, int k, const double A[36], int lda, const double
                  B[49], int ib0, double C[49]);

#endif

/*
 * File trailer for xgemm.h
 *
 * [EOF]
 */
