#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <assert.h>

typedef struct {
  size_t total;
  size_t size;
  uint8_t* beg;
} Arena;

Arena init(void* ptr, size_t capacity){
  Arena a = {
    .total = capacity,
    .size = 0,
    .beg = ptr,
  };
  return a;
}

uint8_t* allocate(Arena* a, size_t s){
  assert(a->size + s <= a->total);
  uint8_t* ptr = &pool[a->size+s-1];
  a->size += s;
  return ptr;
}

void freea(Arena* a){
  a->size = 0;
  a->total = 0;
  a->beg = NULL;
}

void info(Arena* a){
  printf("Size = %lu\nCapacity = %lu\n", a->size, a->total);
  printf("Starting Address = %p\nEnding Address = %p\n",a->beg, a->end);
}

int main(){



  return 0;
}