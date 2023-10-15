/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"

noreturn void __exit(int code)
{
  asm("movl %0, %%edi; call exit" : : "r"(code));
  while(1);
}
