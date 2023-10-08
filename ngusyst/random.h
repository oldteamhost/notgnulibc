/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_RANDOM_H
#define NOTGNU_RANDOM_H

#include "../ngubits/types.h"
#include "cdefs.h"

#ifndef _set_errno_
  #define _set_errno_(val) errno = (val)
#endif

#define RAND_MAX 0x7fffffff

#define TYPE_0   0
#define BREAK_0  8
#define DEG_0    0
#define SEP_0    0

/* x**7 + x**3 + 1.  */
#define TYPE_1  1
#define BREAK_1 32
#define DEG_1   7
#define SEP_1   3

/* x**15 + x + 1.  */
#define TYPE_2  2
#define BREAK_2 64
#define DEG_2   15
#define SEP_2   1

/* x**31 + x**3 + 1.  */
#define TYPE_3  3
#define BREAK_3 128
#define DEG_3   31
#define SEP_3   3

/* x**63 + x + 1.  */
#define TYPE_4  4
#define BREAK_4 256
#define DEG_4   63
#define SEP_4   1

__BEGIN_DECLS

struct random_data
{
  i32 *fptr;      /* Front pointer.  */
  i32 *rptr;      /* Rear pointer.  */
  i32 *state;     /* Array of state values.  */
  int rand_type;  /* Type of random number generator.  */
  int rand_deg;   /* Degree of random number generator.  */
  int rand_sep;   /* Distance between front and rear.  */
  i32 *end_ptr;   /* Pointer behind state table.  */
};

int       random_r(struct random_data *buf, i32 *result);
int       srandom_r(u32 seed, struct random_data *buf);
long int  random(void);
int       rand_r(u32 *seed);

__END_DECLS

#endif


