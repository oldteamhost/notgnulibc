/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

int
memcmp(const void *s1, const void *s2, u64 n)
{
  if (n) {
    const u8 *p1 = s1, *p2 = s2;
    do {
      if (*p1++ != *p2++) {
        return (*--p1 - *--p2);
      }
    } while (--n != 0);
  }
  return (0);
}
