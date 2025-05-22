#include "../includes/grid_types.h"
#include "input/mouse_handler.h"
#include "physics/physik_engine.h"
#include "rendering/sdl_handler.h"
#include <SDL2/SDL_render.h>

// 16 -> 60 fps
#define GAME_SPEED 8

int main(void) {

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window, and renderer. Check if initializing failed
  // Properties defined in sdl_handler.c
  SDL_Window *window = create_sdl_window();
  SDL_Renderer *renderer = create_sdl_renderer(window);

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
