/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_predict_initialize.cpp
 *
 * Code generation for function 'get_predict_initialize'
 *
 */

/* Include files */
#include "get_predict_initialize.h"
#include "get_predict.h"
#include "get_predict_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void get_predict_initialize()
{
  rt_InitInfAndNaN();
  isInitialized_get_predict = true;
}

/* End of code generation (get_predict_initialize.cpp) */
