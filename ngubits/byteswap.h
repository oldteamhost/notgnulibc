/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_BYTESWAP_H
#define NOTGNU_BYTESWAP_H

#include "types.h"
#include "../ngusyst/cdefs.h"

__BEGIN_DECLS

u16
bswap16(u16 x);

u32
bswap32(u32 x);

u64
bswap64(u64 x);

__END_DECLS

#endif
