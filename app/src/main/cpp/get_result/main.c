/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
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

/* Include files */
#include <jni.h>
#include "main.h"
#include "get_result.h"
#include "get_result_emxAPI.h"
#include "get_result_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static boolean_T argInit_boolean_T(void);
static double argInit_real_T(void);
static void main_get_result(void);


JNIEXPORT jdouble JNICALL
Java_com_billchen_sepsislindt_Activities_MainActivity_getResult(JNIEnv *env, jobject thiz, jdoubleArray jdata, jdouble jfs, jboolean jflag) {
    emxArray_real_T *data;
    int idx;
    jdouble result;

    int size = (*env)->GetArrayLength(env, jdata);

    data = emxCreate_real_T(1, size);

    double *tmp = (*env)->GetDoubleArrayElements(env,jdata,NULL);

    for (idx = 0; idx < size; idx++) {
        data->data[idx] = tmp[idx];
    }

    (*env)->ReleaseDoubleArrayElements(env, jdata, tmp, 0);

    result = get_result(data, jfs, jflag);

    return result;

}


JNIEXPORT jdouble JNICALL
Java_com_billchen_sepsislindt_Activities_AudioActivity_getResult(JNIEnv *env, jobject thiz, jdoubleArray jdata, jdouble jfs, jboolean jflag) {
    emxArray_real_T *data;
    int idx;
    jdouble result;

    int size = (*env)->GetArrayLength(env, jdata);

    data = emxCreate_real_T(1, size);

    double *tmp = (*env)->GetDoubleArrayElements(env,jdata,NULL);

    for (idx = 0; idx < size; idx++) {
        data->data[idx] = tmp[idx];
    }

    (*env)->ReleaseDoubleArrayElements(env, jdata, tmp, 0);

    result = get_result(data, jfs, jflag);

    return result;

}

JNIEXPORT jdouble JNICALL
Java_com_billchen_sepsislindt_Activities_CameraActivity_getResult(JNIEnv *env, jobject thiz, jdoubleArray jdata, jdouble jfs, jboolean jflag) {
    emxArray_real_T *data;
    int idx;
    jdouble result;

    int size = (*env)->GetArrayLength(env, jdata);

    data = emxCreate_real_T(1, size);

    double *tmp = (*env)->GetDoubleArrayElements(env,jdata,NULL);

    for (idx = 0; idx < size; idx++) {
        data->data[idx] = tmp[idx];
    }

    (*env)->ReleaseDoubleArrayElements(env, jdata, tmp, 0);

    result = get_result(data, jfs, jflag);

    return result;

}

/* Function Definitions */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_real_T();
  }

  return result;
}

static boolean_T argInit_boolean_T(void)
{
  return false;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_get_result(void)
{
  emxArray_real_T *data;
  double result;

  /* Initialize function 'get_result' input arguments. */
  /* Initialize function input argument 'data'. */
  data = argInit_1xUnbounded_real_T();

  /* Call the entry-point 'get_result'. */
  result = get_result(data, argInit_real_T(), argInit_boolean_T());
  emxDestroyArray_real_T(data);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_get_result();

  /* Terminate the application.
     You do not need to do this more than one time. */
  get_result_terminate();
  return 0;
}




/* End of code generation (main.c) */
