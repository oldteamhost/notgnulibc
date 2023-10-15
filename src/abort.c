/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"

noreturn void __abort(void)
{
  asm volatile(
#ifdef __KERNEL86
    "mov $1, %eax\n"
    "mov $1, %ebx\n"
    "int $0x80"
#else
    "mov $60, %rax\n"
    "mov $1, %rdi\n"
    "syscall"
#endif
  );
  while (1);
}
