/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:26:48
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "Forward_kinematics_v2.h"
#include "Forward_kinematics_v2_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_4x1_real_T(double result[4]);
static void argInit_5x1_real_T(double result[5]);
static double argInit_real_T(void);
static void main_Forward_kinematics_v2(void);

/* Function Definitions */

/*
 * Arguments    : double result[4]
 * Return Type  : void
 */
static void argInit_4x1_real_T(double result[4])
{
  double result_tmp_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp_tmp = argInit_real_T();
  result[0] = result_tmp_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[2] = result_tmp_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[3] = argInit_real_T();
}

/*
 * Arguments    : double result[5]
 * Return Type  : void
 */
static void argInit_5x1_real_T(double result[5])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_Forward_kinematics_v2(void)
{
  double dv[5];
  double dv1[4];
  double phi[3];

  /* Initialize function 'Forward_kinematics_v2' input arguments. */
  /* Initialize function input argument 'system_parameters'. */
  /* Initialize function input argument 'q'. */
  /* Call the entry-point 'Forward_kinematics_v2'. */
  argInit_5x1_real_T(dv);
  argInit_4x1_real_T(dv1);
  Forward_kinematics_v2(dv, dv1, phi);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Forward_kinematics_v2();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Forward_kinematics_v2_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
