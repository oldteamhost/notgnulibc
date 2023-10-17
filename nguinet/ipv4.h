/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_IPV4_H
#define NOTGNU_IPV4_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"
#include "ngubase/hton.h"
#include "ngubase/proto.h"

#define IPV4_ADDR_CHAR_LEN  16
#define IPV4_ADDR_BITS      32

#define NS_INET_ADDRSZ 4

struct ip_header
{
#define MAX_IHL_LEN 60
  u8  ihl:4;     /* header length */
#define IP_VERSION 4
  u8  version:4; /* ip proto version */
#define DEFAULT_TOS 0
  u8  tos;       /* type of service */
  u16 tot_len;   /* total length */
  u16 ident;     /* identificator */
#define IP_RF 0x8000  /* reserved fragment flag */
#define IP_DF 0x4000  /* dont fragment flag */
#define IP_MF 0x2000  /* more fragments flag */
#define IP_DM 0x1fff  /* mask for fragmenting bits */
  u16 frag_off;  /* fragment offset */
#define MAX_TTL 255
#define DEFAULT_TTL 121
  u8  ttl;       /* time to live */
  u8  protocol;  /* see addr.h */
  u16 check;     /* 16 bit checksum */
  u32 saddr;     /* source ip address */
  u32 daddr;     /* dest ip address */
};

struct ip4_pseudo_header
{
  u32 saddr;
  u32 daddr;
  u8 placeholder;
  u8 protocol;
  u16 length;
};

void
fill_ipv4_header(struct ip_header *iph, u8 header_len, u8 tos, u16 total_len, u16 identificator,
    u16 frag_off, u8 ttl, u8 protocol, u16 checksum, const u8* ipopt, u16 ipoptlen,
    const char* source_ip, const char* dest_ip);

u16 ipv4_check(const char* saddr, const char* daddr, u8 proto, const void* data, u16 len);
u16 ipv4_pseudoheader_check(const char* saddr, const char* daddr, u8 proto, u16 len, const void* data);
u16 checksum_16bit(const u16* data, int length);
int ip_cksum_add(const void *buf, u64 len, int cksum);

#define ip_cksum_carry(x) \
  (x = (x >> 16) + (x & 0xffff), (~(x + (x >> 16)) & 0xffff))

struct ngu_in_addr
{
  unsigned long s_addr;
};

struct ngu_sockaddr_in
{
  short                sin_family;   /* AF_INET */
  u16                  sin_port;     /* port number */
  struct ngu_in_addr   sin_addr;     /* ipv4 addr */
  char                 sin_zero[8];
};

struct ngu_sockaddr
{
  u16  sa_family;  /* Address family */
  char sa_data[];  /* Socket address */
};

struct ngu_ifmap
{
  unsigned long mem_start;
  unsigned long mem_end;
  u16           base_addr;
  u8            irq;
  u8            dma;
  u8            port;
};

struct ngu_ifreq
{
  char name[IF_NAMELEN];
  union
  {
    struct ngu_sockaddr addr;
    struct ngu_sockaddr daddr;
    struct ngu_sockaddr broadaddr;
    struct ngu_sockaddr netmask;
    struct ngu_sockaddr hwaddr;
    short               flags;
    int                 ifindex;
    int                 metric;
    int                 mtu;
    struct ngu_ifmap    map;
    char                slave[IF_NAMELEN];
    char                newname[IF_NAMELEN];
    char                *data;
  };
};

/* linux/socket.h - struct __kernel_sockaddr_storage */
struct ngu_sockaddr_storage
{
  u16  ss_family;
#define NGU_SS_MAXSIZE 128
  char data[NGU_SS_MAXSIZE - sizeof(u16)];
};

struct ip_timestamp
{
  u8  code;
  u8  len;
  u8  ptr;
  u32 flags:4;
  u32 overflow:4;
  u32 data[9];
};

struct ip_auth_header
{
  u8  next_hdr;
  u8  length;
  u16 reserved;
  u32 sec_pi;
  u32 seq;
  u8  auth_data[];
};

struct ip_esp_header
{
  u32 sec_pi;
  u32 seq;
  u8  enc_data[];
};

struct ip_comp_header
{
  u8  next_hdr;
  u8  flags;
  u16 cpi;
};

struct ip_beet_phdr
{
  u8 next_hdr;
  u8 length;
#define IPV4_BEET_PHDR_MAX_LENGTH 8
  u8 pad_length;
  u8 reserved;
};

struct timestamp
{
  u8  len;
  u8  ptr;
  u32 flags:4;
  u32 overflow:4;
  u32 data[9];
};

#ifdef __cplusplus
}
#endif

#endif
