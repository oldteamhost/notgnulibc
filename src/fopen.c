/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdio.h"

FILE* fopen(const char* filename, const char* mode)
{
  FILE* file = (FILE*)malloc(sizeof(FILE));
  if (!file) {
    return NULL;
  }

  file->fd = -1;
  int flags = 0;
  if (strcmp(mode, "r") == 0) {
    flags = O_RDONLY;
  }
  else if (strcmp(mode, "w") == 0) {
    flags = O_WRONLY | O_CREAT | O_TRUNC;
  }
  else if (strcmp(mode, "a") == 0) {
    flags = O_WRONLY | O_CREAT | O_APPEND;
  }
  else if (strcmp(mode, "r+") == 0) {
    flags = O_RDWR;
  }
  else if (strcmp(mode, "w+") == 0) {
    flags = O_RDWR | O_CREAT | O_TRUNC;
  }
  else if (strcmp(mode, "a+") == 0) {
    flags = O_RDWR | O_CREAT | O_APPEND;
  }
  else goto fail;

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
