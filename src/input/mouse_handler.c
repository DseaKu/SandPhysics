#include "mouse_handler.h"
#include <stdint.h>

void handle_mouse_events(SDL_Event e, CellMatrix_t *p_read_matrix,
                         MouseStatus_t *p_MouseStatus) {

  switch (e.type) {

  // Handle mouse click
  case SDL_MOUSEBUTTONDOWN:
    if (e.button.button == SDL_BUTTON_LEFT) {
      set_cell(p_read_matrix, e.motion.x, e.motion.y);
      p_MouseStatus->is_l_hold = true;
      p_MouseStatus->x = e.motion.x;
      p_MouseStatus->y = e.motion.y;
    }
    break;

  case SDL_MOUSEBUTTONUP:
    if (e.button.button == SDL_BUTTON_LEFT) {
      p_MouseStatus->is_l_hold = false;
    }
    break;

  // Handle mouse motion while button is pressed
  case SDL_MOUSEMOTION:
    if (e.motion.state & SDL_BUTTON_LMASK) {
      set_cell(p_read_matrix, e.motion.x, e.motion.y);
    }
    p_MouseStatus->x = e.motion.x;
    p_MouseStatus->y = e.motion.y;
    break;

  default:
    break;
  }
}

void set_cell(CellMatrix_t *p_read_matrix, uint32_t mouse_x, uint32_t mouse_y) {

  // Convert screen coordinates to matrix coordinates
  uint32_t matrix_x = mouse_x / CELL_LENGTH;
  uint32_t matrix_y = mouse_y / CELL_LENGTH;

  for (uint32_t i = 0; i < SPREAD_DENSITY; i++) {

    // Set random xy-coordinates
    uint32_t rand_x = matrix_x - SPREAD_SCOPE / 2 + rand() % SPREAD_SCOPE;
    uint32_t rand_y = matrix_y - SPREAD_SCOPE / 2 + rand() % SPREAD_SCOPE;

    // Set cell, ensure coordinates are within bounds
    if (rand_x - 1 > 0 && rand_x < MATRIX_WIDTH && rand_y > 0 &&
        rand_y < MATRIX_HEIGHT) {
      (*p_read_matrix)[rand_x][rand_y].CellId = SAND;
      (*p_read_matrix)[rand_x][rand_y].is_falling = true;
    }
  }
}
