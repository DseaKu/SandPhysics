#include "mouse_handler.h"

void handle_mouse_events(SDL_Event e, CellMatrix *render_grid) {

  // Handle mouse click
  if (e.type == SDL_MOUSEBUTTONDOWN) {
    if (e.button.button == SDL_BUTTON_LEFT) {
      int mouseX, mouseY;
      SDL_GetMouseState(&mouseX, &mouseY);
      handle_mouse_click(render_grid, mouseX, mouseY);
    }
  }
  // Handle mouse motion while button is pressed
  else if (e.type == SDL_MOUSEMOTION) {
    if (e.motion.state & SDL_BUTTON_LMASK) {
      int mouseX = e.motion.x;
      int mouseY = e.motion.y;
      handle_mouse_click(render_grid, mouseX, mouseY);
    }
  }
  // Handle mouse motion while button is pressed
  else if (e.type == SDL_MOUSEMOTION) {
    if (e.motion.state & SDL_BUTTON_LMASK) {
      int mouseX = e.motion.x;
      int mouseY = e.motion.y;
      handle_mouse_click(render_grid, mouseX, mouseY);
    }
  }
}
void handle_mouse_click(CellMatrix *grid, int mouseX, int mouseY) {
  // Convert screen coordinates to grid coordinates
  int gridX = mouseX / CELL_LENGTH;
  int gridY = mouseY / CELL_LENGTH;

  // Ensure coordinates are within bounds
  if (gridX >= 0 && gridX < MATRIX_WIDTH && gridY >= 0 &&
      gridY < MATRIX_HEIGHT) {
    (*grid)[gridX][gridY].cell_id = 1;
  }
}
