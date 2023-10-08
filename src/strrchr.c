/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strrchr(const char *s, int c)
{
  char *save;
  for (save = NULL;; ++s) {
    if (*s == c) {
      save = (char *)s;
    }
    if (*s == '\0') {
      return (save);
    }
  }
  /*TODO*/
}

