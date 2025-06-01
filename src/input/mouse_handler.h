#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "../../includes/cell_matrix.h"
#include "../../includes/cell_types.h"
#include "../../includes/sdl_utils.h"

void handle_mouse_events(SDL_Event e, CellMatrix_t *p_render_matrix);
void set_cell(CellMatrix_t *p_cell_matrix, int mouseX, int mouseY);
#endif //  MOUSE_HANDLER_H
