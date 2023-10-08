/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../ngubits/byteswap.h"

u16 bswap16(u16 x)
{
  return (x >> 8) | (x << 8);
}

u32 bswap32(u32 x)
{
  return ((x >> 24) & 0xFF) | ((x >> 8) & 0xFF00)
      | ((x << 8) & 0xFF0000) | ((x << 24) & 0xFF000000);
}

u64 bswap64(u64 x)
{
  return ((x >> 56) & 0xFF) | ((x >> 40) & 0xFF00) | ((x >> 24) & 0xFF0000)
      | ((x >> 8) & 0xFF000000) | ((x << 8) & 0xFF00000000) | ((x << 24)
      & 0xFF0000000000) | ((x << 40) & 0xFF000000000000) | ((x << 56)
      & 0xFF00000000000000);
}
