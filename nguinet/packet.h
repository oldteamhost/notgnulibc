/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_PACKET_H
#define NOTGNU_PACKET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"

struct sockaddr_pkt
{
  u16 family;
  u8  device[14];
  u16 protocol;
};

struct ngu_sockaddr_ll
{
  u16 family;       /* Always AF_PACKET */
  u16 protocol;     /* Physical-layer protocol */
  int ifindex;  /* Interface number */
  u16 hatype;   /* ARP hardware type */
  u8  pkttype;  /* Packet type */
  u8  halen;    /* Length of address */
  u8  addr[8];  /* Physical-layer address */
};

struct packet_mreq
{
  int ifindex;    /* interface index */
  u16 type;       /* action */
  u16 alen;       /* address length */
  u8  address[8]; /* physical-layer address */
};

/* Packet types */

#define PACKET_HOST               0  /* To us */
#define PACKET_BROADCAST          1  /* To all */
#define PACKET_MULTICAST          2  /* To group */
#define PACKET_OTHERHOST          3  /* To someone else */
#define PACKET_OUTGOING           4  /* Outgoing of any type */
#define PACKET_LOOPBACK           5  /* MC/BRD frame looped back */
#define PACKET_USER               6  /* To user space */
#define PACKET_KERNEL             7  /* To kernel space */

/* Unused, PACKET_FASTROUTE and
 * PACKET_LOOPBACK are invisible to user space */

#define PACKET_FASTROUTE          6 /* Fastrouted frame */

/* Packet socket options */

#define PACKET_ADD_MEMBERSHIP     1
#define PACKET_DROP_MEMBERSHIP    2
#define PACKET_RECV_OUTPUT        3
/* Value 4 is still used by obsolete turbo-packet. */
#define PACKET_RX_RING            5
#define PACKET_STATISTICS         6
#define PACKET_COPY_THRESH        7
#define PACKET_AUXDATA            8
#define PACKET_ORIGDEV            9
#define PACKET_VERSION           10
#define PACKET_HDRLEN            11
#define PACKET_RESERVE           12
#define PACKET_TX_RING           13
#define PACKET_LOSS              14
#define PACKET_VNET_HDR          15
#define PACKET_TX_TIMESTAMP      16
#define PACKET_TIMESTAMP         17
#define PACKET_FANOUT            18
#define PACKET_TX_HAS_OFF        19
#define PACKET_QDISC_BYPASS      20
#define PACKET_ROLLOVER_STATS    21
#define PACKET_FANOUT_DATA       22
#define PACKET_IGNORE_OUTGOING   23

#define PACKET_FANOUT_HASH        0
#define PACKET_FANOUT_LB          1
#define PACKET_FANOUT_CPU         2
#define PACKET_FANOUT_ROLLOVER    3
#define PACKET_FANOUT_RND         4
#define PACKET_FANOUT_QM          5
#define PACKET_FANOUT_CBPF        6
#define PACKET_FANOUT_EBPF        7
#define PACKET_FANOUT_FLAG_ROLLOVER  0x1000
#define PACKET_FANOUT_FLAG_UNIQUEID  0x2000
#define PACKET_FANOUT_FLAG_DEFRAG    0x8000

#ifdef __cplusplus
}
#endif

#endif

