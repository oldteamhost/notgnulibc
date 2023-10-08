/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../math.h"

static const double
two54      =  1.80143985094819840000e+16, /* 0x43500000, 0x00000000 */
ivln10hi   =  4.34294481878168880939e-01, /* 0x3fdbcb7b, 0x15200000 */
ivln10lo   =  2.50829467116452752298e-11, /* 0x3dbb9438, 0xca9aadd5 */
log10_2hi  =  3.01029995663611771306e-01, /* 0x3FD34413, 0x509F6000 */
log10_2lo  =  3.69423907715893078616e-13; /* 0x3D59FEF3, 0x11F12B36 */

static const double    zero  =  0.0;
static volatile double vzero = 0.0;

static const double
Lg1 = 6.666666666666735130e-01,  /* 3FE55555 55555593 */
Lg2 = 3.999999999940941908e-01,  /* 3FD99999 9997FA04 */
Lg3 = 2.857142874366239149e-01,  /* 3FD24924 94229359 */
Lg4 = 2.222219843214978396e-01,  /* 3FCC71C5 1D8E78AF */
Lg5 = 1.818357216161805012e-01,  /* 3FC74664 96CB03DE */
Lg6 = 1.531383769920937332e-01,  /* 3FC39A09 D078C69F */
Lg7 = 1.479819860511658591e-01;  /* 3FC2F112 DF3E5244 */

static double
k_log1p(double f)
{
  double hfsq,s,z,R,w,t1,t2;

  s = f/(2.0+f);
  z = s*s;
  w = z*z;
  t1= w*(Lg2+w*(Lg4+w*Lg6));
  t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
  R = t2+t1;
  hfsq=0.5*f*f;
  return s*(hfsq+R);
}

double
log10 (double x)
{
  double f,hfsq,hi,lo,r,val_hi,val_lo,w,y,y2;
  i32 i,k,hx;
  u32 lx;

  EXTRACT_WORDS(hx,lx,x);

  k=0;
  if (hx < 0x00100000) {
    if (((hx & 0x7fffffff) | lx) == 0) {
      return -two54/vzero;
    }
    if (hx < 0)  {
      return (x-x)/zero;
    }
    k -= 54; x *= two54; /* subnormal number, scale up x */
    GET_HIGH_WORD(hx,x);
  }
  if (hx >= 0x7ff00000) {
    return x+x;
  }
  if (hx == 0x3ff00000 && lx == 0) {
    return zero;
  }
  k += (hx >> 20)-1023;
  hx &= 0x000fffff;
  i = (hx+0x95f64)&0x100000;
  SET_HIGH_WORD(x,hx|(i^0x3ff00000));	/* normalize x or x/2 */
  k += (i>>20);
  y = (double)k;
  f = x - 1.0;
  hfsq = 0.5*f*f;
  r = k_log1p(f);

  hi = f - hfsq;
  SET_LOW_WORD(hi,0);
  lo = (f - hi) - hfsq + r;
  val_hi = hi*ivln10hi;
  y2 = y*log10_2hi;
  val_lo = y*log10_2lo + (lo+hi)*ivln10lo + lo*ivln10hi;
  w = y2 + val_hi;
  val_lo += (y2 - w) + val_hi;
  val_hi = w;

  return val_lo + val_hi;
}
