#include "cell_handler.h"

void cal_physic_cell(Cell_t read_cell, const CellMatrix_t read_matrix,
                     CellMatrix_t *p_write_matrix, uint32_t x, uint32_t y) {
  // Determine cell id
  switch (read_cell.CellId) {
  case EMPTY:
    break;

  case SAND:
    sand_physic(read_matrix, p_write_matrix, x, y);
    break;

  case WATER:
    break;

  case SOLID:
    break;

  default:
    break;
  }
}

void sand_physic(const CellMatrix_t read_matrix, CellMatrix_t *p_write_matrix,
                 uint32_t x, uint32_t y) {

  // Stay if cell is ground. Set not falling
  if (y == MATRIX_HEIGHT - 1) {
    (*p_write_matrix)[x][y].CellId = SAND;
    (*p_write_matrix)[x][y].is_falling = false;
  }

  // Try to move down, if down is empty or falling. Set falling
  else if (read_matrix[x][y + 1].CellId == EMPTY ||
           read_matrix[x][y + 1].is_falling == true) {
    (*p_write_matrix)[x][y + 1].CellId = SAND;
    (*p_write_matrix)[x][y + 1].is_falling = true;
  }

  // Try to move down-right, if down-right is empty and within bounds
  else if (x < MATRIX_WIDTH - 1 && read_matrix[x + 1][y + 1].CellId == EMPTY) {
    (*p_write_matrix)[x + 1][y + 1].CellId = SAND;
  }

  // Try to move down-left, if down-left is empty and within bounds
  else if (x > 0 && read_matrix[x - 1][y + 1].CellId == EMPTY) {
    (*p_write_matrix)[x - 1][y + 1].CellId = SAND;
  }

  // If no movement possible, stay in current position. Set not falling
  else {
    (*p_write_matrix)[x][y].CellId = SAND;
    (*p_write_matrix)[x][y].is_falling = false;
  }
}
