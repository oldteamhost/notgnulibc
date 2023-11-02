/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../nguinet/eth.h"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if_ether.h>
#include "../unistd.h"

struct eth_handle
{
  int                    fd;
  struct ngu_sockaddr_ll sll;
  struct ngu_ifreq       ifr;
};

eth_t*
eth_open(const char *device)
{
  eth_t *e;
  if ((e = calloc(1, sizeof(*e))) != NULL) {
    if ((e->fd = socket(PF_PACKET, SOCK_RAW, HTONS(ETH_P_ALL))) < 0) {
      return (eth_close(e));
    }
    strlcpy(e->ifr.name, device, sizeof(e->ifr.name));
    if (ioctl(e->fd, SIOCGIFINDEX, &e->ifr) < 0) {
      return (eth_close(e));
    }

    e->sll.family = AF_PACKET;
    e->sll.ifindex = e->ifr.ifindex;
  }
  return e;
}

size_t
eth_send(eth_t *e, const void *buf, size_t len)
{
  struct eth_hdr *eth = (struct eth_hdr *)buf;
  e->sll.protocol = eth->eth_type;

  return (sendto(e->fd, buf, len, 0, (struct sockaddr *)&e->sll,
        sizeof(e->sll)));
}

eth_t*
eth_close(eth_t *e)
{
  if (e != NULL) {
    if (e->fd >= 0) {
      _close(e->fd);
    }
    free(e);
  }
  return (NULL);
}

int
send_ip_packet_eth(const struct eth_nfo *eth, const u8 *packet, u32 packetlen)
{
  eth_t *ethsd;
  u8 *eth_frame;
  int res;

  eth_frame = (u8 *) malloc(14 + packetlen);
  memcpy(eth_frame + 14, packet, packetlen);
  eth_pack_hdr(eth_frame, eth->dstmac, eth->srcmac, ETH_TYPE_IP);

  if (!eth->ethsd) {
    ethsd = eth_open(eth->devname);
  }
  else {
    ethsd = eth->ethsd;
  }

  res = eth_send(ethsd, eth_frame, 14 + packetlen);
  free(eth_frame);
  return res;
}

int
send_ip6_packet_eth(const struct eth_nfo *eth, const u8 *packet, u32 packetlen)
{
  eth_t *ethsd;
  struct eth_hdr *eth_frame;
  u8 *copy;
  int res;

  copy = (u8 *) malloc(packetlen + sizeof(*eth_frame));
  memcpy(copy + sizeof(*eth_frame), packet, packetlen);
  eth_frame = (struct eth_hdr *) copy;
  eth_pack_hdr(eth_frame, eth->dstmac, eth->srcmac, ETH_TYPE_IPV6);
  if (!eth->ethsd) {
    ethsd = eth_open(eth->devname);
  }
  else {
    ethsd = eth->ethsd;
  }

  res = eth_send(ethsd, eth_frame, sizeof(*eth_frame) + packetlen);
  free(eth_frame);

  return res;
}
