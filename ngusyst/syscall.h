/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_SYSCALL_H
#define NOTGNU_SYSCALL_H

#include "../stdarg.h"
#include <sys/syscall.h> /* for calls (linux header) */

long int ___syscall(long int number, long int a0, long int a1, long int a2,
    long int a3, long int a4, long int a5);

long int syscall(long int number, ...);

#endif

