#ifndef CELL_PHYSIC_H
#define CELL_PHYSIC_H
#include "../../includes/cell_matrix.h"
#include "../../includes/cell_types.h"

void cal_physic_cell(Cell read_cell_t, const CellMatrix read_matrix,
                     CellMatrix *p_update_matrix, uint32_t x, uint32_t y);

void sand_physic(Cell read_cell_t, const CellMatrix read_matrix,
                 CellMatrix *p_update_matrix, uint32_t x, uint32_t y);
#endif // CELL_PHYSIC_H
