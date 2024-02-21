#include "arena/arena.c"
#include <assert.h>
#include <stdio.h>

int main(void) {
  uint8_t mem[1024 * 1024];
  Arena a1 = init(mem, 7);
  Arena a2 = init(mem + 7, 1024 * 1024 - 7);
  int *i1 = allocate(&a1, 16, sizeof(int));
  int *i2 = allocate(&a2, 16,  sizeof(int));
  puts("Write i1...");
  *i1 = 42;
  puts("Read i1...");
  printf("%d\n", *i1);
  puts("Write i2...");
  *i2 = 42;
  puts("Read i2...");
  printf("%d\n", *i2);
}
