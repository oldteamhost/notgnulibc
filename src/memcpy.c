/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"
#include "../ngubits/types.h"

typedef long word;
#define wsize sizeof(word)
#define wmask (wsize - 1)

void*
memcpy(void* s1, const void* s2, u64 length)
{
  char *dst;
  const char *src;
  u64 t;

  dst = s1;
  src = s2;

  if (length == 0 || dst == src) {
    goto done;
  }
#define TLOOP(s) if (t) TLOOP1(s)
#define TLOOP1(s) do { s; } while (--t)
  if ((unsigned long)dst < (unsigned long)src) {
    t = (u64)src;
    if ((t | (u64)dst) & wmask) {
      if ((t ^ (u64)dst) & wmask || length < wsize) {
        t = length;
      }
      else {
      t = wsize - (t & wmask);
    }
    length -= t;
    TLOOP1(*dst++ = *src++);
  }
  t = length / wsize;
  TLOOP(*(word *)dst = *(const word *)src; src += wsize;
  dst += wsize);
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
        *(word *)dst = *(const word *)src);
    t = length & wmask;
    TLOOP(*--dst = *--src);
  }
done:
  return (s1);
}
