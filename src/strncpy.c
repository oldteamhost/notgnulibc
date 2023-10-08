/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strncpy(char* s1, const char* s2, u64 n)
{
  if (n != 0) {
    char *d = s1;
    const char *s = s2;
    do {
      if ((*d++ = *s++) == '\0') {
        while (--n != 0) {
          *d++ = '\0';
        }
        break;
      }
    } while (--n != 0);
  }
  return (s1);
}
