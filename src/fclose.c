/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdio.h"

int fclose(FILE* file)
{
  if (file == NULL) goto fail;

  // fileno(file);
  int fd = file->fd;
  if (fd < 0) goto fail;

  int res = _close(fd);
  if (res < 0) goto fail;

  free(file);
  return 0;

fail:
  return EOF;
}

