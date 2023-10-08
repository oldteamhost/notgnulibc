/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_STDDEF_H
#define NOTGNU_STDDEF_H

#include "ngubits/types.h"
#include "ngusyst/null.h" /* for NULL */

typedef ___ptrdiff_t ptrdiff_t;
typedef ___size_t size_t;

#ifndef __cplusplus
  typedef ___wchar_t wchar_t;
#endif

#ifdef __VERY_OLD_OFFSETOF
  #define offsetof(st, m) ((size_t)&(((st *)0)->m))
#endif

#ifdef __OLD_OFFSETOF
  #define offsetof( st, m ) ( (size_t) (& ((st *)0)->m ) )
#endif

#define __offsetof(type, field) __builtin_offsetof(type, field)

#define container_of(ptr, type, member) ({                 \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);   \
    (type *)( (char *)__mptr - offsetof(type,member) );})

#endif

