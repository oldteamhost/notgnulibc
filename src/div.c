/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

div_t
div(int num, int denom)
{
  div_t result;

  result.quot = num / denom;
  result.rem = num % denom;

  return result;
}
