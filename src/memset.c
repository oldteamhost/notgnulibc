/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

void*
memset(void* s, int c, u64 n)
{
  char* bb;

  for (bb = (char *)s; n--;) {
    *bb++ = c;
  }
  return (s);
}
