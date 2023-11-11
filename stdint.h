/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_STDINT_H
#define NOTGNU_STDINT_H

#include "ngubits/types.h"
#include "ngubits/wordsize.h"

#ifdef __WCHAR_MAX__
  #define __WCHAR_MAX __WCHAR_MAX__
#elif L'\0' - 1 > 0
  #define __WCHAR_MAX (0xffffffffu + L'\0')
#else
  #define __WCHAR_MAX (0x7fffffff + L'\0')
#endif

#ifdef __WCHAR_MIN__
  #define __WCHAR_MIN __WCHAR_MIN__
#elif L'\0' - 1 > 0
  #define __WCHAR_MIN (L'\0' + 0)
#else
  #define __WCHAR_MIN (-__WCHAR_MAX - 1)
#endif

typedef __int_least8_t    int_least8_t;
typedef __int_least16_t   int_least16_t;
typedef __int_least32_t   int_least32_t;
typedef __int_least64_t   int_least64_t;

typedef __uint_least8_t   uint_least8_t;
typedef __uint_least16_t  uint_least16_t;
typedef __uint_least32_t  uint_least32_t;
typedef __uint_least64_t  uint_least64_t;

typedef signed char       int_fast8_t;
#if __WORDSIZE == 64
  typedef long int        int_fast16_t;
  typedef long int        int_fast32_t;
  typedef long int        int_fast64_t;
#else
  typedef int             int_fast16_t;
  typedef int             int_fast32_t;
  typedef long long int   int_fast64_t;
#endif

#if __WORDSIZE == 64
  typedef unsigned long int       uint_fast16_t;
  typedef unsigned long int       uint_fast32_t;
  typedef unsigned long int       uint_fast64_t;
#else
  typedef unsigned int            uint_fast16_t;
  typedef unsigned int            uint_fast32_t;
  typedef unsigned long long int  uint_fast64_t;
#endif

#if __WORDSIZE == 64
  #ifndef __intptr_t_defined
    typedef long int intptr_t;
    #define __intptr_t_defined
  #endif
typedef unsigned long int uintptr_t;
#else
  #ifndef __intptr_t_defined
    typedef int intptr_t;
  #define __intptr_t_defined
  #endif
typedef unsigned int uintptr_t;
#endif

typedef __intmax_t  intmax_t;
typedef __uintmax_t uintmax_t;

#if __WORDSIZE == 64
  #define __INT64_C(c) c ## L
  #define __UINT64_C(c) c ## UL
#else
  #define __INT64_C(c) c ## LL
  #define __UINT64_C(c) c ## ULL
#endif

#define INT8_MIN     (-128)
#define INT16_MIN    (-32767-1)
#define INT32_MIN    (-2147483647-1)
#define INT64_MIN    (-__INT64_C(9223372036854775807)-1)

#define INT8_MAX   (127)
#define INT16_MAX  (32767)
#define INT32_MAX  (2147483647)
#define INT64_MAX  (__INT64_C(9223372036854775807))

#define UINT8_MAX   (255)
#define UINT16_MAX  (65535)
#define UINT32_MAX  (4294967295U)
#define UINT64_MAX  (__UINT64_C(18446744073709551615))


#define INT_LEAST8_MIN   (-128)
#define INT_LEAST16_MIN  (-32767-1)
#define INT_LEAST32_MIN  (-2147483647-1)
#define INT_LEAST64_MIN  (-__INT64_C(9223372036854775807)-1)

#define INT_LEAST8_MAX   (127)
#define INT_LEAST16_MAX  (32767)
#define INT_LEAST32_MAX  (2147483647)
#define INT_LEAST64_MAX  (__INT64_C(9223372036854775807))

#define UINT_LEAST8_MAX   (255)
#define UINT_LEAST16_MAX  (65535)
#define UINT_LEAST32_MAX  (4294967295U)
#define UINT_LEAST64_MAX  (__UINT64_C(18446744073709551615))

#define INT_FAST8_MIN (-128)
#if __WORDSIZE == 64
  #define INT_FAST16_MIN (-9223372036854775807L-1)
  #define INT_FAST32_MIN (-9223372036854775807L-1)
#else
  #define INT_FAST16_MIN (-2147483647-1)
  #define INT_FAST32_MIN (-2147483647-1)
#endif
#define INT_FAST64_MIN (-__INT64_C(9223372036854775807)-1)

#define INT_FAST8_MAX (127)
#if __WORDSIZE == 64
  #define INT_FAST16_MAX (9223372036854775807L)
  #define INT_FAST32_MAX (9223372036854775807L)
#else
  #define INT_FAST16_MAX (2147483647)
  #define INT_FAST32_MAX (2147483647)
#endif
#define INT_FAST64_MAX (__INT64_C(9223372036854775807))

#define UINT_FAST8_MAX (255)
#if __WORDSIZE == 64
  #define UINT_FAST16_MAX (18446744073709551615UL)
  #define UINT_FAST32_MAX (18446744073709551615UL)
#else
  #define UINT_FAST16_MAX (4294967295U)
  #define UINT_FAST32_MAX (4294967295U)
#endif
#define UINT_FAST64_MAX (__UINT64_C(18446744073709551615))


#if __WORDSIZE == 64
  #define INTPTR_MIN   (-9223372036854775807L-1)
  #define INTPTR_MAX   (9223372036854775807L)
  #define UINTPTR_MAX  (18446744073709551615UL)
#else
  #define INTPTR_MIN   (-2147483647-1)
  #define INTPTR_MAX   (2147483647)
  #define UINTPTR_MAX  (4294967295U)
#endif


# define INTMAX_MIN   (-__INT64_C(9223372036854775807)-1)
# define INTMAX_MAX   (__INT64_C(9223372036854775807))
# define UINTMAX_MAX  (__UINT64_C(18446744073709551615))

# if __WORDSIZE == 64
  #define PTRDIFF_MIN (-9223372036854775807L-1)
  #define PTRDIFF_MAX (9223372036854775807L)
#else
  #if __WORDSIZE32_PTRDIFF_LONG
    #define PTRDIFF_MIN (-2147483647L-1)
    #define PTRDIFF_MAX (2147483647L)
  #else
    #define PTRDIFF_MIN (-2147483647-1)
    #define PTRDIFF_MAX (2147483647)
  #endif
#endif

#define SIG_ATOMIC_MIN (-2147483647-1)
#define SIG_ATOMIC_MAX (2147483647)

#if __WORDSIZE == 64
  #define SIZE_MAX (18446744073709551615UL)
#else
  #if __WORDSIZE32_SIZE_ULONG
    #define SIZE_MAX (4294967295UL)
  #else
    #define SIZE_MAX (4294967295U)
  #endif
#endif

#ifndef WCHAR_MIN
  #define WCHAR_MIN __WCHAR_MIN
  #define WCHAR_MAX __WCHAR_MAX
#endif

#define WINT_MIN (0u)
#define WINT_MAX (4294967295u)

#define INT8_C(c) c
#define INT16_C(c) c
#define INT32_C(c) c
#if __WORDSIZE == 64
  #define INT64_C(c) c ## L
#else
  #define INT64_C(c) c ## LL
#endif

#define UINT8_C(c) c
#define UINT16_C(c) c
#define UINT32_C(c) c ## U

#if __WORDSIZE == 64
  #define UINT64_C(c) c ## UL
#else
  #define UINT64_C(c) c ## ULL
#endif

#if __WORDSIZE == 64
  #define INTMAX_C(c) c ## L
  #define UINTMAX_C(c) c ## UL
#else
  #define INTMAX_C(c) c ## LL
  #define UINTMAX_C(c) c ## ULL
#endif

#define INT8_WIDTH          8
#define UINT8_WIDTH         8
#define INT16_WIDTH         16
#define UINT16_WIDTH        16
#define INT32_WIDTH         32
#define UINT32_WIDTH        32
#define INT64_WIDTH         64
#define UINT64_WIDTH        64
#define INT_LEAST8_WIDTH    8
#define UINT_LEAST8_WIDTH   8
#define INT_LEAST16_WIDTH   16
#define UINT_LEAST16_WIDTH  16
#define INT_LEAST32_WIDTH   32
#define UINT_LEAST32_WIDTH  32
#define INT_LEAST64_WIDTH   64
#define UINT_LEAST64_WIDTH  64
#define INT_FAST8_WIDTH     8
#define UINT_FAST8_WIDTH    8
#define INT_FAST16_WIDTH    __WORDSIZE
#define UINT_FAST16_WIDTH   __WORDSIZE
#define INT_FAST32_WIDTH    __WORDSIZE
#define UINT_FAST32_WIDTH   __WORDSIZE
#define INT_FAST64_WIDTH    64
#define UINT_FAST64_WIDTH   64
#define INTPTR_WIDTH        __WORDSIZE
#define UINTPTR_WIDTH       __WORDSIZE
#define INTMAX_WIDTH        64
#define UINTMAX_WIDTH       64
#define PTRDIFF_WIDTH       __WORDSIZE
#define SIG_ATOMIC_WIDTH    32
#define SIZE_WIDTH          __WORDSIZE
#define WCHAR_WIDTH         32
#define WINT_WIDTH          32

#endif
