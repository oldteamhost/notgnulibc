/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strcpy(char* s1, const char* s2)
{
  char *save = s1;
  for (; (*s1 = *s2) != 0; ++s2, ++s1);
  return save;
}
