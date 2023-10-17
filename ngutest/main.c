#include "../assert.h"
#include "../unistd.h"
#include "../ngusyst/malloc.h"
#include "../stdlib.h"
#include "../ngubits/types.h"
#include <stdio.h>

int com_interg(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

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
  size_t size = 12;
  void *mem = malloc(size);
  assert(mem != NULL);
  free(mem);

  /* __getpagesize() */
  int page_size = __getpagesize();
  assert(page_size > 0);

  /* bsearch() */
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = 5;
  int* __result = (int*)bsearch(&key, arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), com_interg);
  assert(__result != NULL);
  assert(*__result == key);

  /* heapsort() */
  int _arr[] = {9, 2, 5, 1, 6, 3, 8, 4, 7};
  int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t nmemb = sizeof(_arr) / sizeof(_arr[0]);
  heapsort(_arr, nmemb, sizeof(int), com_interg);
  for (size_t i = 0; i < nmemb; i++) {
    assert(_arr[i] == expected[i]);
  }

  /* qsort() */
  int __arr[] = {9, 2, 5, 1, 6, 3, 8, 4, 7};
  int _expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t _nmemb = sizeof(__arr) / sizeof(__arr[0]);
  qsort(__arr, _nmemb, sizeof(int), com_interg);
  for (size_t i = 0; i < _nmemb; i++) {
    assert(__arr[i] == _expected[i]);
  }

  printf("Goodbye, world!\n");
  return 0;
}
