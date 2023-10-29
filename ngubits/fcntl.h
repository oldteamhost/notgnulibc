/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef NOTGNU_FCNTL_H
#define NOTGNU_FCNTL_H

#define O_RDONLY  0        /* Open read-only. */
#define O_WRONLY  1        /* Open write-only. */
#define O_RDWR    2        /* Open read/write. */

#define O_CREAT   0x0200   /* Create file if it doesn't exist. */
#define O_EXCL    0x0800   /* Fail if file already exists. */
#define O_TRUNC   0x0400   /* Truncate file to zero length. */
#define O_NOCTTY  0x8000   /* Don't assign a controlling terminal. */
#define O_ASYNC   0x0040   /* Send SIGIO to owner when data is ready. */
#define O_FSYNC   0x0080   /* Synchronous writes.  */
#define O_SYNC    O_FSYNC

#define O_APPEND   0x0008  /* Writes append to the file. */
#define O_NONBLOCK 0x0004  /* Non-blocking I/O. */

#define O_ACCMODE (O_RDONLY|O_WRONLY|O_RDWR)

#define F_DUPFD 0 /* Duplicate file descriptor.  */
#define F_GETFD 1 /* Get file descriptor flags.  */
#define F_SETFD 2 /* Set file descriptor flags.  */
#define F_GETFL 3 /* Get file status flags.  */
#define F_SETFL 4 /* Set file status flags.  */

#define F_RDLCK 1 /* Read lock.  */
#define F_WRLCK 2 /* Write lock.  */
#define F_UNLCK 3 /* Remove lock.  */

int open(const char *filename, int flags, int mode);

#endif

