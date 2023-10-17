/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_INET_H
#define NOTGNU_INET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ngubits/byteswap.h"
#include "../ipv4.h"
#include "../ipv6.h"

/* Check if the given IP address belongs to Class A. */
#define INET_CLASSA(a) (((((u32)(a)) & 0x80000000) == 0) ? 1 : 0)
/* Network mask for Class A. */
#define INET_CLASSA_NET 0xff000000
/* Number of bits to shift to get the network number for Class A. */
#define INET_CLASSA_NSHIFT 24
/* Host mask for Class A. */
#define INET_CLASSA_HOST (0xffffffff & ~INET_CLASSA_NET)
/* Maximum number of hosts in Class A. */
#define INET_CLASSA_MAX 128

/* Check if the given IP address belongs to Class B. */
#define INET_CLASSB(a) (((((u32)(a)) & 0xc0000000) == 0x80000000) ? 1 : 0)
/* Network mask for Class B. */
#define INET_CLASSB_NET 0xffff0000
/* Number of bits to shift to get the network number for Class B. */
#define INET_CLASSB_NSHIFT 16
/* Host mask for Class B. */
#define INET_CLASSB_HOST (0xffffffff & ~INET_CLASSB_NET)
/* Maximum number of hosts in Class B. */
#define INET_CLASSB_MAX 65536

/* Check if the given IP address belongs to Class C. */
#define INET_CLASSC(a) (((((u32)(a)) & 0xe0000000) == 0xc0000000) ? 1 : 0)
/* Network mask for Class C. */
#define INET_CLASSC_NET 0xffffff00
/* Number of bits to shift to get the network number for Class C. */
#define INET_CLASSC_NSHIFT 8
/* Host mask for Class C. */
#define INET_CLASSC_HOST (0xffffffff & ~INET_CLASSC_NET)

/* Check if the given IP address belongs to Class D (Multicast). */
#define INET_CLASSD(a) (((((u32)(a)) & 0xf0000000) == 0xe0000000) ? 1 : 0)

/* Check if the given IP address is in the experimental range. */
#define INET_EXPERIMENTAL(a) (((((u32)(a)) & 0xe0000000) == 0xe0000000) ? 1 : 0)

/* Check if the given IP address belongs to a reserved (bad) class. */
#define INET_BADCLASS(a) (((((u32)(a)) & 0xf0000000) == 0xf0000000) ? 1 : 0)

/* Network number for the local host loopback.
 * This is typically the loopback address used to refer to the local machine. */
#define INET_LOOPBACKNET 127

/* Address to loopback in software to the local host.
 * INADDR_LOOPBACK represents the loopback address, which is typically 127.0.0.1. */
#define INET_ADDR_LOOPBACK ((u32) 0x7f000001) /* IPv4 127.0.0.1 */

/* Defines for Multicast INADDR.
 * These macros define various IPv4 multicast group addresses. Multicast is a method
 * of sending network traffic to multiple destinations simultaneously. */
#define INET_ADDR_UNSPEC_GROUP      ((u32) 0xe0000000) /* 224.0.0.0 */
#define INET_ADDR_ALLHOSTS_GROUP    ((u32) 0xe0000001) /* 224.0.0.1 */
#define INET_ADDR_ALLRTRS_GROUP     ((u32) 0xe0000002) /* 224.0.0.2 */
#define INET_ADDR_ALLSNOOPERS_GROUP ((u32) 0xe000006a) /* 224.0.0.106 */
#define INET_ADDR_MAX_LOCAL_GROUP   ((u32) 0xe00000ff) /* 224.0.0.255 */


/* This macro represents the special IP address 0.0.0.0, which is typically used
 * to specify "any" or "all" available network interfaces on a device. When used
 * as the IP address for a socket, it means that the socket can accept connections
 * from any available network interface. It's often used when binding a server socket
 * to listen on all available network interfaces.*/
#define INET_ADDR_ANY        ((u32) 0x00000000)


/* This macro represents the broadcast IP address 255.255.255.255. Broadcast addresses
 * are used to send a message to all devices on the same network segment. When you send
 * a packet to the broadcast address, it is delivered to all devices within the local
 * network segment. This is often used for network discovery or broadcasting messages
 * within a local network.*/
#define INET_ADDR_BROADCAST  ((u32) 0xffffffff)


/* This macro represents the special IP address 0xffffffff, which is often used to indicate
 * an invalid or uninitialized IP address. It's not a valid IP address in actual use and can
 * be used to represent an error condition when working with IP addresses.*/
#define INET_ADDR_NONE       ((u32) 0xffffffff)


/* This macro represents the IP address 192.0.0.8 in hexadecimal format 0xc0000008. It's a
 * specific IP address that might be used for testing or as a placeholder in certain network
 * configurations. Its use may depend on the specific context in which it's used, but it's not
 * a standard or widely recognized IP address. */
#define INET_ADDR_DUMMY      ((u32) 0xc0000008)


#ifndef _ngu_in_addr_
  #define _ngu_in_addr \
  struct ngu_in_addr
#endif

#ifdef SPRINTFCHAR
  #define SPRINTF(x) strlen(sprintf/**/x)
#else
  #define SPRINTF(x) ((size_t)sprintf x)
#endif

u32           inet_addr      (const char *cp);
char*         inet_ntoa      (_ngu_in_addr in);
int           inet_pton      (int af, const char *cp, void *buf);
const char*   inet_ntop      (int af, const void* cp, char* buf, u32 length);
u32           inet_netw      (const char* cp);  /* NGU: netw = network */
u32           inet_netf      (_ngu_in_addr in); /* NGU: netf = netof*/
u32           inet_lnaf      (_ngu_in_addr in); /* NGU: lnaf = lnaof */
char*         inet_neta      (u32 src, char* dst, u32 len);

char*         inet_net_ntop  (int af, const void* src, int bits, char* dst, u32 size);
int           inet_net_pton  (int af, const char* src, void* dst, u32 size);

int           inet_cidr_pton (int af, const char* src, void* dst, int* bits);
char*         inet_cidr_ntop (int af, const void* src, int bits, char* dst, u32 len);

_ngu_in_addr  inet_makeaddr  (u32 net, u32 host);

#ifdef __cplusplus
}
#endif

#endif
