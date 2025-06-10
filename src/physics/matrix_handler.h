#ifndef MATRIX_HANDLER_H
#define MATRIX_HANDLER_H

#include "../../includes/cell_matrix.h"
#include "../../includes/sdl_utils.h"
#include "cell_handler.h"

// Function declarations
void cal_physic_cell_matrix(const CellMatrix_t read_matrix,
                            CellMatrix_t *p_write_matrix);

void synchronize_matrices(CellMatrix_t *p_read_matrix,
                          CellMatrix_t *p_write_matrix);

#endif // MATRIX_HANDLER_H
