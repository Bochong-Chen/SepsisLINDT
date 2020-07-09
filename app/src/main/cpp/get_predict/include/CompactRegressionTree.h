/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactRegressionTree.h
 *
 * Code generation for function 'CompactRegressionTree'
 *
 */

#ifndef COMPACTREGRESSIONTREE_H
#define COMPACTREGRESSIONTREE_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "get_predict_types.h"

/* Function Declarations */
extern double CompactRegressionTree_predict(const double obj_CutPredictorIndex
  [21], const double obj_Children[42], const double obj_CutPoint[21], const
  boolean_T obj_NanCutPoints[21], const double obj_NodeMean[21], const double X
  [42]);
extern void ab_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ac_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ad_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ae_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void bb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void bc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void bd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void be_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void c_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void cb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void cc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void cd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void d_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void db_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void dc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void dd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void e_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void eb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ec_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ed_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void f_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void fb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void fc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void fd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void g_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void gb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void gc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void gd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void h_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void hb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void hc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void hd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void i_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ib_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ic_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void id_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void j_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void jb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void jc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void jd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void k_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void kb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void kc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void kd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void l_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void lb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void lc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ld_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void m_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void mb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void mc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void md_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void n_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void nb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void nc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void nd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void o_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ob_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void oc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void od_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void p_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void pb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void pc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void pd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void q_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void qb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void qc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void qd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void r_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void rb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void rc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void rd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void s_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void sb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void sc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void sd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void t_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void tb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void tc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void td_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void u_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ub_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void uc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void ud_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void v_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void vb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void vc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void vd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void w_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void wb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void wc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void wd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void x_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void xb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void xc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void xd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void y_CompactRegressionTree_Compact(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void yb_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void yc_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);
extern void yd_CompactRegressionTree_Compac(double obj_CutPredictorIndex[21],
  double obj_Children[42], double obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], c_classreg_learning_coderutils_
  *obj_ResponseTransform, double obj_NodeMean[21], double obj_ClassNames[2]);

#endif

/* End of code generation (CompactRegressionTree.h) */
