#include "../assert.h"
#include "../unistd.h"
#include "../ngucrypt/md5.h"
#include "../ngusyst/malloc.h"
#include "../stdlib.h"
#include "../ngubits/types.h"
#include "../stdio.h"

int com_interg(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

int main(void)
{
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

  /* (s)rand() */
  srand(time(NULL));
  int secret = rand() % 1238949230 + 1;
  assert(secret != 0);

  /* md5 */
  const char* input_data = "hello";
  size_t input_length = strlen(input_data);

  char* _hex_hash = md5str(input_data, input_length);
  if (_hex_hash != NULL) {
    printf("MD5 Hash: %s\n", _hex_hash);
    free(_hex_hash);
  }

#include "../ngucrypt/sha256.h"
  /* sha256 */
  char* hex_hash = sha256str(input_data, input_length);
  if (hex_hash != NULL) {
    printf("SHA-256 Hash: %s\n", hex_hash);
    free(hex_hash);
  }

  /* sha512 */
#include "../ngucrypt/sha512.h"
  char* __hex_hash = sha512str(input_data, input_length);
  if (__hex_hash != NULL) {
    printf("SHA-512 Hash: %s\n", __hex_hash);
    free(__hex_hash);
  }

  /* open() */
#include "../ngubits/fcntl.h"
  int fd = open("kek.txt", O_RDWR, 0644);
  if (fd < 0) {
    printf("fuck!\n");
    return 1;
  }
  _write(fd, "Hello\n", 6);
  _write(fd, "Hello\n", 6);
  _write(fd, "Hello\n", 6);
  /* close() */
  _close(fd);

  FILE *fp;
  fp = fopen ("net.txt", "a");
  fprintf(fp, "kekekkek\n");
  fclose(fp);

  printf("Goodbye, world!\n");
  return 0;
}
