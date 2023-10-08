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
#include "stddef.h" /* for size_t */

#include <pthread.h>
#include <sys/mman.h>

typedef struct block_info
{
  int               size;
  struct block_info *next;
} block_info;

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

void*  malloc(size_t);
void*  calloc(size_t nmemb, size_t size);
void*  realloc(void *ptr, size_t size);
void   free(void *p);

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

void*         heap_allocate(size_t size);
void*         find_best_fit_from_bin_large(size_t size);
void*         mmap_new_memory(size_t size);
void*         alloc_large(size_t size);
void*         block_from_unused_heap(size_t size);
void*         memalign(size_t alignment, size_t s);
void*         align8(void *x);
block_info**  get_bin(size_t size);

__END_DECLS

#endif

