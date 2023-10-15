/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngusyst/syscall.h"

long int ___syscall(long int number,
    long int a0, long int a1,
    long int a2, long int a3,
    long int a4, long int a5)
{
  long int result;
  asm volatile (
    "syscall"
    : "=a" (result)
    : "a" (number), "D" (a0), "S" (a1), "d" (a2), "r" (a3), "r" (a4), "r" (a5)
    : "rcx", "r11", "memory"
  );
  return result;
}

long int syscall(long int number, ...)
{
  va_list args;

  va_start (args, number);
  long int a0 = va_arg (args, long int);
  long int a1 = va_arg (args, long int);
  long int a2 = va_arg (args, long int);
  long int a3 = va_arg (args, long int);
  long int a4 = va_arg (args, long int);
  long int a5 = va_arg (args, long int);
  va_end (args);

  long int r = ___syscall(number, a0, a1, a2, a3, a4, a5);
  return r;
}
