/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strtok(char* s1, const char* s2)
{
  static char* last;
  return (strtok_r(s1, s2, &last));
}
