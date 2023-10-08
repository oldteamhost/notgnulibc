/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

typedef long word;
#define wsize sizeof(word)
#define wmask (wsize - 1)

void*
memcpy(void* s1, const void* s2, u64 length)
{
  char *dst = s1;
  const char *src = s2;
  u64 t;

  if (length == 0 || dst == src) { /* nothing to do */
    goto done;
  }

#define TLOOP(s) if (t) TLOOP1(s)
#define TLOOP1(s) do { s; } while (--t)

  if ((u64)dst < (u64)src) {
    t = (u64)src; /* only need low bits */
    if ((t | (u64)dst) & wmask) {
      if ((t ^ (u64)dst) & wmask || length < wsize)
        t = length;
      else {
        t = wsize - (t & wmask);
      }
      length -= t;
      TLOOP1(*dst++ = *src++);
    }
    t = length / wsize;
    TLOOP(*(word *)(void *)dst = *(const word *)(const void *)src;
      src += wsize; dst += wsize);
    t = length & wmask;
    TLOOP(*dst++ = *src++);
  }
  else {
    src += length;
    dst += length;
    t = (u64)src;
    if ((t | (u64)dst) & wmask) {
      if ((t ^ (u64)dst) & wmask || length <= wsize) {
        t = length;
      }
      else {
        t &= wmask;
      }
      length -= t;
      TLOOP1(*--dst = *--src);
    }
    t = length / wsize;
    TLOOP(src -= wsize; dst -= wsize;
        *(word *)(void *)dst = *(const word *)(const void *)src);
    t = length & wmask;
    TLOOP(*--dst = *--src);
  }
done:
  return (s1);
}
