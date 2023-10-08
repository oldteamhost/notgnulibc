/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../string.h"

char*
strtok_r(char* str, const char* delim, char** sptr)
{
  char *ret;
  if (str == NULL) {
    str = *sptr;
  }
  while(*str && strchr(delim, *str)) {
    ++str;
  }
  if(*str == '\0') {
    return NULL;
  }
  ret = str;
  while(*str && !strchr(delim, *str)) {
    ++str;
  }
  if(*str) {
    *str++ = '\0';
  }
  *sptr = str;
  return ret;
}

