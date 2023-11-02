/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

#define min(a, b) (a) < (b) ? a : b

#define SWAPTYPE_BYTEV  1
#define SWAPTYPE_INTV   2
#define SWAPTYPE_LONGV  3
#define SWAPTYPE_INT    4
#define SWAPTYPE_LONG   5

#define TYPE_ALIGNED(TYPE, a, es) \
  (((char *)a - (char *)0) % sizeof(TYPE) == 0 && es % sizeof(TYPE) == 0)

#define swapcode(TYPE, parmi, parmj, n) {  \
  size_t i = (n) / sizeof (TYPE);          \
  TYPE *pi = (TYPE *) (parmi);             \
  TYPE *pj = (TYPE *) (parmj);             \
  do {                                     \
    TYPE t = *pi;                          \
    *pi++ = *pj;                           \
    *pj++ = t;                             \
  } while (--i > 0);                       \
}

static __inline void
swapfunc(char *a, char *b, size_t n, int swaptype)
{
  switch (swaptype) {
    case SWAPTYPE_INT:
    case SWAPTYPE_INTV:
      swapcode(int, a, b, n);
      break;
    case SWAPTYPE_LONG:
    case SWAPTYPE_LONGV:
      swapcode(long, a, b, n);
      break;
    default:
      swapcode(char, a, b, n);
      break;
  }
}

#define swap(a, b)	do { \
  switch (swaptype) { \
    case SWAPTYPE_INT: { \
      int t = *(int *)(a); \
      *(int *)(a) = *(int *)(b); \
      *(int *)(b) = t; \
      break; \
    }\
    case SWAPTYPE_LONG: { \
      long t = *(long *)(a);         \
      *(long *)(a) = *(long *)(b);   \
      *(long *)(b) = t;              \
      break;                         \
    }                                \
    default:                         \
      swapfunc(a, b, es, swaptype);  \
  }                                  \
} while (0)

#define vecswap(a, b, n) if ((n) > 0) swapfunc(a, b, n, swaptype)

static __inline char*
med3(char *a, char *b, char *c, int (*cmp)(const void *, const void *))
{
  return cmp(a, b) < 0 ?
    (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
    :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
}

static void
introsort(char *a, size_t n, size_t es, size_t maxdepth, int swaptype,
    int (*cmp)(const void *, const void *))
{
  char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
  int cmp_result;
  size_t r, s;

loop:
  if (n < 7) {
    for (pm = a + es; pm < a + n * es; pm += es)
      for (pl = pm; pl > a && cmp(pl - es, pl) > 0;
        pl -= es)
          swap(pl, pl - es);
    return;
  }
  if (maxdepth == 0) {
    if (heapsort(a, n, es, cmp) == 0)
    return;
  }
  maxdepth--;
  pm = a + (n / 2) * es;
  if (n > 7) {
    pl = a;
    pn = a + (n - 1) * es;
    if (n > 40) {
      s = (n / 8) * es;
      pl = med3(pl, pl + s, pl + 2 * s, cmp);
      pm = med3(pm - s, pm, pm + s, cmp);
      pn = med3(pn - 2 * s, pn - s, pn, cmp);
    }
    pm = med3(pl, pm, pn, cmp);
  }
  swap(a, pm);
  pa = pb = a + es;
  pc = pd = a + (n - 1) * es;
  for (;;) {
    while (pb <= pc && (cmp_result = cmp(pb, a)) <= 0) {
      if (cmp_result == 0) {
        swap(pa, pb);
        pa += es;
      }
      pb += es;
    }
    while (pb <= pc && (cmp_result = cmp(pc, a)) >= 0) {
      if (cmp_result == 0) {
        swap(pc, pd);
        pd -= es;
      }
      pc -= es;
    }
    if (pb > pc) {
      break;
    }
    swap(pb, pc);
    pb += es;
    pc -= es;
  }

  pn = a + n * es;
  r = min(pa - a, pb - pa);
  vecswap(a, pb - r, r);
  r = min(pd - pc, pn - pd - es);
  vecswap(pb, pn - r, r);

  r = pb - pa;
  s = pd - pc;
  if (r < s) {
    if (s > es) {
      if (r > es) {
        introsort(a, r / es, es, maxdepth,
        swaptype, cmp);
      }
      a = pn - s;
      n = s / es;
      goto loop;
    }
  }
  else {
    if (r > es) {
      if (s > es) {
        introsort(pn - s, s / es, es, maxdepth, swaptype, cmp);
      }
      n = r / es;
      goto loop;
    }
  }
}

void
qsort(void *base, size_t nitems, size_t size, int (*compar)
    (const void *, const void*))
{
  size_t i, maxdepth = 0;
  int swaptype;

  for (i = nitems; i > 0; i >>= 1) {
    maxdepth++;
  }
  maxdepth *= 2;

  if (TYPE_ALIGNED(long, base, size)) {
    swaptype = size == sizeof(long) ? SWAPTYPE_LONG : SWAPTYPE_LONGV;
  }
  else if (sizeof(int) != sizeof(long) && TYPE_ALIGNED(int, base, size)) {
    swaptype = size == sizeof(int) ? SWAPTYPE_INT : SWAPTYPE_INTV;
  }
  else {
    swaptype = SWAPTYPE_BYTEV;
  }
  introsort(base, nitems, size, maxdepth, swaptype, compar);
}
