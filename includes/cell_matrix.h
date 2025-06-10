#ifndef CELL_MATRIX_H
#define CELL_MATRIX_H

#include "cell_types.h"
#include "sdl_utils.h"
#include "std_includes.h"

#define MATRIX_HEIGHT (WINDOW_HEIGHT / CELL_LENGTH)
#define MATRIX_WIDTH (WINDOW_WIDTH / CELL_LENGTH)

// Type definitions
typedef Cell_t CellMatrix_t[MATRIX_WIDTH][MATRIX_HEIGHT];

#endif // CELL_MATRIX_H
