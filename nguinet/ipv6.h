/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_IPV6_H
#define NOTGNU_IPV6_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"
#include "ngubase/addr.h"

#define IPV6_MIN_MTU 1280
#define IPV6_ADDR_CHAR_LEN 46
#define NS_INET6_ADDRSZ 16
#define NS_INET_T16SZ 2

#define INET6_ADDR_ANY_INIT      {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}}
#define INET6_ADDR_LOOPBACK_INIT {{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}}}

struct ngu_in6_addr
{
  u8  addr8[16];
  u16 addr16[8];
  u32 addr32[4];
};

typedef struct ngu_ip6_addr_dnet
{
  u8 data[NS_INET6_ADDRSZ];
} ip6_addr_t;

struct ngu_sockaddr_in6
{
  short sin6_family;   /* AF_INET6 */
  short sin6_port;     /* port number */
  u32   sin6_flowinfo; /* IPv6 flow information */
  u32   sin6_scope_id; /* Scope ID (new in Linux 2.4) */

  struct ngu_in6_addr sin6_addr;     /* IPv6 address */
};

struct ip6_header
{
  u8  priority:4;
  u8  version:4;
  u8  flow_lbl[3];
  u16 payload_len;
  u8  next_hdr;
  u8  hop_limit;

  struct ngu_in6_addr saddr;
  struct ngu_in6_addr daddr;
};

struct ip6_in_packet_info_header
{
  struct ngu_in6_addr ipi6_addr;
  int                 ipi6_ifindex;
};

struct ip6_mtuinfo_header
{
  struct ngu_sockaddr_in6 ip6m_addr;
  u32                     ip6m_mtu;
};

struct ip6_rt_header
{
  u8 next_hdr;
  u8 ihl;
  u8 type;
  u8 segments_left;
};

struct ip6_opt_header
{
  u8 next_hdr;
  u8 ihl;
};

struct ip6_destopt_hao
{
  u8                  type;
  u8                  length;
  struct ngu_in6_addr addr;
};

#define IPV6_OPT_ROUTERALERT_MLD 0x0000 /* MLD(RFC2710) */

struct rt0_header
{
  struct ngu_in6_addr  addr;
  u32                  reserved;
  struct ip6_rt_header rt_hdr;

};

struct ip6_in_ifreq_header
{
  struct ngu_in6_addr ifr6_addr;
  u32                 ifr6_prefix_length;
  int                 ifr6_if_index;
};

#ifdef __cplusplus
}
#endif

#endif
