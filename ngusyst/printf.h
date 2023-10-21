/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_PRINTF_H
#define NOTGNU_PRINTF_H

#include "cdefs.h"
#include "../string.h"
#include "../stdarg.h"
#include "../ngubits/types.h"

#define ZEROPAD  1
#define SIGN     2
#define PLUS     4
#define SPACE    8
#define LEFT     16
#define SPECIAL  32
#define LARGE    64

#define is_digit(c) ((c) >= '0' && (c) <= '9')

__BEGIN_DECLS

int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char *buf, const char *fmt, ...);
int snprintf(char *buf, ___size_t size, const char *fmt, ...);
int vsnprintf(char *buf, ___size_t size, const char *fmt, va_list args);
int asprintf(char **str, const char *format, ...);
int printf(const char *format, ...);

__END_DECLS

#endif

