/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

void*
memchr(const void* s, int c, u64 n)
{
  if (n != 0) {
    const u8 *p = s;
    do {
      if (*p++ == (unsigned char)c)
        return ((void *)(unsigned long)(p - 1));
    } while (--n != 0);
  }
  return (NULL);
}
