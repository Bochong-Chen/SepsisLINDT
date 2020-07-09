/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.h
 *
 * Code generation for function 'interp1'
 *
 */

#ifndef INTERP1_H
#define INTERP1_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "get_result_types.h"

/* Function Declarations */
extern void interp1(const double varargin_1_data[], const int varargin_1_size[1],
                    const double varargin_2_data[], const int varargin_2_size[1],
                    const emxArray_real_T *varargin_3, emxArray_real_T *Vq);

#endif

/* End of code generation (interp1.h) */
