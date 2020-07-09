/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactEnsemble.h
 *
 * Code generation for function 'CompactEnsemble'
 *
 */

#ifndef COMPACTENSEMBLE_H
#define COMPACTENSEMBLE_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "get_predict_types.h"

/* Function Declarations */
extern void CompactEnsemble_ensemblePredict(const boolean_T obj_IsCached[100],
  const double X[42], const double classnames[2], double score[2]);

#endif

/* End of code generation (CompactEnsemble.h) */
