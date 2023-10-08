/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_CTYPE_H
#define NOTGNU_CTYPE_H

/* Here I decided to depart a bit from the ANSI standard,
 * because these functions can also be done as macros. */
#define isdigit(c) \
  ((c >= '0' && c <= '9') ? 1 : 0)
#define isascii(c) \
  ((c >= 0) && (c <= 127))
#define isspace(c) \
  ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r') || (c == '\v') || (c == '\f'))
#define isalnum(c) \
  (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) ? 1 : 0)
#define isalpha(c) \
  (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0)
#define iscntrl(c) \
  ((c >= 0 && c <= 31) || (c == 127) ? 1 : 0)
#define isgraph(c) \
  ((c >= 33 && c <= 126) ? 1 : 0)
#define islower(c) \
  ((c >= 'a' && c <= 'z') ? 1 : 0)
#define isprint(c) \
  ((c >= 32 && c <= 126) ? 1 : 0)
#define ispunct(c) \
  (((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) ? 1 : 0)
#define isupper(c) \
  ((c >= 'A' && c <= 'Z') ? 1 : 0)
#define isxdigit(c) \
  (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) ? 1 : 0)
#define toupper(c) \
  ((islower(c)) ? (c - 32) : c)
#define tolower(c) \
  ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)

#endif


