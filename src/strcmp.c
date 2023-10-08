/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

int
strcmp(const char* s1, const char* s2)
{
  while (*s1 == *s2++) {
    if (*s1++ == '\0') {
      return (0);
    }
  }
  return (*(const u8*)s1 - *(const u8*)(s2 - 1));
}
