/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactRegressionTree.cpp
 *
 * Code generation for function 'CompactRegressionTree'
 *
 */

/* Include files */
#include "CompactRegressionTree.h"
#include "get_predict.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const boolean_T bv[21] = { false, false, false, false, false, false,
  false, false, true, true, true, false, true, false, true, true, true, true,
  true, true, true };

static const signed char iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv1[21] = { false, false, false, false, false, false,
  false, false, true, true, true, true, true, false, false, true, true, true,
  true, true, true };

static const signed char iv1[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv2[21] = { false, false, false, false, false, false,
  false, false, true, true, false, false, true, true, true, true, true, true,
  true, true, true };

static const signed char iv2[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv3[21] = { false, false, false, false, false, true,
  false, false, false, false, false, true, true, true, true, true, true, true,
  true, true, true };

static const signed char iv3[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
  13, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0 };

static const boolean_T bv4[21] = { false, false, false, false, false, false,
  false, true, false, false, false, true, true, true, true, true, true, true,
  true, true, true };

static const signed char iv4[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv5[21] = { false, false, false, false, false, false,
  false, false, false, true, false, true, true, true, true, true, true, true,
  true, true, true };

static const signed char iv5[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv6[21] = { false, false, false, false, false, false,
  false, true, true, true, false, true, true, false, false, true, true, true,
  true, true, true };

static const signed char iv6[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv7[21] = { false, false, false, false, false, false,
  false, true, true, false, true, true, true, false, false, true, true, true,
  true, true, true };

static const signed char iv7[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv8[21] = { false, false, false, false, false, false,
  true, false, false, false, false, true, true, true, true, true, true, true,
  true, true, true };

static const signed char iv8[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0,
  0, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv9[21] = { false, false, false, false, false, false,
  false, true, true, true, true, true, false, false, false, true, true, true,
  true, true, true };

static const signed char iv9[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv10[21] = { false, false, false, false, true, false,
  false, false, true, true, false, false, false, true, true, true, true, true,
  true, true, true };

static const signed char iv10[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
  13, 14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0 };

static const boolean_T bv11[21] = { false, false, false, false, false, true,
  false, false, true, false, false, true, false, true, true, true, true, true,
  true, true, true };

static const signed char iv11[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
  13, 14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0 };

static const boolean_T bv12[21] = { false, false, false, false, false, false,
  false, false, false, true, true, true, true, false, true, true, true, true,
  true, true, true };

static const signed char iv12[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv13[21] = { false, false, false, false, false, false,
  false, false, true, true, false, true, true, false, true, true, true, true,
  true, true, true };

static const signed char iv13[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv14[21] = { false, false, false, true, false, false,
  false, true, true, false, false, false, false, true, true, true, true, true,
  true, true, true };

static const signed char iv14[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
  13, 0, 0, 0, 0, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0 };

static const boolean_T bv15[21] = { false, false, false, false, false, false,
  false, false, false, true, true, true, true, true, false, true, true, true,
  true, true, true };

static const signed char iv15[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv16[21] = { false, false, false, false, false, false,
  false, true, false, true, true, true, true, false, false, true, true, true,
  true, true, true };

static const signed char iv16[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv17[21] = { false, false, false, false, false, false,
  false, true, true, true, false, false, true, true, false, true, true, true,
  true, true, true };

static const signed char iv17[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv18[21] = { false, false, false, false, false, false,
  false, true, false, true, true, true, false, false, true, true, true, true,
  true, true, true };

static const signed char iv18[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv19[21] = { false, false, false, false, false, false,
  false, false, false, false, true, true, true, true, true, true, true, true,
  true, true, true };

static const signed char iv19[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv20[21] = { false, false, false, false, false, false,
  false, false, true, false, false, true, true, true, true, true, true, true,
  true, true, true };

static const signed char iv20[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv21[21] = { false, false, false, false, false, false,
  false, true, true, true, true, false, false, true, false, true, true, true,
  true, true, true };

static const signed char iv21[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 0, 0, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

static const boolean_T bv22[21] = { false, false, false, false, false, false,
  false, false, true, true, true, false, false, true, true, true, true, true,
  true, true, true };

static const signed char iv22[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 };

/* Function Definitions */
double CompactRegressionTree_predict(const double obj_CutPredictorIndex[21],
  const double obj_Children[42], const double obj_CutPoint[21], const boolean_T
  obj_NanCutPoints[21], const double obj_NodeMean[21], const double X[42])
{
  int m;
  m = 0;
  while (!((obj_CutPredictorIndex[m] == 0.0) || rtIsNaN(X[static_cast<int>
           (obj_CutPredictorIndex[m]) - 1]) || obj_NanCutPoints[m])) {
    if (X[static_cast<int>(obj_CutPredictorIndex[m]) - 1] < obj_CutPoint[m]) {
      m = static_cast<int>(obj_Children[m << 1]) - 1;
    } else {
      m = static_cast<int>(obj_Children[(m << 1) + 1]) - 1;
    }
  }

  return obj_NodeMean[m];
}

void ab_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 0.9375, 2.8125, 12.6875, -2.125, 99.125, 94.5,
    -1.1639999999999997, 0.0, 99.5, 135.0, 0.0, 0.0, 0.0, 0.0, 106.5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, false, false, true, true, true, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0062277938924713326, -0.12046230974683926,
    0.11365069220818337, -0.27511946038557877, 0.17454134527929197,
    -0.700966435719783, 0.15462970046148503, -1.0092184391515735,
    -0.0729090654847681, 0.41749899078908076, -0.57058727052361669,
    0.67251664301400682, -1.0321253337329872, -0.037783116619022374,
    0.32156810639358763, -0.85226631055014535, 0.042318128261402348,
    0.12795761335623171, 1.4220193411991959, -0.17996779022681597,
    0.50760409482966717 };

  static const signed char b_iv1[21] = { 30, 25, 8, 26, 5, 23, 29, 0, 15, 21, 0,
    0, 0, 0, 21, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ac_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 46.9375, 139.5, 48.25, 97.969, 0.0, -4.5,
    52.375, 6.875, 0.0, 0.0, 87.5, 6.625, 57.1875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0017603772376906231, -0.27559124693826925,
    0.033525719171320328, -0.38872916535851593, 1.0871816703145929,
    0.47096813974187679, -0.025661242046562765, -0.79445259612982,
    0.009068551897691, -0.70561743029394475, 0.633398892743412,
    -0.4558418305828314, 0.031561918585743046, -1.0053981901496234,
    0.52612584035939824, 1.079516493010334, 0.10518169638963143,
    -0.56827635014068889, 1.1488967715613048, 0.29094718722805285,
    -0.056290459667438834 };

  static const signed char b_iv[21] = { 22, 21, 10, 17, 0, 25, 10, 27, 0, 0, 19,
    29, 4, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv10[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv10[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ad_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 31.5, -10.25, 37.5, 0.0, -7.125, 0.0, 90.75,
    95.0, 15.75, 0.0, 18.25, 0.0, 0.0, 26.0625, 21.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, true, false, true,
    false, false, false, true, false, true, true, false, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 0, 0, 10,
    11, 12, 13, 14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0013457546675248919, 0.00841381915708194,
    -0.7786890022512224, 1.0110850321505582, 0.00098480536491696671,
    0.66168459108724509, -0.98670132574097025, -0.65720131352870559,
    0.018909636934103857, 1.0013837301568733, -1.0154365652695916,
    1.014525111293453, -0.808707731569825, 0.004092196698640126,
    0.56862678332944716, -1.0169780235269752, -0.0488771364887837,
    -0.021816253819099154, 0.51497752362865989, 0.9020578386177226,
    -1.0219453367222049 };

  static const signed char b_iv1[21] = { 8, 29, 22, 0, 29, 0, 23, 3, 26, 0, 26,
    0, 0, 20, 14, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ae_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 90.5625, 104.25, -4.125, 73.5, 116.031, 49.0,
    -1.1875, 108.125, 0.0, 120.5, 0.0, 0.0, 0.0, 4.875, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, false, true, false, true, true, true, false, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0061895807923853744, -0.07709693081873524,
    0.10370298595681399, -0.37728706911409654, 0.0062898129617127412,
    -0.82195806075666966, 0.13590398152973326, 0.074661312267578051,
    -0.7267964389727305, 0.23624718470084202, -0.16626845410243005,
    0.9489768793750073, -0.99921048696094761, -0.12413589006401858,
    0.27743076153192242, 0.38731757204752093, -0.73903512029331264,
    0.43047579535738056, -0.43340125800217805, -0.3218797551976601,
    0.64257854514308077 };

  static const signed char b_iv1[21] = { 19, 15, 30, 13, 3, 10, 29, 3, 0, 21, 0,
    0, 0, 28, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void bb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { -19.75, 109.5, -4.2815000000000012, 0.0, 0.0,
    45.0, 59.125, 104.0, 62.5, 46.9375, 97.275, 0.0, 0.0, 0.0, 19.5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, true, true, false,
    false, false, false, false, false, true, true, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.008349084965744354, 1.1250491760707746,
    -0.020872412041487827, 1.3689325759490181, -1.0475212934029317,
    -0.31394657138732085, 0.027044058980706429, 0.71777196008866972,
    -0.46784268653433608, 0.18473696625687075, -0.12483636798820211,
    0.97360733415617162, -1.1143698234564028, -1.0445745633573702,
    -0.013254836034391562, -0.26548956893050984, 0.30431319641849175,
    -0.60543125621141713, 0.005886680201974818, 0.36937306499837863,
    -1.1867076957948985 };

  static const signed char b_iv1[21] = { 27, 1, 27, 0, 0, 16, 10, 1, 10, 22, 6,
    0, 0, 0, 14, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void bc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.094, 98.9375, 99.969, 69.75, 86.5, 48.8125,
    22.289, 93.5, 18.4375, 15.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { 0.00024955666578655475, 0.052269753845148995,
    -0.17748053739650058, -0.0078334371883887772, 0.44615478448729651,
    -0.8948440969570115, -0.064043113708901742, -0.35441044099039459,
    0.059074293318358159, 0.742312484973288, -0.3474595945602294,
    0.35934059102014687, -1.0533478047417562, 0.051270208297565727,
    -0.85807765224135746, 0.5924347150365793, -0.61137117259877694,
    0.25838447244177104, -0.11354314933585871, -0.76276707829341206,
    0.91128328190069363 };

  static const signed char b_iv[21] = { 5, 5, 5, 13, 13, 10, 8, 5, 8, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv19[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv19[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void bd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 10.0625, 7.625, -8.75, 128.25, 94.25, 144.5,
    76.5, -7.125, 97.875, 0.0, 99.1525, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.00041229526379853772, 0.026098655789301563,
    -0.255492226619974, -0.005423944553101503, 0.56019774809857126,
    0.58045139386745892, -0.45074326269561255, -0.071492864201457423,
    0.19573842072329981, 0.96020082406146978, 0.071774651806219281,
    1.0081552033313337, -1.014320991494273, 0.66228380335287584,
    -0.70504905283021813, -0.6643299509342544, -0.02726785348862917,
    -0.024370153685234257, 0.48665241339384913, -0.62466642047270726,
    0.96755481433058721 };

  static const signed char b_iv[21] = { 27, 27, 26, 15, 7, 9, 7, 25, 5, 0, 24, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv5[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv5[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void be_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.094, 98.9375, 100.73, 98.125, 94.5, 132.25,
    119.9375, 0.0, 0.0, 0.0, 15.75, 92.75, 99.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, true, true, false, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0063208101490100426, 0.0421684347146836,
    -0.17513830698704425, -0.010633271286580544, 0.40776925322835461,
    -0.2576345827840511, 0.73714233745479962, 0.0098525484856939061,
    -0.9957873526550366, -1.0050291561440277, 0.54068357371287534,
    -0.38424550839008975, 0.32773057431843455, 0.89363677247646889,
    -0.9048857271844839, -0.57836336674729816, 0.70363906276413257,
    0.45405981810641083, -0.49969237309161874, 0.60054179448219291,
    -1.0049486911580725 };

  static const signed char b_iv1[21] = { 5, 5, 24, 5, 17, 9, 19, 0, 0, 0, 2, 21,
    24, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void c_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 98.125, 22.25, 74.5, 99.8125, 89.5,
    90.5, 0.0, 100.65, 0.0, 0.0, 72.75, 0.0, 4.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, false, true, true, false, true, false, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.34466588511136548, -0.980891719745212,
    0.43979057591622578, -0.59591836734693693, -1.3982300884955734,
    1.0796460176991136, -0.48717948717948717, -0.39195979899497491,
    -1.4782608695652175, -0.74285714285714288, -1.5183246073298431,
    0.32258064516129037, 1.3658536585365855, 0.51063829787234039, -2.0,
    -1.7209302325581395, 2.0, 1.0303030303030303, -0.48275862068965519,
    -0.23076923076923078, 1.4285714285714286 };

  static const signed char b_iv1[21] = { 20, 5, 14, 4, 3, 19, 13, 0, 24, 0, 0, 7,
    0, 27, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void cb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 57.5, 68.5, 60.5, 4.5, 0.0, 52.0, 64.586, 23.5,
    0.0, 0.0, 80.5, 14.5, 65.625, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0098198294000888826, -0.7526170009107046,
    0.0079081921095032759, -0.99941073901710453, 0.5381888512213342,
    0.86344580991455833, -0.012005244454914351, -1.1142963699373702,
    1.0300219008129645, -0.37054594388160766, 1.2635048036191678,
    -0.49677376634353043, 0.017771593954561918, -1.147756792718811,
    1.0207443842538462, 1.2765179139856171, -1.0033582785988364,
    1.1671916480029096, -0.78331095792604233, 1.034491133078387,
    -0.0019312298605273896 };

  static const signed char b_iv[21] = { 7, 16, 7, 30, 0, 10, 7, 2, 0, 0, 4, 20,
    7, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv10[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv10[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void cc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, -1.875, -2.875, 19.9295, -3.25, 97.25,
    37.5, -2.015500000000003, -0.875, 0.0, 93.625, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.002538834905327195, -0.08009427375741475,
    0.12016475773992913, 0.0922991963061812, -0.199571527874656,
    -0.643868062956342, 0.15988241067823272, -0.098030123956654863,
    0.49171180318919527, -0.98196061909428334, -0.12370312406114579,
    -1.0616583812294778, 0.19392853480200328, -0.81963269623806023,
    0.18860560472645935, -0.24642579861127395, 0.70733561151345425,
    0.70224168350517935, -1.1238394748617722, -0.9607681742207459,
    -0.060969710952309408 };

  static const signed char b_iv[21] = { 20, 25, 30, 2, 28, 11, 10, 25, 28, 0, 17,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv5[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv5[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void cd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 59.125, 53.9375, 64.5625, 5.25, 51.25, 17.25,
    97.125, 0.0, 0.0, 0.0, 0.0, 0.0, 68.5, 93.5, 91.5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { 0.0020808641804472331, 0.092469256525613275,
    -0.0820877453539127, -0.029299261730954144, 0.28221136652527956,
    -0.32927205835265033, 0.037015058929170036, -0.097863114893592063,
    0.72776816498709607, -0.5206775488909221, 0.44353408337528943,
    -0.67510185984976634, -0.058882510613391482, 0.23578831751358523,
    -0.17710196280363255, -0.25457696784821382, 0.81033822141540568,
    -0.56532131767940275, 0.3520556377047479, 0.66287607229250933,
    -0.29254558738712411 };

  static const signed char b_iv[21] = { 10, 10, 10, 30, 22, 2, 11, 0, 0, 0, 0, 0,
    16, 11, 21, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void d_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.9375, 99.125, 20.25, 95.25, 100.65, -8.5,
    90.5, 89.5, 0.0, 0.0, 0.0, 93.5, 0.0, 70.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.19877313536255975, -0.54652868764121487,
    0.25881429845574322, -0.36508055284417762, -0.94220887869289194,
    0.78519409478027558, -0.2094609685473259, -0.16761880230042916,
    -0.983190343842739, -1.0651828028367403, 1.0784063805761728,
    -0.44483515524869011, 0.88830424089378279, 0.4755644985516021,
    -1.5339859857078388, -0.3253369828428806, 0.58314840931633871,
    0.26420334664877893, -2.9796633980470366, 0.773502152488036,
    -1.0642592152120736 };

  static const signed char b_iv[21] = { 20, 11, 14, 1, 24, 25, 13, 19, 0, 0, 0,
    19, 0, 4, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void db_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 31.5, 28.375, 37.5, 27.6405, 95.0, 0.0, 90.75,
    8.0159999999999982, 0.0, 57.5, 90.25, 0.0, 18.25, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0049417985784063964, 0.010822524681110288,
    -0.89612895486726785, -0.012746870959936854, 0.72027268737041394,
    0.95358766953894081, -1.0911171354129561, -0.0002481597422744096,
    -1.1938975649676282, -0.24143734627368205, 1.0984475957080275,
    1.0110337115301613, -1.1247590299890822, 0.016174567220267923,
    -0.9002051011113531, 0.88280341772166637, -1.1626611861322487,
    -1.0382566817713863, 1.1757517502482833, -1.1385509395913052,
    0.10621551050884979 };

  static const signed char b_iv[21] = { 8, 8, 22, 8, 23, 0, 23, 28, 0, 10, 21, 0,
    26, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv11[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv11[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void dc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.36, 98.835000000000008, 57.5, 88.25, 82.75,
    126.0, 68.5, 96.25, 4.875, 0.0, 16.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0058453607913608345, -0.047805358082880382,
    0.20147063276806268, 0.015221998289050579, -0.34970850627620614,
    -0.26770348958046275, 0.44555403735549282, 0.1405225338395942,
    -0.25726544906691734, -0.79497908428853958, -0.00258441850849873,
    -0.49796389590271423, 0.55241843032758331, 0.81519115199202741,
    0.033931124059281968, 0.46879815868190694, 0.026946529689179554,
    -0.35184459823214753, 0.68882952169742218, -0.54909183490247881,
    0.36050028676556944 };

  static const signed char b_iv[21] = { 18, 24, 22, 1, 1, 21, 22, 17, 28, 0, 14,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv5[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv5[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void dd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 95.5625, 96.25, 96.9375, 13.5, 78.5, 93.75,
    99.25, 0.0, 92.955, 0.0, 0.0, 0.0, 104.5, 13.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { 0.0017726791836813005, 0.16070905368859248,
    -0.043253946614901895, 0.28707358637238295, -0.60049771543177288,
    -0.28660879302791326, 0.042923540613151963, -1.0124046553372532,
    0.34269795007164339, -0.79773446496138056, 1.0117152154891003,
    0.60233398543228689, -0.36461705110313336, 0.36923497093072227,
    -0.0350484225709652, -0.32971671457432233, 0.44585651732394105,
    -0.84124462019963209, -0.19571202440892571, 0.46657235820331189,
    -1.0113906755590685 };

  static const signed char b_iv[21] = { 17, 11, 11, 20, 22, 5, 21, 0, 23, 0, 0,
    0, 3, 25, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv18[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv18[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void e_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 57.1875, 7.9375, 0.9375, 135.09550000000002,
    96.550000000000011, 187.5, 68.25, 16.9375, 0.0, 0.0, 0.0, 0.0, 0.0, 15.953,
    84.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.12652104619791635, 0.28043560005887197,
    -0.41005513411541944, 0.09059704127438, 1.144901258041517,
    -0.72527045556165459, -0.072310049663234247, -0.07215493596388127,
    1.0838944898541127, -1.4253739508322083, 1.3198104545468068,
    -0.75746718880637676, 3.4117233005212486, -0.38695756495011624,
    0.37144750403421478, -0.66934349643692026, 0.20848823397585733,
    -1.1396660866094115, -0.076397762004753789, 0.72173343899642284,
    -0.62199418729721812 };

  static const signed char b_iv[21] = { 4, 27, 30, 21, 6, 21, 16, 20, 0, 0, 0, 0,
    0, 2, 4, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv1[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void eb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 23.875, -1.5154999999999994,
    -6.0940000000000012, 86.5, 78.5, 22.75, 13.344000000000001, 67.5, 0.0, 0.0,
    0.0, 0.0, 85.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0038220394385077017, -0.09682329523627585,
    0.13313546934607537, -0.14170806385771012, 0.61214085130155538,
    -0.48242643393780632, 0.20164278213476017, -0.707781845995711,
    -0.069257659635096766, 1.3580248121366423, -1.1069553297249004,
    0.98555129945697606, -0.86483655877598065, 0.44064720854674666,
    0.021054809817784265, 0.56973321481357531, -1.0269807340211865,
    -0.523217875532777, 0.012999429279266008, 0.014213443478729416,
    0.78694754263727429 };

  static const signed char b_iv[21] = { 20, 8, 30, 26, 13, 13, 20, 8, 13, 0, 0,
    0, 0, 13, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv12[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv12[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ec_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 95.866, 59.5, 96.705, 112.8985, 79.0, 93.625,
    96.75, 0.0, 0.0, 0.0, 0.0, 0.0, 98.25, 23.875, 55.5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0027855519200117359, -0.61466817868697365,
    0.0121828091155673, 0.14183648901626178, -1.0388144370708936,
    0.3604344798290286, -0.028809256383533217, 0.79519019249794565,
    -0.87086182176005655, -1.1133225104461479, 1.00903708766607,
    -1.0723226892671123, 0.46830760392088805, -0.67543119159564158,
    -0.00072772902794351912, 0.81738466989535929, 0.067741538303615123,
    -0.96304618338410775, 0.51523510317304655, -1.0464693431428955,
    0.012470448237878389 };

  static const signed char b_iv[21] = { 12, 16, 24, 9, 16, 17, 6, 0, 0, 0, 0, 0,
    5, 2, 1, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ed_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.094, 69.75, -4.75, 3.5, 75.25, 68.5, 100.031,
    -6.5, 0.0, 0.0, 98.75, 0.0, 0.0, 0.0, 69.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, false, true, true, false, true, true, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.002254767896742805, 0.049925840765058759,
    -0.17884304837394391, -0.23600405638904684, 0.10668779196402166,
    0.38760819481741138, -0.29511431353832429, -0.39506874038710887,
    0.81830639625827006, 0.493428639687287, 0.013579312883372007,
    0.58891244046556224, -1.0082499416707174, 0.28171551154767038,
    -0.453852376316923, 1.0239808120594969, -0.48944901533584578,
    -0.08442463443483815, 0.44122589256979594, -0.6460093669575212,
    0.12763207069750809 };

  static const signed char b_iv1[21] = { 5, 13, 26, 28, 7, 4, 3, 30, 0, 0, 11, 0,
    0, 0, 22, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void f_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 4.8435000000000006, 100.3775, -2.4375, 90.1875,
    15.9375, 81.0625, -5.25, 57.5, 0.0, 0.0, 101.25, 61.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.075114573879624225, -0.17082570901500971,
    0.41676710330141786, -0.2590197354255156, 0.61541803248267546,
    -0.23402589606083113, 0.98588846980687173, -0.080547408575909252,
    -0.65437218462092839, -1.0887892056194075, 0.89398059033784494,
    -0.56304065676405746, 1.7169354703509563, -0.23435179394159111,
    1.2707639478452828, -1.3626998659311653, 0.010618407738993927,
    1.31003479968007, -0.7333493128330616, 0.2793268682269644,
    -1.5634779011500803 };

  static const signed char b_iv[21] = { 30, 24, 29, 1, 20, 22, 25, 7, 0, 0, 6, 4,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv2[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv2[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void fb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 31.375, 0.0, 123.25, 70.5, 128.25, 98.55, 99.25,
    86.5, 134.9375, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 76.0, -11.75, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, true, false, false, false, false,
    false, false, false, true, true, true, true, true, true, false, false, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.003216118413448986, 1.4117070611978,
    -0.011159806495436056, 0.085237693215318114, -0.14385575366635198,
    0.017093701921615898, 0.4930171518516428, -0.49646912473712712,
    0.082143361087973418, -0.12119906513562735, 0.27741053173582009,
    0.82098452215786621, -0.86647543065563071, -0.56555894756914571,
    1.2299403606170729, 0.71590223384368779, -0.097143352649436451,
    1.0949719838440566, -0.62157539453343735, 1.0999719517813689,
    -0.22416851359986936 };

  static const signed char b_iv1[21] = { 22, 0, 3, 10, 15, 6, 17, 16, 15, 0, 0,
    0, 0, 0, 0, 4, 25, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void fc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 33.0, 0.0, 90.5625, 104.25, 94.1875, 72.5,
    98.835000000000008, 19.75, 20.25, 0.0, 0.0, 156.0, 80.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, true, false, false, false, false,
    false, false, false, true, true, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0049735294484769474, 1.0426653225924047,
    -0.012760739954482502, -0.0920874718124359, 0.098251098635164513,
    -0.42935609167465072, 0.0058065964888754122, 0.26899569133910767,
    -0.086174897757753915, 0.039426868960182951, -0.71293509859551818,
    0.12254561877583399, -0.38719430410915723, -0.11160390968091023,
    0.46821277798967886, 0.14110172111367081, -0.82470121516899531,
    0.18612028169099595, -0.88189778231297489, -0.60781145270883563,
    0.91478171468914593 };

  static const signed char b_iv1[21] = { 22, 0, 19, 15, 1, 13, 24, 20, 14, 0, 0,
    15, 16, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void fd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 97.0625, 22.25, 13.125, 47.1875, 151.5,
    89.25, 0.0, 67.5, 0.0, 18.25, -0.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, false, true, false, false, true, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0013768877867640819, -0.075118197449329266,
    0.12005554297917835, 0.069706477731552155, -0.20931086100914209,
    0.2769678347328221, -0.22522928327392452, 0.69615526947036432,
    -0.032167930871397035, 0.33912853789218028, -0.28581098382158227,
    0.33274232207527743, -0.68371352359659066, 0.030156685585222713,
    -0.90519735651809907, -0.64799334383048812, 0.086471858020465933,
    -0.12110903610896846, -0.75997435005966019, 0.063806642814309519,
    0.60883563284907016 };

  static const signed char b_iv1[21] = { 20, 5, 14, 2, 10, 9, 13, 0, 13, 0, 20,
    25, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void g_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 7.625, 1.875, 14.25, 127.5, 21.125, 0.0, 61.75,
    -7.125, 112.5, -3.375, 26.875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.037779847315712031, -0.1254744374455688,
    0.41834489301126421, -0.3015098747879148, 0.20440194396550426,
    2.4901010335258764, 0.28580456623855804, -0.46193993067293937,
    0.1138131155341887, 0.37308546479133409, -0.39534423020183362,
    0.74786216384692628, -0.20632128644322789, -1.1404029126522723,
    -0.30745389084977082, 2.6510512907873305, -0.0021175812941304703,
    1.0875238447172473, 0.18522152177404408, -0.809799333395854,
    0.96734864116788566 };

  static const signed char b_iv[21] = { 27, 25, 20, 15, 2, 0, 4, 25, 9, 29, 14,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv3[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv3[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void gb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 97.65, 97.65, 97.666, 97.55, 98.75, 45.75,
    20.9375, -13.5, 0.0, 0.0, 99.5, 0.0, 0.0, 1.625, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { 0.0019599695742722831, 0.18160938577078936,
    -0.078695821911527089, 0.32830906043563546, -0.48580791802371731,
    -0.771286548714098, 0.00380005757261141, 0.21018208901699703,
    1.3341421774258533, -1.1093781581080484, 0.25965749184055703,
    0.5535027547851904, -1.002114762374162, -0.13894855590163782,
    0.22233412485522266, -1.1225974616735308, 0.28125538736020678,
    0.95028069654143077, -0.98334445504798629, 0.16201085517854066,
    -0.43961373928714831 };

  static const signed char b_iv[21] = { 24, 6, 12, 6, 23, 4, 20, 27, 0, 0, 11, 0,
    0, 27, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv13[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv13[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void gc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 98.475, 58.125, 98.65, 2.75, 129.5, 98.6055,
    101.5, 1.625, 0.0, 14.1875, 98.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0077120465027650477, -0.096343823719429733,
    0.12270617979862994, 0.10353793583515865, -0.26833085123016281,
    0.752304340378877, 0.025154082966147025, -0.067235237084507432,
    0.636220913484856, -0.47246336068988326, 0.22722336808355634,
    0.93933522359910948, -0.94621455993593273, 0.46185791017178179,
    -0.082478134721190255, 0.036511565958656074, -0.93231939100452343,
    0.23164206822910868, -0.6600051600955098, 0.50179794275540024,
    -0.54028189357216083 };

  static const signed char b_iv[21] = { 24, 16, 24, 28, 15, 12, 9, 28, 0, 8, 18,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv20[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv20[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void gd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 100.65, 100.55, 94.3125, 99.125,
    -11.694500000000005, 91.9845, 110.0, 75.75, 106.125, 0.0, 0.0, 0.0, 0.0, 0.0,
    148.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.003923937519104425, -0.02716229421968331,
    0.36122491428733888, -0.0096193690667875729, -0.75007092887215876,
    -0.73239857757483906, 0.49614824076201647, 0.048550760030559657,
    -0.21444782937580562, 1.0206455326490096, -1.0170310759990717,
    1.0024221802430004, -1.0126319344076065, -0.2185123634388543,
    0.70165210793326693, 0.0896777672951417, -0.31237067857463757,
    -0.29721648013220658, 0.48606995874721787, 0.84515507199186024,
    -0.70445201378430689 };

  static const signed char b_iv[21] = { 24, 6, 23, 17, 27, 23, 15, 4, 13, 0, 0,
    0, 0, 0, 9, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv15[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv15[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void h_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 0.9375, 48.5, 13.875, 0.0, 96.47, 94.125,
    -1.1639999999999997, 96.125, 96.75, 0.0, 0.0, 21.344, 90.5, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, true, false, false,
    false, false, false, true, true, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.026576705432121504, -0.21225628633685281,
    0.16778755911017648, 2.39640456215483, -0.24196454062484465,
    -1.3622369348595014, 0.215531311027508, -1.024414018323222,
    -0.14641695243013592, -1.7275562932256214, -1.2545695404076986,
    -0.083455781328943782, 0.42844179278455535, -0.3860180513055857,
    -1.2783920763055909, 0.8105901834348942, -0.2305549211934256,
    0.11169482495901574, -1.1596083185764763, 0.0501238818685685,
    0.80355782850917878 };

  static const signed char b_iv1[21] = { 30, 19, 20, 0, 6, 5, 29, 11, 24, 0, 0,
    14, 19, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void hb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 27.5, 15.75, 92.5, 7.625, 53.75, 96.1, 0.0,
    86.25, 75.875, 0.0, -4.5, 0.0, 93.6875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    true, false, false, true, false, true, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    0, 0, 14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.00602134150910602, -0.018942168084672615,
    0.97050960750769433, 0.010998499973718649, -0.86518624465551386,
    1.1184703845087387, -1.0324688041105359, -0.049029261821806731,
    0.41190342140889175, 1.0290747791577728, -1.020253439499335,
    -1.0022964097447455, 1.1316284972748611, -0.020396883199857,
    -0.90015097275425593, 1.1659764950088141, 0.16642430806019859,
    0.701957512583464, -1.2000304273143307, 1.2897043999914715,
    1.0788850680501851 };

  static const signed char b_iv1[21] = { 27, 27, 13, 27, 4, 6, 0, 4, 7, 0, 28, 0,
    5, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void hc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 27.5, 40.539, 92.5, 99.5, 46.031, 96.1, 0.0,
    98.55, 95.5, 93.25, 100.65, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.0047927411827686775, -0.016088334522587705,
    1.0412580183872975, -0.56076859596984274, 0.0036687301819613174,
    1.0525336108327146, -1.0006264532256592, 0.33589384535030026,
    -0.85791001076323026, 0.44231748359295486, -0.028019005217221594,
    -1.0008249845758368, 1.0618199656117837, 0.90752682792618089,
    -0.76835240759556989, 0.75612756054693642, -0.98524205652002561,
    -0.56359524125313165, 0.57945125224871863, -0.058346224806517938,
    0.41468426850880974 };

  static const signed char b_iv[21] = { 27, 4, 13, 3, 4, 6, 0, 24, 17, 5, 24, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv8[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv8[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void hd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 15.9375, 4.9375, 60.5, -4.25, 16.5, -0.5, 1.75,
    0.0, -8.5, 0.0, 0.0, 0.0, 0.0, -3.25, 90.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0026222170619244617, -0.17577198700828309,
    0.0421003163171072, -0.36027020560743928, 0.44244912953108162,
    0.56767805095051194, 0.018630425141161214, -0.93793489499552651,
    -0.16775562477737135, 0.66890878658032482, -1.0099703341789712,
    0.81659704769854524, -0.92063836606769334, 0.12075667230692022,
    -0.098123132252819351, 0.5811564820156957, -0.35148658266553068,
    -0.18925211937979972, 0.25922020976613513, -0.37681463303376478,
    0.088711591365407114 };

  static const signed char b_iv[21] = { 20, 27, 7, 25, 2, 25, 27, 0, 27, 0, 0, 0,
    0, 27, 19, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv16[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv16[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void i_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.094, -27.6565, 28.5, 0.0, 122.5, 0.0, 100.75,
    93.25, 98.5, 95.25, -12.5, 0.0, 68.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const boolean_T b_bv[21] = { false, false, false, true, false, true,
    false, false, false, false, false, true, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 0, 0, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.018737008994349713, 0.096500326793566266,
    -0.33717139583824, 8.9962579424643536, 0.0876845640933739, 6.40781319244365,
    -0.36184794407334647, 0.12598547278254768, -1.3182225488542545,
    -0.54969077251445342, 0.3903342519870282, -0.3558278389163132,
    0.223106457565685, -1.172321383124652, -2.1404395811421488,
    0.68841035026324926, -0.707515755036782, 2.5196480635451746,
    0.11050241915216039, -0.41849139115744788, 0.36637040593064751 };

  static const signed char b_iv1[21] = { 5, 26, 10, 0, 1, 0, 1, 23, 17, 3, 27, 0,
    13, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ib_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { -2.25, 2.9065000000000012, -1.9375, 14.625,
    99.0, 71.5, 86.75, 100.02000000000001, 0.0, 97.5825, 0.0, 0.0, 0.0, 0.0,
    89.875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, false, true, false, true, true, true, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0022086011735359674, -0.19700717833908948,
    0.052429316026964982, -0.43693358737586124, 0.19352454075987824,
    0.68088867475778747, 0.00093214404165126033, -0.606955788171396,
    1.0175905769102864, 0.4739941136034056, -0.706699313314878,
    -0.60321454275211339, 0.89943608981683421, -0.930753988786019,
    0.023948824941412959, -0.78057221529412368, 0.35761981873751686,
    -0.32534859006346906, 0.84792884862961149, 1.002424104603675,
    -0.011608504025920287 };

  static const signed char b_iv1[21] = { 27, 25, 27, 26, 12, 13, 15, 24, 0, 18,
    0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ic_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 92.156, 85.5, 140.5, 1.75, 99.05, -2.3125,
    -4.1565000000000012, 0.0, 0.0, 0.0, 0.0, 115.375, 25.742, 0.0, 76.5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0016906895553497033, 0.2820269035592714,
    -0.027522831467011191, -0.3440436875013958, 0.51192031985076636,
    -0.070898443661297411, 0.2062689049071677, -0.65054134484100845,
    0.71267749784080636, 0.66406168855712844, -0.9522931155190677,
    -0.26472079754215366, 0.00422380051224351, -0.770562800608493,
    0.32962025071170853, -0.30786109460088784, 0.9181930475018163,
    0.059272352378211587, -0.595820749137383, 0.55809101928203819,
    -0.0263171889682641 };

  static const signed char b_iv[21] = { 9, 9, 21, 29, 24, 26, 27, 0, 0, 0, 0, 19,
    8, 0, 22, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv21[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv21[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void id_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 48.75, 44.5, 50.875, 1.5, 99.25, 127.5, 16.969,
    98.85, 0.0, 0.0, 0.0, 0.0, 0.0, 67.625, 90.875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.0034522284451669032, 0.2025870703587497,
    -0.048000100382279351, -0.30913641447460394, 0.40221387587535629,
    -0.444964377257369, -0.017169469054265592, 0.24789259874114281,
    -0.99123462994531775, 0.55411224351496724, -0.49211863917489196,
    -0.74206267272849347, 0.74611663953530227, -0.17599297636874414,
    0.078228991808955234, 0.72329652051313664, -0.80375240386452274,
    -0.41083830031312241, 0.14110770043995888, 0.24639729752703643,
    -0.19516757129541751 };

  static const signed char b_iv[21] = { 10, 22, 10, 26, 19, 21, 2, 18, 0, 0, 0,
    0, 0, 16, 1, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv1[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void j_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 75.25, 96.705, 98.75, -4.5, 96.75, 0.0625,
    129.0, 0.0, 23.5, 23.8905, 46.9375, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.021998213227563648, 0.0604986943043241,
    -0.50000315498197245, 0.5510318839523779, -0.016226984533703279,
    -0.821729987524303, 0.19020588315663517, -1.3278501767381332,
    0.69246846653798166, -1.0972135780102006, 0.060594025228809308,
    -0.52071882768495281, -1.1833158507532033, -0.657520799774957,
    0.67772477129760067, 0.90625638292662836, -0.50818353024194862,
    -1.37918164463925, 1.3282584949944807, -0.45422057001469407,
    0.14911862952109939 };

  static const signed char b_iv[21] = { 4, 24, 12, 30, 6, 28, 21, 0, 2, 2, 22, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv4[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv4[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void jb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 95.995, 12.5, 96.705, 0.0, 99.25, 19.5, 96.85,
    0.0, 0.0, 85.5, 81.75, 5.4690000000000012, 99.5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0014451284216741569, -0.63476619467074635,
    0.014473704903726398, 1.0503360885424573, -0.812073758517345,
    0.40790475287509648, -0.028742621669190782, -0.95567548918188161,
    0.38456065897650049, 0.65335023700799455, -0.30594609182023141,
    -0.77317312353180445, -0.0088142764111427824, 0.72306163916385524,
    -1.0664794366461625, 0.28693892360589185, -0.93429323159291577,
    -1.1216052783550128, 0.5436892968108088, -0.023448911525592205,
    0.89281814789507274 };

  static const signed char b_iv[21] = { 12, 14, 24, 0, 19, 14, 24, 0, 0, 22, 1,
    27, 22, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv14[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv14[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void jc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 27.5, 150.625, 92.5, 72.25, -3.875, 96.1, 0.0,
    68.0625, 15.5, 99.5, 53.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.00076616743659854041,
    -0.0082887005107942953, 1.0201059926145934, 0.015627661068204037,
    -0.316802348708862, 1.0292674783264049, -1.0003486614467292,
    -0.03910557678561935, 0.25169678860310196, 0.8204531480711752,
    -0.47150097759551429, -1.0005221417631576, 1.0380429434692882,
    0.024021077350697553, -0.35530541189135878, 0.67761737926053955,
    0.070953987329928844, 0.97347833427446051, -1.0060747215306858,
    0.37361838360830518, -0.74150293238118892 };

  static const signed char b_iv[21] = { 27, 9, 13, 16, 28, 6, 0, 4, 14, 17, 22,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv8[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv8[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void jd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 96.705, 128.5, 96.75, 108.0625, -2.5, 23.8905,
    107.25, 57.5, 0.0, 0.0, 0.0, 0.0, 0.0, 103.5, 24.375, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0045607536461325692, 0.23601081010364375,
    -0.04241889920927977, 0.023528390984798992, 0.69455478191623721,
    -0.71133481810188792, -0.0069759671493587984, 0.35013339779154146,
    -0.69368520801223177, -0.89366427131003723, 0.89242848422197851,
    -0.89875309542997128, 0.16053745217223123, -0.047301086610641641,
    0.3182585475111781, 0.85441827362624712, -0.25987209694606234,
    -0.010761246901546642, -0.86436785649059067, 0.42509278401324269,
    -0.89773072074922589 };

  static const signed char b_iv[21] = { 24, 21, 6, 3, 28, 2, 19, 10, 0, 0, 0, 0,
    0, 19, 2, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv1[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void k_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 57.1875, 57.375, 57.875, 98.25, -0.1875, 0.0,
    -5.1875, 2.75, 93.5, 21.75, 94.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.022231962327744315, 0.16787481335962287,
    -0.159831900517724, -0.023797274727362632, 0.54748146901363159,
    -1.9521949859625365, -0.12967270993982585, 0.29644807558167746,
    -0.35223459465160589, -0.065858161675511326, 1.0486326953637239,
    -1.0141251825039077, -0.083731808054762116, -0.056161883501995635,
    1.2530801946037413, 0.96604423002649387, -0.52805630833521788,
    -0.72777610023066375, 0.65915130386618292, 1.1490562856588074,
    -5.6221108079771707 };

  static const signed char b_iv[21] = { 4, 22, 4, 24, 28, 0, 30, 28, 17, 2, 16,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv3[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv3[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void kb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 118.25, 115.5, -0.6875, 100.875, 50.0, 1.0625,
    80.5, 97.5, 107.25, 0.0, 0.0, 0.0, 0.0, 0.0, 52.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0029902566704532647, 0.014319643261784018,
    -0.57230687683457682, -0.0037485396172956056, 0.99543082787045845,
    0.22791179133277831, -0.98672694964279761, 0.04746033654104985,
    -0.2561331634162064, -1.0798903491640455, 1.1738581249562434,
    -1.0315764749163108, 1.045718571319415, 1.0175450215053834,
    -1.0470626778216054, 0.0080415000886405914, 0.61434259820332793,
    -0.61440699916162145, 0.14727675209987356, 0.19988902760528582,
    -1.1241731977197307 };

  static const signed char b_iv[21] = { 19, 19, 28, 19, 22, 30, 1, 19, 19, 0, 0,
    0, 0, 0, 4, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv15[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv15[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void kc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.125, 104.75, 106.75, 98.9375, 20.25, 19.75,
    1.875, 66.5625, 72.5, 0.0, 0.0, 0.0, 97.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, false, false, true, true, true, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -4.9985953285826779E-5, 0.050984734989854924,
    -0.16654170935388565, 0.098810534842723327, -0.34923902642284271,
    -0.27267522929983035, 0.66799566949362044, 0.019359547986837138,
    0.43951363077161815, 0.017302016908348854, -0.9826374929768229,
    -0.53304317689575631, 0.072589879317970382, -0.46549397376898921,
    1.050233325068012, -0.11168451571175356, 0.29430945818285892,
    0.58263050943909223, -1.0067643619798285, -0.60049098296641557,
    0.35105755107439895 };

  static const signed char b_iv1[21] = { 17, 7, 7, 11, 14, 20, 25, 16, 4, 0, 0,
    0, 12, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void kd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.36, 99.45, 68.5, 57.1875, 39.0, 0.0, 14.5,
    49.75, 60.8125, 0.0, 0.0, 6.5, 100.95, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, false, false, true, true, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0035825102246644746, -0.041364339720909173,
    0.20217457753494653, -0.020198096342641258, -0.96318780691370176,
    -1.0134966743731237, 0.2870166909350419, 0.10908359387662497,
    -0.10881467167002959, 1.0026533725685964, -1.014035402280949,
    -0.510313664872436, 0.40243988478992504, -0.10306426816923943,
    0.29920564615318973, -0.53974333213643844, -0.037210201600433084,
    -0.87035083857817785, 1.0076380216797105, 0.52804905135962232,
    -0.25077241869358607 };

  static const signed char b_iv1[21] = { 18, 6, 19, 4, 10, 0, 14, 4, 4, 0, 0, 27,
    18, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void l_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 45.931, 0.0, 31.5, 95.05, 14.5, 12.5,
    -4.2815000000000012, 90.75, 0.0, 0.0, 0.0, 45.0, 40.539, 0.0, 86.75, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, true, false, false, false, false,
    false, false, true, true, true, false, false, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.010057128818451595, 2.2144971129449154,
    -0.024286730076549887, 0.00031597114966805379, -1.0269966051892181,
    -1.0931934741977274, 0.021861387099360731, -1.2367995336926383,
    1.5079813127979707, -1.309706458691325, 0.98553149126510187,
    -0.34872777825673734, 0.092049025650128763, 1.0554273852847043,
    -1.324545233269385, 1.5121099573516343, -0.6077674223372701,
    -0.85459242606562014, 0.13433138085998567, -1.980669114154324,
    -1.2547398628128732 };

  static const signed char b_iv1[21] = { 19, 0, 8, 6, 25, 27, 27, 23, 0, 0, 0,
    16, 4, 0, 3, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void lb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 99.094, 37.5, 69.75, 127.5, 0.0, 97.375,
    0.0, 75.25, -8.5, 70.0, 95.125, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, true, false, false, false, false, true, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 0, 0, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0021292916466841192, -0.084042278222575539,
    0.12228001844620744, 0.010008081176501578, -0.37195003847492486,
    -1.1348956002523702, 0.16466821715776492, -0.408099142795577,
    0.11428428721570619, -0.59942519692937224, 0.32903394737954955,
    -0.016813071622678828, 0.42533750032259465, 0.69399986404177538,
    -0.03578707011797589, 0.64013986018940117, -0.77096769280951749,
    0.82841374098793241, -1.0574647544980802, 0.40286228145346603,
    -0.25953028754415813 };

  static const signed char b_iv1[21] = { 20, 5, 10, 13, 15, 0, 5, 0, 7, 27, 10,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void lc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 19.9295, -0.030999999999999694, 92.25, 97.745,
    57.1875, 143.5, 99.35, 1.5, 0.0, -2.25, 1.125, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0019342845318314043, -0.07596376060500476,
    0.11098053934208874, -0.34946548364265578, 0.050743681993938194,
    -0.64194986176235946, 0.16520905985991724, -0.017845499374665327,
    -0.65405704199474912, 0.31878604647297937, -0.087941680483895071,
    -0.82636526232370677, 0.76586768784569415, 0.26933531061621441,
    -0.23194393281037703, -0.571260553516906, 0.55955509513672852,
    -0.72414051507164789, 0.52713850999632172, 0.18498355062492802,
    -0.39045422621577952 };

  static const signed char b_iv[21] = { 2, 28, 23, 6, 10, 21, 24, 27, 0, 27, 27,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv20[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv20[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ld_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 27.5, 21.5, 96.1, 0.9375, 0.75, 0.0, 92.5,
    -0.15600000000000058, 116.25, 0.0, 0.0, 0.0, 0.0, 104.875, 0.0, 0.0, -4.25,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, false, false, true, true, true, true, false, true, true, false, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0047650681109253435, -0.013433978857749851,
    1.0081184974278041, -0.003431919267155656, -0.87656455537556255,
    -1.0001005172015089, 1.0128505146443, -0.097279225996277446,
    0.0950746005351649, -1.0170089142682124, 1.001849428974539, 1.01480707031447,
    -1.0000240310020623, 0.013893555600757848, -0.36796402954778945,
    0.24936097779912328, -0.068836156133980031, -0.42362361678119154,
    0.12912122464381076, 0.46161181089887382, -0.19501800830697549 };

  static const signed char b_iv1[21] = { 27, 27, 6, 30, 28, 0, 13, 30, 15, 0, 0,
    0, 0, 15, 0, 0, 26, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void m_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 118.25, 115.5, 89.5, 100.3775, 50.0, 0.0, 51.5,
    100.25, 102.1, 0.0, 99.5, 0.0, 12.8595, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, false, false, true, false, true, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.011425081069109689, 0.018248386244731841,
    -0.63529108804237022, -0.00989865627278635, 1.47283318841693,
    1.245878936454454, -0.97672310268427076, -0.062915374590364087,
    0.483697183000144, -1.153655511038487, 1.7426640741393407,
    1.0276941956570038, -1.2629467025452428, -0.021132251226866891,
    -1.4600271236021038, 0.66616900721396821, -1.1459380510195583,
    1.4864130779939224, 4.30744413840957, 1.1611244720122056,
    -1.3372998570122137 };

  static const signed char b_iv1[21] = { 19, 19, 7, 24, 22, 0, 4, 6, 18, 0, 23,
    0, 2, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void mb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 91.25, 6.875, 92.9375, 13.25, 128.5, 102.656,
    139.0625, 0.0, 100.25, 0.0, 0.0, 0.0, 0.0, 158.0, 4.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0044464694930239348, -0.54689435614724613,
    0.020504320195749132, -0.84271804711665077, 0.45745175235903052,
    0.673596262049854, 0.001338389459124772, 0.71989332116539018,
    -1.0120084703223635, 1.0881441591871224, -0.79861389203954392,
    1.0087234288881177, -0.56534341812298594, 0.054736960658263473,
    -0.23631590450439788, -1.1034795276607934, 1.0708435433014643,
    0.041330035228805212, 1.6597224287937922, -0.47818875330269178,
    0.32016915375435151 };

  static const signed char b_iv[21] = { 23, 27, 17, 2, 21, 13, 3, 0, 18, 0, 0, 0,
    0, 9, 27, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv16[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv16[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void mc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 98.5625, 98.5275, 24.25, 24.5, 99.6, 145.5,
    154.5, 0.0, -1.125, 0.0, 0.0, 16.25, 94.375, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, false, true, true, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0046632910335006926, -0.083695567427057,
    0.13630046621166164, -0.028486536706954953, -0.929634929128949,
    0.21015488502665172, -0.46595959332917369, -0.07249995348275,
    0.39385684615693295, -1.0514096184680941, 0.59884152356638776,
    0.27407014681797709, -0.47668503861280437, -0.68294555096174725,
    0.97907144021178893, -0.20574066124429646, 0.82698999770988157,
    -0.080554673783247543, 0.44353257314212635, 0.672094959526722,
    -0.92376025457852828 };

  static const signed char b_iv1[21] = { 12, 18, 2, 20, 18, 9, 15, 0, 29, 0, 0,
    14, 23, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void md_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { -20.046999999999997, 0.0, -14.25, 107.5, 92.25,
    99.65, 0.0, 86.6875, 7.0, 0.0, 0.0, 2.6875, 97.95, 56.75, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, true, false, false, false, false,
    true, false, false, true, true, false, false, false, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0,
    0, 12, 13, 14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0031858138538609177, 0.96486995816691257,
    -0.01116166289981127, -0.801139586596238, 0.00025574524071914019,
    -0.931762378353553, 0.85511979297992247, 0.010771234785437732,
    -0.62449457154548238, -1.0095786915799689, 0.28222834473351616,
    0.00011145256531490676, 0.88528370700957, -0.8341630425360661,
    0.85880846248091214, -0.0633228722496614, 0.14083598874049258,
    -1.001053932249498, 0.97227160192191264, 1.0054899647812803,
    -0.98303358231737026 };

  static const signed char b_iv1[21] = { 26, 0, 26, 19, 10, 18, 0, 10, 27, 0, 0,
    25, 6, 4, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void n_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 125.5, 128.4375, 118.75, -7.125, 7.625, 15.5,
    -7.5, 0.0, -1.9060000000000006, 0.0, 0.0, 0.0, -9.7385000000000019, 0.0,
    -6.625, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, false, true, true, true, false, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0098452360204153589, -0.10674005980454734,
    0.16186344369598885, -0.014323483232706409, -0.72565441392337715,
    0.77212211290437294, 0.030463664136439583, -0.81792855487594884,
    0.061267811872743834, -0.96082346385646711, 0.23939573193515382,
    -1.3715731372093, 1.1753630057372255, -1.1459252645207825,
    0.0996284995495562, 0.5954934731352074, -0.11022108134108895,
    6.7342682936401692, 1.0599163682260673, 4.4206765709792553,
    0.071497316929022517 };

  static const signed char b_iv1[21] = { 21, 3, 3, 25, 27, 14, 28, 0, 28, 0, 0,
    0, 27, 0, 28, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void nb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 10.0625, 7.625, 76.5, 13.0625, 14.625, 61.5,
    56.375, -0.0625, 91.25, 0.0, 0.0, 0.0, 0.0, 0.0, 14.9375, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0027471276194920287, 0.026932814846303235,
    -0.30158541096584263, -0.016492953358980128, 0.69262571121697436,
    0.62966902054225349, -0.56609866189626323, -0.39738474913813476,
    0.022308531315359339, -0.583327516580588, 0.88800316345742936,
    -0.63740977633800322, 1.0528594165486551, 0.62189090055835561,
    -0.95461743567295476, -0.71090065792580337, 0.33302168517600239,
    -0.7904746734672915, 0.046933377528750778, 1.0815961399389553,
    -1.0759997872251368 };

  static const signed char b_iv[21] = { 27, 27, 7, 8, 14, 16, 16, 28, 23, 0, 0,
    0, 0, 0, 20, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv15[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv15[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void nc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 100.85, 99.125, 106.5, 13.125, 7.625, 96.0,
    102.6, 97.5, 14.905999999999999, 0.0, 106.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0049275660259234522, -0.02613360853747804,
    0.483966426712211, 0.025949648494629222, -0.24775507684199244,
    -0.40170238140651032, 0.76390266166586052, 0.42386244056922218,
    -0.019746172569543211, -0.36298312037303171, 0.34011634769604976,
    0.84829982998154374, -1.0088324606683867, 0.94015866227406275,
    -1.0232557355662213, 0.8584732978948576, -0.2832169905161005,
    -0.7083425676921935, 0.03004914391272253, -0.755998577236166,
    0.896667101024492 };

  static const signed char b_iv[21] = { 24, 11, 9, 2, 27, 3, 18, 5, 2, 0, 9, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv5[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv5[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void nd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.25, 114.25, 76.0, 110.25, 125.25, 0.0, 0.0,
    19.9295, 124.5, 72.5, 2.75, 0.0, -3.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    true, false, false, false, false, true, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0,
    0, 12, 13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0021177901315521117, -0.010693044877295502,
    0.78001774624617148, 0.0047296366423804073, -0.56063970331215185,
    1.0286024423612479, -1.0038827689318865, -0.011453111887489558,
    0.51203909993915975, -0.777878803270186, 0.51980823231076967,
    -0.086390598829151413, 0.10484820178346835, 0.84271052303979821,
    -0.30902390853878553, 1.0067254682531424, -0.8897660983041169,
    -1.0012787394999083, 0.98514660132282761, 0.49026596405931011,
    -0.039301629276227143 };

  static const signed char b_iv1[21] = { 26, 13, 16, 13, 9, 0, 0, 2, 3, 21, 30,
    0, 25, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void o_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 10.9375, 4.75, 12.0625, 8.25, 0.0, 98.25,
    92.875, 0.0, 0.0, 100.55, 123.0, 103.5, 12.3125, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, true, false,
    false, true, true, false, false, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 0, 0, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.012575323930678926, -0.83886801775061282,
    0.0076675864556685416, -1.0564009616459864, 1.1152581698869215,
    0.55193468592789108, -0.030468694671631498, 1.1540021441697,
    -1.1681157967397195, 1.3187327952562302, -0.23654324834742646,
    -0.83642940767245155, 0.0083061769280172622, 1.6962646998087894,
    -2.3050971974616297, -1.032709807896746, 1.5575179323992954,
    0.37809618402191786, -1.3532188981835316, -2.5057167351088778,
    0.021461790448080293 };

  static const signed char b_iv1[21] = { 8, 30, 2, 2, 0, 5, 5, 0, 0, 24, 3, 3, 2,
    0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ob_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 100.95, 59.125, 99.088, -4.25, 64.5625, 73.5,
    102.55, 0.0, 68.75, 23.5, 112.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0021635250226581049, 0.016961091632262931,
    -0.503911879906623, 0.12012668179156509, -0.081930691219809185,
    -0.83114281080402763, 0.68485180440321947, -0.45283767798244551,
    0.18461298483248534, -0.40132039468955361, 0.060542980461338165,
    -0.97911289637701193, 0.46667899160558785, 0.87220134501273594,
    -1.0200580079969614, -0.21000311928277274, 0.28123031994466613,
    -0.58148117651358455, 0.62362782882283874, 0.4734459712321154,
    -0.061115655239986681 };

  static const signed char b_iv[21] = { 18, 10, 23, 27, 10, 16, 6, 0, 13, 8, 9,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv4[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv4[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void oc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 92.25, 87.5625, 98.0, 83.5, 97.5, -9.5, 76.25,
    33.0, 2.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { 0.00014853778740623507, 0.012537865322234831,
    -0.7163487907317877, -0.00018608050871239573, 0.89981318669133348,
    -1.0246050400320668, 0.021216031080087062, 0.015026503755107445,
    -0.57004183639588224, 1.0204157324502892, -0.817844078944054,
    -1.0429812969017489, -1.0195886437703527, -1.0121588925732463,
    0.83756331990518407, 0.99921735346199936, 0.0074542244425788934,
    -0.86540555702509148, 0.65010675891447367, -1.0017975688505452,
    1.041088557677605 };

  static const signed char b_iv[21] = { 10, 10, 23, 4, 17, 28, 1, 22, 29, 30, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv19[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv19[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void od_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { -19.75, 1.5, -13.5, 0.0, 0.0, 44.5,
    18.953000000000003, 0.0, 100.4, 158.078, 110.0, 0.0, 0.0, 156.625, 164.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, true, true, false,
    false, true, false, false, false, true, true, false, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10,
    11, 0, 0, 12, 13, 14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { 0.0010895533150408385, 0.79818448705985368,
    -0.0066811517156141692, 0.95724234475025782, -1.0024556670799483,
    -0.69765365061337759, 0.012533261105772469, 1.0091761121625242,
    -0.92966708577242074, 0.0025728119365455741, 1.0139019325756295,
    -0.99840314681255715, 1.003967054830941, 0.024819661047740006,
    -0.41437598334288672, 1.0157182796502298, -1.0000415678633743,
    0.012793272618875287, 0.949672667330437, -0.87393447310851891,
    0.46158870179058226 };

  static const signed char b_iv1[21] = { 27, 29, 27, 0, 0, 16, 26, 0, 24, 3, 7,
    0, 0, 3, 21, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void p_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 37.25, 21.125, 0.0, 104.25, 59.5,
    106.25, 18.25, 97.219, 86.0, 64.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, true, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.01066527214752021, -0.12779045216677837,
    0.14664154694624218, 1.3552414205168302, -0.15520675940474041,
    0.3930924896525223, -0.16815953669381464, -0.57675327861743941,
    -0.0019406970697670002, 0.77828353348486545, 0.079862652182626365,
    0.0056362581078766572, -1.2501514951883947, -0.321499742258805,
    -1.307624060412335, 0.26750221449648226, -0.29113768979055488,
    0.85010754870708383, -2.8579145892399191, -0.80681285298139893,
    0.48499425812318647 };

  static const signed char b_iv1[21] = { 20, 10, 2, 0, 15, 10, 1, 14, 11, 16, 10,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void pb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { -6.75, 76.0, 8.0159999999999982, 43.5, 0.0,
    2.9375, 24.125, 0.0, 8.0, 98.475, 97.35, 0.0, 0.0, 0.0, 0.0, 0.0, 44.75, 0.0,
    0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, true, false,
    false, true, false, false, false, true, true, true, true, true, false, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0036290162584128038, -0.43417520543873794,
    0.019471716606070243, -0.62500990163940862, 0.924802166175083,
    0.032883202912621277, -1.049289990374652, 0.94950997479441823,
    -0.78059517132018785, -0.032636592994543689, 0.313352705934525,
    -1.1670540983408115, 1.0121139219069659, -0.86875960294943988,
    0.68672019233330228, -0.15733612269409911, 0.15157831833873606,
    -0.18760139022334346, 0.48873412581158426, -0.82684637123111948,
    0.24977265010283345 };

  static const signed char b_iv1[21] = { 29, 22, 28, 4, 0, 28, 20, 0, 26, 24, 6,
    0, 0, 0, 0, 0, 16, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void pc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 46.9375, -8.5, 48.75, 4.5, 87.672, 99.75,
    51.9375, 0.0, 0.0, 0.0, 0.0, 0.0, 108.0, -2.5, -5.1875, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.00040957254163880366, -0.25526060785283433,
    0.031216281080819412, 0.79447695999979739, -0.38137037123695844,
    0.47182193093143837, -0.025440187749451802, 0.97531774351687139,
    -1.0088483622679323, 0.53593068381962561, -0.51159758946021727,
    0.6122177888705822, -0.2625384955065303, -0.44668778554291561,
    0.014900185422144337, -0.88836439144217283, 0.96942170025621577,
    -0.95708275670267517, 0.027059323084680741, -0.7766789213997044,
    0.038392624772170869 };

  static const signed char b_iv[21] = { 22, 27, 10, 29, 9, 5, 10, 0, 0, 0, 0, 0,
    9, 25, 30, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void pd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 180.125, 174.0, 57.125, 158.078, 110.5, 0.0,
    133.25, 152.4375, 78.5, 0.0, 0.0, 0.0, 0.0, 20.125, 64.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, false, false, true, true, true, true, false, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.000674063465548551, 0.0085775827823045,
    -0.73353781535910734, -0.00013777796979089194, 0.97644311536330786,
    1.0067916675787021, -0.96085187866305011, 0.015993224339432097,
    -0.53333069497812768, 0.99677988749915458, -1.0002873478723397,
    1.001431044174599, -1.0163223652001281, -0.001863638382786838,
    0.66400508387777457, -0.74023621544626161, 0.86717294622995367,
    -0.077859300784166363, 0.12590862609012476, -1.0081589726598814,
    0.78777672781922292 };

  static const signed char b_iv1[21] = { 9, 21, 4, 3, 1, 0, 3, 9, 16, 0, 0, 0, 0,
    20, 7, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void q_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 98.55, 98.5275, 170.0, 86.031, 89.75, 25.25,
    150.0, 94.25, 0.0, 0.0, 99.36, 98.85, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0072672168649025272, -0.10419164000283876,
    0.16129426387104495, 0.0025698950185898766, -1.2683436510191972,
    0.21473239081202816, -1.5478923054786395, 0.15031724665253837,
    -0.29633408548567874, -6.146797300365634, -1.1449956400323824,
    0.31699038046241024, -0.49655498244771734, 0.39326244995685933,
    -2.1828885641936706, 1.126407693895118, 0.031715128106241997,
    -1.5545254062706098, 0.041940375840322265, 0.87245346213184816,
    0.12857076778908119 };

  static const signed char b_iv[21] = { 6, 18, 21, 1, 3, 2, 9, 21, 0, 0, 18, 6,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv2[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv2[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void qb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 0.9375, 73.625, 102.25, 136.5, 96.55, 90.75,
    -1.1875, 17.75, 0.0, 0.0, 0.0, 0.0, 0.0, -4.75, 77.6875, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0043650768781736942, -0.10943728664838082,
    0.10409689099700835, -0.046455146445075063, -0.5918589422880004,
    0.4017521052895065, 0.013927594686102397, -0.12678281354428519,
    0.43561572735329196, 0.93655694671803913, -0.75274322775711788,
    0.65085522327135448, -0.035452259038523018, -0.18459653956114969,
    0.17625278149157744, 0.09245318048084275, -0.365233501125984,
    0.56976095503278568, -0.37307358908670474, -0.28250162289979658,
    0.45291052151804356 };

  static const signed char b_iv[21] = { 30, 4, 3, 21, 12, 1, 29, 20, 0, 0, 0, 0,
    0, 26, 7, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv1[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void qc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 100.3775, 100.07499999999999, 96.25,
    19.296999999999997, 108.5, 78.0, 148.5, 116.25, 0.0, 0.0, 100.1, 0.0, 0.0,
    48.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.002306621317502392, -0.026759012298387386,
    0.34273254330274, 0.0015105868001447159, -0.62951577873054176,
    -0.30165577569620394, 0.59203718580132636, 0.011512666637433333,
    -0.95779485898749994, -0.91360898562565418, 0.30241905410961595,
    -0.67733783652653778, 1.0193032498709267, 0.79332718951692638,
    -0.90940320005620434, 0.10192649370522308, -0.084241460991474171,
    -1.0428948170951187, 1.0188740153981013, -0.71364498555375278,
    0.91092561576900832 };

  static const signed char b_iv[21] = { 24, 6, 5, 25, 19, 22, 9, 15, 0, 0, 12, 0,
    0, 10, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv13[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv13[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void qd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 59.125, 2.4375, 93.875, -1.1639999999999997,
    99.4375, 88.5, 94.656, -0.875, -2.25, 0.0, 0.0, 0.0, 0.0, 90.5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.00019507751584836152, 0.090810786697160945,
    -0.086963772867213074, -0.00011457953834027916, 0.33636059227434684,
    -0.7291069299369537, -0.034612696729629917, -0.3609935291498797,
    0.12242950337207142, 0.55360171981126138, -0.16230921548666485,
    1.0058280992900321, -0.83474129614720716, 0.44962297163898984,
    -0.10468303085997717, 0.31896976700269797, -0.712348735883384,
    -0.49700948227947567, 0.24278725620980907, 0.839066386714792,
    -0.29927791335208054 };

  static const signed char b_iv[21] = { 10, 25, 17, 29, 5, 17, 17, 28, 27, 0, 0,
    0, 0, 7, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv12[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv12[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void r_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 57.5, 84.625, 59.5, 4.75, 0.0, 16.5, 93.5625,
    23.5, 0.0, 0.0, 0.0, 6.5, 17.4375, 0.0, 0.0, 0.0, 0.0, 97.001, 0.0, 0.0, 0.0
  };

  static const boolean_T b_bv[21] = { false, false, false, false, true, false,
    false, false, true, true, true, false, false, true, true, true, true, false,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0076424465340872829, -0.82969042236695456,
    0.0208278381422234, -1.0102673121765744, 1.6039123536450284,
    1.4063419576131788, -0.0011559377895249217, -1.226873199160174,
    1.1186030063235142, -1.0444099837979566, 1.6489876243517327,
    -0.40332794782511233, 0.042127271125935249, -1.2869988997980577,
    1.0857842421304513, -0.657189629013033, 0.68932313235948506,
    -0.13371222568932342, 0.17646232240956258, 0.40477206828215084,
    -0.30128217600585339 };

  static const signed char b_iv1[21] = { 7, 16, 7, 30, 0, 20, 11, 2, 0, 0, 0, 27,
    2, 0, 0, 0, 0, 24, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void rb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { -7.125, 95.25, -5.953, -5.25, 98.5, 6.5, 31.375,
    0.0, 0.0, 0.0, 55.5, 72.0, 0.0, 0.0, 84.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0024269474569912097, -0.61471283407374977,
    0.014840891505910007, 0.67564148753718667, -0.93933837125158093,
    0.66534863225499519, -0.0070239349119250814, -1.0166626242794083,
    1.0422275457486756, 1.0295615686140385, -1.0557420602992946,
    0.97539525955692841, -1.0782406318053095, 1.2335955909267522,
    -0.01580852788085213, 1.0131498888256363, -1.1207304574770269,
    1.1570709689993095, -0.90458744557620185, -0.76072713645019208,
    0.0001779192497376396 };

  static const signed char b_iv[21] = { 28, 5, 28, 25, 21, 29, 22, 0, 0, 0, 16,
    4, 0, 0, 21, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv17[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv17[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void rc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 131.3125, 128.125, 21.125, 127.75, 1.75, 20.969,
    64.8125, 0.0, 123.25, 0.0, 1.0, 0.0, 0.0, 0.0, 77.75, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, false, true, false, true, true, true, false, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0016643818677423876, -0.0515108241417194,
    0.14353455133971843, -0.00058435743857808311, -0.62605547368340031,
    0.31479438753117256, -0.23040719305308419, -0.055741682764586527,
    0.34980009205221335, -1.0077020273194786, 0.21969380460366655,
    0.13351185442478572, 1.0745973416927379, 0.34274820183523347,
    -0.63786212723659308, 0.71783604256218, -0.049000247871763006,
    0.97352006571881844, -0.86041176602697911, -0.97267814917557271,
    0.61529593683998907 };

  static const signed char b_iv1[21] = { 9, 9, 2, 21, 25, 2, 10, 0, 3, 0, 27, 0,
    0, 0, 4, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void rd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 40.539, 95.5, 45.781, -7.5, 31.0, 14.75,
    -1.1565000000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 59.0, -1.875, 10.25, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.00057247850402040437, -0.47785026716638124,
    0.01731225984622406, 0.8093908944423408, -0.66009362045037967,
    0.47376542557236812, -0.013690655633600356, -1.0012500387431473,
    0.99435087512635534, -0.81537358517674918, 1.002558609041919,
    -0.92667516679293627, 0.70879236830967307, -0.16721433639912206,
    0.071539324593186238, -0.86114698321305938, 0.79167115540829525,
    0.13896307303311392, -0.36293487167196076, 0.11546131961042899,
    -0.50699109743481319 };

  static const signed char b_iv[21] = { 4, 17, 4, 27, 2, 2, 26, 0, 0, 0, 0, 0,
    19, 29, 27, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void s_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.094, 13.125, 94.5, 115.0, 90.875, 94.25,
    23.1875, 11.0, 0.0, 0.0, 98.906, 54.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0062937676680186443, 0.072039926089186856,
    -0.24574722291760376, 0.62405413088488493, 0.020941283881286292,
    -0.48219196030787875, 0.15292867336298943, 1.3274901871433846,
    -0.15727397684883404, -1.4043904331617676, 0.056384866738680477,
    0.65713379165827479, -0.66846185976175321, 0.38545519793971561,
    -1.0751446817867905, -1.259474537445229, 1.6071270071957513,
    -0.023123517117880705, 0.62332947689189011, 0.077812639133039554,
    2.8644635091024244 };

  static const signed char b_iv[21] = { 5, 2, 19, 21, 17, 21, 8, 20, 0, 0, 5, 22,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv2[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv2[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void sb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 92.25, 87.5625, 14.0, 138.25, 25.5, 0.0, 7.0,
    130.75, 97.72, 97.55, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, false, false, false, true, false, true, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.00068676514097861332, 0.012298054970002779,
    -0.67247803856135679, -0.0080979001635835823, 1.0032719562136949,
    0.881213397353173, -1.0185080192547014, 0.040473850740564338,
    -0.24894840316807534, 1.1018896146408075, -1.0117031288540086,
    -1.0921121664964308, -0.030625845270627304, -0.014238347846609916,
    0.46165306242308352, 0.44013312988146136, -0.4726734309118954,
    -1.0062375352875557, 1.1228832732983, -1.0356339098468996,
    -1.239749056399855 };

  static const signed char b_iv1[21] = { 10, 10, 2, 3, 2, 0, 27, 3, 24, 6, 0, 26,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void sc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 91.25, 16.25, 20.125, 90.5, -6.5, 69.75, 66.5,
    0.0, 0.0, 0.0, 0.0, 21.5, 46.9375, 0.0, 79.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.001469549975007791, -0.48009702059610049,
    0.015493520468214547, 0.69586327598242415, -0.77819818919154327,
    -0.056314803338431807, 0.13670403064977876, 1.0215142365828112,
    -0.79575871849712487, 0.15686852582932517, -0.88022437311115043,
    -0.36442530074924662, 0.013291860734064105, 0.74647815394507488,
    0.081616693770010185, -0.46681780173312992, 1.0041851921287355,
    -0.64381415722359958, 0.06668978106868699, -0.30065078119448957,
    0.22230885614207871 };

  static const signed char b_iv[21] = { 23, 14, 20, 7, 26, 13, 13, 0, 0, 0, 0,
    14, 22, 0, 7, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv21[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv21[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void sd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 6.75, 98.399, 106.25, 98.22, 101.5, 49.5, 14.5,
    0.0, 0.0, 0.0, 111.875, 0.0, 0.0, 13.5, 124.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.0010283646588144773, -0.042961053968617179,
    0.22404567539054809, -0.13672629762056729, 0.10966932391700572,
    -0.24593574957402278, 0.39411527779348032, -0.059992740512435548,
    -0.81205694629664238, 0.61566097896361061, -0.0320292038028451,
    0.785610274256805, -0.59436771614884387, -0.19434628107713678,
    0.53796870753684412, -0.44715467163355743, 0.1221046789644884,
    0.75617409127922963, -0.95933962636364045, 0.86974065826085178,
    0.054335843517635721 };

  static const signed char b_iv[21] = { 27, 6, 21, 18, 9, 22, 14, 0, 0, 0, 9, 0,
    0, 14, 15, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv6[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv6[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void t_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 95.5625, 90.5, 100.3775, 93.25, 97.95, 100.55,
    18.75, 1.5, 15.25, 0.0, 73.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0078241595694515179, 0.21934023127134306,
    -0.08322185587633496, 0.44234954843503327, -0.22287822128829002,
    -0.13890503698305587, 0.44621063264707006, -0.10865368987419144,
    0.77204820289532849, -1.0178695100867587, 0.19503453329008305,
    -0.1060436470667777, -1.5374619553857396, 1.0371447688715851,
    -0.0046965231754453364, -0.47332484850812762, 1.0522811456101844,
    -0.63349947719991229, 1.1259802123908091, -0.30268190734634332,
    1.2083436105990086 };

  static const signed char b_iv[21] = { 17, 13, 24, 23, 18, 6, 2, 30, 14, 0, 16,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv5[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv5[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void tb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 14.9885, 106.875, 94.25, 12.125, -2.25, 89.5,
    13.75, 0.0, 0.0, 0.0, 65.5, 46.5, 0.0, 0.0, 87.25, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { 7.227837122272838E-5, -0.21949607478143557,
    0.04609871298461983, -0.75190874734259239, 0.030402090104539755,
    0.46424338182604752, -0.001946552483039735, -0.20558699960602891,
    -1.0529250340219036, -0.867956887159713, 0.17750024698580216,
    -0.072758090641699261, 0.94846206289190227, -0.83062573829133823,
    0.028674182725880112, 0.54502372246311492, -0.29598495741729525,
    1.0555889873134399, -0.4719538522071195, 0.16600647107416089,
    -0.20261555320662838 };

  static const signed char b_iv[21] = { 2, 9, 15, 2, 30, 7, 8, 0, 0, 0, 4, 10, 0,
    0, 7, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv17[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv17[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void tc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 97.001, 57.5, 97.18, 3.25, 93.625, 53.25, 97.15,
    0.0, 0.0, 0.0, 95.85, 97.25, 0.0, 0.0, 75.031, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.0019385408999304376, 0.19132245282584598,
    -0.053366081227039591, -1.0023029277281035, 0.25550999040062783,
    -0.59504628046167851, 0.0060631355281993366, -1.0378493490907488,
    1.0012571791951617, -0.84858428716479883, 0.32690576471937954,
    0.14751457651259781, -0.88300987893339844, -1.0526668380854407,
    0.028546331027661964, -0.59528518725529611, 0.40654227525627235,
    0.81347899892014686, -0.97470486310669358, 0.25681003466972485,
    -0.050088970986805738 };

  static const signed char b_iv[21] = { 24, 7, 12, 30, 17, 10, 24, 0, 0, 0, 12,
    18, 0, 0, 7, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv17[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv17[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void td_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 28.25, 96.705, 151.0, -4.125, 96.75, 50.0, 91.0,
    0.0, 98.45, 23.8905, 55.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { 0.00050581943407347824, 0.01699744637043446,
    -0.53390203895815191, 0.26659844720685755, -0.017252812003552085,
    -0.76031585027902016, 0.876002631523722, -1.0095640210190959,
    0.3797206055488147, -0.67684317624401524, 0.010414320413825531,
    0.535259391001591, -0.99215736622856054, 1.0058640782066215,
    -1.0003658070778203, 0.49298820950013877, -0.80189229785088745,
    -0.87386242913757928, 1.0081162114185669, -1.000270278202015,
    0.024238627152552938 };

  static const signed char b_iv[21] = { 2, 24, 3, 30, 18, 4, 1, 0, 12, 2, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv4[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv4[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void u_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 57.1875, -4.2815000000000012, 26.625, 69.0,
    16.9375, 23.125, -1.2654999999999994, 0.0, 0.0, 16.906, 44.75, 0.0, 80.5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, true, true, false, false, true, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0015644531431025115, 0.14966790148288533,
    -0.1033413844409603, -0.42728299204409864, 0.24526923274955226,
    -0.16039462644736865, 0.548411345803803, 0.72311635746361824,
    -0.93272967934809992, -0.23458347070496452, 0.42807992217742352,
    -0.090291583569317019, -0.88152300876056244, -1.2387991921032542,
    0.84491693174189308, -0.5495315524432951, 0.65789297249094025,
    -0.4438398708975429, 0.60841810663420048, 0.54378333676796076,
    -1.3799379936971798 };

  static const signed char b_iv1[21] = { 4, 27, 20, 19, 20, 14, 30, 0, 0, 14, 16,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ub_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 100.85, 68.25, 101.35, 2.4375, 95.5625, 6.5,
    0.875, 19.9295, 14.9885, 0.0, 107.375, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0026177763642795519, -0.026619090287460765,
    0.46825816348552063, -0.091743484581916987, 0.14233815573092903,
    0.74831092558128465, -0.41024570438112112, -0.19776232750375886,
    0.14763630226096761, 0.74086488750738133, -0.02012903704936302,
    0.91612732955144172, -0.9471198091665638, -1.0691982222771395,
    0.38320351015515358, -0.39481754654450757, 0.0508267110721887,
    -0.40632584404708327, 0.25921771414080591, 0.70961377201929088,
    -0.16212169562447806 };

  static const signed char b_iv[21] = { 24, 16, 12, 25, 17, 28, 30, 2, 2, 0, 9,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv5[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv5[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void uc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 57.1875, 54.4375, 63.6875, 7.625, 52.25,
    -7.8125, 64.3125, 0.0, 0.0, 0.0, 0.0, 0.0, 4.125, 74.0, 109.125, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.00769037524723861, 0.11323517300811914,
    -0.07856416692616254, 0.03207802683054737, 0.46343798431651928,
    -0.38186381087549848, 0.043485886510316048, -0.05818068282380344,
    0.5918186811579158, -0.26944422190297856, 0.65516282954267657,
    0.65800166817010775, -0.48887504398055731, 0.791845655877918,
    -0.043564836907571756, -0.705349939441291, 0.061004920844959738,
    -0.75423026128493709, 1.0113903323433195, 0.35159766266655329,
    -0.17608992870890647 };

  static const signed char b_iv[21] = { 4, 4, 4, 27, 10, 26, 4, 0, 0, 0, 0, 0,
    25, 1, 3, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void ud_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 141.5, 157.0, 17.75, 63.6875, 0.0, 4.0, -1.4375,
    60.25, 64.3125, 0.0, 0.0, 99.5, 101.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, true, false,
    false, false, false, true, true, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.0049143365093685691, -0.038910580809449632,
    0.24453216144919734, -0.025609527619114173, -0.89216108649500347,
    -0.25723169290878545, 0.453823891869293, -0.11091855378685823,
    0.096457558310137678, -0.817176692987678, 0.89428768882355447,
    -0.049818134564608242, 0.70999635969265906, 0.0017731221695552796,
    -0.43475948921559443, 0.81394879815924814, 0.0063982900250378087,
    0.3671663417255096, -0.652672156006561, -1.005794316363336,
    0.79408605725985137 };

  static const signed char b_iv1[21] = { 21, 15, 20, 4, 0, 25, 29, 10, 4, 0, 0,
    23, 15, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void v_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 65.75, -4.5, 11.625, 16.9375, 93.5, 97.625,
    12.375, 0.0, 0.0, 0.0, 93.0, 0.0, 0.0, -1.3125, 15.9375, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.005163574614600275, -0.37864935270364841,
    0.040167610215403243, 1.553729122324601, -0.59877803128849871,
    -1.125156556806898, 0.058447134588863518, -1.0322129103470947,
    1.8028603544272872, 1.2093637416215788, -0.79342951310790066,
    -1.1905177205390314, -1.0579746753807273, 0.87487042494276768,
    0.011436372624399567, 0.70287758940564926, -0.9563446841919504,
    -0.2918222363889269, 1.178593406659953, -0.44721429540954155,
    0.076716275675842147 };

  static const signed char b_iv[21] = { 19, 30, 20, 2, 5, 11, 20, 0, 0, 0, 17, 0,
    0, 29, 20, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv6[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv6[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void vb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 31.5, 141.5, 37.5, 157.0, 96.0625, 0.0, 90.75,
    19.296999999999997, 0.0, 97.65, 98.425000000000011, 0.0, 16.578000000000003,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { 0.00064029329810241353, 0.013230583751882125,
    -0.84885886996549353, -0.025361536112588769, 0.24226121666549461,
    0.651032872871609, -1.0286643014092374, -0.004809688528176031,
    -1.2090479264004221, 0.68034288401989562, -0.061589140804318224,
    1.0036902404939665, -1.0587185866523683, 0.00737395177149441,
    -1.0729267143647887, 0.031347137636459813, 0.93281959307859486,
    0.31501120930219906, -0.67030772877074885, -1.0640668564451083,
    -0.54699129141060254 };

  static const signed char b_iv[21] = { 8, 21, 22, 15, 5, 0, 23, 25, 0, 18, 18,
    0, 27, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv11[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv11[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void vc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 82.5, 83.5, 90.1875, 83.75, 90.5, 91.0,
    97.125, 0.0, 0.0, 0.0, 75.5, 92.3125, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.0012630499654102802, -0.076612774524779534,
    0.12278307325532462, -0.11099834691099278, 0.53373340121470214,
    0.17690903274841943, -0.45344270876626014, -0.025774017517110833,
    -0.39132002064312738, 0.80682051316965864, -0.67562926116027566,
    -0.035209471680424105, 0.36383190506412189, -0.7674106203523573,
    0.76908282568038844, 0.16564764391584152, -0.26715719304670993,
    0.32820349164954421, -0.35395265095307676, 0.701537574238261,
    0.062024938506691316 };

  static const signed char b_iv[21] = { 20, 16, 16, 1, 4, 19, 22, 11, 0, 0, 0, 7,
    1, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv22[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv22[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void vd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 130.875, 128.125, -1.25, 127.5, 25.5, 70.0,
    84.25, 127.5, 0.0, 0.0, 0.0, -0.125, 0.0, 21.125, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.00067372691466127774, -0.05234022469581974,
    0.16240237890911452, -0.018508000038039422, -0.79452858179417263,
    -0.31389477566873064, 0.30550334297702475, -0.04567029970096978,
    0.8731985905632017, -0.8965517753274066, 1.003207913706845,
    0.564595931721189, -0.60838366878536865, 0.37112110685153243,
    -0.55055097439303013, 0.00081448001749712692, -0.49709231942393606,
    0.96503864385829619, -1.0045851516366271, 0.51169025572838933,
    -0.028519558248975754 };

  static const signed char b_iv[21] = { 9, 9, 30, 9, 14, 7, 4, 3, 0, 0, 0, 28, 0,
    2, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void w_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 99.36, 99.25, 14.6875, 8.5, 78.5, 6.5, 57.5,
    0.0, 0.0, 103.5, 0.0, 0.0, 0.0, 112.185, 102.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const double dv1[21] = { -0.00637047721012755, -0.064186606313878666,
    0.24667173968456912, -0.011398433394237588, -0.66686553821208638,
    -0.64143167203530915, 0.40450172212821767, -0.032596211699914918,
    1.0687013378174666, -0.9440513366323483, 1.2010914785888345,
    -1.0748498754237286, 1.3661614328089231, -0.14826504448417258,
    0.69537912193863072, 0.45395781043187616, -1.2117999971336129,
    -0.6743304984333568, 0.532103491652433, 0.79602779266651857,
    -1.7167669180033545 };

  static const signed char b_iv[21] = { 18, 24, 14, 30, 22, 27, 22, 0, 0, 3, 0,
    0, 0, 21, 18, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv7[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv7[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void wb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 27.5, -7.125, 92.5, 101.5, -1.9375, 96.1, 0.0,
    96.75, 20.0, 96.9375, -0.030999999999999694, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0010736938236896834, -0.0091754130425292357,
    0.96945056349977854, -0.6904237239308425, 0.0039486812998568823,
    1.0258488492356623, -1.0042864112253855, -1.0112481492775061,
    0.23458085943076015, 0.16686163005513285, -0.062594179318660959,
    -1.0026487058917111, 1.0521705468873233, 1.0072368125517996,
    -1.0664477286104872, -1.025167912159423, 0.84845693556232293,
    -0.15752073917376888, 0.43122364792989171, -0.41085996717581491,
    0.035995128842178183 };

  static const signed char b_iv[21] = { 27, 28, 13, 19, 28, 6, 0, 3, 20, 11, 28,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv8[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv8[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void wc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 126.25, 128.4375, 2.8125, 76.625, 32.5, 74.875,
    83.5, 98.45, 0.0, 0.0, 0.0, 129.8905, -9.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { 0.0016142866225400908, -0.061712808842052116,
    0.14444272558294088, 0.0047084445728838359, -0.662776726585943,
    0.028552626949065598, 0.4207244605174989, 0.029650713760614733,
    -0.82906257367545244, 1.0280457794046765, -0.72585658445337531,
    -0.12622761475002484, 0.47693589051038565, 0.56464159682814818,
    -0.64555889495434815, -0.078559564968905593, 0.24231222041674755,
    0.48114701765788276, -0.30019594310934095, -0.7426406641605916,
    0.66383201200840014 };

  static const signed char b_iv[21] = { 21, 3, 25, 4, 22, 10, 22, 6, 0, 0, 0, 21,
    26, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv22[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv22[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void wd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 127.5, 21.125, 116.25, 18.25, 59.5,
    19.75, 94.875, 94.5, 0.0, 0.0, 44.3125, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, false,
    false, false, false, true, true, false, true, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.00060475936883758706, -0.081533907211072135,
    0.13912325793937014, -0.16422174031909861, 0.17532102274347902,
    0.30989019500989184, -0.090288512382359423, -0.054075778701982775,
    -0.51813420619555517, 0.3352884679807388, -0.26831541378239476,
    0.60263157936003309, 0.11878963420729022, -0.587887325578578,
    0.056250682813408164, -0.61910782610991777, 0.042858653242200395,
    0.40616592568306525, -0.71308362898819044, -0.45755733960853956,
    0.83381254528834992 };

  static const signed char b_iv1[21] = { 20, 15, 2, 15, 20, 10, 8, 11, 11, 0, 0,
    10, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void x_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 19.296999999999997, 57.1875, 25.125, 40.539,
    63.6875, 163.5, 0.0, 95.5, 39.5, 98.75, 64.3125, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0045650675567996749, 0.011908555973765752,
    -1.0469019420169441, 0.15312125671009205, -0.079709388524499519,
    -1.2813159131366711, 1.0788199190875929, -0.40938535606062182,
    0.23152465672449782, -0.35198051432026251, 0.028363434321225157,
    -1.3463559285857019, 1.0328680077169632, 0.86299018596560484,
    -0.69327439910901523, 1.2809086977239599, 0.18588525249379564,
    -0.71775732017538019, 0.17857121478782373, 1.4739786919349407,
    -0.10394465967533342 };

  static const signed char b_iv[21] = { 25, 4, 20, 4, 4, 15, 0, 17, 10, 17, 4, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv8[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv8[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void xb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 40.539, 95.5, 45.781, -7.5, -5.8125, 14.75,
    48.3125, 0.0, 0.0, 0.0, 0.0, 0.0, -1.25, 4.5, 28.25, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0014709275328346311, -0.45879469963885566,
    0.017883567555448534, 0.80706552534558407, -0.67400895083818935,
    0.51515030939422557, -0.013978275601491789, -1.0098813626722225,
    1.0057632357060449, 1.0646755310242144, -0.84099472967697286,
    -0.99471934222620806, 0.74511242340384842, -0.51720712340680175,
    0.026857937459630277, 0.14161078941802666, 0.97142812120590682,
    -0.70076880666924468, 0.87996224849039339, 0.050182106415500874,
    -0.69632576068510421 };

  static const signed char b_iv[21] = { 4, 17, 4, 27, 29, 2, 4, 0, 0, 0, 0, 0,
    29, 25, 2, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void xc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 0.9375, 55.25, 13.875, 96.25, 103.75, 0.0,
    115.5, 0.0, 50.125, 0.0, 15.25, 69.625, 117.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, false, false, true,
    false, true, false, true, false, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 0, 0, 14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { 3.7721524050087288E-6, -0.095454185227206625,
    0.094540314883360649, 0.15705240750620242, -0.26278259701169687,
    -1.0196371865527059, 0.12113825851790325, -1.0294371936421669,
    0.20626557778471308, -0.98272555389615568, -0.12679243431454187,
    0.283402289735837, -0.049601182843365774, -0.0914583336549937,
    0.46617121083221874, 0.3774310020997847, -0.24283033785077546,
    0.18872520961935532, 0.83667200156712263, -0.62907727287467541,
    0.12581050037536842 };

  static const signed char b_iv1[21] = { 30, 16, 20, 18, 15, 0, 15, 0, 16, 0, 14,
    10, 9, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void xd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 95.995, -5.75, 96.93, 0.0, 104.75, 90.3125,
    13.75, 0.0, 0.0, 62.75, 4.0, 13.125, -2.875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const double dv1[21] = { -0.0014255600701056966, -0.59994888952956582,
    0.013686704318289222, 0.99602137887011388, -0.7331251664463484,
    0.28219100119771329, -0.026172330734386313, 0.12516435079785987,
    -0.97437130211501932, 0.46694469258550414, -0.26868033433454874,
    -0.36390019425889913, 0.0087477162201772488, -0.43342384129302047,
    0.6403302535344142, -0.55143167185158581, 1.0035632457772985,
    0.062655529067607588, -0.92300467750514337, 0.25287268764103887,
    -0.055177588070569425 };

  static const signed char b_iv[21] = { 12, 26, 24, 0, 21, 1, 8, 0, 0, 7, 30, 2,
    28, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv14[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv14[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void y_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 95.995, 110.3985, 96.705, 96.050000000000011,
    154.0, 19.5, 96.75, 0.0, 0.0, 0.0, 0.0, 0.0, 21.5, 23.875, 96.55, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0027931973051233809, -0.66459659652032221,
    0.019477781367567629, -0.03582261791524656, -1.1793305531101208,
    0.50922733866047665, -0.040493008490703163, 0.80144657501467909,
    -1.16288010650969, -1.2484251175277643, 1.025414769488161,
    0.9114884008387093, -0.39386185434351778, -0.97152084038350439,
    0.010375033092639535, -1.2114835494427165, 0.46393923639111123,
    -1.2700242969214586, 0.64085085224622318, -4.17790976721223,
    0.022840182521455147 };

  static const signed char b_iv[21] = { 12, 9, 24, 24, 21, 14, 6, 0, 0, 0, 0, 0,
    20, 2, 18, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv9[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv9[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void yb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 20.125, 82.5, 21.125, 69.5, 96.5, 124.5, 92.25,
    0.0, 95.25, 0.0, 0.0, 0.0, 19.5, 19.75, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const double dv1[21] = { -0.0010718587597254936, -0.073822063043509953,
    0.11325445824516446, -0.11161279140039645, 0.56433414388302339,
    0.34039578858404629, -0.16811393046258286, -0.03892565291851674,
    -0.47272018950388611, 0.88143374707817124, -1.0909261088575242,
    0.55504167427855322, -0.04784045650455622, 0.041439152350378615,
    -0.72559753432520591, 0.56050836459878761, -0.71302399035773734,
    0.63954995560483274, -0.39930442864739729, -0.85673467866233766,
    0.24446872892126667 };

  static const signed char b_iv[21] = { 20, 16, 2, 22, 16, 15, 1, 0, 5, 0, 0, 0,
    8, 8, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv18[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv18[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void yc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 53.5, 22.0, -3.9689999999999994, 0.0, 0.0,
    -4.0020000000000007, -3.0625, 98.6, 99.5, 0.0, 114.25, 99.75, 99.5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T b_bv[21] = { false, false, false, true, true, false,
    false, false, false, true, false, false, false, true, true, true, true, true,
    true, true, true };

  static const signed char b_iv[42] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10,
    11, 12, 13, 14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0 };

  static const double dv1[21] = { -0.00489645429945405, -0.91800090663815415,
    0.0038656519818814085, -1.01192561509406, 1.0036135708376024,
    0.2269526726715666, -0.030402129414796916, 0.0016790990492102963,
    0.79018198195608058, -1.0218970612263751, -0.020302503993979218,
    -0.23661988772465747, 0.483914453685758, 0.9384529238485726,
    -0.83706528434177163, -0.0021099002178552408, -0.5238536375940408,
    -0.52452614715112023, 0.89450440848136115, 0.80820678814024727,
    -1.0272631885502661 };

  static const signed char b_iv1[21] = { 7, 8, 28, 0, 0, 28, 28, 6, 23, 0, 13,
    23, 23, 0, 0, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = b_bv[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv1[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = b_iv[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

void yd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21], double
  obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints[21],
  boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2])
{
  int i;
  static const double dv[21] = { 46.9375, -0.5, 84.75, 113.5, 7.375, 34.5,
    52.375, 0.0, 0.0, 131.0, 0.0, 0.0, 0.0, -4.5, 53.75, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const double dv1[21] = { -0.0027626491174758262, -0.28200322671695921,
    0.027253671503414834, 0.28524302726054385, -0.518150200204572,
    -0.93073427853927038, 0.040945751122973245, 0.55117275695493573,
    -0.56509993616953025, -0.6767361786097712, 0.4725597853229615,
    -1.0043506262800392, 1.0014457325256234, 0.30875677655115569,
    -0.0070973802546017142, -0.85667620855383875, 0.23863251285727055,
    -0.905831569574297, 0.47072939085789073, -0.32993882889709186,
    0.059308177506405525 };

  static const signed char b_iv[21] = { 22, 27, 21, 3, 27, 20, 22, 0, 0, 9, 0, 0,
    0, 25, 10, 0, 0, 0, 0, 0, 0 };

  *obj_ResponseTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPoint[i] = dv[i];
    obj_NanCutPoints[i] = bv7[i];
    obj_NodeMean[i] = dv1[i];
    obj_CutPredictorIndex[i] = b_iv[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = iv7[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_ClassNames[0] = 1.0;
  obj_ClassNames[1] = 2.0;
}

/* End of code generation (CompactRegressionTree.cpp) */
