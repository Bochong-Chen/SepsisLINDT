/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "interp1.h"
#include "get_result.h"
#include "get_result_emxutil.h"
#include "pchip.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T_1x1000
#define struct_emxArray_real_T_1x1000

struct emxArray_real_T_1x1000
{
  double data[1000];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1x1000*/

#ifndef typedef_emxArray_real_T_1x1000
#define typedef_emxArray_real_T_1x1000

typedef struct emxArray_real_T_1x1000 emxArray_real_T_1x1000;

#endif                                 /*typedef_emxArray_real_T_1x1000*/

#ifndef struct_emxArray_real_T_999x4
#define struct_emxArray_real_T_999x4

struct emxArray_real_T_999x4
{
  double data[3996];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_999x4*/

#ifndef typedef_emxArray_real_T_999x4
#define typedef_emxArray_real_T_999x4

typedef struct emxArray_real_T_999x4 emxArray_real_T_999x4;

#endif                                 /*typedef_emxArray_real_T_999x4*/

#ifndef struct_sCUhM3ZCmeCTI2KuMi0zZSH_tag
#define struct_sCUhM3ZCmeCTI2KuMi0zZSH_tag

struct sCUhM3ZCmeCTI2KuMi0zZSH_tag
{
  emxArray_real_T_1x1000 breaks;
  emxArray_real_T_999x4 coefs;
};

#endif                                 /*struct_sCUhM3ZCmeCTI2KuMi0zZSH_tag*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct sCUhM3ZCmeCTI2KuMi0zZSH_tag struct_T;

#endif                                 /*typedef_struct_T*/

/* Function Declarations */
static void interp1SplineOrPCHIP(const double y_data[], const int y_size[1],
  const emxArray_real_T *xi, emxArray_real_T *yi, const double x_data[], const
  int x_size[1]);

/* Function Definitions */
static void interp1SplineOrPCHIP(const double y_data[], const int y_size[1],
  const emxArray_real_T *xi, emxArray_real_T *yi, const double x_data[], const
  int x_size[1])
{
  int b_y_size[2];
  int loop_ub;
  double b_y_data[1000];
  struct_T pp;
  int k;
  int high_i;
  double xloc;
  int low_i;
  int low_ip1;
  int mid_i;
  b_y_size[0] = 1;
  b_y_size[1] = y_size[0];
  loop_ub = y_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&b_y_data[0], &y_data[0], loop_ub * sizeof(double));
  }

  pchip(x_data, x_size, b_y_data, b_y_size, pp.breaks.data, pp.breaks.size,
        pp.coefs.data, pp.coefs.size);
  loop_ub = xi->size[0] - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(high_i,xloc,low_i,low_ip1,mid_i)

  for (k = 0; k <= loop_ub; k++) {
    if (rtIsNaN(xi->data[k])) {
      yi->data[k] = rtNaN;
    } else {
      if (rtIsNaN(xi->data[k])) {
        xloc = xi->data[k];
      } else {
        high_i = pp.breaks.size[1];
        low_i = 1;
        low_ip1 = 2;
        while (high_i > low_ip1) {
          mid_i = (low_i >> 1) + (high_i >> 1);
          if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }

          if (xi->data[k] >= pp.breaks.data[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        xloc = xi->data[k] - pp.breaks.data[low_i - 1];
        xloc = xloc * (xloc * (xloc * pp.coefs.data[low_i - 1] + pp.coefs.data
          [(low_i + pp.breaks.size[1]) - 2]) + pp.coefs.data[(low_i + 2 *
          (pp.breaks.size[1] - 1)) - 1]) + pp.coefs.data[(low_i + 3 *
          (pp.breaks.size[1] - 1)) - 1];
      }

      yi->data[k] = xloc;
    }
  }
}

void interp1(const double varargin_1_data[], const int varargin_1_size[1], const
             double varargin_2_data[], const int varargin_2_size[1], const
             emxArray_real_T *varargin_3, emxArray_real_T *Vq)
{
  int y_size[1];
  int n;
  double y_data[1000];
  int x_size[1];
  double x_data[1000];
  int nx;
  int y_tmp;
  int k;
  int exitg1;
  double xtmp;
  int nd2;
  y_size[0] = varargin_2_size[0];
  n = varargin_2_size[0];
  if (0 <= n - 1) {
    memcpy(&y_data[0], &varargin_2_data[0], n * sizeof(double));
  }

  x_size[0] = varargin_1_size[0];
  n = varargin_1_size[0];
  if (0 <= n - 1) {
    memcpy(&x_data[0], &varargin_1_data[0], n * sizeof(double));
  }

  nx = varargin_1_size[0] - 1;
  y_tmp = Vq->size[0];
  Vq->size[0] = varargin_3->size[0];
  emxEnsureCapacity_real_T(Vq, y_tmp);
  n = varargin_3->size[0];
  for (y_tmp = 0; y_tmp < n; y_tmp++) {
    Vq->data[y_tmp] = 0.0;
  }

  if (varargin_3->size[0] != 0) {
    k = 0;
    do {
      exitg1 = 0;
      if (k <= nx) {
        if (rtIsNaN(varargin_1_data[k])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        if (varargin_1_data[1] < varargin_1_data[0]) {
          y_tmp = (nx + 1) >> 1;
          for (n = 0; n < y_tmp; n++) {
            xtmp = x_data[n];
            nd2 = nx - n;
            x_data[n] = x_data[nd2];
            x_data[nd2] = xtmp;
          }

          if ((varargin_2_size[0] != 0) && (varargin_2_size[0] > 1)) {
            n = varargin_2_size[0] - 1;
            nd2 = varargin_2_size[0] >> 1;
            for (k = 0; k < nd2; k++) {
              xtmp = y_data[k];
              y_tmp = n - k;
              y_data[k] = y_data[y_tmp];
              y_data[y_tmp] = xtmp;
            }
          }
        }

        interp1SplineOrPCHIP(y_data, y_size, varargin_3, Vq, x_data, x_size);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (interp1.c) */
