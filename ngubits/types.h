/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_BITS_TYPES_H
#define NOTGNU_BITS_TYPES_H

#include "wordsize.h"

/* This file stores all data types from the standard library. The three "___"
 * is necessary so that the names do not conflict. Because according to the
 * standard, let's say size_t should be located in stddeff.h. But it is not
 * convenient to control all data types when half of them are in different
 * files, so I created it here "__size_t", and in stddeff.h it looks like
 * "typedef __size_t size_t". Thus, I can control all data types from this
 * file and do it without violating the standard.*/

#if __WORDSIZE == 64
  typedef signed long int         ___int64_t;
#else
  typedef signed long long int    ___int64_t;
#endif
typedef signed int           ___int32_t;
typedef signed short int     ___int16_t;
typedef signed char          ___int8_t;

#if __WORDSIZE == 64
  typedef unsigned long int       ___uint64_t;
#else
  typedef unsigned long long int  ___uint64_t;
#endif
typedef unsigned int         ___uint32_t;
typedef unsigned short int   ___uint16_t;
typedef unsigned char        ___uint8_t;

typedef unsigned long int    ___u_long;
typedef unsigned int         ___u_int;
typedef unsigned short int   ___u_short;
typedef unsigned char        ___u_char;

#if __WORDSIZE == 64
  typedef long int                ___quad_t;
  typedef unsigned long int       ___u_quad_t;
#else
  typedef long long int           ___quad_t;
  typedef unsigned long long int  ___u_quad_t;
#endif

#if __WORDSIZE == 64
  typedef long int               __intmax_t;
  typedef unsigned long int      __uintmax_t;
#else
  typedef long long int          __intmax_t;
  typedef unsigned long long int __uintmax_t;
#endif

#if __WORDSIZE == 64
  typedef ___int64_t  __intptr_t;
  typedef ___int64_t  __intfptr_t;
  typedef ___uint64_t __uintptr_t;
  typedef ___uint64_t __uintfptr_t;
  typedef ___uint64_t __vm_offset_t;
  typedef ___uint64_t __vm_size_t;
#else
  typedef ___int32_t  __intptr_t;
  typedef ___int32_t  __intfptr_t;
  typedef ___uint32_t __uintptr_t;
  typedef ___uint32_t __uintfptr_t;
  typedef ___uint32_t __vm_offset_t;
  typedef ___uint32_t __vm_size_t;
#endif

/* notgnu default types */
typedef ___uint64_t u64;
typedef ___uint32_t u32;
typedef ___uint16_t u16;
typedef ___uint8_t  u8;

typedef ___int64_t  i64;
typedef ___int32_t  i32;
typedef ___int16_t  i16;
typedef ___int8_t   i8;

typedef ___uint32_t ___clock_t;
typedef ___int64_t ___time_t;

#define TYPE_SIGNED(type) (((type) -1) < 0)
typedef __builtin_va_list __va_list;

typedef union
{
  char __mbstate8[128];
  i64  _mbstateL;
} ___mbstate_t;
typedef ___mbstate_t mbstate_t;

#ifndef __off_t_defined
  typedef long ___off_t;
#endif

typedef i64 ___ptrdiff_t;

#if __WORDSIZE == 64
  typedef u64 ___size_t;
#else
  typedef u32 ___size_t;
#endif

typedef u32 ___wchar_t;

#ifndef _CHAR16_T_DECLARED
  typedef u16 ___char16_t;
  #define _CHAR16_T_DECLARED
#endif

#ifndef _CHAR32_T_DECLARED
  typedef u32 ___char32_t;
  #define _CHAR32_T_DECLARED
#endif

#endif

