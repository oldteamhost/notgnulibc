/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_WORDSIZE_H
#define NOTGNU_WORDSIZE_H

/* To customize libraries for a 32-bit processor,
 * specify the -D_KERNEL86 flag at compile time */

/* 64 bit system (default) */
#ifdef _KERNEL86
  #include "wordsize86.h"
#else
  #include "wordsize64.h"
#endif


#endif
