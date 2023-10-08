/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

void srand(unsigned seed)
{
  static struct random_data rand_buf;
  static char rand_state[2048];
  rand_buf.state = (i32*)rand_state;
  srandom_r(seed, &rand_buf);
}

