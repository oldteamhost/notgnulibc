/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

static const unsigned long mask01 = 0x0101010101010101;
static const unsigned long mask80 = 0x8080808080808080;

#define LONGPTR_MASK (sizeof(long) - 1)

#define testbyte(x) do {    \
  if (p[x] == '\0')         \
    return (p - s + x);   \
} while (0)

u64
strlen(const char* s)
{
  const char *p;
  const unsigned long *lp;
  long va, vb;

  lp = (const unsigned long *)((u64)s & ~LONGPTR_MASK);
  va = (*lp - mask01);
  vb = ((~*lp) & mask80);
  lp++;
  if (va & vb) {
    for (p = s; p < (const char *)lp; p++) {
      if (*p == '\0') {
        return (p - s);
      }
    }
  }
  for (;; lp++) {
    va = (*lp - mask01);
    vb = ((~*lp) & mask80);
    if (va & vb) {
      p = (const char *)(lp);
      testbyte(0);
      testbyte(1);
      testbyte(2);
      testbyte(3);
      testbyte(4);
      testbyte(5);
      testbyte(6);
      testbyte(7);
    }
  }
  return 0;
}

