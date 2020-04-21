/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 21-Apr-2020 15:02:40
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
#include "Find_parameters_dynamixel.h"
#include "Find_parameters_dynamixel_emxAPI.h"
#include "Find_parameters_dynamixel_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static emxArray_char_T *argInit_1xUnbounded_char_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static char argInit_char_T(void);
static double argInit_real_T(void);
static rtString argInit_rtString(void);
static void main_Find_parameters_dynamixel(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : emxArray_char_T *
 */
static emxArray_char_T *argInit_1xUnbounded_char_T(void)
{
  emxArray_char_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_char_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_char_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static const int iv[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : char
 */
static char argInit_char_T(void)
{
  return '?';
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
 * Return Type  : rtString
 */
static rtString argInit_rtString(void)
{
  rtString result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.Value = argInit_1xUnbounded_char_T();
  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_Find_parameters_dynamixel(void)
{
  emxArray_real_T *p_s;
  emxArray_real_T *R_s;
  emxArray_real_T *time;
  double N;
  emxArray_real_T *t;
  emxArray_real_T *dtheta;
  emxArray_real_T *ddtheta;
  emxArray_real_T *b_I;
  rtString dtype;
  double p[3];
  double R[9];
  emxInitArray_real_T(&p_s, 2);
  emxInitArray_real_T(&R_s, 2);
  emxInitArray_real_T(&time, 1);

  /* Initialize function 'Find_parameters_dynamixel' input arguments. */
  N = argInit_real_T();

  /* Initialize function input argument 't'. */
  t = argInit_Unboundedx1_real_T();

  /* Initialize function input argument 'dtheta'. */
  dtheta = argInit_Unboundedx1_real_T();

  /* Initialize function input argument 'ddtheta'. */
  ddtheta = argInit_Unboundedx1_real_T();

  /* Initialize function input argument 'I'. */
  b_I = argInit_Unboundedx1_real_T();

  /* Initialize function input argument 'dtype'. */
  dtype = argInit_rtString();

  /* Call the entry-point 'Find_parameters_dynamixel'. */
  Find_parameters_dynamixel(N, t, dtheta, ddtheta, b_I, &dtype, argInit_real_T(),
    argInit_real_T(), p, p_s, R, R_s, time);
  emxDestroyArray_real_T(time);
  emxDestroyArray_real_T(R_s);
  emxDestroyArray_real_T(p_s);
  emxDestroy_rtString(dtype);
  emxDestroyArray_real_T(b_I);
  emxDestroyArray_real_T(ddtheta);
  emxDestroyArray_real_T(dtheta);
  emxDestroyArray_real_T(t);
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
  main_Find_parameters_dynamixel();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Find_parameters_dynamixel_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
