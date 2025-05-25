#ifndef GRAVITY_TYPES_H
#define GRAVITY_TYPES_H

#include "cell_types.h"
#include "sdl_utils.h"
#include "std_includes.h"

#define MATRIX_HEIGHT (WINDOW_HEIGHT / CELL_LENGTH)
#define MATRIX_WIDTH (WINDOW_WIDTH / CELL_LENGTH)

// Type definitions
typedef Cell CellMatrix[MATRIX_WIDTH][MATRIX_HEIGHT];

#endif // GRAVITY_TYPES_H
