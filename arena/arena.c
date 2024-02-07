#include "arena.h"
#include <stdio.h>
#include <math.h>

size_t findi(size_t current, size_t num){
  if(num<4) return current+num;
  else {
    float q = current;
    float w = num;
    q = ceil(q/w)*w;
    size_t y = q;
    return y;
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

uint8_t* allocate(Arena* a, size_t s){
  if(a->size + s > a -> total){
    uint8_t* ptr = NULL;
    return ptr;
  }
  uint8_t* ptr = a->beg;
  size_t temp = findi(a->size, s);
  ptr += temp;
  a->size = temp;
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
