/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 17:04:06
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "J_v2_types.h"

/* Function Declarations */
extern void b_xaxpy(int n, double a, const double x[30], int ix0, double y[6],
                    int iy0);
extern void c_xaxpy(int n, double a, const double x[6], int ix0, double y[30],
                    int iy0);
extern void d_xaxpy(int n, double a, int ix0, double y[25], int iy0);
extern void xaxpy(int n, double a, int ix0, double y[30], int iy0);

#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
