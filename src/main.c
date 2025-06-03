#include "../includes/cell_matrix.h"
#include "input/mouse_handler.h"
#include "physics/physik_engine.h"
#include "rendering/sdl_handler.h"
#include <SDL2/SDL_render.h>

// 16 -> 60 fps
#define GAME_SPEED 16

int main(void) {

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window, and renderer. Check if initializing failed
  // Properties defined in sdl_handler.c
  SDL_Window *p_window = create_sdl_window();
  SDL_Renderer *p_renderer = create_sdl_renderer(p_window);

  // Main loop flag
  bool is_quit = false;

  // Event handler
  SDL_Event e;

  CellMatrix_t render_matrix = {0};

  MouseStatus_t MouseStatus = {.is_l_hold = false};

  // Main loop
  while (!is_quit) {

    if (SDL_PollEvent(&e) == true) {
      // Handle events on queue
      while (SDL_PollEvent(&e) == true) {

        // User requests quit
        if (e.type == SDL_QUIT) {
          is_quit = true;
        }
        // Process events
        else {
          handle_mouse_events(e, &render_matrix, &MouseStatus);
        }
      }
    }
    // If mouse is hold
    else if (MouseStatus.is_l_hold) {
      set_cell(&render_matrix, MouseStatus.x, MouseStatus.y);
    }

    // Clear screen
    SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);
    SDL_RenderClear(p_renderer);

    // Add all cells to be rendered to the renderer
    rendering_matrices(render_matrix, p_renderer);

    // Updating cells
    CellMatrix_t update_matrix = {0};
    cal_physic_cell_matrix(render_matrix, &update_matrix);

    // Synchronize matrices
    synchronize_matrices(&render_matrix, &update_matrix);

    // Update the screen
    SDL_RenderPresent(p_renderer);

    SDL_Delay(GAME_SPEED);
  }

  // Destroy renderer and window
  SDL_DestroyRenderer(p_renderer);
  SDL_DestroyWindow(p_window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
}
