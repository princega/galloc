#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  size_t total;
  size_t size;
  uint8_t* data_ptr;
} Arena;

Arena arena_init(size_t capacity){
  void* d = malloc(capacity*sizeof(uint8_t));
  Arena arena {
    .total = capacity;
    .size = 0;
    .data_ptr = d;
  }
  return arena;
}


int main(){
  Arena a = arena_init(1024);

}
