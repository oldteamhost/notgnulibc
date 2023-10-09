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
  char message[4096];
  int len = 0;
  if (func == NULL) {
    len = snprintf(message, sizeof(message), "Assertion failed: (%s), file %s, line %d.\n",
        expression, file, line);
    _write(2, message, len);
    _abort(1);
  }
  else {
    len = snprintf(message, sizeof(message), "Assertion failed: (%s), function %s, file %s, line %d.\n",
        expression, func, file, line);
    _write(2, message, len);
    _abort(1);
  }
}

