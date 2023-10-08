/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../time.h"

#define dminus(x) (-x)

double
difftime(time_t time1, time_t time0)
{
  if (sizeof(time_t) < sizeof(double)) {
    double t1 = time1, t0 = time0;
    return t1 - t0;
  }

  if (!TYPE_SIGNED(time_t))
    return time0 <= time1 ? time1 - time0 : dminus(time0 - time1);

  /* Use uintmax_t if wide enough.  */
  if (sizeof(time_t) <= sizeof(unsigned long long)) {
    unsigned long long t1 = time1, t0 = time0;
    return time0 <= time1 ? t1 - t0 : dminus(t0 - t1);
  }

  if ((time1 < 0) == (time0 < 0)) {
    return time1 - time0;
  }
  {
    long double t1 = time1, t0 = time0;
    return t1 - t0;
  }
}
