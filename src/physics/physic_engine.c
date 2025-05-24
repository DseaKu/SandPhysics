#include "physik_engine.h"

void updating_cells(const Grid_t current_grid, Grid_t *update_grid) {

  for (uint x = 0; x < GRID_WIDTH; x++) {
    for (uint y = 0; y < GRID_HEIGHT; y++) {

      // Found cell in grid
      if (current_grid[x][y].cell_id != 0) {
        //
        // // Stay if cell is ground
        // if (y == GRID_HEIGHT - 1) {
        //   (*update_grid)[x][y] = 1;
        // }
        //
        // // Try to move down, if under cell is empty
        // else if (current_grid[x][y + 1] == 0) {
        //   (*update_grid)[x][y + 1] = 1;
        // }
        //
        // // Try to move down-right, if down-right is empty and within bounds
        // else if (x < GRID_WIDTH - 1 && current_grid[x + 1][y + 1] == 0) {
        //
        //   (*update_grid)[x + 1][y + 1] = 1;
        // }
        //
        // // Try to move down-left, if down-left is empty and within bounds
        // else if (x > 0 && current_grid[x - 1][y + 1] == 0) {
        //
        //   (*update_grid)[x - 1][y + 1] = 1;
        // }
        //
        // // If no movement possible, stay in current position
        // else {
        //   (*update_grid)[x][y] = 1;
        //}
      }
    }
  }
}

// Synchronise grids
void synchronize_grids(Grid_t *current_grid, Grid_t *update_grid) {
  for (uint x = 0; x < GRID_WIDTH; x++) {
    for (uint y = 0; y < GRID_HEIGHT; y++) {
      (*current_grid)[x][y] = (*update_grid)[x][y];
    }
  }
}

// Iterate grid and render cells
void rendering_grid(const Grid_t render_grid, SDL_Renderer *renderer) {
  for (uint y = 0; y < GRID_HEIGHT; y++) {
    for (uint x = 0; x < GRID_WIDTH; x++) {
      if (render_grid[x][y].cell_id == 1) {

        // Draw a red rectangle
        SDL_Rect rect = {x * CELL_LENGTH, y * CELL_LENGTH, CELL_LENGTH,
                         CELL_LENGTH};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
      }
    }
  }
}
