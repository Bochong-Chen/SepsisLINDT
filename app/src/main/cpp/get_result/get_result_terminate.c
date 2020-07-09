/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_result_terminate.c
 *
 * Code generation for function 'get_result_terminate'
 *
 */

/* Include files */
#include "get_result_terminate.h"
#include "get_result.h"
#include "get_result_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void get_result_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_get_result = false;
}

/* End of code generation (get_result_terminate.c) */
