/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngusyst/random.h"

static i32
randtbl[DEG_3 + 1] =
{
  TYPE_3,
  -1726662223, 379960547, 1735697613, 1040273694, 1313901226,
  1627687941, -179304937, -2073333483, 1780058412, -1989503057,
  -615974602, 344556628, 939512070, -1249116260, 1507946756,
  -812545463, 154635395, 1388815473, -1926676823, 525320961,
  -1009028674, 968117788, -123449607, 1284210865, 435012392,
  -2017506339, -911064859, -370259173, 1132637927, 1398500161,
  -205601318,
};

long int
random(void)
{
  i32* result = 0;
  struct random_data unsafe_state =
  {
    .fptr = &randtbl[SEP_3 + 1],
    .rptr = &randtbl[1],
    .state = &randtbl[1],

    .rand_type = TYPE_3,
    .rand_deg = DEG_3,
    .rand_sep = SEP_3,

    .end_ptr = &randtbl[sizeof (randtbl) / sizeof (randtbl[0])]
  };

  i32* state = 0;
  struct random_data *buf = &unsafe_state;

   if (buf == 0 || result == 0) {
     return -1;
   }

  state = buf->state;

  if (buf->rand_type == 0) {
    i32 val = ((state[0] * 1103515245U) + 12345U) & 0x7fffffff;
    state[0] = val;
    *result = val;
  }
  else {
    i32* fptr = buf->fptr;
    i32* rptr = buf->rptr;
    i32* end_ptr = buf->end_ptr;
    u32 val;

    val = *fptr += (u32) *rptr;
    *result = val >> 1;
    ++fptr;

    if (fptr >= end_ptr) {
      fptr = state;
      ++rptr;
    }
    else {
      ++rptr;
      if (rptr >= end_ptr) {
        rptr = state;
      }
    }
      buf->fptr = fptr;
      buf->rptr = rptr;
  }

  return *result;
}
