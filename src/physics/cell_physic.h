#ifndef CELL_PHYSIC_H
#define CELL_PHYSIC_H
#include "../../includes/cell_types.h"
#include "../../includes/grid_types.h"

void update_cell_physics(Cell *p_Cell, Grid *update_grid);
void sand_physics();
#endif // CELL_PHYSIC_H
