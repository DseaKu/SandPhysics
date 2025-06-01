#include "mouse_handler.h"

void handle_mouse_events(SDL_Event e, CellMatrix_t *p_render_matrix) {

  switch (e.type) {

  // Handle mouse click
  case SDL_MOUSEBUTTONDOWN:
    if (e.button.button == SDL_BUTTON_LEFT) {
      set_cell(p_render_matrix, e.motion.x, e.motion.y);
    }
    break;

  // Handle mouse motion while button is pressed
  case SDL_MOUSEMOTION:
    if (e.motion.state & SDL_BUTTON_LMASK) {
      set_cell(p_render_matrix, e.motion.x, e.motion.y);
    }
    break;

  default:
    break;
  }
}

void set_cell(CellMatrix_t *p_render_matrix, int mouseX, int mouseY) {
  // Convert screen coordinates to matrix coordinates
  uint32_t gridX = mouseX / CELL_LENGTH;
  uint32_t gridY = mouseY / CELL_LENGTH;

  // Ensure coordinates are within bounds
  if (gridX - 1 > 0 && gridX < MATRIX_WIDTH && gridY > 0 &&
      gridY < MATRIX_HEIGHT) {
    (*p_render_matrix)[gridX][gridY].cell_id = SAND;
  }
}
