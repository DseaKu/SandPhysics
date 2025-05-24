#ifndef GRAVITY_TYPES_H
#define GRAVITY_TYPES_H

#include "cell_types.h"
#include "sdl_utils.h"
#include <stdint.h>

#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_LENGTH)
#define GRID_WIDTH (WINDOW_WIDTH / CELL_LENGTH)

// Type definitions
typedef Cell_t Grid_t[GRID_WIDTH][GRID_HEIGHT];

#endif // GRAVITY_TYPES_H
