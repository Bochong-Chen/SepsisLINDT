/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find_baseline.c
 *
 * Code generation for function 'find_baseline'
 *
 */

/* Include files */
#include "find_baseline.h"
#include "get_result.h"
#include "get_result_emxutil.h"
#include "interp1.h"
#include "quantile.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void __anon_fcn(double windowSizeIn, const int x_size[1], double
  varargout_1_data[], int varargout_1_size[2]);

/* Function Definitions */
static void __anon_fcn(double windowSizeIn, const int x_size[1], double
  varargout_1_data[], int varargout_1_size[2])
{
  int loop_ub;
  int i;
  varargout_1_size[0] = (short)x_size[0];
  varargout_1_size[1] = 1;
  loop_ub = (short)x_size[0];
  for (i = 0; i < loop_ub; i++) {
    varargout_1_data[i] = windowSizeIn;
  }
}

void find_baseline(const emxArray_real_T *X, emxArray_real_T *Y, double
                   varargin_2, double varargin_4, emxArray_real_T *B)
{
  double c_stepSize_tunableEnvironment_i;
  double c_windowSize_tunableEnvironment;
  int idx;
  int i;
  boolean_T exitg1;
  static const boolean_T bv[8] = { false, true, false, false, false, false,
    false, false };

  boolean_T guard1 = false;
  signed char k_data[8];
  boolean_T x_data[8];
  boolean_T y;
  static const boolean_T bv1[8] = { true, false, false, false, false, false,
    false, false };

  double Xp[1000];
  double WE[1000];
  double Xpid;
  int id;
  int loop_ub;
  int Xp_size[1];
  double Xw_data[1000];
  int Xw_size[2];
  emxArray_boolean_T *r;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *b_Y;
  int nw;
  int end;
  int WE_size[1];
  double Xp_data[1000];

  /* MSBACKADJ provides background correction for a signal with peaks */
  /*  */
  /*    YOUT = MSBACKADJ(X,Y) adjusts the variable background (baseline) of a */
  /*    signal with peaks by following three steps: 1) estimates the background */
  /*    within multiple shifted windows of width 200 separation units along the */
  /*    x-axis, 2) regresses the varying baseline to the window points using a */
  /*    spline approximation, and 3) adjusts the background of the input signal Y.   */
  /*  */
  /*    X and Y are column vectors where paired values represent points in the */
  /*    signal. Y can be a matrix with several signals, all sharing the same X */
  /*    scale. Units in the X scale (separation units or s.u.) may quantify */
  /*    wavelength, frequency, distance, time or m/z depending on the type of */
  /*    instrument that generates the signal.  */
  /*  */
  /*    MSBACKADJ(...,'WINDOWSIZE',WS) sets the width for the shifting window. */
  /*    The default is 200 s.u., which means a background point is estimated */
  /*    for windows of 200 s.u. in width. WS may also be a function handle. */
  /*    The referenced function is evaluated at each X value to compute  */
  /*    a variable width for the windows. This option is useful for cases where */
  /*    the resolution of the signal is dissimilar at different regions. */
  /*  */
  /*    MSBACKADJ(...,'STEPSIZE',SS) sets the steps for the shifting window. */
  /*    The default is 200 s.u., which means a background point is estimated */
  /*    for windows at every 200 s.u. SS may also be a function handle. The */
  /*    referenced function is evaluated at each X value to compute the */
  /*    distance between adjacent windows. */
  /*  */
  /*    MSBACKADJ(...,'REGRESSIONMETHOD',RM) sets the method used to regress */
  /*    the window estimated points to a soft curve. The default is 'pchip'; */
  /*    i.e., shape-preserving piecewise cubic interpolation. Other options are */
  /*    'linear' and 'spline' interpolation. */
  /*  */
  /*    MSBACKADJ(...,'ESTIMATIONMETHOD',EM) sets the method used to find the */
  /*    likely background value at every window. Default is 'quantile', in */
  /*    which the quantile value is set to 10%. An alternative method is 'em', */
  /*    which assumes a doubly stochastic model; i.e., every sample is the */
  /*    i.i.d. draw of any of two normal distributed classes (background or */
  /*    peaks). Because the class label is hidden, the distributions are */
  /*    estimated with an expectation-maximization algorithm. The ultimate */
  /*    background value is the mean of the background class. */
  /*  */
  /*    MSBACKADJ(...,'SMOOTHMETHOD',SM) sets the method used to smooth the */
  /*    curve of estimated points, useful to eliminate the effect of possible */
  /*    outliers. Options are 'none' (default), 'lowess' (linear fit), 'loess' */
  /*    (quadratic fit), or 'rlowess' and 'rloess' (robust linear and quadratic */
  /*    fit). */
  /*  */
  /*    MSBACKADJ(...,'QUANTILEVALUE',QV) changes the default quantile value. */
  /*    The default is 0.10. */
  /*  */
  /*    MSBACKADJ(...,'PRESERVEHEIGHTS',true) sets the baseline subtraction */
  /*    mode to preserve the height of the tallest peak in the signal when */
  /*    subtracting the baseline. By default heights are not preserved. */
  /*  */
  /*    MSBACKADJ(...,'SHOWPLOT',SP) plots the background estimated points, the */
  /*    regressed baseline, and the original signal. When SP is TRUE, the first */
  /*    signal in Y is used. If MSBACKADJ is called without output arguments, a */
  /*    plot will be shown unless SP is FALSE. SP can also contain an index to */
  /*    one of the signals in Y. */
  /*  */
  /*    Examples:  */
  /*  */
  /*       % Correct the baseline of SELDI-TOF mass-spectrograms: */
  /*       load sample_lo_res */
  /*  */
  /*       % Adjust the baseline of a group of spectrograms. */
  /*       YB = msbackadj(MZ_lo_res,Y_lo_res); */
  /*  */
  /*       % Plot the third spectrogram in Y_lo_res and its estimated baseline. */
  /*       msbackadj(MZ_lo_res,Y_lo_res,'SHOWPLOT',3); */
  /*  */
  /*       % Plot the estimated baseline for the fourth spectrogram in Y_lo_res */
  /*       % using an anonymous function to describe a MZ dependent parameter. */
  /*       wf = @(mz) 200 + .001 .* mz; */
  /*       msbackadj(MZ_lo_res,Y_lo_res(:,4),'STEPSIZE',wf); */
  /*  */
  /*  */
  /*    See also MSALIGN, MSHEATMAP, MSLOWESS, MSNORM, MSPREPRODEMO, */
  /*    MSRESAMPLE, MSSGOLAY, MSVIEWER.  */
  /*    Copyright 2003-2015 The MathWorks, Inc. */
  /*  References:  */
  /*  [1] Lucio Andrade and Elias Manolakos, "Signal Background Estimation and */
  /*      Baseline Correction Algorithms for Accurate DNA Sequencing" Journal */
  /*      of VLSI, special issue on Bioinformatics 35:3 pp 229-243 (2003) */
  /*  set defaults */
  c_stepSize_tunableEnvironment_i = 200.0;
  c_windowSize_tunableEnvironment = 200.0;
  idx = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (bv[i]) {
      idx++;
      k_data[idx - 1] = (signed char)(i + 1);
      if (idx >= 8) {
        exitg1 = true;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  guard1 = false;
  if (idx == 1) {
    x_data[0] = (1 == k_data[0]);
    y = (int)x_data[0];
    if (y) {
      idx = 0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (idx == 1) {
      x_data[0] = (2 == k_data[0]);
      y = (int)x_data[0];
      if (y) {
        idx = 1;
      } else {
        idx = -1;
      }
    } else {
      idx = -1;
    }
  }

  switch (idx) {
   case 0:
    /*  step size */
    c_stepSize_tunableEnvironment_i = varargin_2;
    break;

   case 1:
    /*  window size */
    c_windowSize_tunableEnvironment = varargin_2;
    break;
  }

  idx = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (bv1[i]) {
      idx++;
      k_data[idx - 1] = (signed char)(i + 1);
      if (idx >= 8) {
        exitg1 = true;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  guard1 = false;
  if (idx == 1) {
    x_data[0] = (1 == k_data[0]);
    y = (int)x_data[0];
    if (y) {
      idx = 0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (idx == 1) {
      x_data[0] = (2 == k_data[0]);
      y = (int)x_data[0];
      if (y) {
        idx = 1;
      } else {
        idx = -1;
      }
    } else {
      idx = -1;
    }
  }

  switch (idx) {
   case 0:
    /*  step size */
    c_stepSize_tunableEnvironment_i = varargin_4;
    break;

   case 1:
    /*  window size */
    c_windowSize_tunableEnvironment = varargin_4;
    break;
  }

  /*  change scalars to function handlers */
  /*  allocate space for Xp and WE */
  for (i = 0; i < 1000; i++) {
    Xp[i] = 0.0;
    WE[i] = rtNaN;
  }

  /*  calculates the location of the windows (when it is the same for all the */
  /*  signals) */
  Xpid = fmax(0.0, X->data[0]);
  id = -1;
  while (Xpid <= X->data[X->size[0] - 1]) {
    Xp[id + 1] = Xpid;
    Xpid += c_stepSize_tunableEnvironment_i;
    id++;
  }

  /*  iterate for every signal */
  /*  find the location of the windows (when it is different for every */
  /*  signal, otherwise this was done out of the loop) */
  if (1 > id + 1) {
    loop_ub = -1;
  } else {
    loop_ub = id;
  }

  Xp_size[0] = loop_ub + 1;
  __anon_fcn(c_windowSize_tunableEnvironment, Xp_size, Xw_data, Xw_size);

  /*  find the estimated baseline for every window */
  emxInit_boolean_T(&r, 1);
  emxInit_boolean_T(&r1, 1);
  emxInit_int32_T(&r2, 1);
  emxInit_real_T(&b_Y, 1);
  for (nw = 0; nw <= id; nw++) {
    idx = X->size[0];
    i = r->size[0];
    r->size[0] = X->size[0];
    emxEnsureCapacity_boolean_T(r, i);
    c_stepSize_tunableEnvironment_i = Xp[nw] + Xw_data[nw];
    i = r1->size[0];
    r1->size[0] = X->size[0];
    emxEnsureCapacity_boolean_T(r1, i);
    for (i = 0; i < idx; i++) {
      r->data[i] = (X->data[i] >= Xp[nw]);
      r1->data[i] = (X->data[i] <= c_stepSize_tunableEnvironment_i);
    }

    end = r->size[0] - 1;
    idx = 0;
    for (i = 0; i <= end; i++) {
      if (r->data[i] && r1->data[i]) {
        idx++;
      }
    }

    i = r2->size[0];
    r2->size[0] = idx;
    emxEnsureCapacity_int32_T(r2, i);
    idx = 0;
    for (i = 0; i <= end; i++) {
      if (r->data[i] && r1->data[i]) {
        r2->data[idx] = i + 1;
        idx++;
      }
    }

    idx = r2->size[0];
    i = b_Y->size[0];
    b_Y->size[0] = r2->size[0];
    emxEnsureCapacity_real_T(b_Y, i);
    for (i = 0; i < idx; i++) {
      b_Y->data[i] = Y->data[r2->data[i] - 1];
    }

    WE[nw] = quantile(b_Y);
  }

  emxFree_int32_T(&r2);
  emxFree_boolean_T(&r1);
  emxFree_boolean_T(&r);

  /*  for nw = 1:numWindows */
  /*  regress the estimated points */
  idx = Xw_size[0] * Xw_size[1] - 1;
  for (i = 0; i <= idx; i++) {
    Xw_data[i] /= 2.0;
  }

  if (1 > id + 1) {
    idx = -1;
  } else {
    idx = id;
  }

  Xp_size[0] = loop_ub + 1;
  for (i = 0; i <= loop_ub; i++) {
    Xp_data[i] = Xp[i] + Xw_data[i];
  }

  WE_size[0] = idx + 1;
  if (0 <= idx) {
    memcpy(&Xp[0], &WE[0], (idx + 1) * sizeof(double));
  }

  loop_ub = X->size[0];
  i = b_Y->size[0];
  b_Y->size[0] = X->size[0];
  emxEnsureCapacity_real_T(b_Y, i);
  for (i = 0; i < loop_ub; i++) {
    b_Y->data[i] = X->data[i];
  }

  interp1(Xp_data, Xp_size, Xp, WE_size, b_Y, B);

  /*  apply the correction */
  loop_ub = Y->size[0] - 1;
  i = b_Y->size[0];
  b_Y->size[0] = loop_ub + 1;
  emxEnsureCapacity_real_T(b_Y, i);
  for (i = 0; i <= loop_ub; i++) {
    b_Y->data[i] = Y->data[i] - B->data[i];
  }

  loop_ub = b_Y->size[0];
  for (i = 0; i < loop_ub; i++) {
    Y->data[i] = b_Y->data[i];
  }

  emxFree_real_T(&b_Y);

  /*  if nargout>0 || (ns == plotId)     */
  /*  for ns = 1:numSignals  */
}

/* End of code generation (find_baseline.c) */
