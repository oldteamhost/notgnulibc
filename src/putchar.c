/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdio.h"
#include "../unistd.h"

int putchar(int c)
{
  return (_write(1, &c, 1));
}
