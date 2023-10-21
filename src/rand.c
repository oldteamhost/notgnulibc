/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

static __u_long next = 1;

static int
do_rand(unsigned long *ctx)
{
  long hi, lo, x;
  x = (*ctx % 0x7ffffffe) + 1;
  hi = x / 127773;
  lo = x % 127773;
  x = 16807 * lo - 2836 * hi;
  if (x < 0) {
    x += 0x7fffffff;
  }
  x--;
  *ctx = x;
  return (x);
}

int
rand(void)
{
  return (do_rand(&next));
}

void
srand(unsigned seed)
{
  next = seed;
}

