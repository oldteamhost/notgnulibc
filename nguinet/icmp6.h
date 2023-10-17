/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_ICMP4_H
#define NOTGNU_ICMP4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"

struct icmp6_header
{
  u8  type;
  u8  code;
  u16 check;
  union
  {
    u32 un_data32 [1];
    u16 un_data16 [2];
    u8  un_data8  [4];
  } data_run;
};

struct icmp6_filter_header
{
  u32 filter[8];
};

/*TODO*/


#ifdef __cplusplus
}
#endif
#endif

