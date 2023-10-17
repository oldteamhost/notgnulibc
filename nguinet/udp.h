/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_UDP_H
#define NOTGNU_UDP_H

#include "ipv6.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"
#include "ngubase/hton.h"

struct udp_header
{
  u16 sport;
  u16 dport;
#define DEFAULT_UDP_LEN 8
  u16 ulen;
  u16 check;
};

u8*
build_udp(u16 sport, u16 dport, const char* data, u16 datalen, u32* packetlen);

#define fill_udp_header(udp_header, sport, dport, ulen, check) \
  do {                                                         \
    (udp_header)->sport = HTONS(sport);                        \
    (udp_header)->dport = HTONS(dport);                        \
    (udp_header)->ulen  = HTONS(*ulen);                        \
    (udp_header)->check = HTONS(check);                        \
  } while (0)

/* UDP_SOCKET_OPTIONS */

#define UDPCORK           1   /* Never send partially complete segments. */
#define UDP_ENCA_PACKET   100 /* Set the socket to accept encapsulated packets.*/
#define UDP_NOT_CHECK6_TX 101 /* Disable SENDING checksum for UDP over IPv6 */
#define UDP_NOT_CHECK6_RX 102 /* Disable ACCEPTING checksum for UDP over IPv6 */
#define UDP_SEGMENTS      103 /* Set GSO segmentation size. */
#define UDP_GRO_PACKETS   104 /* This socket can receive UDP GRO packets. */

/* UDP_ENCAPSULATION_TYPES */

#define UDP_ENCA_PACKET_ESPINUDP_NON_IKE 1 /* draft-ietf-ipsec-nat-t-ike-00/01 */
#define UDP_ENCA_PACKET_ESPINUDP         2 /* draft-ietf-ipsec-udp-encaps-06 */
#define UDP_ENCA_PACKET_L2TPINUDP        3 /* RFC 2661 */
#define UDP_ENCA_PACKET_GTP0             4 /* GSM TS 09.60 */
#define UDP_ENCA_PACKET_GTP1U            5 /* 3GPP TS 29.060 */

#define UDP_SOCK_OPT_LVL 17 /* Sockopt level for UDP */

#ifdef __cplusplus
}
#endif

#endif

