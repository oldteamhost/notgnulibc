/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_PROTO_H
#define NOTGNU_PROTO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "addr.h"

/* Protocol families, same as address families. */
#define PF_UNSPEC       AF_UNSPEC
#define PF_UNIX         AF_UNIX
#define PF_LOCAL        AF_LOCAL
#define PF_INET         AF_INET
#define PF_AX25         AF_AX25
#define PF_IPX          AF_IPX
#define PF_APPLETALK    AF_APPLETALK
#define PF_NETROM       AF_NETROM
#define PF_BRIDGE       AF_BRIDGE
#define PF_ATMPVC       AF_ATMPVC
#define PF_X25          AF_X25
#define PF_INET6        AF_INET6
#define PF_ROSE         AF_ROSE
#define PF_DECnet       AF_DECnet
#define PF_NETBEUI      AF_NETBEUI
#define PF_SECURITY     AF_SECURITY
#define PF_KEY          AF_KEY
#define PF_NETLINK      AF_NETLINK
#define PF_ROUTE        AF_ROUTE
#define PF_PACKET       AF_PACKET
#define PF_ASH          AF_ASH
#define PF_ECONET       AF_ECONET
#define PF_ATMSVC       AF_ATMSVC
#define PF_RDS          AF_RDS
#define PF_SNA          AF_SNA
#define PF_IRDA         AF_IRDA
#define PF_PPPOX        AF_PPPOX
#define PF_WANPIPE      AF_WANPIPE
#define PF_LLC          AF_LLC
#define PF_CAN          AF_CAN
#define PF_TIPC         AF_TIPC
#define PF_BLUETOOTH    AF_BLUETOOTH
#define PF_IUCV         AF_IUCV
#define PF_RXRPC        AF_RXRPC
#define PF_ISDN         AF_ISDN
#define PF_PHONET       AF_PHONET
#define PF_IEEE802154   AF_IEEE802154
#define PF_CAIF         AF_CAIF
#define PF_ALG          AF_ALG
#define PF_NFC          AF_NFC
#define PF_MAX          AF_MAX

/* STANDART_IP_PROTOCOLS */
#define PROTO_IP       0    /* Dummy protocol for TCP.  */
#define PROTO_ICMP     1    /* Internet Control Message Protocol.  */
#define PROTO_IGMP     2    /* Internet Group Management Protocol. */
#define PROTO_IPIP     4    /* IPIP tunnels (older KA9Q tunnels use 94).  */
#define PROTO_TCP      6    /* Transmission Control Protocol.  */
#define PROTO_EGP      8    /* Exterior Gateway Protocol.  */
#define PROTO_PUP      12   /* PUP protocol.  */
#define PROTO_UDP      17   /* User Datagram Protocol.  */
#define PROTO_IDP      22   /* XNS IDP protocol.  */
#define PROTO_TP       29   /* SO Transport Protocol Class 4.  */
#define PROTO_DCCP     33   /* Datagram Congestion Control Protocol.  */
#define PROTO_IPV6     41   /* IPv6 header.  */
#define PROTO_RSVP     46   /* Reservation Protocol.  */
#define PROTO_GRE      47   /* General Routing Encapsulation.  */
#define PROTO_ESP      50   /* Encapsulating Security Payload.  */
#define PROTO_AH       51   /* Authentication Header.  */
#define PROTO_MTP      92   /* Multicast Transport Protocol.  */
#define PROTO_BEETPH   94   /* IP option pseudo header for BEET.  */
#define PROTO_ENCAP    98   /* Encapsulation Header.  */
#define PROTO_PIM      103  /* Protocol Independent Multicast.  */
#define PROTO_COMP     108  /* Compression Header Protocol.  */
#define PROTO_SCTP     132  /* Stream Control Transmission Protocol.  */
#define PROTO_UDPLITE  136  /* UDP-Lite protocol.  */
#define PROTO_MPLS     137  /* MPLS in IP.  */
#define PROTO_ETHERNET 143  /* Ethernet-within-IPv6 Encapsulation.  */
#define PROTO_RAW      255  /* Raw IP packets.  */
#define PROTO_MPTCP    262  /* Multipath TCP connection.  */

/* USE_KERNEL_IPV6_DEFS */
#define PROTO_HOPOPTS  0    /* IPv6 Hop-by-Hop options. */
#define PROTO_ROUTING  43   /* IPv6 routing header. */
#define PROTO_FRAGMENT 44   /* IPv6 fragmentation header. */
#define PROTO_ICMP6    58   /* ICMPv6. */
#define PROTO_NONE     59   /* IPv6 no next header. */
#define PROTO_DSTOPTS  60   /* IPv6 destination options. */
#define PROTO_MH       135  /* IPv6 mobility header. */

#ifdef __cplusplus
}
#endif

#endif
