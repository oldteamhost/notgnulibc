#include "../assert.h"
#include "../stdlib.h"
#include "../ngusyst/printf.h"
#include "../ngusyst/syscall.h"
#include <sys/syscall.h>

int main(void)
{
  const char* conv_t = "123.2";

  double check = atof(conv_t);
  assert(check == 123.2);

  const char* x = "10";
  const char* y = "9";
  printf("Hello, world!\n");

  const char *message = "Hello, syscall through glibc!\n";
  size_t length = strlen(message);
  syscall(SYS_write, 1, message, length);

  assert(atoi(x) == atoi(y));
  printf("Goodbye, world!\n");
  return 0;
}
