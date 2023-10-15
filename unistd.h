/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_UNISTD_H
#define NOTGNU_UNISTD_H

#include "stdarg.h"
#include "ngubits/types.h"
#include "ngusyst/cdefs.h"
#include "stddef.h"
#include "stdnoreturn.h"

__BEGIN_DECLS

extern char **__environ;

char* _sbrk(int incr);
/* asm functions */
noreturn void __exit(int code);
noreturn void __abort(void);

size_t _write(int fd, const void *dest, size_t bcount);

int _getpagesize(void);

__END_DECLS

#endif

