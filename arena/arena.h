#include <stddef.h>
#include <stdint.h>

typedef struct{
  size_t total;
  size_t size;
  uint8_t* beg;
} Arena;

Arena init (uint8_t* pool_ptr, size_t capacity);
uint8_t* allocate(Arena* a, size_t s, size_t parameter);
void freea(Arena* a);
size_t findi(size_t current, size_t parameter, size_t s);
void info (Arena* a);
