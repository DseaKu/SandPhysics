#ifndef CELL_TYPES_H
#define CELL_TYPES_H
#include <stdint.h>

#define CELL_LENGTH 5
typedef struct color_t {
  int8_t r;
  int8_t g;
  int8_t b;
  int8_t occapacity;
} color_t;

typedef struct cell_t {
  int8_t id;
  int32_t life_time;
  int32_t velocity;
  color_t color;
} cell_t;

#endif // CELL_TYPES_H
