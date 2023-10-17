/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_HTON_H
#define NOTGNU_HTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ngubits/byteswap.h"

#define       HTONS(x)          bswap16(x)
#define       HTONL(x)          bswap32(x)
#define       NTOHS(x)          bswap16(x)
#define       NTOHL(x)          bswap32(x)

#ifdef __cplusplus
}
#endif

#endif
