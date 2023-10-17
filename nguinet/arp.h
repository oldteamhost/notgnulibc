/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_ARP_H
#define NOTGNU_ARP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"
#include "ipv4.h"

/* address = MAC address */

/*TODO*/

#define ARP_HRD_ETH 	0x0001	/* ethernet hardware */
#define ARP_HRD_IEEE802	0x0006	/* IEEE 802 hardware */

#define ARP_HRD_INFINIBAND 0x0020 /* InfiniBand */
#define ARP_HRD_APPLETALK 0x0309 /* AppleTalk DDP */
#define ARP_HDR_IEEE80211 0x0321  /* IEEE 802.11 */
#define ARP_HRD_IEEE80211_PRISM 0x0322  /* IEEE 802.11 + prism header */
#define ARP_HRD_IEEE80211_RADIOTAP 0x0323  /* IEEE 802.11 + radiotap header */
#define ARP_HRD_VOID 0xFFFF			/* Void type, nothing is known */


struct arp_header
{
  u16 addr;     /* hardware address */
  u16 proto;    /* protocol address */
  u8  addrlen;  /* length of hardware address */
  u8  protolen; /* length of protocol address */
  u16 opcode;   /* ARP opcode (command) */
};

#include <sys/socket.h>
#include "../ngubase/addr.h"
struct arp_request_header
{
  struct sockaddr addr;
  struct sockaddr proto_addr;
  int             flags;
  struct sockaddr netmask;
  char            dev[IF_NAMELEN];
};

struct arp_request_header_old
{
  struct sockaddr proto_addr;
  struct sockaddr addr;
  int             flags;
  struct sockaddr netmask;
};

#ifdef __cplusplus
}
#endif

#endif

