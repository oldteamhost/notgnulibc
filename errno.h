/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_ERRNO_H
#define NOTGNU_ERRNO_H

/* This is the classic ANSI C
 * standard errno.h. */

#include "ngusyst/cdefs.h"

#define EDOM    0 /* Error DOMain */
#define EILSEQ  1 /* Error InvaLid SEQuence */
#define ERANGE  2 /* Error RANGE */

#define seterrno(value) \
  (errno = (value))

__BEGIN_DECLS

extern int errno;

__END_DECLS

#endif
