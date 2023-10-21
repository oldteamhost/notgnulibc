/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_STDLIB_H
#define NOTGNU_STDLIB_H

#include "ngusyst/cdefs.h"
#include "stdnoreturn.h"
#include "ngusyst/random.h"

#include "ctype.h"
#include "limits.h"
#include "string.h"

#include "ngusyst/malloc.h" /* for malloc and other */
#include "stddef.h" /* for size_t */

typedef struct
{
  int quot, rem;
} div_t;

typedef struct
{
  long int quot, rem;
} ldiv_t;

__BEGIN_DECLS

extern void exit(int code);
extern void abort(void);

int    atoi(const char* s);
long   atol(const char* s);
double atof(const char* s);

int    rand(void);
void   srand(unsigned seed);

char* getenv(const char* name);
int _system(const char* command); /* TODO */
noreturn void __exit(int code);
noreturn void __abort(void);

#define abs(x) \
  ((x) < 0 ? -(x) : (x))
#define labs(j) \
  ((j) < 0 ? -(j) : (j))

div_t  div(int num, int denom);
ldiv_t ldiv(long num, long denom);

void*
bsearch(const void *key, const void *base0, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

int
heapsort(void *vbase, size_t nmemb, size_t size, int (*compar)
    (const void *, const void *));

void
qsort(void *base, size_t nitems, size_t size, int (*compar)
    (const void *, const void*));

double strtod(const char* str, char** endptr);

unsigned long
strtoul(const char* nptr, char** endptr, int base);

long
strtol(const char* nptr, char** endptr, int base);

__END_DECLS

#endif

