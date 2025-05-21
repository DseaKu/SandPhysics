#ifndef GRAVITY_ENGINE_H
#define GRAVITY_ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

// Constants
#define SQUARE_LENGTH 10

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1000
#define GRID_HEIGHT (WINDOW_HEIGHT / SQUARE_LENGTH)
#define GRID_WIDTH (WINDOW_WIDTH / SQUARE_LENGTH)

// Type definitions
typedef uint32_t Grid[GRID_WIDTH][GRID_HEIGHT];

// Function declarations
void updating_grid(const Grid current_grid, Grid *update_grid);
void synchronize_grid(Grid *current_grid, Grid *update_grid);
void rendering_grid(const Grid render_grid, SDL_Renderer *renderer);

#endif // GRAVITY_ENGINE_H
