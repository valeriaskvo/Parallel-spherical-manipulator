/*
 * File: xgemm.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:54:23
 */

#ifndef XGEMM_H
#define XGEMM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Forward_kinematics_v2_types.h"

/* Function Declarations */
extern void b_xgemm(int m, int n, int k, const double A[36], int ia0, int lda,
                    const double B[36], double C[36], int ldc);
extern void xgemm(int m, int n, int k, const double A[25], int lda, const double
                  B[36], int ib0, int ldb, double C[36]);

#endif

/*
 * File trailer for xgemm.h
 *
 * [EOF]
 */
