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
#include "ngubase/hton.h"

/* Destination Unreachable Message */

#define ICMP_DEST_UNREACH  3   /*Destination Unreachable*/
#define ICMP_NET_UNREACH   0   /*Network Unreachable*/
#define ICMP_HOST_UNREACH  1   /*Host Unreachable*/
#define ICMP_PROT_UNREACH  2   /*Protocol Unreachable*/
#define ICMP_PORT_UNREACH  3   /*Port Unreachable*/
#define ICMP_FRAG_NEEDED   4   /*Fragmentation Needed/DF set*/
#define ICMP_SR_FAILED     5   /*Source Route failed*/

/* Parameter Problem Message */

#define ICMP_PARAMETERPROB  12 /*Parameter Problem*/
#define ICMP_POINTINDIC_ER  0  /*Pointer indicates the error.*/

/* Time Exceeded Message */

#define ICMP_TIME_EXCEEDED  11 /*Time Exceeded*/
#define ICMP_EXC_TTL        0  /*TTL count exceeded*/
#define ICMP_EXC_FRAGTIME   1  /*Fragment Reass time exceeded*/

/* Redirect Message */

#define ICMP_REDIRECT       5 /*Redirect (change route)*/
#define ICMP_REDIR_NET      0 /*Redirect Net*/
#define ICMP_REDIR_HOST     1 /*Redirect Host*/
#define ICMP_REDIR_NETTOS   2 /*Redirect Net for TOS*/
#define ICMP_REDIR_HOSTTOS  3 /*Redirect Host for TOS*/

/* Echo Message */

#define ICMP_ECHO           8  /*Echo Request*/
#define ICMP_EXT_ECHO       42 /*Exceeded Echo*/
#define ICMP_ECHOREPLY      0  /*Echo Reply*/
#define ICMP_EXT_ECHOREPLY  43 /*Exceeded Echo Reply*/

/*Timestamp Message*/

#define ICMP_TIMESTAMP      13 /*Timestamp Request*/
#define ICMP_TIMESTAMPREPLY 14 /*Timestamp Reply*/

/*Information Message*/

#define ICMP_INFO_REQUEST   15 /*Information Request*/
#define ICMP_INFO_REPLY     16 /*Information Reply*/

struct icmp4_header
{
  u8   type;
  u8   code;
  u16  check;
  u16  ident;
  u16  seq;
#define MAGIC "helloworld"
#define MAGIC_LEN 10
  char magic[MAGIC_LEN];
};

#define fill_icmp4_header(icmp_header, type, code, ident, seq) \
  do {                                                         \
    (icmp_header)->ident = HTONS(ident);                       \
    (icmp_header)->code = code;                                \
    (icmp_header)->type = type;                                \
    (icmp_header)->seq = HTONS(seq);                           \
    (icmp_header)->checksum = 0;                               \
  } while (0)

struct icmp4_header_default
{
  u8  type;
  u8  code;
  u16 check;
  u16 ident;
  u16 seq;
  u32 gateway;
  u16 __unused;
  u16 mtu;
  u8  reserved[4];
};

struct icmp4_filter
{
#define ICMP_FILTER 1
  u32 data;
};

/* RFC 4884 extension struct: one per message */
struct icmp4_ext_hdr
{
  u8  reserved1:4, version:4;
  u8  reserved2;
  u16 check;
};

/* RFC 4884 extension object header: one for each object */
struct icmp4_extobj_hdr
{
  u16 length;
  u8 class_num;
  u8 class_type;
};

/* RFC 8335: 2.1 Header for c-type 3 payload */
struct icmp4_ext_echo_ctype3_hdr
{
  u16 afi;
  u8 addrlen;
  u8 reserved;
};

#include "ipv6.h"
/* RFC 8335: 2.1 Interface Identification Object */
struct icmp_ext_echo_iio
{
  struct icmp4_extobj_hdr exthdr;
  union
  {
    char name[IF_NAMELEN];
    u32 ifindex;
    struct
    {
      struct icmp4_ext_echo_ctype3_hdr ct3hdr;
      union
      {
        u32 ipv4_addr;
        struct ngu_in6_addr ipv6_addr;
      } ip_addr;
    } addr;
  } ident;
};

#ifdef __cplusplus
}
#endif

#endif

