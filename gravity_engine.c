#include "gravity_engine.h"

void updating_grid(const Grid current_grid, Grid *update_grid) {

  for (uint x = 0; x < GRID_WIDTH; x++) {
    for (uint y = 0; y < GRID_HEIGHT; y++) {

      // Gravity logic
      // Found square in grid
      if (current_grid[x][y] != 0) {

        // Stay if square is ground
        if (y == GRID_HEIGHT - 1) {
          (*update_grid)[x][y] = 1;
        }

        // Try to move down, if under square is empty
        else if (current_grid[x][y + 1] == 0) {
          (*update_grid)[x][y + 1] = 1;
        }

        // Try to move down-right, if down-right is empty
        else if (current_grid[x + 1][y + 1] == 0) {

          (*update_grid)[x + 1][y + 1] = 1;
        }

        // Try to move down-left, if down-left is empty
        else if (current_grid[x - 1][y - 1] == 0) {

          (*update_grid)[x - 1][y - 1] = 1;
        }
      }
    }
  }
}

// Synchronise grids
void synchronize_grid(Grid *current_grid, Grid *update_grid) {
  for (uint x = 0; x < GRID_WIDTH; x++) {
    for (uint y = 0; y < GRID_HEIGHT; y++) {
      (*current_grid)[x][y] = (*update_grid)[x][y];
    }
  }
}
