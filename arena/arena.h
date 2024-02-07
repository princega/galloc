#include <stddef.h>
#include <stdint.h>

typedef struct{
  size_t capacity;
  size_t size;
  uint8_t* p;
} Arena;

Arena init (uint8_t* pool_ptr, size_t capacity);
uint8_t* allocate(Arena* a, size_t s);
void freea(Arena* a);
void info (Arena* a);
