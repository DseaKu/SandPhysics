#include "cell_physic.h"
#include "physik_engine.h"

void cal_physic_cell_matrix(CellMatrix read_matrix,
                            CellMatrix *p_write_matrix) {
  for (uint x = 0; x < GRID_WIDTH; x++) {
    for (uint y = 0; y < GRID_HEIGHT; y++) {

      // Found cell in grid
      if (read_matrix[x][y].cell_id != 0) {

        update_cell_physic(read_matrix[x][y], p_write_matrix);
      }
    }
  }
}

// Synchronise matrices
void synchronize_matrices(CellMatrix *current_grid, CellMatrix *update_grid) {
  for (uint x = 0; x < GRID_WIDTH; x++) {
    for (uint y = 0; y < GRID_HEIGHT; y++) {
      (*current_grid)[x][y] = (*update_grid)[x][y];
    }
  }
}

// Render cells
void rendering_matrices(const CellMatrix render_grid,
                        SDL_Renderer *p_renderer) {
  for (uint y = 0; y < GRID_HEIGHT; y++) {
    for (uint x = 0; x < GRID_WIDTH; x++) {
      if (render_grid[x][y].cell_id != 0) {

        // Draw a red rectangle
        SDL_Rect rect = {x * CELL_LENGTH, y * CELL_LENGTH, CELL_LENGTH,
                         CELL_LENGTH};
        SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(p_renderer, &rect);
      }
    }
  }
}
