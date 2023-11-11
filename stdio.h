/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_STDIO_H
#define NOTGNU_STDIO_H

#include "ngubits/types.h"
#include "ngubits/fcntl.h"
#include "ngusyst/cdefs.h"
#include "string.h"
#include "stdarg.h"
#include "ngusyst/null.h" /* for null */
#include "stdlib.h"

#define BUFSIZ 8192
#define EOF (-1)

#define ZEROPAD  1
#define SIGN     2
#define PLUS     4
#define SPACE    8
#define LEFT     16
#define SPECIAL  32
#define LARGE    64

#define is_digit(c) ((c) >= '0' && (c) <= '9')

__BEGIN_DECLS

struct stdio_file
{
  int fd;
  int flags;
  u32 bs;
  u32 bm;
  u32 buflen;
  char *buf;
  struct stdio_file *next;
  int popen_kludge;
  unsigned char ungetbuf;
  char ungotten;
};

typedef struct stdio_file FILE;

FILE* fopen(const char* filename, const char* mode);
int fclose(FILE* file);

int putchar(int c);
int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char *buf, const char *fmt, ...);
int snprintf(char *buf, ___size_t size, const char *fmt, ...);
int vsnprintf(char *buf, ___size_t size, const char *fmt, va_list args);
int asprintf(char **str, const char *format, ...);
int printf(const char *format, ...);
int _vfprintf(FILE *s, const char *fmt, va_list args, unsigned int mode_flags);
int fprintf(FILE *stream, const char *fmt, ...);

__END_DECLS

#endif

