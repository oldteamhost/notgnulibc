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

/*
 * The printf function outputs formatted text to the standard output
 * using the provided arguments. It allows formatting output based on
 * the format string fmt and a variable number of arguments.
*/
int printf(const char* fmt, ...);

/*
 * The vprintf function outputs formatted text to the
 * standard output using the provided va_list arguments.
 * It allows formatting output based on the format string
 * fmt and the va_list argument list ap.
*/
int vprintf(const char *fmt, va_list ap);

/*
 * The sprintf function formats text according to the
 * provided format string cfmt and stores the result in
 * the buffer buf. This function takes a variable number
 * of arguments, not va_list.
*/
int sprintf(char *buf, const char *cfmt, ...);

/*
 * The asprintf function is similar to sprintf but
 * dynamically allocates memory for the buffer buf and
 * automatically frees it. The result is stored in the buf,
 * which must be freed after use.
*/
int asprintf(char **buf, const char *cfmt, ...);

/*
 * The snprintf function formats text according to the
 * provided format string cfmt and stores the result in the
 * buffer buf. However, it also takes a size parameter to
 * prevent buffer overflow.
*/
int snprintf(char *buf, size_t size, const char *cfmt, ...);

/*
 * The vsnprintf function is similar to snprintf, but it takes
 * a va_list argument to pass the arguments of the format string.
*/
int vsnprintf(char *buf, size_t size, const char *cfmt, va_list ap);

/*
 * The vsprintf function is similar to sprintf, but it takes a va_list
 * argument to pass the arguments of the format string.
*/
int vsprintf(char *buf, const char *cfmt, va_list ap);

__END_DECLS

#endif
