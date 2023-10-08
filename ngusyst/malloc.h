/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_MALLOC_H
#define NOTGNU_MALLOC_H

#include <pthread.h>
#include <unistd.h>
#include <mcheck.h>
#include <sys/mman.h>
#include <string.h>

#include "../limits.h"

typedef struct block_info
{
  int size;
  struct block_info *next;
} block_info;

void* malloc(size_t);
void* calloc(size_t nmemb, size_t size);
void* realloc(void *ptr, size_t size);
void* memalign(size_t alignment, size_t s);
void  free(void *p);

void* align8(void *x);
void* heap_allocate(size_t size);
void* find_best_fit_from_bin_large(size_t size);
void* mmap_new_memory(size_t size);
void* alloc_large(size_t size);
void* block_from_unused_heap(size_t size);
void  abortfn(enum mcheck_status status);

block_info** get_bin(size_t size);

#endif
