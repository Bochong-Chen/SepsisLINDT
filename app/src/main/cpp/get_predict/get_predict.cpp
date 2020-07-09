/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_predict.cpp
 *
 * Code generation for function 'get_predict'
 *
 */

/* Include files */
#include "get_predict.h"
#include "CompactEnsemble.h"
#include "get_predict_data.h"
#include "get_predict_initialize.h"
#include "rt_nonfinite.h"
#include <cstring>

/* Function Definitions */
double get_predict(const double testdata[42])
{
  double result;
  boolean_T mdl_IsCached[100];
  double dv[2];
  double score[2];
  boolean_T b[2];
  boolean_T notNaN;
  int k;
  boolean_T exitg1;
  double classnum;
  if (isInitialized_get_predict == false) {
    get_predict_initialize();
  }

  std::memset(&mdl_IsCached[0], 0, 100U * sizeof(boolean_T));
  dv[0] = 1.0;
  dv[1] = 2.0;
  CompactEnsemble_ensemblePredict(mdl_IsCached, testdata, dv, score);
  b[0] = rtIsNaN(score[0]);
  b[1] = rtIsNaN(score[1]);
  notNaN = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!b[k]) {
      notNaN = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  notNaN = !notNaN;
  classnum = rtNaN;
  if (notNaN) {
    if ((score[0] < score[1]) || (rtIsNaN(score[0]) && (!rtIsNaN(score[1])))) {
      k = 2;
    } else {
      k = 1;
    }

    classnum = k;
  }

  result = 2.0;
  if (notNaN) {
    if (classnum < 4.294967296E+9) {
      k = static_cast<int>(classnum);
    } else {
      k = 0;
    }

    result = (static_cast<double>(k) - 1.0) + 1.0;
  }

  return result;
}

/* End of code generation (get_predict.cpp) */
