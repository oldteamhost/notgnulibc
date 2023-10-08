/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

#define IDX(c) ((u8)(c) / LONG_BIT)
#define BIT(c) ((unsigned long)1 << ((u8)(c) % LONG_BIT))

u64
strcspn(const char* s1, const char* s2)
{
  const char *_s1;
  unsigned long bit;
  unsigned long tbl[(UCHAR_MAX + 1) / LONG_BIT];
  int idx;

  if(*s1 == '\0'){
    return (0);
  }
#if LONG_BIT == 64 /* always better to unroll on 64-bit architectures */
  tbl[0] = 1;
  tbl[3] = tbl[2] = tbl[1] = 0;
#else
  for (tbl[0] = idx = 1; idx < sizeof(tbl) / sizeof(tbl[0]); idx++) {
    tbl[idx] = 0;
  }
#endif
  for (; *s2 != '\0'; s2++) {
    idx = IDX(*s2);
    bit = BIT(*s2);
    tbl[idx] |= bit;
  }

  for(_s1 = s1;; _s1++) {
    idx = IDX(*_s1);
    bit = BIT(*_s1);
    if ((tbl[idx] & bit) != 0) {
      break;
    }
  }
  return (_s1 - s1);
}
