#include "cell_physic.h"

void update_cell_physic(Cell read_cell_t, const CellMatrix read_matrix,
                        CellMatrix *p_update_matrix, uint32_t x, uint32_t y) {
  // Determine cell id
  switch (read_cell_t.cell_id) {
  case EMPTY:
    break;

  case SAND:
    sand_physic(read_cell_t, read_matrix, p_update_matrix, x, y);
    break;
  }
}

void sand_physic(Cell read_cell_t, const CellMatrix read_matrix,
                 CellMatrix *p_update_matrix, uint32_t x, uint32_t y) {

  // Stay if cell is ground
  if (y == MATRIX_HEIGHT - 1) {
    (*p_update_matrix)[x][y].cell_id = SAND;
  }

  // Try to move down,
  // if under cell is empty
  else if (read_matrix[x][y + 1].cell_id == EMPTY) {
    (*p_update_matrix)[x][y + 1].cell_id = SAND;
  }

  // Try to move down-right, if down-right is empty and within bounds
  else if (x < MATRIX_WIDTH - 1 && read_matrix[x + 1][y + 1].cell_id == EMPTY) {

    (*p_update_matrix)[x + 1][y + 1].cell_id = SAND;
  }

  // Try to move down-left, if down-left is empty and within bounds
  else if (x > 0 && read_matrix[x - 1][y + 1].cell_id == EMPTY) {

    (*p_update_matrix)[x - 1][y + 1].cell_id = SAND;
  }

  // If no movement possible, stay in current position
  else {
    (*p_update_matrix)[x][y].cell_id = SAND;
  }
}
