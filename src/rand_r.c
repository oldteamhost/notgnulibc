/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngusyst/random.h"

int
rand_r(u32 *seed)
{
  u32 next = *seed;
  int result;

  next *= 1103515245;
  next += 12345;
  result = (u32) (next / 65536) % 2048;

  next *= 1103515245;
  next += 12345;
  result <<= 10;
  result ^= (u32) (next / 65536) % 1024;

  next *= 1103515245;
  next += 12345;
  result <<= 10;
  result ^= (u32) (next / 65536) % 1024;

  *seed = next;
  return result;
}
