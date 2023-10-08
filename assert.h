/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_ASSERT_H
#define NOTGNU_ASSERT_H

#include "string.h"
#include "unistd.h"
#include "ngusyst/cdefs.h"
#include "ngusyst/printf.h"

__BEGIN_DECLS

/* casual 386 bsd style, (func, file, line, expression) */
void
assert(const char*, const char*, int, const char*);

__END_DECLS

#endif

