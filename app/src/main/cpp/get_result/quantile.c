/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quantile.c
 *
 * Code generation for function 'quantile'
 *
 */

/* Include files */
#include "quantile.h"
#include "derive_hr.h"
#include "get_result.h"
#include "get_result_emxutil.h"
#include "get_result_rtwutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double quantile(const emxArray_real_T *x)
{
  double y;
  emxArray_int32_T *idx;
  int n;
  int i;
  int nj;
  emxArray_int32_T *iwork;
  int b_i;
  int i2;
  int j;
  int pEnd;
  int p;
  double r;
  int q;
  int qEnd;
  int kEnd;
  if (x->size[0] == 0) {
    y = rtNaN;
  } else {
    emxInit_int32_T(&idx, 1);
    n = x->size[0] + 1;
    i = idx->size[0];
    idx->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(idx, i);
    nj = x->size[0];
    for (i = 0; i < nj; i++) {
      idx->data[i] = 0;
    }

    emxInit_int32_T(&iwork, 1);
    i = iwork->size[0];
    iwork->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(iwork, i);
    i = x->size[0] - 1;
    for (nj = 1; nj <= i; nj += 2) {
      if ((x->data[nj - 1] <= x->data[nj]) || rtIsNaN(x->data[nj])) {
        idx->data[nj - 1] = nj;
        idx->data[nj] = nj + 1;
      } else {
        idx->data[nj - 1] = nj + 1;
        idx->data[nj] = nj;
      }
    }

    if ((x->size[0] & 1) != 0) {
      idx->data[x->size[0] - 1] = x->size[0];
    }

    b_i = 2;
    while (b_i < n - 1) {
      i2 = b_i << 1;
      j = 1;
      for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        nj = 0;
        kEnd = qEnd - j;
        while (nj + 1 <= kEnd) {
          r = x->data[idx->data[q] - 1];
          i = idx->data[p - 1];
          if ((x->data[i - 1] <= r) || rtIsNaN(r)) {
            iwork->data[nj] = i;
            p++;
            if (p == pEnd) {
              while (q + 1 < qEnd) {
                nj++;
                iwork->data[nj] = idx->data[q];
                q++;
              }
            }
          } else {
            iwork->data[nj] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < pEnd) {
                nj++;
                iwork->data[nj] = idx->data[p - 1];
                p++;
              }
            }
          }

          nj++;
        }

        for (nj = 0; nj < kEnd; nj++) {
          idx->data[(j + nj) - 1] = iwork->data[nj];
        }

        j = qEnd;
      }

      b_i = i2;
    }

    emxFree_int32_T(&iwork);
    nj = x->size[0];
    while ((nj > 0) && rtIsNaN(x->data[idx->data[nj - 1] - 1])) {
      nj--;
    }

    if (nj < 1) {
      y = rtNaN;
    } else if (nj == 1) {
      y = x->data[idx->data[0] - 1];
    } else {
      r = 0.1 * (double)nj;
      b_i = (int)rt_roundd_snf(r);
      if (b_i < 1) {
        y = x->data[idx->data[0] - 1];
      } else if (b_i >= nj) {
        y = x->data[idx->data[nj - 1] - 1];
      } else {
        r -= (double)b_i;
        y = (0.5 - r) * x->data[idx->data[b_i - 1] - 1] + (r + 0.5) * x->
          data[idx->data[b_i] - 1];
      }
    }

    emxFree_int32_T(&idx);
  }

  return y;
}

/* End of code generation (quantile.c) */
