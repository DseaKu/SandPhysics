#ifndef GRAVITY_ENGINE_H
#define GRAVITY_ENGINE_H

#include "../../includes/cell_matrix.h"
#include "../../includes/sdl_utils.h"
#include "cell_physic.h"

// Constants
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_LENGTH)
#define GRID_WIDTH (WINDOW_WIDTH / CELL_LENGTH)

// Function declarations
void cal_physic_cell_matrix(CellMatrix read_matrix, CellMatrix *p_write_matrix);

void synchronize_matrices(CellMatrix *p_read_matrix,
                          CellMatrix *p_write_matrix);

void rendering_matrices(const CellMatrix read_matrix, SDL_Renderer *p_renderer);

#endif // GRAVITY_ENGINE_iamaH
