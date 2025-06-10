
#include "sdl_handler.h"

SDL_Window *create_sdl_window() {

  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("SDL2 Window",           // window title
                       SDL_WINDOWPOS_UNDEFINED, // initial x position
                       SDL_WINDOWPOS_UNDEFINED, // initial y position
                       WINDOW_WIDTH,            // width, in pixels
                       WINDOW_HEIGHT,           // height, in pixels
                       SDL_WINDOW_SHOWN         // flags
      );

  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_Quit();
  }
  return window;
}

SDL_Renderer *create_sdl_renderer(SDL_Window *window) {

  // Create a renderer for the window
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window,
                         -1, // index of the rendering driver to initialize
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  return renderer;
}

// Render cells
void rendering_matrices(const CellMatrix_t read_matrix,
                        SDL_Renderer *p_renderer) {
  for (uint32_t y = 0; y < MATRIX_HEIGHT; y++) {
    for (uint32_t x = 0; x < MATRIX_WIDTH; x++) {
      if (read_matrix[x][y].CellId != EMPTY) {

        // Draw a square with cell color
        SDL_Rect rect = {x * CELL_LENGTH, y * CELL_LENGTH, CELL_LENGTH,
                         CELL_LENGTH};
        SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(p_renderer, &rect);
      }
    }
  }
}
