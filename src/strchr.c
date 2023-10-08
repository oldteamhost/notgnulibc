/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strchr(const char* s, int c)
{
  for (;; ++s) {
    if (*s == c) {
      return (char *)s;
    }
    if (*s == '\0') {
      return NULL;
    }
  }
}
