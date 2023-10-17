/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../unistd.h"
#include "../string.h"
#include "../ngubits/types.h"

static void*
current_brk = NULL;

void*
_sbrk(int incr)
{
  void* old_brk;
  void* new_brk;

  if (current_brk == NULL) {
    current_brk = _brk(NULL);
  }

  old_brk = current_brk;
  new_brk = (void*)((__uintptr_t)current_brk + incr);

  if (_brk(new_brk) == (void*)-1) {
    return (void*)-1;
  }

  current_brk = new_brk;
  return old_brk;
}
