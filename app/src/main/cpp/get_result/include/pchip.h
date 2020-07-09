/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pchip.h
 *
 * Code generation for function 'pchip'
 *
 */

#ifndef PCHIP_H
#define PCHIP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "get_result_types.h"

/* Function Declarations */
extern void pchip(const double x_data[], const int x_size[1], const double
                  y_data[], const int y_size[2], double v_breaks_data[], int
                  v_breaks_size[2], double v_coefs_data[], int v_coefs_size[2]);

#endif

/* End of code generation (pchip.h) */
