/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../nguinet/tcpip.h"

int send_ip_packet(const struct eth_nfo *eth, const u8 *packet, u32 packetlen)
{
  int res;
  res = send_ip_packet_eth(eth, packet, packetlen);
  return res;
}

int send_ip6_packet(const struct eth_nfo *eth, const u8 *packet, u32 packetlen)
{
  int res;
  res = send_ip6_packet_eth(eth, packet, packetlen);
  return res;
}
