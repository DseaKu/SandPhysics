#include "../includes/grid_types.h"
#include "input/mouse_handler.h"
#include "physics/physik_engine.h"

// 16 -> 60 fps
#define GAME_SPEED 8

int main(void) {

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

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
    return 1;
  }

  // Create a renderer for the window
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window,
                         -1, // index of the rendering driver to initialize
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Main loop flag
  int quit = 0;

  // Event handler
  SDL_Event e;

  // Rendering grid matrix
  Grid render_grid = {0};

  // Main application loop
  while (!quit) {

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {

      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = 1;
      }

      // Process events
      else {
        handle_mouse_events(e, &render_grid);
      }
    }

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Add all squares to render matrix
    rendering_grid(render_grid, renderer);

    // Updating cells
    Grid update_grid = {0};
    updating_cells(render_grid, &update_grid);

    // Synchronize grids
    synchronize_grids(&render_grid, &update_grid);

    // Update the screen
    SDL_RenderPresent(renderer);

    SDL_Delay(GAME_SPEED);
  }

  // Destroy renderer and window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
}
