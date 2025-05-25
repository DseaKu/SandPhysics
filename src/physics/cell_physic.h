#ifndef CELL_PHYSIC_H
#define CELL_PHYSIC_H
#include "../../includes/cell_matrix.h"
#include "../../includes/cell_types.h"

void update_cell_physic(Cell read_cell_t, CellMatrix *p_update_grid, uint32_t x,
                        uint32_t y);
void sand_physics();
#endif // CELL_PHYSIC_H
