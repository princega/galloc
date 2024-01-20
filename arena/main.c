#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct {
  size_t total;
  size_t size;
  uint8_t* data_ptr;
} Arena;

Arena arena_init(size_t capacity){
  void* d = malloc(capacity*sizeof(uint8_t));
  Arena arena = {
    .total = capacity,
    .size = 0,
    .data_ptr = d,
  };
  return arena;
}

void print(Arena* a){
  printf("Size = %lu\nCapacity = %lu\n", a->size, a->total);
}

void* alloc(Arena* a, size_t s){
  assert(a->size+s < a->total);
  uint8_t data[s];
  void* d = &data;
  a->size += s;
  return d;
}

void free_arena(Arena* a){
  a->size = 0;
  a->total = 0;
  free(a->data_ptr);
}

int main(){
  Arena a = arena_init(1024);

}
