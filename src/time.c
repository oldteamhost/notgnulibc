/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../time.h"

time_t
time(time_t* timer)
{
  struct timeval tv;
  gettimeofday(&tv, NULL);

  if (timer != NULL) {
    *timer = tv.tv_sec;
  }
  return tv.tv_sec;
}

