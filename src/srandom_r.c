/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngusyst/random.h"

int
srandom_r(u32 seed, struct random_data *buf)
{
  int type;
  i32 *state;
  long int i;
  i32 word;
  i32 *dst;
  int kc;

  if (buf == 0) {
    goto fail;
  }
  type = buf->rand_type;
  if ((u32) type >= 5)
    goto fail;

  state = buf->state;
  if (seed == 0)
    seed = 1;
  state[0] = seed;
  if (type == TYPE_0)
    goto done;

  dst = state;
  word = seed;
  kc = buf->rand_deg;
  for (i = 1; i < kc; ++i)
    {
      long int hi = word / 127773;
      long int lo = word % 127773;
      word = 16807 * lo - 2836 * hi;
      if (word < 0)
  word += 2147483647;
      *++dst = word;
    }

  buf->fptr = &state[buf->rand_sep];
  buf->rptr = &state[0];
  kc *= 10;
  while (--kc >= 0)
    {
      i32 discard;
      (void) random_r (buf, &discard);
    }

 done:
  return 0;
 fail:
  return -1;
}
