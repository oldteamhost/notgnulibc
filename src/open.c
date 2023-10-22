/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngubits/fcntl.h"

int open(const char *filename, int flags, int mode)
{
  int fd;
  asm (
#ifdef _KERNEL86
    "movl $5, %%eax\n\t"
    "movl %1, %%ebx\n\t"
    "movl %2, %%ecx\n\t"
    "movl %3, %%edx\n\t"
    "int $0x80\n\t"
    : "=a" (fd)
    : "m" (filename), "m" (flags), "m" (mode)
#else
    "mov $2, %%rax\n"
    "mov %1, %%rdi\n"
    "mov %2, %%rsi\n"
    "mov %3, %%rdx\n"
    "syscall\n"
    : "=a" (fd)
    : "m" (filename), "m" (flags), "m" (mode)
#endif
  );
  return fd;
}
