#include "gravity_engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

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
  render_grid[4][8] = 1;
  render_grid[4][2] = 1;
  render_grid[8][3] = 1;
  // Main application loop
  while (!quit) {

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      // User requests quit
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
    }

    // Clear screen with a color (here: white)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Iterate grid and render rects
    for (uint y = 0; y < GRID_HEIGHT; y++) {
      for (uint x = 0; x < GRID_WIDTH; x++) {
        if (render_grid[x][y] == 1) {

          // Draw a red rectangle
          SDL_Rect rect = {x * SQUARE_LENGTH, y * SQUARE_LENGTH, SQUARE_LENGTH,
                           SQUARE_LENGTH};
          SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
          SDL_RenderFillRect(renderer, &rect);
        }
      }
    }

    // Update grid
    Grid update_grid = {0};

    updating_grid(render_grid);

    for (uint x = 0; x < GRID_WIDTH; x++) {
      for (uint y = 0; y < GRID_HEIGHT; y++) {

        // Gravity logic
        // Found square in grid
        if (render_grid[x][y] != 0) {

          // Stay if square is ground
          if (y == GRID_HEIGHT - 1) {
            update_grid[x][y] = 1;
          }

          // Try to move down, if under square is empty
          else if (render_grid[x][y + 1] == 0) {
            update_grid[x][y + 1] = 1;
          }

          // Try to move down-right, if down-right is empty
          else if (render_grid[x + 1][y + 1] == 0) {

            update_grid[x + 1][y + 1] = 1;
          }
          //
          // Try to move down-left, if down-left is empty
          else if (render_grid[x - 1][y - 1] == 0) {

            update_grid[x - 1][y - 1] = 1;
          }
        }
      }
    }

    // Synchronise grids
    for (uint x = 0; x < GRID_WIDTH; x++) {
      for (uint y = 0; y < GRID_HEIGHT; y++) {
        render_grid[x][y] = update_grid[x][y];
      }
    }

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
