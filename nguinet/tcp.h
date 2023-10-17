/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_TCP_H
#define NOTGNU_TCP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ngubits/types.h"
#include "ipv4.h"

#define TCPMSS               512
#define TCP_MAX_WINDOW       65535
#define TCP_MAX_WINDOW_SHIFT 14
#define TCP_SOCK_OPT_LVL     6

struct tcp_header
{
  u16 source;
  u16 dest;
  u32 seq;
  u32 ack_seq;
  u16 res1:4;
  u16 doff:4;
  u8  fin:1;
  u8  syn:1;
  u8  rst:1;
  u8  psh:1;
  u8  ack:1;
  u8  urg:1;
  u8  cwr:1;
  u8  ece:1;
  u8  res2:2;
  u8  window;
  u16 check;
  u16 urg_ptr;
};

struct tcp_header_default
{
  u16 th_sport;  /* Source port. */
  u16 th_dport;  /* Destination port. */
  u32 th_seq;    /* Sequence number. */
  u32 th_ack;    /* Acknowledgement number. */
  u8  th_off:4;  /* Data offset. */
  u8  th_x2:4;   /* (unused). */
  u8  th_flags;  /* TCP flags. */
  u16 th_win;    /* Window. */
  u16 th_sum;    /* Checksum. */
  u16 th_urp;    /* Urgent pointer. */
};

struct tcp_flags
{
#define TCP_FIN 0x01
#define TCP_SYN 0x02
#define TCP_RST 0x04
#define TCP_PSH 0x08
#define TCP_ACK 0x10
#define TCP_URG 0x20
#define TCP_CWR 0x40
#define TCP_ECE 0x80
  u8 syn; /* Synchronize sequence numbers. */
  u8 ack; /* Acknowledgment field significant. */
  u8 rst; /* Reset the connection. */
  u8 fin; /* No more data from sender. */
  u8 psh; /* Push Function. */
  u8 urg; /* Urgent Pointer field significant. */
  u8 cwr; /* Congestion Window reduced. */
  u8 ece; /* Explicit Congestion notification echo. */
};

#ifndef RESET_TCP_FLAGS
  #define RESET_TCP_FLAGS(tcp_flags_ptr) \
    do {                                 \
      (tcp_flags_ptr)->syn = 0;          \
      (tcp_flags_ptr)->ack = 0;          \
      (tcp_flags_ptr)->rst = 0;          \
      (tcp_flags_ptr)->fin = 0;          \
      (tcp_flags_ptr)->psh = 0;          \
      (tcp_flags_ptr)->urg = 0;          \
      (tcp_flags_ptr)->cwr = 0;          \
      (tcp_flags_ptr)->ece = 0;          \
    } while (0)
#endif

void
fill_tcp_header(struct tcp_header* tcp_header, u16 source_port, u16 dest_port, u32 seq_num, u32 ack_num,
    u16 window_size, u16 urgent_ptr, u8 doff, u8 res1, struct tcp_flags flags);

#define SET_SYN_PACKET(tcp_flags_ptr) \
  do {                                \
    RESET_TCP_FLAGS(tcp_flags_ptr);   \
    (tcp_flags_ptr)->syn = 1;         \
  } while (0)

#define SET_ACK_PACKET(tcp_flags_ptr) \
  do {                                \
    RESET_TCP_FLAGS(tcp_flags_ptr);   \
    (tcp_flags_ptr)->ack = 1;         \
  } while (0)

#define SET_WINDOW_PACKET(tcp_flags_ptr) \
  SET_ACK_PACKET(tcp_flags_ptr)

#define SET_NULL_PACKET(tcp_flags_ptr) \
  do {                                 \
    RESET_TCP_FLAGS(tcp_flags_ptr);    \
  } while (0)

#define SET_FIN_PACKET(tcp_flags_ptr) \
  do {                                \
    RESET_TCP_FLAGS(tcp_flags_ptr);   \
    (tcp_flags_ptr)->fin = 1;         \
  } while (0)

#define SET_MAIMON_PACKET(tcp_flags_ptr) \
  do {                                   \
    RESET_TCP_FLAGS(tcp_flags_ptr);      \
    (tcp_flags_ptr)->fin = 1;            \
    (tcp_flags_ptr)->ack = 1;            \
  } while (0)

#define SET_XMAS_PACKET(tcp_flags_ptr) \
  do {                                 \
    RESET_TCP_FLAGS(tcp_flags_ptr);    \
    (tcp_flags_ptr)->fin = 1;          \
    (tcp_flags_ptr)->psh = 1;          \
    (tcp_flags_ptr)->urg = 1;          \
  } while (0)

struct tcp_info_header
{
#define TCP_STATE_OPEN 0
#define TCP_STATE_DISORDER 1
#define TCP_STATE_CWR 2
#define TCP_STATE_RECOVERY 3
#define TCP_STATE_LOSS 4
  u8  state;
  u8  ca_state;
  u8  retransmits;
  u8  probes;
  u8  backoff;
  u8  options;
  u8  snd_wscale:4, rcv_wscale:4; /* SENT & RECV */

  u32 rto;
  u32 ato;
  u32 snd_mss;
  u32 rcv_mss;

  u32 unacked;
  u32 sacked;
  u32 lost;
  u32 retrans;
  u32 fackets;

  u32 last_data_sent;
  u32 last_ack_sent;

  u32 last_data_recv;
  u32 last_ack_recv;
};

union tcp_word_header
{
  struct tcp_header tcphdr;
  u32               words[5];
};

struct tcp_md5sig_header
{
#define TCPMD5SIG_MAX_KEY_LEN 80 /* For TCP_MD5SIG socket option. */
#define TCPMD5SIG_FLAG_PREFIX 1  /* tcp_md5sig extension flags for TCP_MD5SIG_EXT (Address prefix len). */
  struct ngu_sockaddr_storage addr;

  u8  flags;
  u8  prefixlen;
  u16 keylen;
  int ifindex;
  u8  key[TCPMD5SIG_MAX_KEY_LEN];
};

struct tcp_diag_md5sig
{
  u8  family;
  u8  prefixlen;
  u16 keylen;
  u32 addr[4];
  u8  key[TCPMD5SIG_MAX_KEY_LEN];
};

struct tcp_repair_opt
{
  u32 code;
  u32 val;
};

/* Queue to repair, for TCP_REPAIR_QUEUE.  */
enum
{
  TCP_NO_QUEUE,
  TCP_RECV_QUEUE,
  TCP_SEND_QUEUE,
  TCP_QUEUES_NR,
};

#define TCP_COOKIEMIN 8  /* 64-bits */
#define TCP_COOKIEMAX 16 /* 128-bits */
#define TCP_COOKIE_ALWAYS (1 << 0) /* IN Discard SYN without cookie*/
#define TCP_COOKIE_NEVER (1 << 1)  /* OUT Prohibit outgoing cookies, supercedes everything.*/
#define TCP_COOKIE_PAIRLEN (2*TCP_COOKIEMAX)

struct tcp_cookie_transactions_header
{
  u16 flags;
  u8  pad1;
  u8  cookie_desired;
  u16 s_data_desired;
  u16 used;
#define TCPMSS_DEFAULT 536U  /* IPv4 (RFC1122, RFC2581) */
#define TCPMSS_DESIRED 1220U /* IPv6 (tunneled), EDNS0 (RFC3226) */
  u8 value[TCPMSS_DEFAULT];
};

/* For use with TCP_REPAIR_WINDOW. */
struct tcp_repair_window_header
{
  u32 snd_wl1;
  u32 snd_wnd;
  u32 max_win;
  u32 rcv_wnd;
  u32 rcv_wup;
};

/* For use with TCP_ZEROCOPY_RECEIVE.
 * setsockopt(fd, IPPROTO_TCP, TCP_ZEROCOPY_RECEIVE, ...)*/
#define TCP_FLAG_RECEIVE_ZEROCOPY_TLB_CLEAN_HINT 0x1
struct tcp_zerocopy_receive_header
{
  u64 address;        /* In: address of mapping. */
  u32 length;         /* In/out: number of bytes to map/mapped. */
  u32 recv_skip_hint; /* Out: amount of bytes to skip. */
  u32 inq;
  u32 err;
  u64 copybuf_addr;
  u32 copybuf_length;
  u32 flags;
  u64 msg_control;
  u64 msg_control_len;
  u32 msg_flags;
  u32 reserved; /* NULL */
};

struct tcp_pseudo_header
{
  u32 source_address;
  u32 dest_address;
  u8  placeholder;
  u8  protocol;
  u16 tcp_length;
  struct tcp_header tcp;
};

#ifdef __cplusplus
}
#endif

#endif

