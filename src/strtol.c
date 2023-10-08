/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdlib.h"

long
strtol(const char *nptr, char** endptr, int base)
{
  u8 c;
  const char *s = nptr;
  unsigned long acc;
  unsigned long cutoff;
  int neg = 0, any, cutlim;

  do {
    c = *s++;
  } while (isspace(c));
  if (c == '-') {
    neg = 1;
    c = *s++;
  }
  else if (c == '+') {
    c = *s++;
  }
  if ((base == 0 || base == 16) &&
    c == '0' && (*s == 'x' || *s == 'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  if (base == 0) {
    base = c == '0' ? 8 : 10;
  }
  cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
  cutlim = cutoff % (unsigned long)base;
  cutoff /= (unsigned long)base;
  for (acc = 0, any = 0;; c = *s++) {
    if (!isascii(c)) {
      break;
    }
    if (isdigit(c)) {
      c -= '0';
    }
    else if (isalpha(c)) {
      c -= isupper(c) ? 'A' - 10 : 'a' - 10;
    }
    else {
      break;
    }
    if (c >= base) {
      break;
    }
    if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) {
      any = -1;
    }
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? LONG_MIN : LONG_MAX;
  }
  else if (neg) {
    acc = -acc;
  }
  if (endptr != NULL) {
    *endptr = any ? (char *)(unsigned long)(s - 1) : (char *)nptr;
  }
  return (acc);
}
