#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "../../includes/cell_types.h"
#include "../../includes/grid_types.h"
#include "../../includes/sdl_utils.h"

void handle_mouse_events(SDL_Event e, Grid_t *render_grid);
void handle_mouse_click(Grid_t *grid, int mouseX, int mouseY);
#endif //  MOUSE_HANDLER_H
