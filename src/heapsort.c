/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

#define SWAP(a, b, count, size, tmp) { \
  count = size; \
  do { \
  tmp = *a; \
  *a++ = *b; \
  *b++ = tmp; \
  } while (--count); \
}

#define COPY(a, b, count, size, tmp1, tmp2) { \
  count = size; \
  tmp1 = a; \
  tmp2 = b; \
  do { \
  *tmp1++ = *tmp2++; \
  } while (--count); \
}

#define CREATE(initval, nmemb, par_i, child_i, par, child, size, count, tmp) { \
  for (par_i = initval; (child_i = par_i * 2) <= nmemb; \
    par_i = child_i) { \
    child = base + child_i * size; \
    if (child_i < nmemb && compar(child, child + size) < 0) { \
      child += size; \
      ++child_i; \
    } \
    par = base + par_i * size; \
    if (compar(child, par) <= 0) { \
      break; \
    } \
    SWAP(par, child, count, size, tmp); \
  } \
}

#define SELECT(par_i, child_i, nmemb, par, child, size, k, count, tmp1, tmp2) { \
  for (par_i = 1; (child_i = par_i * 2) <= nmemb; par_i = child_i) { \
    child = base + child_i * size; \
    if (child_i < nmemb && compar(child, child + size) < 0) { \
      child += size; \
      ++child_i; \
    } \
    par = base + par_i * size; \
    COPY(par, child, count, size, tmp1, tmp2); \
  } \
  for (;;) { \
    child_i = par_i; \
    par_i = child_i / 2; \
    child = base + child_i * size; \
    par = base + par_i * size; \
    if (child_i == 1 || compar(k, par) < 0) { \
      COPY(child, k, count, size, tmp1, tmp2); \
      break; \
    } \
    COPY(child, par, count, size, tmp1, tmp2); \
  } \
}

int
heapsort(void *vbase, size_t nmemb, size_t size, int (*compar)
    (const void *, const void *))
{
  size_t cnt, i, j, l;
  char tmp, *tmp1, *tmp2;
  char *base, *k, *p, *t;

  if (nmemb <= 1) {
    return (0);
  }

  if (!size) {
    return (-1);
  }

  if ((k = malloc(size)) == NULL) {
    return (-1);
  }

  base = (char *)vbase - size;
  for (l = nmemb / 2 + 1; --l;) {
    CREATE(l, nmemb, i, j, t, p, size, cnt, tmp);
  }

  while (nmemb > 1) {
    COPY(k, base + nmemb * size, cnt, size, tmp1, tmp2);
    COPY(base + nmemb * size, base + size, cnt, size, tmp1, tmp2);
    --nmemb;
    SELECT(i, j, nmemb, t, p, size, k, cnt, tmp1, tmp2);
  }

  free(k);
  return (0);
}
