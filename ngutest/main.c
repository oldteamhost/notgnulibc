#include "../ngusyst/malloc.h"

int main(void)
{
  size_t size = 12;
  void *mem = malloc(size);
  free(mem);
  return 0;
}
