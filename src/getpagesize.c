/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"


int __getpagesize(void)
{
#include <unistd.h>
  /* TODO */
  return sysconf(_SC_PAGESIZE);
}
