/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

/* from compiler */
extern char **__environ;

char*
getenv(const char *name)
{
  if (__environ == NULL || name[0] == '\0') {
    return NULL;
  }

  size_t len = strlen(name);
  for (char **ep = __environ; *ep != NULL; ++ep) {
    if (name[0] == (*ep)[0] && strncmp (name, *ep, len) == 0
        && (*ep)[len] == '=') {
      return *ep + len + 1;
    }
  }
  return NULL;
}
