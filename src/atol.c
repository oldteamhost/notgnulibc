/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

long
atol(const char* s)
{
  return strtol(s, (char**)NULL, 10);
}

