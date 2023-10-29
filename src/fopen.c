/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdio.h"

FILE* fopen(const char* filename, const char* mode)
{
  const char *m = mode;
  int flags = 0;

  FILE* file = (FILE*)malloc(sizeof(FILE));
  if (!file) {
    return NULL;
  }
  file->fd = -1;

  switch (*m++)
  {
    case 'r':
      flags = O_RDONLY;
      break;
    case 'w':
      flags = O_WRONLY;
      break;
    case 'a':
      flags = O_WRONLY | O_APPEND;
      break;
    default:
      goto fail;
  }

  if (m[0] == '+' || (m[0] == 'b' && m[1] == '+')) {
    flags |= O_RDWR;
  }

  file->fd = open(filename, flags, 0666);
  if (file->fd == -1) goto fail;

  file->flags = flags;
  file->bs = 0;
  file->bm = 0;
  file->buflen = BUFSIZ;
  file->buf = (char*)malloc(BUFSIZ);
  file->next = NULL;
  file->popen_kludge = 0;
  file->ungetbuf = 0;
  file->ungotten = 0;

#ifdef WANT_THREAD_SAFE
  pthread_mutex_init(&(file->m), NULL);
#endif

  return file;

fail:
  free(file);
  return NULL;
}
