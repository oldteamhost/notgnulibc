/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_WCTYPE_H
#define NOTGNU_WCTYPE_H

#include "ngubits/types.h"

typedef unsigned long int  wctype_t;
typedef i32                wctrans_t;
typedef u32                wint_t;

#define iswalnum(c)  ((c >= L'0' && c <= L'9') || (c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z'))
#define iswalpha(c)  ((c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z'))
#define iswblank(c)  (c == L' ' || c == L'\t')
#define iswcntrl(c)  ((c >= 0 && c <= 31) || c == 127)
#define iswdigit(c)  (c >= L'0' && c <= L'9')
#define iswgraph(c)  (c >= 33 && c <= 126)
#define iswlower(c)  (c >= L'a' && c <= L'z')
#define iswprint(c)  (c >= 32 && c <= 126)
#define iswpunct(c)  ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
#define iswspace(c)  (c == L' ' || (c >= L'\t' && c <= L'\r'))
#define iswupper(c)  (c >= L'A' && c <= L'Z')
#define iswxdigit(c) ((c >= L'0' && c <= L'9') || (c >= L'a' && c <= L'f') || (c >= L'A' && c <= L'F'))

#define towlower(c) \
    ((c >= L'A' && c <= L'Z') ? (c + (L'a' - L'A')) : c)

#define towupper(c) \
    ((c >= L'a' && c <= L'z') ? (c - (L'a' - L'A')) : c)

#define wctrans(s) (wctrans(s))

#define wctype(s) (wctype(s))

#define towctrans(c, category) \
    (towlower(c) == c ? towctrans(c, category) : c)

#define iswctype(c, category) \
    (wctrans(c) == wctrans(L"") ? 0 : (wctrans(c) & wctype(category)))

#endif

