/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "get_result.h"
#include "get_result_emxutil.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y);
static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y);

/* Function Definitions */
static void dobluesteinfft(const emxArray_real_T *x, int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y)
{
  emxArray_creal_T *wwc;
  int nInt2m1;
  int ju;
  int idx;
  int rt;
  int nInt2;
  int ihi;
  double nt_im;
  double nt_re;
  int nt_re_tmp;
  emxArray_creal_T *fy;
  int nRowsD2;
  int nRowsD4;
  int i;
  boolean_T tst;
  double twid_re;
  double twid_im;
  emxArray_creal_T *fv;
  emxInit_creal_T(&wwc, 1);
  nInt2m1 = (n1 + n1) - 1;
  ju = wwc->size[0];
  wwc->size[0] = nInt2m1;
  emxEnsureCapacity_creal_T(wwc, ju);
  idx = n1;
  rt = 0;
  wwc->data[n1 - 1].re = 1.0;
  wwc->data[n1 - 1].im = 0.0;
  nInt2 = n1 << 1;
  for (ihi = 0; ihi <= n1 - 2; ihi++) {
    ju = ((ihi + 1) << 1) - 1;
    if (nInt2 - rt <= ju) {
      rt += ju - nInt2;
    } else {
      rt += ju;
    }

    nt_im = -3.1415926535897931 * (double)rt / (double)n1;
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = cos(nt_im);
      nt_im = sin(nt_im);
    }

    wwc->data[idx - 2].re = nt_re;
    wwc->data[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  ju = nInt2m1 - 1;
  for (ihi = ju; ihi >= n1; ihi--) {
    wwc->data[ihi] = wwc->data[idx];
    idx++;
  }

  nInt2 = x->size[0];
  if (n1 < nInt2) {
    nInt2 = n1;
  }

  ju = y->size[0];
  y->size[0] = n1;
  emxEnsureCapacity_creal_T(y, ju);
  if (n1 > x->size[0]) {
    ju = y->size[0];
    y->size[0] = n1;
    emxEnsureCapacity_creal_T(y, ju);
    for (ju = 0; ju < n1; ju++) {
      y->data[ju].re = 0.0;
      y->data[ju].im = 0.0;
    }
  }

  rt = 0;
  for (ihi = 0; ihi < nInt2; ihi++) {
    nt_re_tmp = (n1 + ihi) - 1;
    y->data[ihi].re = wwc->data[nt_re_tmp].re * x->data[rt];
    y->data[ihi].im = wwc->data[nt_re_tmp].im * -x->data[rt];
    rt++;
  }

  ju = nInt2 + 1;
  for (ihi = ju; ihi <= n1; ihi++) {
    y->data[ihi - 1].re = 0.0;
    y->data[ihi - 1].im = 0.0;
  }

  emxInit_creal_T(&fy, 1);
  nInt2m1 = y->size[0];
  if (nInt2m1 >= N2) {
    nInt2m1 = N2;
  }

  idx = N2 - 2;
  nRowsD2 = N2 / 2;
  nRowsD4 = nRowsD2 / 2;
  ju = fy->size[0];
  fy->size[0] = N2;
  emxEnsureCapacity_creal_T(fy, ju);
  if (N2 > y->size[0]) {
    ju = fy->size[0];
    fy->size[0] = N2;
    emxEnsureCapacity_creal_T(fy, ju);
    for (ju = 0; ju < N2; ju++) {
      fy->data[ju].re = 0.0;
      fy->data[ju].im = 0.0;
    }
  }

  nInt2 = 0;
  ju = 0;
  rt = 0;
  for (i = 0; i <= nInt2m1 - 2; i++) {
    fy->data[rt] = y->data[nInt2];
    rt = N2;
    tst = true;
    while (tst) {
      rt >>= 1;
      ju ^= rt;
      tst = ((ju & rt) == 0);
    }

    rt = ju;
    nInt2++;
  }

  fy->data[rt] = y->data[nInt2];
  if (N2 > 1) {
    for (i = 0; i <= idx; i += 2) {
      nt_re = fy->data[i + 1].re;
      nt_im = fy->data[i + 1].im;
      twid_re = fy->data[i].re;
      twid_im = fy->data[i].im;
      fy->data[i + 1].re = fy->data[i].re - fy->data[i + 1].re;
      fy->data[i + 1].im = fy->data[i].im - fy->data[i + 1].im;
      twid_re += nt_re;
      twid_im += nt_im;
      fy->data[i].re = twid_re;
      fy->data[i].im = twid_im;
    }
  }

  rt = 2;
  nInt2 = 4;
  nInt2m1 = ((nRowsD4 - 1) << 2) + 1;
  while (nRowsD4 > 0) {
    for (i = 0; i < nInt2m1; i += nInt2) {
      nt_re_tmp = i + rt;
      nt_re = fy->data[nt_re_tmp].re;
      nt_im = fy->data[nt_re_tmp].im;
      fy->data[nt_re_tmp].re = fy->data[i].re - fy->data[nt_re_tmp].re;
      fy->data[nt_re_tmp].im = fy->data[i].im - fy->data[nt_re_tmp].im;
      fy->data[i].re += nt_re;
      fy->data[i].im += nt_im;
    }

    idx = 1;
    for (ju = nRowsD4; ju < nRowsD2; ju += nRowsD4) {
      twid_re = costab->data[ju];
      twid_im = sintab->data[ju];
      i = idx;
      ihi = idx + nInt2m1;
      while (i < ihi) {
        nt_re_tmp = i + rt;
        nt_re = twid_re * fy->data[nt_re_tmp].re - twid_im * fy->data[nt_re_tmp]
          .im;
        nt_im = twid_re * fy->data[nt_re_tmp].im + twid_im * fy->data[nt_re_tmp]
          .re;
        fy->data[nt_re_tmp].re = fy->data[i].re - nt_re;
        fy->data[nt_re_tmp].im = fy->data[i].im - nt_im;
        fy->data[i].re += nt_re;
        fy->data[i].im += nt_im;
        i += nInt2;
      }

      idx++;
    }

    nRowsD4 /= 2;
    rt = nInt2;
    nInt2 += nInt2;
    nInt2m1 -= rt;
  }

  emxInit_creal_T(&fv, 1);
  r2br_r2dit_trig_impl(wwc, N2, costab, sintab, fv);
  rt = fy->size[0];
  for (ju = 0; ju < rt; ju++) {
    twid_im = fy->data[ju].re * fv->data[ju].im + fy->data[ju].im * fv->data[ju]
      .re;
    fy->data[ju].re = fy->data[ju].re * fv->data[ju].re - fy->data[ju].im *
      fv->data[ju].im;
    fy->data[ju].im = twid_im;
  }

  r2br_r2dit_trig_impl(fy, N2, costab, sintabinv, fv);
  emxFree_creal_T(&fy);
  if (fv->size[0] > 1) {
    twid_re = 1.0 / (double)fv->size[0];
    rt = fv->size[0];
    for (ju = 0; ju < rt; ju++) {
      fv->data[ju].re *= twid_re;
      fv->data[ju].im *= twid_re;
    }
  }

  idx = 0;
  ju = wwc->size[0];
  for (ihi = n1; ihi <= ju; ihi++) {
    y->data[idx].re = wwc->data[ihi - 1].re * fv->data[ihi - 1].re + wwc->
      data[ihi - 1].im * fv->data[ihi - 1].im;
    y->data[idx].im = wwc->data[ihi - 1].re * fv->data[ihi - 1].im - wwc->
      data[ihi - 1].im * fv->data[ihi - 1].re;
    idx++;
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&wwc);
}

static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y)
{
  int istart;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int temp_re_tmp;
  int ihi;
  istart = x->size[0];
  if (istart >= unsigned_nRows) {
    istart = unsigned_nRows;
  }

  nRowsM2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iy = y->size[0];
    y->size[0] = unsigned_nRows;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i <= istart - 2; i++) {
    y->data[iy] = x->data[ix];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= nRowsM2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      twid_re = y->data[i].re;
      twid_im = y->data[i].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y->data[i].re = twid_re;
      y->data[i].im = twid_im;
    }
  }

  iy = 2;
  ix = 4;
  ju = ((nRowsD4 - 1) << 2) + 1;
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - y->data[temp_re_tmp].re;
      y->data[temp_re_tmp].im = y->data[i].im - y->data[temp_re_tmp].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (nRowsM2 = nRowsD4; nRowsM2 < nRowsD2; nRowsM2 += nRowsD4) {
      twid_re = costab->data[nRowsM2];
      twid_im = sintab->data[nRowsM2];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
          data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    iy = ix;
    ix += ix;
    ju -= iy;
  }
}

void fft(const emxArray_real_T *x, int n, emxArray_creal_T *y)
{
  emxArray_real_T *costab1q;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  boolean_T useRadix2;
  int pow2p;
  int pmin;
  int ihi;
  int pmax;
  double twid_re;
  boolean_T exitg1;
  int istart;
  int nRowsM2;
  int nRowsD2;
  int nRowsD4;
  int i;
  double temp_re;
  double temp_im;
  double twid_im;
  int temp_re_tmp;
  emxInit_real_T(&costab1q, 2);
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  if ((x->size[0] == 0) || (n == 0)) {
    pow2p = y->size[0];
    y->size[0] = n;
    emxEnsureCapacity_creal_T(y, pow2p);
    if (n > x->size[0]) {
      pow2p = y->size[0];
      y->size[0] = n;
      emxEnsureCapacity_creal_T(y, pow2p);
      for (pow2p = 0; pow2p < n; pow2p++) {
        y->data[pow2p].re = 0.0;
        y->data[pow2p].im = 0.0;
      }
    }
  } else {
    useRadix2 = ((n & (n - 1)) == 0);
    pmin = 1;
    if (useRadix2) {
      pmax = n;
    } else {
      ihi = (n + n) - 1;
      pmax = 31;
      if (ihi <= 1) {
        pmax = 0;
      } else {
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          istart = (pmin + pmax) >> 1;
          pow2p = 1 << istart;
          if (pow2p == ihi) {
            pmax = istart;
            exitg1 = true;
          } else if (pow2p > ihi) {
            pmax = istart;
          } else {
            pmin = istart;
          }
        }
      }

      pmin = 1 << pmax;
      pmax = pmin;
    }

    twid_re = 6.2831853071795862 / (double)pmax;
    ihi = pmax / 2 / 2;
    pow2p = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = ihi + 1;
    emxEnsureCapacity_real_T(costab1q, pow2p);
    costab1q->data[0] = 1.0;
    pmax = ihi / 2 - 1;
    for (istart = 0; istart <= pmax; istart++) {
      costab1q->data[istart + 1] = cos(twid_re * ((double)istart + 1.0));
    }

    pow2p = pmax + 2;
    pmax = ihi - 1;
    for (istart = pow2p; istart <= pmax; istart++) {
      costab1q->data[istart] = sin(twid_re * (double)(ihi - istart));
    }

    costab1q->data[ihi] = 0.0;
    if (!useRadix2) {
      ihi = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pow2p = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pow2p);
      pow2p = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pow2p);
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      pow2p = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintabinv, pow2p);
      for (istart = 0; istart < ihi; istart++) {
        sintabinv->data[istart + 1] = costab1q->data[(ihi - istart) - 1];
      }

      pow2p = costab1q->size[1];
      for (istart = pow2p; istart <= pmax; istart++) {
        sintabinv->data[istart] = costab1q->data[istart - ihi];
      }

      for (istart = 0; istart < ihi; istart++) {
        costab->data[istart + 1] = costab1q->data[istart + 1];
        sintab->data[istart + 1] = -costab1q->data[(ihi - istart) - 1];
      }

      pow2p = costab1q->size[1];
      for (istart = pow2p; istart <= pmax; istart++) {
        costab->data[istart] = -costab1q->data[pmax - istart];
        sintab->data[istart] = -costab1q->data[istart - ihi];
      }
    } else {
      ihi = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pow2p = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pow2p);
      pow2p = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pow2p);
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      for (istart = 0; istart < ihi; istart++) {
        costab->data[istart + 1] = costab1q->data[istart + 1];
        sintab->data[istart + 1] = -costab1q->data[(ihi - istart) - 1];
      }

      pow2p = costab1q->size[1];
      for (istart = pow2p; istart <= pmax; istart++) {
        costab->data[istart] = -costab1q->data[pmax - istart];
        sintab->data[istart] = -costab1q->data[istart - ihi];
      }

      sintabinv->size[0] = 1;
      sintabinv->size[1] = 0;
    }

    if (useRadix2) {
      istart = x->size[0];
      if (istart >= n) {
        istart = n;
      }

      nRowsM2 = n - 2;
      nRowsD2 = n / 2;
      nRowsD4 = nRowsD2 / 2;
      pow2p = y->size[0];
      y->size[0] = n;
      emxEnsureCapacity_creal_T(y, pow2p);
      if (n > x->size[0]) {
        pow2p = y->size[0];
        y->size[0] = n;
        emxEnsureCapacity_creal_T(y, pow2p);
        for (pow2p = 0; pow2p < n; pow2p++) {
          y->data[pow2p].re = 0.0;
          y->data[pow2p].im = 0.0;
        }
      }

      pmin = 0;
      pow2p = 0;
      pmax = 0;
      for (i = 0; i <= istart - 2; i++) {
        y->data[pmax].re = x->data[pmin];
        y->data[pmax].im = 0.0;
        ihi = n;
        useRadix2 = true;
        while (useRadix2) {
          ihi >>= 1;
          pow2p ^= ihi;
          useRadix2 = ((pow2p & ihi) == 0);
        }

        pmax = pow2p;
        pmin++;
      }

      y->data[pmax].re = x->data[pmin];
      y->data[pmax].im = 0.0;
      if (n > 1) {
        for (i = 0; i <= nRowsM2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          twid_re = y->data[i].re;
          twid_im = y->data[i].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          twid_re += temp_re;
          twid_im += temp_im;
          y->data[i].re = twid_re;
          y->data[i].im = twid_im;
        }
      }

      pmax = 2;
      pmin = 4;
      pow2p = ((nRowsD4 - 1) << 2) + 1;
      while (nRowsD4 > 0) {
        for (i = 0; i < pow2p; i += pmin) {
          temp_re_tmp = i + pmax;
          temp_re = y->data[temp_re_tmp].re;
          temp_im = y->data[temp_re_tmp].im;
          y->data[temp_re_tmp].re = y->data[i].re - y->data[temp_re_tmp].re;
          y->data[temp_re_tmp].im = y->data[i].im - y->data[temp_re_tmp].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }

        istart = 1;
        for (nRowsM2 = nRowsD4; nRowsM2 < nRowsD2; nRowsM2 += nRowsD4) {
          twid_re = costab->data[nRowsM2];
          twid_im = sintab->data[nRowsM2];
          i = istart;
          ihi = istart + pow2p;
          while (i < ihi) {
            temp_re_tmp = i + pmax;
            temp_re = twid_re * y->data[temp_re_tmp].re - twid_im * y->
              data[temp_re_tmp].im;
            temp_im = twid_re * y->data[temp_re_tmp].im + twid_im * y->
              data[temp_re_tmp].re;
            y->data[temp_re_tmp].re = y->data[i].re - temp_re;
            y->data[temp_re_tmp].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += pmin;
          }

          istart++;
        }

        nRowsD4 /= 2;
        pmax = pmin;
        pmin += pmin;
        pow2p -= pmax;
      }
    } else {
      dobluesteinfft(x, pmin, n, costab, sintab, sintabinv, y);
    }
  }

  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  emxFree_real_T(&costab1q);
}

/* End of code generation (fft.c) */
