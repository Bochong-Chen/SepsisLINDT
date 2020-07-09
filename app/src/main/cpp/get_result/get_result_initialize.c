/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_result_initialize.c
 *
 * Code generation for function 'get_result_initialize'
 *
 */

/* Include files */
#include "get_result_initialize.h"
#include "get_result.h"
#include "get_result_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void get_result_initialize(void)
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_get_result = true;
}

/* End of code generation (get_result_initialize.c) */
