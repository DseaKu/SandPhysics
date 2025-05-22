#ifndef GRAVITY_ENGINE_H
#define GRAVITY_ENGINE_H

#include "../../includes/grid_types.h"
#include "../../includes/sdl_utils.h"

// Constants
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_LENGTH)
#define GRID_WIDTH (WINDOW_WIDTH / CELL_LENGTH)

// Function declarations
void updating_cells(const Grid current_grid, Grid *update_grid);
void synchronize_grids(Grid *current_grid, Grid *update_grid);
void rendering_grid(const Grid render_grid, SDL_Renderer *renderer);

#endif // GRAVITY_ENGINE_H
