/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictOneWithCache.cpp
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

/* Include files */
#include "predictOneWithCache.h"
#include "CompactRegressionTree.h"
#include "get_predict.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <math.h>

/* Function Definitions */
void predictOneWithCache(const double X[42], double cachedScore[2], double
  *cachedWeights, const double weak_learner_CutPredictorIndex[21], const double
  weak_learner_Children[42], const double weak_learner_CutPoint[21], const
  boolean_T weak_learner_NanCutPoints[21], const double weak_learner_NodeMean[21],
  const double weak_learner_ClassNames[2], boolean_T *cached, const double
  classnames[2], boolean_T initCache, double score[2])
{
  double learnerscore[2];
  int iloc_idx_0;
  int i;
  boolean_T exitg1;
  int iloc_idx_1;
  double absx;
  int exponent;
  boolean_T tf[2];
  boolean_T y;
  learnerscore[0] = rtNaN;
  learnerscore[1] = rtNaN;
  iloc_idx_0 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    absx = std::abs(classnames[i] / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = std::ldexp(1.0, exponent - 53);
    }

    if (std::abs(classnames[i] - weak_learner_ClassNames[0]) < absx) {
      iloc_idx_0 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  iloc_idx_1 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    absx = std::abs(classnames[i] / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = std::ldexp(1.0, exponent - 53);
    }

    if (std::abs(classnames[i] - weak_learner_ClassNames[1]) < absx) {
      iloc_idx_1 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  absx = CompactRegressionTree_predict(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_NodeMean, X);
  learnerscore[iloc_idx_0 - 1] = absx;
  learnerscore[iloc_idx_1 - 1] = -absx;
  if (initCache) {
    cachedScore[0] = 0.0;
    cachedScore[1] = 0.0;
  } else {
    tf[0] = rtIsNaN(cachedScore[0]);
    tf[1] = rtIsNaN(cachedScore[1]);
    y = false;
    iloc_idx_0 = 0;
    exitg1 = false;
    while ((!exitg1) && (iloc_idx_0 < 2)) {
      if (tf[iloc_idx_0]) {
        y = true;
        exitg1 = true;
      } else {
        iloc_idx_0++;
      }
    }

    if (y) {
      if (tf[0]) {
        cachedScore[0] = 0.0;
      }

      if (tf[1]) {
        cachedScore[1] = 0.0;
      }
    }
  }

  if (!*cached) {
    *cached = true;
    cachedScore[0] += learnerscore[0] * 0.5;
    cachedScore[1] += learnerscore[1] * 0.5;
    *cachedWeights += 0.5;
  }

  score[0] = cachedScore[0];
  score[1] = cachedScore[1];
}

/* End of code generation (predictOneWithCache.cpp) */
