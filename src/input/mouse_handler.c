#include "mouse_handler.h"

void handle_mouse_click(Grid *grid, int mouseX, int mouseY) {
  // Convert screen coordinates to grid coordinates
  int gridX = mouseX / SQUARE_LENGTH;
  int gridY = mouseY / SQUARE_LENGTH;

  // Ensure coordinates are within bounds
  if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 && gridY < GRID_HEIGHT) {
    (*grid)[gridX][gridY] = 1;
  }
}
