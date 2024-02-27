#include "arena.h"
#include <stdio.h>
#include <math.h>

size_t findi(size_t current, size_t parameter){
  float r = current;
  float y = parameter;
  if(y<2) return current+parameter;
  else {
    r = ceil(r/y) * y;
    return (size_t)r;
  }
}

Arena init(uint8_t* ptr, size_t capacity){
  Arena a = {
    .total = capacity,
    .size = 0,
    .beg = ptr,
  };
  return a;
}

uint8_t* allocate(Arena* a, size_t s, size_t parameter){
  if(a->size + s > a -> total){
    uint8_t* ptr = NULL;
    return ptr;
  }
  uint8_t* ptr = a->beg;
  size_t temp = findi(a->size, parameter);
  ptr += temp;
  a->size = (temp + s-1);
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
