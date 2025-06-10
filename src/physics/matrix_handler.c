#include "matrix_handler.h"
#include "cell_handler.h"
#include <sys/types.h>

void cal_physic_cell_matrix(const CellMatrix_t read_matrix,
                            CellMatrix_t *p_write_matrix) {
  for (uint32_t x = 0; x < MATRIX_WIDTH; x++) {
    for (uint32_t y = 0; y < MATRIX_HEIGHT; y++) {

      // Find non-empty cell in cell matrix
      if (read_matrix[x][y].CellId != EMPTY) {

        cal_physic_cell(read_matrix[x][y], read_matrix, p_write_matrix, x, y);
      }
    }
  }
}

// Synchronise matrices
void synchronize_matrices(CellMatrix_t *p_read_matrix,
                          CellMatrix_t *p_write_matrix) {
  for (uint32_t x = 0; x < MATRIX_WIDTH; x++) {
    for (uint32_t y = 0; y < MATRIX_HEIGHT; y++) {
      (*p_read_matrix)[x][y] = (*p_write_matrix)[x][y];
    }
  }
}
