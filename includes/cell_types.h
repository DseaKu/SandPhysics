#ifndef CELL_TYPES_H
#include "std_includes.h"

#define CELL_TYPES_H
#define CELL_LENGTH 5

typedef struct Color_t {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t occapacity;
} Color;

typedef struct Cell {
  uint8_t cell_id;
  uint32_t life_time;
  uint32_t velocity;
  Color color;
} Cell;

#endif // CELL_TYPES_H
