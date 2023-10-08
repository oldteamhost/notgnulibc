/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * string.h - contains functions for working
 * with strings.
*/

#ifndef NOTGNU_STRING_H
#define NOTGNU_STRING_H

#include "ngubits/types.h"
#include "ngusyst/cdefs.h"
#include "ctype.h"
#include "limits.h"

#ifndef NULL /* NULL casual macros */
  #define NULL ((void *) 0)
#endif

__BEGIN_DECLS

/*TODO fucking locale*/
int   strcoll(const char *s1, const char *s2);
char* strrchr(const char *s, int c);
u64   strxfrm(char* s1, const char* s2, u64 n);

/* NO ANSI */
void* memset_fast(void* b, int c, u64 len); /* for big datablocks */
void* memccpy(void* t, const void* f, int c, u64 n);
u64   strlcpy(char* dst, const char* src, u64 dlen);
char* strtok_r(char* str, const char* delim, char** sptr);

/* ANSI C */
void* memset(void* s, int c, u64 n);
void* memchr(const void* s, int c, u64 n);
int   memcmp(const void *s1, const void *s2, u64 n);
void* memcpy(void* s1, const void* s2, u64 n);
u64   strlen(const char* s);
char* strchr(const char* s, int c);
char* strcpy(char* s1, const char* s2);
int   strcmp(const char* s1, const char* s2);
int   strncmp(const char* s1, const char* s2, u64 n);
char* strncpy(char* s1, const char* s2, u64 n);
char* strstr(const char* s1, const char* s2);
char* strtok(char* s1, const char* s2);
char* strncat(char* s1, const char* s2, u64 n);
char* strpbrk(const char* s1, const char* s2);
u64   strspn(const char* s1, const char* s2);
u64   strcspn(const char* s1, const char* s2);
char* strerror(int errnum);
char* strcat(char* s1, const char* s2);

#define memmove(s1, s2, n)  memcpy(s1, s2, n)
#define bcopy(s1, s2, n)    memcpy(s1, s2, n)

__END_DECLS

#endif
