/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * derive_hr.c
 *
 * Code generation for function 'derive_hr'
 *
 */

/* Include files */
#include "derive_hr.h"
#include "fft.h"
#include "find_baseline.h"
#include "get_result.h"
#include "get_result_emxutil.h"
#include "get_result_rtwutil.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double derive_hr(emxArray_real_T *frame, double fs)
{
  double hr;
  emxArray_real_T *P1;
  int i;
  long i1;
  long q0;
  long q1;
  emxArray_real_T *norm_frame;
  emxArray_real_T *centered_frame;
  int loop_ub;
  int vlen;
  int idx;
  emxArray_real_T *absdiff;
  emxArray_real_T *b_absdiff;
  double y;
  double xbar;
  double scale;
  emxArray_creal_T *z;
  emxArray_creal_T *r;
  double t;
  emxArray_real_T b_norm_frame;
  int c_norm_frame[1];
  boolean_T exitg1;

  /*  get hr from averaged video frames */
  emxInit_real_T(&P1, 2);
  if (frame->size[1] > 400) {
    i = (int)rt_roundd_snf((double)frame->size[1] / 6.0);
    i1 = i;
    if (i1 == MIN_int64_T) {
      q0 = frame->size[1];
      if (q0 > 0L) {
        q0 = MAX_int64_T;
      } else {
        q0 += MAX_int64_T;
      }

      if (q0 < MAX_int64_T) {
        if (q0 > 9223372036854775806L) {
          q0 = MAX_int64_T;
        } else {
          q0++;
        }
      }
    } else {
      q0 = -i1;
      q1 = frame->size[1];
      if ((q0 < 0L) && (q1 < MIN_int64_T - q0)) {
        q0 = MIN_int64_T;
      } else if ((q0 > 0L) && (q1 > MAX_int64_T - q0)) {
        q0 = MAX_int64_T;
      } else {
        q0 += q1;
      }
    }

    if (i1 > q0) {
      i = 0;
      vlen = 0;
    } else {
      i = (int)i1 - 1;
      vlen = (int)q0;
    }

    idx = P1->size[0] * P1->size[1];
    P1->size[0] = 1;
    loop_ub = vlen - i;
    P1->size[1] = loop_ub;
    emxEnsureCapacity_real_T(P1, idx);
    for (vlen = 0; vlen < loop_ub; vlen++) {
      P1->data[vlen] = frame->data[i + vlen];
    }

    i = frame->size[0] * frame->size[1];
    frame->size[0] = 1;
    frame->size[1] = P1->size[1];
    emxEnsureCapacity_real_T(frame, i);
    loop_ub = P1->size[0] * P1->size[1];
    for (i = 0; i < loop_ub; i++) {
      frame->data[i] = P1->data[i];
    }
  }

  /*  for time performace, start counting */
  /* tic */
  /*  exclude underlying baseline, */
  /*  normalize data */
  emxInit_real_T(&norm_frame, 2);
  if (frame->size[1] < 1) {
    norm_frame->size[0] = 1;
    norm_frame->size[1] = 0;
  } else {
    i = norm_frame->size[0] * norm_frame->size[1];
    norm_frame->size[0] = 1;
    norm_frame->size[1] = (int)((double)frame->size[1] - 1.0) + 1;
    emxEnsureCapacity_real_T(norm_frame, i);
    loop_ub = (int)((double)frame->size[1] - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      norm_frame->data[i] = (double)i + 1.0;
    }
  }

  emxInit_real_T(&centered_frame, 1);
  i = centered_frame->size[0];
  centered_frame->size[0] = frame->size[1];
  emxEnsureCapacity_real_T(centered_frame, i);
  loop_ub = frame->size[1];
  for (i = 0; i < loop_ub; i++) {
    centered_frame->data[i] = frame->data[i];
  }

  emxInit_real_T(&absdiff, 1);
  i = absdiff->size[0];
  absdiff->size[0] = norm_frame->size[1];
  emxEnsureCapacity_real_T(absdiff, i);
  loop_ub = norm_frame->size[1];
  for (i = 0; i < loop_ub; i++) {
    absdiff->data[i] = norm_frame->data[i];
  }

  emxInit_real_T(&b_absdiff, 1);
  find_baseline(absdiff, centered_frame, fs, fs / 2.0, b_absdiff);
  vlen = centered_frame->size[0];
  emxFree_real_T(&b_absdiff);
  if (centered_frame->size[0] == 0) {
    y = 0.0;
  } else {
    y = centered_frame->data[0];
    for (loop_ub = 2; loop_ub <= vlen; loop_ub++) {
      y += centered_frame->data[loop_ub - 1];
    }
  }

  y /= (double)centered_frame->size[0];
  vlen = centered_frame->size[0];
  if (centered_frame->size[0] == 0) {
    xbar = rtNaN;
  } else if (centered_frame->size[0] == 1) {
    if ((!rtIsInf(centered_frame->data[0])) && (!rtIsNaN(centered_frame->data[0])))
    {
      xbar = 0.0;
    } else {
      xbar = rtNaN;
    }
  } else {
    xbar = centered_frame->data[0];
    for (loop_ub = 2; loop_ub <= vlen; loop_ub++) {
      xbar += centered_frame->data[loop_ub - 1];
    }

    xbar /= (double)centered_frame->size[0];
    i = absdiff->size[0];
    absdiff->size[0] = centered_frame->size[0];
    emxEnsureCapacity_real_T(absdiff, i);
    for (loop_ub = 0; loop_ub < vlen; loop_ub++) {
      absdiff->data[loop_ub] = fabs(centered_frame->data[loop_ub] - xbar);
    }

    xbar = 0.0;
    scale = 3.3121686421112381E-170;
    vlen = centered_frame->size[0];
    for (loop_ub = 0; loop_ub < vlen; loop_ub++) {
      if (absdiff->data[loop_ub] > scale) {
        t = scale / absdiff->data[loop_ub];
        xbar = xbar * t * t + 1.0;
        scale = absdiff->data[loop_ub];
      } else {
        t = absdiff->data[loop_ub] / scale;
        xbar += t * t;
      }
    }

    xbar = scale * sqrt(xbar);
    xbar /= sqrt((double)centered_frame->size[0] - 1.0);
  }

  emxFree_real_T(&absdiff);
  i = norm_frame->size[0] * norm_frame->size[1];
  norm_frame->size[0] = 1;
  norm_frame->size[1] = centered_frame->size[0];
  emxEnsureCapacity_real_T(norm_frame, i);
  loop_ub = centered_frame->size[0];
  for (i = 0; i < loop_ub; i++) {
    norm_frame->data[i] = (centered_frame->data[i] - y) / xbar;
  }

  emxFree_real_T(&centered_frame);
  emxInit_creal_T(&z, 2);
  emxInit_creal_T(&r, 1);

  /* figure; */
  /* plot((1:f_num)/fs, norm_frame); */
  /*  perform fft */
  vlen = norm_frame->size[1];
  b_norm_frame = *norm_frame;
  c_norm_frame[0] = vlen;
  b_norm_frame.size = &c_norm_frame[0];
  b_norm_frame.numDimensions = 1;
  fft(&b_norm_frame, norm_frame->size[1], r);
  i = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = norm_frame->size[1];
  emxEnsureCapacity_creal_T(z, i);
  vlen = frame->size[1];
  loop_ub = norm_frame->size[1];
  for (i = 0; i < loop_ub; i++) {
    if (r->data[i].im == 0.0) {
      z->data[i].re = r->data[i].re / (double)vlen;
      z->data[i].im = 0.0;
    } else if (r->data[i].re == 0.0) {
      z->data[i].re = 0.0;
      z->data[i].im = r->data[i].im / (double)vlen;
    } else {
      z->data[i].re = r->data[i].re / (double)vlen;
      z->data[i].im = r->data[i].im / (double)vlen;
    }
  }

  emxFree_creal_T(&r);
  vlen = z->size[1];
  i = norm_frame->size[0] * norm_frame->size[1];
  norm_frame->size[0] = 1;
  norm_frame->size[1] = z->size[1];
  emxEnsureCapacity_real_T(norm_frame, i);
  for (loop_ub = 0; loop_ub < vlen; loop_ub++) {
    norm_frame->data[loop_ub] = rt_hypotd_snf(z->data[loop_ub].re, z->
      data[loop_ub].im);
  }

  emxFree_creal_T(&z);
  i = (int)rt_roundd_snf((double)frame->size[1] / 2.0 + 1.0);
  loop_ub = (int)rt_roundd_snf((double)frame->size[1] / 2.0 + 1.0);
  vlen = P1->size[0] * P1->size[1];
  P1->size[0] = 1;
  P1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(P1, vlen);
  for (vlen = 0; vlen < loop_ub; vlen++) {
    P1->data[vlen] = norm_frame->data[vlen];
  }

  if (2 > i - 1) {
    i = 0;
    vlen = -1;
    idx = 0;
  } else {
    i = 1;
    vlen = (int)rt_roundd_snf((double)frame->size[1] / 2.0 + 1.0) - 2;
    idx = 1;
  }

  loop_ub = vlen - i;
  for (vlen = 0; vlen <= loop_ub; vlen++) {
    P1->data[idx + vlen] = 2.0 * norm_frame->data[i + vlen];
  }

  i = norm_frame->size[0] * norm_frame->size[1];
  norm_frame->size[0] = 1;
  loop_ub = (int)floor((double)frame->size[1] / 2.0);
  norm_frame->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(norm_frame, i);
  for (i = 0; i <= loop_ub; i++) {
    norm_frame->data[i] = i;
  }

  i = norm_frame->size[0] * norm_frame->size[1];
  vlen = norm_frame->size[0] * norm_frame->size[1];
  norm_frame->size[0] = 1;
  emxEnsureCapacity_real_T(norm_frame, vlen);
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    norm_frame->data[i] = fs * norm_frame->data[i] / (double)frame->size[1];
  }

  /* figure; */
  /* plot(f * 60, P1(1:length(f))); */
  /*  set fft values outside of this range to zero */
  xbar = rt_roundd_snf(40.0 * (double)frame->size[1] / (fs * 60.0));
  if (xbar < 2.147483648E+9) {
    if (xbar >= -2.147483648E+9) {
      i = (int)xbar;
    } else {
      i = MIN_int32_T;
    }
  } else if (xbar >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }

  if (1 > i) {
    loop_ub = 0;
  } else {
    loop_ub = i;
  }

  for (i = 0; i < loop_ub; i++) {
    P1->data[i] = 0.0;
  }

  xbar = rt_roundd_snf(250.0 * (double)frame->size[1] / (fs * 60.0));
  if (xbar < 2.147483648E+9) {
    if (xbar >= -2.147483648E+9) {
      i = (int)xbar;
    } else {
      i = MIN_int32_T;
    }
  } else if (xbar >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }

  if (i > P1->size[1]) {
    i = -1;
    vlen = 0;
  } else {
    i -= 2;
    vlen = P1->size[1];
  }

  loop_ub = (vlen - i) - 1;
  for (vlen = 0; vlen < loop_ub; vlen++) {
    P1->data[(i + vlen) + 1] = 0.0;
  }

  /* figure; */
  /* plot(f * 60,P1(1:length(f))); */
  /*  get bpm and assign to hr */
  vlen = P1->size[1];
  if (P1->size[1] <= 2) {
    if (P1->size[1] == 1) {
      idx = 1;
    } else if ((P1->data[0] < P1->data[1]) || (rtIsNaN(P1->data[0]) && (!rtIsNaN
                 (P1->data[1])))) {
      idx = 2;
    } else {
      idx = 1;
    }
  } else {
    if (!rtIsNaN(P1->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= P1->size[1])) {
        if (!rtIsNaN(P1->data[loop_ub - 1])) {
          idx = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      scale = P1->data[idx - 1];
      i = idx + 1;
      for (loop_ub = i; loop_ub <= vlen; loop_ub++) {
        xbar = P1->data[loop_ub - 1];
        if (scale < xbar) {
          scale = xbar;
          idx = loop_ub;
        }
      }
    }
  }

  emxFree_real_T(&P1);
  hr = 60.0 * norm_frame->data[idx - 1];

  /*  for time performance, stop counting */
  /*  and output time spent. */
  /* toc */
  emxFree_real_T(&norm_frame);
  return hr;
}

/* End of code generation (derive_hr.c) */
