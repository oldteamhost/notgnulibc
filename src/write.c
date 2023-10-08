/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"

size_t ngu_write(int fd, const void *dest, size_t bcount)
{
  size_t bytes_written;

  asm
  (
#ifdef _KERNEL86
   "movl $4, %%eax\n"
    "movl %[fd], %%ebx\n"
    "movl %[buf], %%ecx\n"
    "movl %[count], %%edx\n"
    "int $0x80\n"
    : "=a" (result)
    : [fd] "g" (fd), [buf] "g" (buf), [count] "g" (count)
    : "%ebx", "%ecx", "%edx", "memory"
#else
    "movq $1, %%rax \n"
    "movq %[fd], %%rdi \n"
    "movq %[dest], %%rsi \n"
    "movq %[bcount], %%rdx \n"
    "syscall \n"
    : "=a" (bytes_written)
    : [fd] "g" (fd), [dest] "g" (dest), [bcount] "g" (bcount)
    : "%rdi", "%rsi", "%rdx", "memory"
#endif
  );
  return bytes_written;
}

