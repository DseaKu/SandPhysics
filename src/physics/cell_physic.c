#include "cell_physic.h"

void update_cell_physic(Cell read_cell_t, CellMatrix *p_update_grid) {}
void sand_physics() {
  //
  // // Stay if cell is ground
  // if (y == GRID_HEIGHT - 1) {
  //   (*update_grid)[x][y] = 1;
  // }
  //
  // // Try to move down,
  // if under cell is empty
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
