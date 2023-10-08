/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

int
strncmp(const char* s1, const char* s2, u64 n)
{
  if (n == 0) {
    return (0);
  }
  do {
    if (*s1 != *s2++) {
      return (*(const u8*)s1 -
          *(const u8*)(s2 - 1));
    }
    if (*s1++ == '\0') {
      break;
    }
  } while (--n != 0);
  return (0);
}
