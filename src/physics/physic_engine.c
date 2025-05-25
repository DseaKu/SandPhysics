#include "cell_physic.h"
#include "physik_engine.h"
#include <sys/types.h>

void cal_physic_cell_matrix(const CellMatrix read_matrix,
                            CellMatrix *p_write_matrix) {
  for (uint32_t x = 0; x < GRID_WIDTH; x++) {
    for (uint32_t y = 0; y < GRID_HEIGHT; y++) {

      // Find non-empty cell in cell matrix
      if (read_matrix[x][y].cell_id != EMPTY) {

        cal_physic_cell(read_matrix[x][y], read_matrix, p_write_matrix, x, y);
      }
    }
  }
}

// Synchronise matrices
void synchronize_matrices(CellMatrix *p_read_matrix,
                          CellMatrix *p_write_matrix) {
  for (uint32_t x = 0; x < GRID_WIDTH; x++) {
    for (uint32_t y = 0; y < GRID_HEIGHT; y++) {
      (*p_read_matrix)[x][y] = (*p_write_matrix)[x][y];
    }
  }
}

// Render cells
void rendering_matrices(const CellMatrix read_matrix,
                        SDL_Renderer *p_renderer) {
  for (uint32_t y = 0; y < GRID_HEIGHT; y++) {
    for (uint32_t x = 0; x < GRID_WIDTH; x++) {
      if (read_matrix[x][y].cell_id != EMPTY) {

        // Draw a square with cell color
        SDL_Rect rect = {x * CELL_LENGTH, y * CELL_LENGTH, CELL_LENGTH,
                         CELL_LENGTH};
        SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(p_renderer, &rect);
      }
    }
  }
}
