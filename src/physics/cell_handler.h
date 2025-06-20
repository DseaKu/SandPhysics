#ifndef CELL_HANDLER_H
#define CELL_HANDLER_H
#include "../../includes/cell_matrix.h"
#include "../../includes/cell_types.h"

void cal_physic_cell(Cell_t read_cell, const CellMatrix_t read_matrix,
                     CellMatrix_t *p_write_matrix, uint32_t x, uint32_t y);

void sand_physic(const CellMatrix_t read_matrix, CellMatrix_t *p_write_matrix,
                 uint32_t x, uint32_t y);
#endif // CELL_HANDLER_H
