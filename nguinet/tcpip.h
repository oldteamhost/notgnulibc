/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * oldteam & lomaster 2023
 * tcpip.h - Набор функций для работы с протоколами TCPIP стека.
 *
 * Функции для создание пакета для протокола:
 *    build_[PROTO, version...]_pkt
 *  Заполняет его заголовок и возвращает указатель на пакет -
 *  - к которому добавила его.
 *
 *  Функции для отправки пакета для протокола:
 *    send_[PROTO]_pkt
 *  Отправляет пакет протокола.
*/

#ifndef NOTGNU_TCPIP_H
#define NOTGNU_TCPIP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ipv4.h"
#include "ipv6.h"
#include "icmp4.h"
#include "icmp6.h"
#include "tcp.h"
#include "udp.h"

#include "../ngubits/types.h"

#define IPOPT u8* ipopt
#define IPOPTLEN int ipoptlen

#define PACKETLEN u32* packetlen
#define OUTPACKETLEN u32* outpacketlen

#ifndef SADDR
  #define SADDR const char* saddr
#endif
#ifndef DADDR
  #define DADDR const char* daddr
#endif

#ifndef SADDR6
#define SADDR6 \
  const struct ngu_in6_addr* saddr
#endif
#ifndef DADDR6
  #define DADDR6 \
    const struct ngu_in6_addr* daddr
#endif

typedef u8* pkt_t;

pkt_t
build_ip_pkt(SADDR, DADDR, u8 proto, u8 ttl, u16 ident, u8 tos,
    IPOPT, IPOPTLEN, const char* data, u16 datalen, PACKETLEN);

pkt_t
build_ip6_pkt(SADDR, DADDR, u8 tc, u32 flowlabel, u8 next_hdr, u8 hop_limit,
    const char* data, u16 datalen, OUTPACKETLEN);

pkt_t
build_udp_pkt(SADDR, DADDR, u8 tos, u8 ttl, IPOPT, IPOPTLEN,
    u16 sport, u16 dport, const char* data, u16 datalen, PACKETLEN);

pkt_t
build_udp6_pkt(SADDR6, DADDR6, u8 tc, u32 flowlabel, u8 hop_limit,
    u16 sport, u16 dport, const char* data, u16 datalen, PACKETLEN);

pkt_t
build_icmp_pkt(SADDR, DADDR, u8 ttl, u16 ident, u8 tos, IPOPT, IPOPTLEN,
    u16 seq, u8 id, u8 type, u8 code, const char* data, u16 datalen, PACKETLEN);

pkt_t
build_icmp6_pkt(SADDR6, DADDR6, u8 tc, u32 flowlabel, u8 hop_limit, u16 seq,
    u16 id, u8 type, u8 code, const char* data, u16 datalen, PACKETLEN);

pkt_t
build_tcp_pkt(SADDR, DADDR, u8 ttl, u16 ident, u8 tos, IPOPT, IPOPTLEN,
    u16 sport, u16 dport, u32 seq, u32 ack, u8 reserved, u8 flags, u16 window,
    u16 urp, const u8* tcpopt, u32 tcpoptlen, const char* data, u16 datalen, PACKETLEN);

pkt_t
build_tcp6_pkt(SADDR6, DADDR6, u8 tc, u32 flowlabel, u8 hop_limit, u16 sport,
    u16 dport, u32 seq, u32 ack, u8 reserved, u8 flags, u16 window, u16 urp,
    const u8* tcpopt, u32 tcpoptlen, const char* data, u16 datalen, PACKETLEN);

#ifdef __cplusplus
}
#endif

#endif
