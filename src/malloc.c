/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngusyst/malloc.h"

#define META_BLOCK_SIZE 20
#define align4(x) (((((x)-1) >> 2) << 2) + 4)

typedef struct meta_block *meta_ptr;

void *base = NULL;

struct meta_block
{
  int free;
  size_t size;
  meta_ptr next, prev;
  void *ptr;
  char data[1];
};

meta_ptr find_suitable_block(meta_ptr *last, size_t size)
{
  meta_ptr b = base;
  while (b && !(b->free && b->size >= size)) {
    *last = b;
    b = b->next;
  }
  return *last;
}

void split_space(meta_ptr block, size_t size)
{
  meta_ptr new_block;
  new_block = (struct meta_block*)block->data + size;
  new_block->size = block->size - size - META_BLOCK_SIZE;
  new_block->next = block->next;
  new_block->free = 1;
  new_block->ptr = new_block->data;
  new_block->prev = block;
  block->next = new_block;
  block->size = size;
  if (new_block->next) {
    new_block->next->prev = new_block;
  }
}

meta_ptr extend_heap(meta_ptr last, size_t size)
{
  meta_ptr old_break, new_break;
  old_break = _sbrk(0);
  new_break = _sbrk(META_BLOCK_SIZE + size);
  if (new_break == (void *)-1) {
    return NULL;
  }
  old_break->size = size;
  old_break->free = 0;
  old_break->next = NULL;
  old_break->prev = NULL;
  old_break->ptr = old_break->data;
  if (last) {
    last->next = old_break;
  }
  return (old_break);
}

meta_ptr merge_blocks(meta_ptr block)
{
  if (block->next && block->next->free) {
    block->size += META_BLOCK_SIZE + block->next->size;
    block->next = block->next->next;
  }
  if (block->next) {
    block->next->prev = block;
  }
  return block;
}

meta_ptr get_block_addr(void *p)
{
  char *tmp = p;
  tmp = tmp - META_BLOCK_SIZE;
  p = tmp;
  return (p);
}

int is_addr_valid(void *p)
{
  if (base) {
    if (p > base && p < _sbrk(0)) {
      return (p == get_block_addr(p)->ptr);
    }
  }
  return 0;
}

void free(void *ptr)
{
  if (is_addr_valid(ptr)) {
    meta_ptr block = get_block_addr(ptr);
    block->free = 1;
    if (block->prev && block->prev->free) {
      block = merge_blocks(block->prev);
    }

    if (block->next) {
      block = merge_blocks(block);
    }
    else {
      if (block->prev) {
        block->prev->next = NULL;
      }
      else {
        base = NULL;
      }
      _brk(block);
    }
  }
}

void *calloc(size_t number, size_t size)
{
  size_t *new;
  size_t s, i;

  new = malloc(number * size);

  if (new) {
    s = align4(number * size) << 2;
    for (i = 0; i < s; i++) {
      new[i] = 0;
    }
  }
  return new;
}

void *malloc(size_t size)
{
  meta_ptr block, last;
  size_t s = align4(size);
  if (base) {
    last = base;
    block = find_suitable_block(&last, s);
    if (block) {
      if (block->size - s >= (META_BLOCK_SIZE + 4)) {
        split_space(block, s);
      }
      block->free = 0;
    }
    else {
      block = extend_heap(last, s);
      if (!block) {
        return NULL;
      }
    }
  }
  else {
    block = extend_heap(NULL, s);
    if (!block) {
      return NULL;
    }
    base = block;
  }
  return block->data;
}
