/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../assert.h"

void
__assert(const char* func, const char* file, int line, const char* expression)
{
  int len = 0;
  char* message = NULL;

  if (func == NULL) {
    len = asprintf(&message, "Assertion failed: (%s), file %s, line %d.\n", expression, file, line);
    goto stderrwrite;
  }
  else {
    len = asprintf(&message, "Assertion failed: (%s), file %s, function %s, line %d.\n", expression, file, func, line);
    goto stderrwrite;
  }

stderrwrite:
  _write(2, message, len);
  __abort();
}

