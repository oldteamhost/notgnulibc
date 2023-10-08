/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

#define COMPAR(x,y) \
  compar(x, y)

void*
bsearch(const void *key, const void *base0, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
  const char *base = base0;
  size_t lim;
  int cmp;
  const void *p;

  for (lim = nmemb; lim != 0; lim >>= 1) {
    p = base + (lim >> 1) * size;
    cmp = COMPAR(key, p);
    if (cmp == 0) {
      return ((void *)p);
    }
    if (cmp > 0) {
      base = (char *)p + size;
      lim--;
    }
  }
  return (NULL);
}
