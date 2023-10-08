/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

void* /* ngu_memCCpy */
memccpy(void* t, const void* f, int c, u64 n)
{
  if (n) {
    u8* tp = t;
    const u8* fp = f;
    u8 uc = c;
    do {
      if ((*tp++ = *fp++) == uc) {
        return (tp);
      }
    } while (--n != 0);
  }
  return (0);
}
