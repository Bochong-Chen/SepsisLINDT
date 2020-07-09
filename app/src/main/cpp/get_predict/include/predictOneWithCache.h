/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictOneWithCache.h
 *
 * Code generation for function 'predictOneWithCache'
 *
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "get_predict_types.h"

/* Function Declarations */
extern void predictOneWithCache(const double X[42], double cachedScore[2],
  double *cachedWeights, const double weak_learner_CutPredictorIndex[21], const
  double weak_learner_Children[42], const double weak_learner_CutPoint[21],
  const boolean_T weak_learner_NanCutPoints[21], const double
  weak_learner_NodeMean[21], const double weak_learner_ClassNames[2], boolean_T *
  cached, const double classnames[2], boolean_T initCache, double score[2]);

#endif

/* End of code generation (predictOneWithCache.h) */
