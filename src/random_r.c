/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngusyst/random.h"

int
random_r(struct random_data *buf, i32 *result)
{
  i32* state;

   if (buf == 0 || result == 0)
    goto fail;

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
  return 0;
 fail:
  return -1;
}
