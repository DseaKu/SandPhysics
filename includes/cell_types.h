#ifndef CELL_TYPES_H
#include "std_includes.h"

#define CELL_TYPES_H
#define CELL_LENGTH 5

typedef enum { EMPTY = 0, SAND = 1, WATER = 2 } CellId_t;

typedef struct Color_t {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t occapacity;
} Color;

typedef struct Cell_t {
  CellId_t cell_id;
  uint32_t life_time;
  uint32_t velocity;
  Color color;
} Cell_t;

#endif // CELL_TYPES_H
