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

void* realloc(void* p, size_t size);
void* malloc(size_t size);
void* calloc(size_t number, size_t size);

void free(void* ptr);

#endif
