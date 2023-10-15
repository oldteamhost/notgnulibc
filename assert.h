/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_ASSERT_H
#define NOTGNU_ASSERT_H

#include "string.h"
#include "ngusyst/cdefs.h"
#include "ngusyst/printf.h"
#include "stdlib.h"
#include "unistd.h"

#ifdef NDEBUG /* disable assert */
  #define assert(e)  ((void)0)
  #define _assert(e) ((void)0)
#else
  #define _assert(e) \
    assert(e)
  #define assert(e) \
    ((e) ? (void)0 : __assert(__func__, __FILE__, __LINE__, #e))
#endif

__BEGIN_DECLS

void
__assert(const char*, const char*, int, const char*);

__END_DECLS

#endif

