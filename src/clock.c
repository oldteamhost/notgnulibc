/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../time.h"

clock_t
clock(void)
{
  struct timeval tv;

  if (gettimeofday(&tv, NULL) == -1) {
    return (clock_t)-1;
  }

  return (tv.tv_sec * CLOCKS_PER_SEC) + ((tv.tv_usec * CLOCKS_PER_SEC) / 1000000);
}
