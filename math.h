/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_MATH_H
#define NOTGNU_MATH_H

/* welcome to hell */

#include "ngubits/types.h"
#include "ngusyst/cdefs.h"

#define HUGE_VAL (__builtin_huge_val ())
#define HUGE_VALF (__builtin_huge_valf ())
#define HUGE_VALL (__builtin_huge_vall ())
#define INFINITY (__builtin_inff ())
#define NAN (__builtin_nanf(""))

#define M_E        2.7182818284590452354  /* e */
#define M_LOG2E    1.4426950408889634074  /* log 2e */
#define M_LOG10E   0.43429448190325182765 /* log 10e */
#define M_LN2      0.69314718055994530942 /* log e2 */
#define M_LN10     2.30258509299404568402 /* log e10 */
#define M_PI       3.14159265358979323846 /* pi */
#define M_PI_2     1.57079632679489661923 /* pi/2 */
#define M_PI_4     0.78539816339744830962 /* pi/4 */
#define M_1_PI     0.31830988618379067154 /* 1/pi */
#define M_2_PI     0.63661977236758134308 /* 2/pi */
#define M_2_SQRTPI 1.12837916709551257390 /* 2/sqrt(pi) */
#define M_SQRT2    1.41421356237309504880 /* sqrt(2) */
#define M_SQRT1_2  0.70710678118654752440 /* 1/sqrt(2) */

#define MAX_FLOAT \
  ((float) 3.40282346638528860e+38)

/* done */
#ifndef abs
  #define abs(x) \
    ((x) < 0 ? -(x) : (x))
#endif

typedef union
{
  double value;
  struct
  {
    u32 lsw;
    u32 msw;
  } parts;
} ieee_double_shape_type;

#define SET_LOW_WORD(d,v)       \
do {                            \
  ieee_double_shape_type sl_u;  \
  sl_u.value = (d);             \
  sl_u.parts.lsw = (v);         \
  (d) = sl_u.value;             \
} while (0)

#define SET_HIGH_WORD(d,v)      \
do {                            \
  ieee_double_shape_type sh_u;  \
  sh_u.value = (d);             \
  sh_u.parts.msw = (v);         \
  (d) = sh_u.value;             \
} while (0)

#define GET_LOW_WORD(i,d)       \
do {                            \
  ieee_double_shape_type gl_u;  \
  gl_u.value = (d);             \
  (i) = gl_u.parts.lsw;         \
} while (0)

#define GET_HIGH_WORD(i,d)      \
do {                            \
  ieee_double_shape_type gh_u;  \
  gh_u.value = (d);             \
  (i) = gh_u.parts.msw;         \
} while (0)

#define EXTRACT_WORDS(ix0,ix1,d)\
do {                            \
  ieee_double_shape_type ew_u;  \
  ew_u.value = (d);             \
  (ix0) = ew_u.parts.msw;       \
  (ix1) = ew_u.parts.lsw;       \
} while (0)

#define EXTRACT_WORD64(ix,d)    \
do {                            \
  ieee_double_shape_type ew_u;  \
  ew_u.value = (d);             \
  (ix) = ew_u.xparts.w;         \
} while (0)

#define INSERT_WORDS(d,ix0,ix1) \
do {                            \
  ieee_double_shape_type iw_u;  \
  iw_u.parts.msw = (ix0);       \
  iw_u.parts.lsw = (ix1);       \
  (d) = iw_u.value;             \
} while (0)

#define INSERT_WORD64(d,ix)     \
do {                            \
  ieee_double_shape_type iw_u;  \
  iw_u.xparts.w = (ix);         \
  (d) = iw_u.value;             \
} while (0)

__BEGIN_DECLS

double sqrt(double); /* done */
double acos(double); /* done */
double log(double); /* done */
double log10(double); /* done */

double exp(double);
double sin(double);
double cos(double);
double tan(double);
double atan(double);
double atan2(double, double);
double cosh(double);
double sinh(double);
double tanh(double);
double frexp(double, int *);
double ldexp(double, int);
double modf(double, double *);
double pow(double, double);
double ceil(double);
double floor(double);
double fmod(double, double);

__END_DECLS

#endif

