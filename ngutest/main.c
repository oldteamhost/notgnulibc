#include "../assert.h"
#include "../stdlib.h"
#include "../ngusyst/printf.h"

int main(void)
{
  const char* x = "10";
  const char* y = "9";
  printf("Hello, world!\n");
  assert(atoi(x) == atoi(y));
  printf("Goodbye, world!\n");
  return 0;
}
