/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"

int _close(int fd) {
  int res;
  asm (
#ifdef _KERNEL86
    "movl $6, %%eax\n"
    "movl %1, %%ebx\n"
    "int $0x80"
    : "=a" (res)
    : "g" (fd)
    : "ebx"
#else
    "movq $3, %%rax\n"
    "movq %1, %%rdi\n"
    "syscall"
    : "=a" (res)
    : "g" (fd)
    : "rdi"
#endif
  );
  return res;
}
