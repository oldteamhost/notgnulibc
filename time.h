/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_TIME_H
#define NOTGNU_TIME_H

#include <sys/time.h> /* linux header*/
#include "ngubits/types.h"
#include "ngusyst/cdefs.h"
#include "stddef.h"

#define CLOCKS_PER_SEC 128
#define TIME_UTC       1

typedef ___clock_t clock_t;
typedef ___time_t  time_t ;

struct tm
{
  int  tm_sec;     /* seconds after the minute [0-60] */
  int  tm_min;     /* minutes after the hour [0-59] */
  int  tm_hour;    /* hours since midnight [0-23] */
  int  tm_mday;    /* day of the month [1-31] */
  int  tm_mon;     /* months since January [0-11] */
  int  tm_year;    /* years since 1900 */
  int  tm_wday;    /* days since Sunday [0-6] */
  int  tm_yday;    /* days since January 1 [0-365] */
  int  tm_isdst;   /* Daylight Savings Time flag */
};

/* fucking linux
  struct timespec
  {
    time_t tv_sec;
    long  tv_nsec;
  };
*/

__BEGIN_DECLS

clock_t  clock(void); /* done */
double   difftime(time_t time1, time_t time0); /* done */
time_t   mktime(struct tm* timeptr);
time_t   time(time_t* timer); /* done */
int      timespec_get(struct timespec* ts, int base);
char*    asctime(const struct tm* timeptr);
char*    ctime(const time_t* timer);
struct   tm *gmtime(const time_t* timer);
struct   tm *localtime(const time_t *timer);

size_t   strftime(char* s, size_t maxsize, const char* format,
    const struct tm* timeptr);

__END_DECLS

#endif

