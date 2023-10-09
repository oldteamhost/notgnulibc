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

__BEGIN_DECLS

extern char **__environ;

char* _sbrk(int incr);

/* asm functions */
size_t _write(int fd, const void *dest, size_t bcount);
int _getpagesize(void);
void _abort(int code);

__END_DECLS

#endif

