/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../assert.h"

void
assert(const char* func, const char* file, int line, const char* expression)
{
  if (func == NULL) {
    printf("Assertion failed: (%s), file %s, line %d.",
        expression, file, line);
    ngu_abort(1);
  }
  else {
    printf(
      "Assertion failed: (%s), function %s, file %s, line %d.",
      expression, func, file, line);
    ngu_abort(1);
  }
}

