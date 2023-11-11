/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../nguinet/arp.h"


#define PROC_ARP_FILE "/proc/net/arp"

struct arp_handle
{
  int fd;
};

arp_t *arp_open(void)
{
  arp_t *a;
  if ((a = calloc(1, sizeof(*a))) != NULL) {
  }
}

/*
int arp_add(arp_t *arp, const struct arp_entry *entry);
int arp_delete(arp_t *arp, const struct arp_entry *entry);
int arp_get(arp_t *arp, struct arp_entry *entry);
int arp_loop(arp_t *arp, arp_handler callback, void *arg);
arp_t *arp_close(arp_t *arp);
*/
