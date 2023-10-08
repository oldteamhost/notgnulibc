/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"
#include "../string.h"
#include "../ngubits/types.h"

static size_t maxheap, heapsize = 0;
static void *heapbased;

char *
sbrk(int incr)
{
  char *ret;
  if (heapbased == 0) {
    return NULL;
  }
  if ((heapsize + incr) <= maxheap) {
    ret = (char *)heapbased + heapsize;
    memset(ret, 0, incr);
    heapsize += incr;
    return(ret);
  }
  return((char *)-1);
}
