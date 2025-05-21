#include "gravity_engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void handle_mouse_click(Grid *grid, int mouseX, int mouseY);
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

  Grid render_grid = {0};
  render_grid[4][2] = 1;

  // Main application loop
  while (!quit) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
      // Handle mouse click
      else if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (e.button.button == SDL_BUTTON_LEFT) {
          int mouseX, mouseY;
          SDL_GetMouseState(&mouseX, &mouseY);
          handle_mouse_click(&render_grid, mouseX, mouseY);
        }
      }
      // Handle mouse motion while button is pressed
      else if (e.type == SDL_MOUSEMOTION) {
        if (e.motion.state & SDL_BUTTON_LMASK) {
          int mouseX = e.motion.x;
          int mouseY = e.motion.y;
          handle_mouse_click(&render_grid, mouseX, mouseY);
        }
      }
    }

    // Clear screen with a color (here: white)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Add all squares to renderer
    rendering_grid(render_grid, renderer);

    // Updating grid
    Grid update_grid = {0};
    updating_grid(render_grid, &update_grid);

    synchronize_grid(&render_grid, &update_grid);

    // Update the screen
    SDL_RenderPresent(renderer);

    // 16 -> 60 fps
    SDL_Delay(16);
  }

  // Destroy renderer and window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
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
