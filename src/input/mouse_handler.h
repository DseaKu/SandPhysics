#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "../../includes/cell_matrix.h"
#include "../../includes/cell_types.h"
#include "../../includes/sdl_utils.h"

void handle_mouse_events(SDL_Event e, CellMatrix *p_render_cell_matrix);
void handle_mouse_click(CellMatrix *p_cell_matrix, int mouseX, int mouseY);
#endif //  MOUSE_HANDLER_H
