/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_MALLOC_H
#define NOTGNU_MALLOC_H

#include "../limits.h"
#include "../stddef.h"
#include "../string.h"
#include "../unistd.h"
#include "cdefs.h"

#include <sys/mman.h>
#include <pthread.h>

typedef struct block_info
{
  int size;
  struct block_info *next;
} block_info;

__BEGIN_DECLS

void* malloc(size_t);
void* calloc(size_t nmemb, size_t size);
void* realloc(void *ptr, size_t size);

void free(void *p);

void* align8(void *x);
block_info** get_bin(size_t size);
void* heap_allocate(size_t size);
void* find_best_fit_from_bin_large(size_t size);
void* mmap_new_memory(size_t size);
void* alloc_large(size_t size);
void* block_from_unused_heap(size_t size);
void* memalign(size_t alignment, size_t s);

__END_DECLS

#endif
