/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

ldiv_t
ldiv(long num, long denom)
{
  ldiv_t r;

  r.quot = num / denom;
  r.rem = num % denom;

  return (r);
}

