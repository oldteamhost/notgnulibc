/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_LIMITS_H
#define NOTGNU_LIMITS_H

/* There are no limits,
 * but there are limits here. */

#include "ngubits/wordsize.h"

/* NO ANSI */
#if __WORDSIZE == 64
  #define LONG_BIT 64
#else
  #define LONG_BIT 32
#endif

#define MB_LEN_MAX 16
#define CHAR_BIT 8

#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

#define UCHAR_MAX 255

#ifdef __CHAR_UNSIGNED__
  #define CHAR_MIN 0
  #define CHAR_MAX UCHAR_MAX
#else
  #define CHAR_MIN SCHAR_MIN
  #define CHAR_MAX SCHAR_MAX
#endif

#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

#define USHRT_MAX 65535

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

#define UINT_MAX 4294967295U

#if __WORDSIZE == 64
  #define LONG_MAX 9223372036854775807L
#else
  #define LONG_MAX 2147483647L
#endif
  #define LONG_MIN (-LONG_MAX - 1L)

#if __WORDSIZE == 64
  #define ULONG_MAX 18446744073709551615UL
#else
  #define ULONG_MAX 4294967295UL
#endif

#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-LLONG_MAX - 1LL)

#define ULLONG_MAX 18446744073709551615ULL

#endif

