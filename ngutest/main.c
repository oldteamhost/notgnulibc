#include "../assert.h"
#include "../unistd.h"
#include "../ngusyst/malloc.h"
#include "../ngubits/types.h"

int main(void)
{
  printf("Hello, world!\n");

  /* _brk() */
  void* original_brk = _brk(NULL);
  void* new_brk = (void*)((__uintptr_t)original_brk + 4096);
  void* result = _brk(new_brk);
  assert(result == new_brk);
  result = _brk(original_brk);
  assert(result == original_brk);

  /* _sbrk() */
  void* _original_brk = _sbrk(0);
  __intptr_t increment = 4096;
  void* _new_brk = _sbrk(increment);
  assert(_new_brk != (void*)-1);
  void* _result = _sbrk((__intptr_t)(_original_brk - _new_brk));
  assert(_result != (void*)-1);

  /* malloc() */
  int* ptr_malloc = (int*)malloc(5 * sizeof(int));
  assert(ptr_malloc != NULL);
  free(ptr_malloc);

  /* calloc() */
  int* ptr_calloc = (int*)calloc(5, sizeof(int));
  assert(ptr_calloc != NULL);
  free(ptr_calloc);

  printf("Goodbye, world!\n");
  return 0;
}
