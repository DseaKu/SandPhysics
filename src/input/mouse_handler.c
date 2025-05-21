#include "mouse_handler.h"

void handle_mouse_events(SDL_Event e, Grid *render_grid) {

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
void handle_mouse_click(Grid *grid, int mouseX, int mouseY) {
  // Convert screen coordinates to grid coordinates
  int gridX = mouseX / SQUARE_LENGTH;
  int gridY = mouseY / SQUARE_LENGTH;

  // Ensure coordinates are within bounds
  if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 && gridY < GRID_HEIGHT) {
    (*grid)[gridX][gridY] = 1;
  }
}
