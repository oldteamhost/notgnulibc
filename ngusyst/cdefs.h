/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_CDEFS_H
#define NOTGNU_CDEFS_H

#if defined(__cplusplus)

  #define __BEGIN_DECLS  \
    extern "C" {

  #define __END_DECLS \
    }

#else
  #define __BEGIN_DECLS
  #define __END_DECLS
#endif

#endif

