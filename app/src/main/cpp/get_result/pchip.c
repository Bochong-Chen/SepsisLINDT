/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pchip.c
 *
 * Code generation for function 'pchip'
 *
 */

/* Include files */
#include "pchip.h"
#include "get_result.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double exteriorSlope(double d1, double d2, double h1, double h2);

/* Function Definitions */
static double exteriorSlope(double d1, double d2, double h1, double h2)
{
  double s;
  double signd1;
  double signs;
  s = ((2.0 * h1 + h2) * d1 - h1 * d2) / (h1 + h2);
  signd1 = d1;
  if (d1 < 0.0) {
    signd1 = -1.0;
  } else if (d1 > 0.0) {
    signd1 = 1.0;
  } else {
    if (d1 == 0.0) {
      signd1 = 0.0;
    }
  }

  signs = s;
  if (s < 0.0) {
    signs = -1.0;
  } else if (s > 0.0) {
    signs = 1.0;
  } else {
    if (s == 0.0) {
      signs = 0.0;
    }
  }

  if (signs != signd1) {
    s = 0.0;
  } else {
    signs = d2;
    if (d2 < 0.0) {
      signs = -1.0;
    } else if (d2 > 0.0) {
      signs = 1.0;
    } else {
      if (d2 == 0.0) {
        signs = 0.0;
      }
    }

    if ((signd1 != signs) && (fabs(s) > fabs(3.0 * d1))) {
      s = 3.0 * d1;
    }
  }

  return s;
}

void pchip(const double x_data[], const int x_size[1], const double y_data[],
           const int y_size[2], double v_breaks_data[], int v_breaks_size[2],
           double v_coefs_data[], int v_coefs_size[2])
{
  int nxm1;
  int cpage;
  int slopes_size_idx_1;
  double d;
  double h_data[999];
  int nxm2;
  double slopes_data[1000];
  double del_data[999];
  double hs;
  double hs3;
  double w1;
  nxm1 = x_size[0] - 2;
  for (cpage = 0; cpage <= nxm1; cpage++) {
    d = x_data[cpage + 1] - x_data[cpage];
    h_data[cpage] = d;
    del_data[cpage] = (y_data[cpage + 1] - y_data[cpage]) / d;
  }

  slopes_size_idx_1 = (short)y_size[1];
  if (x_size[0] == 2) {
    slopes_data[0] = del_data[0];
    slopes_data[1] = del_data[0];
  } else {
    nxm2 = x_size[0];
    for (cpage = 0; cpage <= nxm2 - 3; cpage++) {
      d = h_data[cpage + 1];
      hs = h_data[cpage] + d;
      hs3 = 3.0 * hs;
      w1 = (h_data[cpage] + hs) / hs3;
      hs = (d + hs) / hs3;
      slopes_data[cpage + 1] = 0.0;
      if (del_data[cpage] < 0.0) {
        d = del_data[cpage + 1];
        if (d <= del_data[cpage]) {
          slopes_data[cpage + 1] = del_data[cpage] / (w1 * (del_data[cpage] / d)
            + hs);
        } else {
          if (d < 0.0) {
            slopes_data[cpage + 1] = d / (w1 + hs * (d / del_data[cpage]));
          }
        }
      } else {
        if (del_data[cpage] > 0.0) {
          d = del_data[cpage + 1];
          if (d >= del_data[cpage]) {
            slopes_data[cpage + 1] = del_data[cpage] / (w1 * (del_data[cpage] /
              del_data[cpage + 1]) + hs);
          } else {
            if (d > 0.0) {
              slopes_data[cpage + 1] = del_data[cpage + 1] / (w1 + hs *
                (del_data[cpage + 1] / del_data[cpage]));
            }
          }
        }
      }
    }

    slopes_data[0] = exteriorSlope(del_data[0], del_data[1], h_data[0], h_data[1]);
    slopes_data[x_size[0] - 1] = exteriorSlope(del_data[x_size[0] - 2],
      del_data[x_size[0] - 3], h_data[x_size[0] - 2], h_data[x_size[0] - 3]);
  }

  nxm1 = x_size[0];
  v_breaks_size[0] = 1;
  v_breaks_size[1] = x_size[0];
  nxm2 = x_size[0];
  if (0 <= nxm2 - 1) {
    memcpy(&v_breaks_data[0], &x_data[0], nxm2 * sizeof(double));
  }

  cpage = slopes_size_idx_1 - 1;
  v_coefs_size[0] = slopes_size_idx_1 - 1;
  v_coefs_size[1] = 4;
  for (nxm2 = 0; nxm2 <= nxm1 - 2; nxm2++) {
    hs = (del_data[nxm2] - slopes_data[nxm2]) / h_data[nxm2];
    hs3 = (slopes_data[nxm2 + 1] - del_data[nxm2]) / h_data[nxm2];
    v_coefs_data[nxm2] = (hs3 - hs) / h_data[nxm2];
    v_coefs_data[cpage + nxm2] = 2.0 * hs - hs3;
    v_coefs_data[(cpage << 1) + nxm2] = slopes_data[nxm2];
    v_coefs_data[3 * cpage + nxm2] = y_data[nxm2];
  }
}

/* End of code generation (pchip.c) */
