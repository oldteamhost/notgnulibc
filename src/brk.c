/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"

void* _brk(void* nbrk)
{
  int ret = 0;
  void* old_brk;

  __asm__ __volatile__ (
#ifdef _KERNEL86
      "mov $12, %%rax\n"
      "syscall\n"
      "test %%rax, %%rax\n"
      "jnz 1f\n"
      "mov %%rdi, %0\n"
      "1:\n"
      : "=r" (old_brk)
      : "D" (nbrk)
#else
    "mov $12, %%rax\n"
    "syscall\n"
    "test %%rax, %%rax\n"
    "jnz 1f\n"
    "mov %%rdi, %0\n"
    "1:\n"
    : "=r" (old_brk)
    : "D" (nbrk)
#endif
  );

  if (ret < 0) {
    return (void*)-1;
  }
  return old_brk;
}

