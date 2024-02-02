#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>

#define MAX 8388608
uint8_t pool[MAX];

typedef struct {
  size_t total;
  size_t size;
  uint8_t* beg;
  uint8_t* end;
} Arena;

Arena init(size_t capacity){
  assert(capacity<=MAX);
  Arena a = {
    .total = capacity,
    .size = 0,
    .beg = &pool[0],
    .end = &pool[capacity-1],
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
  a->end = NULL;
}

void info(Arena* a){
  printf("Size = %lu\nCapacity = %lu\n", a->size, a->total);
  printf("Starting Address = %p\nEnding Address = %p\n",a->beg, a->end);
}

int main(){
  Arena a = init(78);
  Arena* p = &a;
  uint8_t* tr =  allocate(p, 7);
  sleep(2);
  tr = allocate(p, 2);
  sleep(2);

  //this should cause pool overflow
  tr = allocate(p, 304);

  return 0;
}
