/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_UCHAR_H
#define NOTGNU_UCHAR_H

#include "ngubits/types.h"
#include "ngusyst/cdefs.h"

#ifndef _CHAR16_T_DECLARED
  typedef ___char16_t char16_t;
  #define _CHAR16_T_DECLARED
#endif

#ifndef _CHAR32_T_DECLARED
  typedef ___char32_t char32_t;
  #define _CHAR32_T_DECLARED
#endif

__BEGIN_DECLS

/* TODO */
u64 c16rtomb(char* pmb, char16_t c16, mbstate_t* ps);
u64 c32rtomb(char* pmb, char32_t c32, mbstate_t* ps);
u64 mbrtoc16(char16_t* pc16, const char* pmb, u64 max, mbstate_t* ps);
u64 mbrtoc32(char32_t* pc32, const char* pmb, u64 max, mbstate_t* ps);

__END_DECLS

#endif

