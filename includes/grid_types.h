#ifndef GRAVITY_TYPES_H
#define GRAVITY_TYPES_H

// Libraries
#include "sdl_utils.h"
#include <stdint.h>

// Constants
#define CELL_LENGTH 5
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_LENGTH)
#define GRID_WIDTH (WINDOW_WIDTH / CELL_LENGTH)

// Type definitions
typedef uint32_t Grid[GRID_WIDTH][GRID_HEIGHT];

#endif // GRAVITY_TYPES_H
