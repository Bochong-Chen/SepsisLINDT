/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactEnsemble.cpp
 *
 * Code generation for function 'CompactEnsemble'
 *
 */

/* Include files */
#include "CompactEnsemble.h"
#include "CompactRegressionTree.h"
#include "get_predict.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void CompactEnsemble_ensemblePredict(const boolean_T obj_IsCached[100], const
  double X[42], const double classnames[2], double score[2])
{
  double t0_CutPredictorIndex[21];
  double t0_Children[42];
  double t0_CutPoint[21];
  boolean_T t0_NanCutPoints[21];
  boolean_T expl_temp[21];
  c_classreg_learning_coderutils_ b_expl_temp;
  double t0_NodeMean[21];
  double t0_ClassNames[2];
  double cachedScore[2];
  double cachedWeights;
  boolean_T b;
  double unusedExpr[2];
  c_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  cachedScore[0] = 0.0;
  cachedScore[1] = 0.0;
  cachedWeights = 0.0;
  b = false;
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, true, unusedExpr);
  d_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[1];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  e_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[2];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  f_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[3];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  g_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[4];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  h_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[5];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  i_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[6];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  j_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[7];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  k_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[8];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  l_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[9];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  m_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[10];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  n_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[11];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  o_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[12];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  p_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[13];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  q_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[14];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  r_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[15];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  s_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[16];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  t_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[17];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  u_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[18];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  v_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[19];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  w_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[20];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  x_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[21];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  y_CompactRegressionTree_Compact(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[22];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ab_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[23];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  bb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[24];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  cb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[25];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  db_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[26];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  eb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[27];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  fb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[28];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  gb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[29];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  hb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[30];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ib_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[31];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  jb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[32];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  kb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[33];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  lb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[34];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  mb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[35];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  nb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[36];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ob_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[37];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  pb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[38];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  qb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[39];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  rb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[40];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  sb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[41];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  tb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[42];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ub_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[43];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  vb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[44];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  wb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[45];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  xb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[46];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  yb_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[47];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ac_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[48];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  bc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[49];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  cc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[50];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  dc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[51];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ec_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[52];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  fc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[53];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  gc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[54];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  hc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[55];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ic_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[56];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  jc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[57];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  kc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[58];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  lc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[59];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  mc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[60];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  nc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[61];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  oc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[62];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  pc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[63];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  qc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[64];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  rc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[65];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  sc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[66];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  tc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[67];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  uc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[68];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  vc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[69];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  wc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[70];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  xc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[71];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  yc_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[72];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ad_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[73];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  bd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[74];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  cd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[75];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  dd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[76];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ed_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[77];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  fd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[78];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  gd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[79];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  hd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[80];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  id_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[81];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  jd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[82];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  kd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[83];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ld_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[84];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  md_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[85];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  nd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[86];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  od_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[87];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  pd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[88];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  qd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[89];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  rd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[90];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  sd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[91];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  td_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[92];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ud_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[93];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  vd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[94];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  wd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[95];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  xd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[96];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  yd_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[97];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  ae_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[98];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, unusedExpr);
  be_CompactRegressionTree_Compac(t0_CutPredictorIndex, t0_Children, t0_CutPoint,
    t0_NanCutPoints, expl_temp, &b_expl_temp, t0_NodeMean, t0_ClassNames);
  b = obj_IsCached[99];
  predictOneWithCache(X, cachedScore, &cachedWeights, t0_CutPredictorIndex,
                      t0_Children, t0_CutPoint, t0_NanCutPoints, t0_NodeMean,
                      t0_ClassNames, &b, classnames, false, score);
}

/* End of code generation (CompactEnsemble.cpp) */
