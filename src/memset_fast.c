/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

void* memset_fast(void* b, int c, u64 len)
{
#define OPSIZ 8
#define OP_T_THRES 16
  typedef unsigned long long int op_t;
  long int dstp = (long int) b;

  if (len >= 8) {
    u64 xlen;
    op_t cccc;

    cccc  = (unsigned char) c;
    cccc |= cccc << 8;
    cccc |= cccc << 16;

    if (OPSIZ > 4) {
      cccc |= (cccc << 16) << 16;
    }
    while (dstp % OPSIZ != 0) {
      ((u8 *) dstp)[0] = c;
      dstp += 1;
      len -= 1;
    }

    xlen = len / (OPSIZ * 8);
    while (xlen > 0) {
      ((op_t *) dstp)[0] = cccc;
      ((op_t *) dstp)[1] = cccc;
      ((op_t *) dstp)[2] = cccc;
      ((op_t *) dstp)[3] = cccc;
      ((op_t *) dstp)[4] = cccc;
      ((op_t *) dstp)[5] = cccc;
      ((op_t *) dstp)[6] = cccc;
      ((op_t *) dstp)[7] = cccc;

      dstp += 8 * OPSIZ;
      xlen -= 1;
    }
      len  %= OPSIZ * 8;
      xlen = len / OPSIZ;
      while (xlen > 0) {
        ((op_t *) dstp)[0] = cccc;
        dstp += OPSIZ;
        xlen -= 1;
      }
      len %= OPSIZ;
  }
  while (len > 0) {
    ((u8*) dstp)[0] = c;
    dstp += 1;
    len  -= 1;
  }
  return (b);
}
