#include "../assert.h"
#include "../ngusyst/printf.h"

int main(void)
{
  printf("Hello, world!\n");
  assert(10 == 9);
  printf("Goodbye world!\n");
  return 0;
}
