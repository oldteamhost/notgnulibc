/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_STDLIB_H
#define NOTGNU_STDLIB_H

#include "limits.h"
#include "string.h"
#include "ngusyst/cdefs.h"
#include "ngusyst/random.h"
#include "ctype.h"

#include "stddef.h" /* for size_t */

typedef struct
{
  int quot, rem;
} div_t;

typedef struct
{
  long int quot, rem;
} ldiv_t;

#define abs(x) \
  ((x) < 0 ? -(x) : (x))

#define labs(j) \
  ((j) < 0 ? -(j) : (j))

__BEGIN_DECLS

int   rand(void);
void  srand(unsigned seed);

int  atoi(const char* s);
long atol(const char* s);

char*  getenv(const char* name);
div_t  div(int num, int denom);
ldiv_t ldiv(long num, long denom);

void*
bsearch(const void *key, const void *base0, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

unsigned long
strtoul(const char* nptr, char** endptr, int base);

long
strtol(const char* nptr, char** endptr, int base);

__END_DECLS

#endif

