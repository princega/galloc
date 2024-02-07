#include "arena.h"
#include <stdio.h>
#include <assert.h>

Arena init(uint8_t* ptr, size_t capacity){
  Arena a = {
    .total = capacity,
    .size = 0,
    .beg = ptr,
  };
  return a;
}

uint8_t* allocate(Arena* a, size_t s){
  if(a->size + s > a -> total){
    uint8_t* ptr = NULL;
    return ptr;
  }
  uint8_t* ptr = a->beg;
  ptr += a->size;
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
  printf("Starting Address = %p\n",a->beg);
}

int main(){



  return 0;
}
