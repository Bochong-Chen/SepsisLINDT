/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_result.c
 *
 * Code generation for function 'get_result'
 *
 */

/* Include files */
#include "get_result.h"
#include "derive_hr.h"
#include "fft.h"
#include "get_result_data.h"
#include "get_result_emxutil.h"
#include "get_result_initialize.h"
#include "get_result_rtwutil.h"
#include "rt_nonfinite.h"
#include <math.h>

#include <jni.h>

/* Function Declarations */
static int div_s32_floor(int numerator, int denominator);

/* Function Definitions */
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  unsigned int tempAbsQuotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator < 0) {
      absNumerator = ~(unsigned int)numerator + 1U;
    } else {
      absNumerator = (unsigned int)numerator;
    }

    if (denominator < 0) {
      absDenominator = ~(unsigned int)denominator + 1U;
    } else {
      absDenominator = (unsigned int)denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }

      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }

  return quotient;
}

double get_result(const emxArray_real_T *data, double fs, boolean_T flag)
{
  double result;
  emxArray_real_T *b_data;
  int i;
  int k;
  int idx;
  int nx;
  emxArray_creal_T *z;
  emxArray_creal_T *r;
  double b_fs;
  emxArray_real_T c_data;
  int d_data[1];
  emxArray_real_T *P2;
  emxArray_real_T *P1;
  double d;
  boolean_T exitg1;
  if (isInitialized_get_result == false) {
    get_result_initialize();
  }

  /*  true for heart rate */
  emxInit_real_T(&b_data, 2);
  if (flag) {
    i = b_data->size[0] * b_data->size[1];
    b_data->size[0] = 1;
    b_data->size[1] = data->size[1];
    emxEnsureCapacity_real_T(b_data, i);
    k = data->size[0] * data->size[1] - 1;
    for (i = 0; i <= k; i++) {
      b_data->data[i] = data->data[i];
    }

    result = derive_hr(b_data, fs);

    /*  false for breathing rate */
  } else {
    /*  derive breathing rate from audio */
    /*  for time performace, start counting */
    /* tic */
    /*  down-sample for speed */
    /*  take absolute value (very important) */
    if (1 > data->size[1]) {
      i = 1;
      idx = -1;
    } else {
      i = 8;
      idx = data->size[1] - 1;
    }

    nx = div_s32_floor(idx, i) + 1;
    idx = b_data->size[0] * b_data->size[1];
    b_data->size[0] = 1;
    b_data->size[1] = nx;
    emxEnsureCapacity_real_T(b_data, idx);
    for (k = 0; k < nx; k++) {
      b_data->data[k] = fabs(data->data[i * k]);
    }

    emxInit_creal_T(&z, 2);
    emxInit_creal_T(&r, 1);
    b_fs = fs / 8.0;

    /* data = medfilt1(data, int64(round(0.333333 * fs))); */
    /*  perform fft */
    nx = b_data->size[1];
    c_data = *b_data;
    d_data[0] = nx;
    c_data.size = &d_data[0];
    c_data.numDimensions = 1;
    fft(&c_data, b_data->size[1], r);
    i = z->size[0] * z->size[1];
    z->size[0] = 1;
    z->size[1] = b_data->size[1];
    emxEnsureCapacity_creal_T(z, i);
    nx = b_data->size[1];
    k = b_data->size[1];
    for (i = 0; i < k; i++) {
      if (r->data[i].im == 0.0) {
        z->data[i].re = r->data[i].re / (double)nx;
        z->data[i].im = 0.0;
      } else if (r->data[i].re == 0.0) {
        z->data[i].re = 0.0;
        z->data[i].im = r->data[i].im / (double)nx;
      } else {
        z->data[i].re = r->data[i].re / (double)nx;
        z->data[i].im = r->data[i].im / (double)nx;
      }
    }

    emxFree_creal_T(&r);
    emxInit_real_T(&P2, 2);
    nx = z->size[1];
    i = P2->size[0] * P2->size[1];
    P2->size[0] = 1;
    P2->size[1] = z->size[1];
    emxEnsureCapacity_real_T(P2, i);
    for (k = 0; k < nx; k++) {
      P2->data[k] = rt_hypotd_snf(z->data[k].re, z->data[k].im);
    }

    emxFree_creal_T(&z);
    emxInit_real_T(&P1, 2);
    i = (int)rt_roundd_snf((double)b_data->size[1] / 2.0 + 1.0);
    k = (int)rt_roundd_snf((double)b_data->size[1] / 2.0 + 1.0);
    idx = P1->size[0] * P1->size[1];
    P1->size[0] = 1;
    P1->size[1] = k;
    emxEnsureCapacity_real_T(P1, idx);
    for (idx = 0; idx < k; idx++) {
      P1->data[idx] = P2->data[idx];
    }

    if (2 > i - 1) {
      i = 0;
      idx = -1;
      nx = 0;
    } else {
      i = 1;
      idx = (int)rt_roundd_snf((double)b_data->size[1] / 2.0 + 1.0) - 2;
      nx = 1;
    }

    k = idx - i;
    for (idx = 0; idx <= k; idx++) {
      P1->data[nx + idx] = 2.0 * P2->data[i + idx];
    }

    i = P2->size[0] * P2->size[1];
    P2->size[0] = 1;
    k = (int)floor((double)b_data->size[1] / 2.0);
    P2->size[1] = k + 1;
    emxEnsureCapacity_real_T(P2, i);
    for (i = 0; i <= k; i++) {
      P2->data[i] = i;
    }

    i = P2->size[0] * P2->size[1];
    idx = P2->size[0] * P2->size[1];
    P2->size[0] = 1;
    emxEnsureCapacity_real_T(P2, idx);
    k = i - 1;
    for (i = 0; i <= k; i++) {
      P2->data[i] = b_fs * P2->data[i] / (double)b_data->size[1];
    }

    /* plot(f * 60, P1(1:length(f))); */
    /*  set fft values outside of the range to zero */
    d = ceil(3.0 * (double)b_data->size[1] / (b_fs * 60.0));
    if (1.0 > d) {
      k = 0;
    } else {
      k = (int)d;
    }

    for (i = 0; i < k; i++) {
      P1->data[i] = 0.0;
    }

    d = ceil(100.0 * (double)b_data->size[1] / (b_fs * 60.0));
    if (d > P1->size[1]) {
      i = -1;
      idx = 0;
    } else {
      i = (int)d - 2;
      idx = P1->size[1];
    }

    k = (idx - i) - 1;
    for (idx = 0; idx < k; idx++) {
      P1->data[(i + idx) + 1] = 0.0;
    }

    /*  find bpm of maximum  */
    /*  and output to breath */
    nx = P1->size[1];
    if (P1->size[1] <= 2) {
      if (P1->size[1] == 1) {
        idx = 1;
      } else if ((P1->data[0] < P1->data[1]) || (rtIsNaN(P1->data[0]) &&
                  (!rtIsNaN(P1->data[1])))) {
        idx = 2;
      } else {
        idx = 1;
      }
    } else {
      if (!rtIsNaN(P1->data[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= P1->size[1])) {
          if (!rtIsNaN(P1->data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        idx = 1;
      } else {
        b_fs = P1->data[idx - 1];
        i = idx + 1;
        for (k = i; k <= nx; k++) {
          d = P1->data[k - 1];
          if (b_fs < d) {
            b_fs = d;
            idx = k;
          }
        }
      }
    }

    emxFree_real_T(&P1);
    result = 60.0 * P2->data[idx - 1];

    /*  for time performance, stop counting */
    /*  and output result */
    /* toc */
    emxFree_real_T(&P2);
  }

  emxFree_real_T(&b_data);
  return result;
}

/* End of code generation (get_result.c) */
