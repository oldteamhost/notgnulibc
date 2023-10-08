/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_PRINTF_H
#define NOTGNU_PRINTF_H

#include "../stdarg.h"
#include "../ngubits/types.h"
#include "../ngusyst/cdefs.h"
#include "../stddef.h"

__BEGIN_DECLS

struct print_buf
{
  char *buf;
  size_t size;
};

int putchar(int c);
int vprintf(const char *fmt, va_list ap);
int sprintf(char *buf, const char *cfmt, ...);
int asprintf(char **buf, const char *cfmt, ...);
int snprintf(char *buf, size_t size, const char *cfmt, ...);
int vsnprintf(char *buf, size_t size, const char *cfmt, va_list ap);
int vsprintf(char *buf, const char *cfmt, va_list ap);
int printf(const char* fmt, ...);

__END_DECLS

#endif
