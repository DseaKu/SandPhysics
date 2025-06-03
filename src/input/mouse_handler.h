#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "../../includes/cell_matrix.h"
#include "../../includes/cell_types.h"
#include "../../includes/sdl_utils.h"

typedef struct MouseStatus_t {
  bool is_l_hold;
  uint32_t x;
  uint32_t y;
} MouseStatus_t;

void handle_mouse_events(SDL_Event e, CellMatrix_t *p_render_matrix,
                         MouseStatus_t *p_MouseStatus);
void set_cell(CellMatrix_t *p_cell_matrix, uint32_t mouseX, uint32_t mouseY);
#endif //  MOUSE_HANDLER_H
