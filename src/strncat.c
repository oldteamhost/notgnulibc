/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strncat(char* s1, const char* s2, u64 n)
{
  if (n != 0) {
    char *d = s1;
    const char *s = s2;

    while (*d != 0) {
      d++;
    }
    do {
      if ((*d = *s++) == '\0') {
        break;
      }
      d++;
    } while (--n != 0);
    *d = '\0';
  }
  return (s1);
}
