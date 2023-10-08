/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strstr(const char* s1, const char* s2)
{
  char c, sc;
  u64 len;

  if ((c = *s2++) != 0) {
    len = strlen(s2);
    do {
      do {
        if ((sc = *s1++) == '\0') {
          return (NULL);
        }
      } while (sc != c);
    } while (strncmp(s1, s2, len) != 0);
    s1--;
  }

  return (char *)s1;
}
