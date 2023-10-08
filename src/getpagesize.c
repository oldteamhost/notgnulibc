/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"

int ngu_getpagesize(void)
{
  int result;
  asm volatile(
    "mov $158, %%rax\n\t"
    "mov $0, %%rdi\n\t"
    "syscall\n\t"
    "mov %%eax, %0"
    : "=r" (result)
    :
    : "rax", "rdi"
  );
  return result;
}

