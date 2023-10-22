/*
 * NCSOCK & NESCA4
 *   Сделано от души 2023.
 * Copyright (c) [2023] [lomaster]
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include "../stdio.h"
#include "../ngusyst/malloc.h"
#include "../ngubits/types.h"
#include "../stdlib.h"
#include "../string.h"
#include "../ctype.h"
#include "../stddef.h"

static char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
static char *upper_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static size_t strnlen(const char *s, size_t count)
{
  const char *sc;
  for (sc = s; *sc != '\0' && count--; ++sc);
  return sc - s;
}

static int skip_atoi(const char **s)
{
  int i = 0;
  while (is_digit(**s)) i = i*10 + *((*s)++) - '0';
  return i;
}

static char *number(char *str, long num, int base, int size, int precision, int type)
{
  char c, sign, tmp[66];
  char *dig = digits;
  int i;

  if (type & LARGE)  dig = upper_digits;
  if (type & LEFT) type &= ~ZEROPAD;
  if (base < 2 || base > 36) return 0;

  c = (type & ZEROPAD) ? '0' : ' ';
  sign = 0;
  if (type & SIGN) {
    if (num < 0) {
      sign = '-';
      num = -num;
      size--;
    } else if (type & PLUS) {
      sign = '+';
      size--;
    } else if (type & SPACE) {
      sign = ' ';
      size--;
    }
  }

  if (type & SPECIAL) {
    if (base == 16) {
      size -= 2;
    } else if (base == 8) {
      size--;
    }
  }

  i = 0;

  if (num == 0) {
    tmp[i++] = '0';
  } else {
    while (num != 0) {
      tmp[i++] = dig[((unsigned long) num) % (unsigned) base];
      num = ((unsigned long) num) / (unsigned) base;
    }
  }

  if (i > precision) precision = i;
  size -= precision;
  if (!(type & (ZEROPAD | LEFT))) while (size-- > 0) *str++ = ' ';
  if (sign) *str++ = sign;

  if (type & SPECIAL) {
    if (base == 8) {
      *str++ = '0';
    } else if (base == 16) {
      *str++ = '0';
      *str++ = digits[33];
    }
  }

  if (!(type & LEFT)) while (size-- > 0) *str++ = c;
  while (i < precision--) *str++ = '0';
  while (i-- > 0) *str++ = tmp[i];
  while (size-- > 0) *str++ = ' ';

  return str;
}

static char *eaddr(char *str, unsigned char *addr, int size, int precision, int type)
{
  char tmp[24];
  char *dig = digits;
  int i, len;

  if (type & LARGE)  dig = upper_digits;
  len = 0;
  for (i = 0; i < 6; i++) {
    if (i != 0) tmp[len++] = ':';
    tmp[len++] = dig[addr[i] >> 4];
    tmp[len++] = dig[addr[i] & 0x0F];
  }

  if (!(type & LEFT)) while (len < size--) *str++ = ' ';
  for (i = 0; i < len; ++i) *str++ = tmp[i];
  while (len < size--) *str++ = ' ';

  return str;
}

static char *iaddr(char *str, unsigned char *addr, int size, int precision, int type)
{
  char tmp[24];
  int i, n, len;

  len = 0;
  for (i = 0; i < 4; i++) {
    if (i != 0) tmp[len++] = '.';
    n = addr[i];
    if (n == 0) {
      tmp[len++] = digits[0];
    } else {
      if (n >= 100) {
        tmp[len++] = digits[n / 100];
        n = n % 100;
        tmp[len++] = digits[n / 10];
        n = n % 10;
      } else if (n >= 10) {
        tmp[len++] = digits[n / 10];
        n = n % 10;
      }

      tmp[len++] = digits[n];
    }
  }

  if (!(type & LEFT)) while (len < size--) *str++ = ' ';
  for (i = 0; i < len; ++i) *str++ = tmp[i];
  while (len < size--) *str++ = ' ';

  return str;
}

static void reverse(char *str, int length)
{
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

#include "../stdbool.h"
static char *itoa(int num, char *str, int base)
{
  int i = 0;
  bool is_negative = false;

  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  if (num < 0 && base == 10) {
    is_negative = true;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    num = num / base;
  }

  if (is_negative) {
    str[i++] = '-';
  }

  str[i] = '\0';
  reverse(str, i);

  return str;
}

static void forcdecpt(char *buffer)
{
  while (*buffer) {
    if (*buffer == '.') return;
    if (*buffer == 'e' || *buffer == 'E') break;
    buffer++;
  }

  if (*buffer) {
    int n = strlen(buffer);
    while (n > 0) {
      buffer[n + 1] = buffer[n];
      n--;
    }

    *buffer = '.';
  } else {
    *buffer++ = '.';
    *buffer = '\0';
  }
}

static void cropzeros(char *buffer)
{
  char *stop;

  while (*buffer && *buffer != '.') buffer++;
  if (*buffer++) {
    while (*buffer && *buffer != 'e' && *buffer != 'E') buffer++;
    stop = buffer--;
    while (*buffer == '0') buffer--;
    if (*buffer == '.') buffer--;
    while ((*++buffer = *stop++));
  }
}

static char *flt(char *str, double num, int size, int precision, char fmt, int flags)
{
  if (fmt == 'f') {
    int int_part = (int)num;
    double frac_part = num - int_part;

    itoa(int_part, str, 10);
    int len = strlen(str);

    if (precision < 0) {
      precision = 6;
    }
    else if (precision == 0 && fmt == 'g') {
      precision = 1;
    }

    if (precision > 0) {
      str[len] = '.';
      len++;

      for (int i = 0; i < precision; i++) {
        frac_part *= 10;
        int digit = (int)frac_part;
        str[len] = digit + '0';
        len++;
        frac_part -= digit;
      }
    }
    str[len] = '\0';
    if (fmt == 'g' && !(flags & SPECIAL)) cropzeros(str);
    if ((flags & SPECIAL) && precision == 0) forcdecpt(str);
    if (!(flags & LEFT)) {
      while (len < size--) {
        *str++ = ' ';
      }
    }
  }
  return str;
}

int vsprintf(char *buf, const char *fmt, va_list args)
{
  int len;
  unsigned long num;
  int i, base;
  char *str;
  char *s;

  int flags;

  int field_width;
  int precision;
  int qualifier;

  for (str = buf; *fmt; fmt++) {
    if (*fmt != '%') {
      *str++ = *fmt;
      continue;
    }
    flags = 0;
repeat:
    fmt++;
    switch (*fmt) {
      case '-': flags |= LEFT; goto repeat;
      case '+': flags |= PLUS; goto repeat;
      case ' ': flags |= SPACE; goto repeat;
      case '#': flags |= SPECIAL; goto repeat;
      case '0': flags |= ZEROPAD; goto repeat;
    }
    field_width = -1;
    if (is_digit(*fmt)) {
      field_width = skip_atoi(&fmt);
    } else if (*fmt == '*') {
      fmt++;
      field_width = va_arg(args, int);
      if (field_width < 0) {
        field_width = -field_width;
        flags |= LEFT;
      }
    }

    precision = -1;
    if (*fmt == '.') {
      ++fmt;
      if (is_digit(*fmt)) {
        precision = skip_atoi(&fmt);
      } else if (*fmt == '*') {
        ++fmt;
        precision = va_arg(args, int);
      }
      if (precision < 0) precision = 0;
    }

    qualifier = -1;
    if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
      qualifier = *fmt;
      fmt++;
    }

    base = 10;

    switch (*fmt) {
      case 'c':
        if (!(flags & LEFT)) while (--field_width > 0) *str++ = ' ';
        *str++ = (unsigned char) va_arg(args, int);
        while (--field_width > 0) *str++ = ' ';
        continue;

      case 's':
        s = va_arg(args, char *);
        if (!s) s = "<NULL>";
        len = strnlen(s, precision);
        if (!(flags & LEFT)) while (len < field_width--) *str++ = ' ';
        for (i = 0; i < len; ++i) *str++ = *s++;
        while (len < field_width--) *str++ = ' ';
        continue;

      case 'p':
        if (field_width == -1) {
          field_width = 2 * sizeof(void *);
          flags |= ZEROPAD;
        }
        str = number(str, (unsigned long) va_arg(args, void *), 16, field_width, precision, flags);
        continue;

      case 'n':
        if (qualifier == 'l') {
          long *ip = va_arg(args, long *);
          *ip = (str - buf);
        } else {
          int *ip = va_arg(args, int *);
          *ip = (str - buf);
        }
        continue;
      case 'A':
        flags |= LARGE;
      case 'a':
        if (qualifier == 'l') {
          str = eaddr(str, va_arg(args, unsigned char *), field_width, precision, flags);
        }
        else {
          str = iaddr(str, va_arg(args, unsigned char *), field_width, precision, flags);
        }
        continue;
      case 'o':
        base = 8;
        break;
      case 'X':
        flags |= LARGE;
      case 'x':
        base = 16;
        break;
      case 'd':
      case 'i':
        flags |= SIGN;
      case 'u':
        break;
      case 'E':
      case 'G':
      case 'e':
      case 'f':
      case 'g':
        str = flt(str, va_arg(args, double), field_width, precision, *fmt, flags | SIGN);
        continue;
      default:
        if (*fmt != '%') *str++ = '%';
        if (*fmt) {
          *str++ = *fmt;
        }
        else {
          --fmt;
        }
        continue;
    }
    if (qualifier == 'l') {
      num = va_arg(args, unsigned long);
    }
    else if (qualifier == 'h' || flags & SIGN) {
      num = va_arg(args, int);
    }
    else {
      num = va_arg(args, unsigned int);
    }

    str = number(str, num, base, field_width, precision, flags);
  }

  *str = '\0';
  return str - buf;
}

int sprintf(char *buf, const char *fmt, ...)
{
  va_list args;
  int n;

  va_start(args, fmt);
  n = vsprintf(buf, fmt, args);
  va_end(args);

  return n;
}

int vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
  char temp_buf[size];
  int result = vsprintf(temp_buf, fmt, args);

  if (size > 0) {
    size_t copy_len = (size - 1 < (size_t)result) ? size - 1 : (size_t)result;
    strncpy(buf, temp_buf, copy_len);
    buf[copy_len] = '\0';
  }

  return result;
}

int snprintf(char *buf, size_t size, const char *fmt, ...)
{
  va_list args;
  int res;

  va_start(args, fmt);
  res = vsnprintf(buf, size, fmt, args);
  va_end(args);

  return res;
}

int asprintf(char **str, const char *format, ...)
{
  va_list args, args_copy;
  int size, res;

  va_start(args, format);
  va_copy(args_copy, args);

  size = vsnprintf(NULL, 0, format, args_copy);
  va_end(args_copy);

  if (size < 0) {
    va_end(args);
    return -1;
  }

  *str = (char *)malloc(size + 1);
  if (*str == NULL) {
    va_end(args);
    return -1;
  }

  res = vsnprintf(*str, size + 1, format, args);
  va_end(args);
  if (res < 0) {
    free(*str);
    *str = NULL;
    return -1;
  }

  return res;
}

int printf(const char *format, ...) {
  const int buffer_size = 1024;
  char buffer[buffer_size];
  va_list args;
  int len;

  va_start(args, format);
  len = vsnprintf(buffer, buffer_size, format, args);
  va_end(args);

  if (len < 0) {
    return -1;
  }

  _write(1, buffer, (size_t)len);
  return len;
}

int _vfprintf(FILE *s, const char *fmt, va_list args, unsigned int mode_flags)
{
  char *formatted_str = NULL;
  int result = asprintf(&formatted_str, fmt, args);

  if (result == -1 || formatted_str == NULL) {
    return -1;
  }

  size_t len = strlen(formatted_str);

  if (_write(s->fd, formatted_str, len) < 0){ /* fwrite */
    free(formatted_str);
    return -1;
  }

  free(formatted_str);
  return len;
}

int fprintf(FILE *stream, const char *fmt, ...)
{
  va_list arg;
  int done;

  va_start (arg, fmt);
  done = _vfprintf(stream, fmt, arg, 0);
  va_end(arg);

  return done;
}
