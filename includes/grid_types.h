#ifndef GRAVITY_TYPES_H
#define GRAVITY_TYPES_H

// Libraries
#include "sdl_utils.h"
#include <stdint.h>

// Constants
#define SQUARE_LENGTH 10
#define GRID_HEIGHT (WINDOW_HEIGHT / SQUARE_LENGTH)
#define GRID_WIDTH (WINDOW_WIDTH / SQUARE_LENGTH)

// Type definitions
typedef uint32_t Grid[GRID_WIDTH][GRID_HEIGHT];

#endif // GRAVITY_TYPES_H
