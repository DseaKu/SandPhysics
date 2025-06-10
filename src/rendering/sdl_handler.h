#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include "../../includes/cell_matrix.h"
#include "../../includes/sdl_utils.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

SDL_Window *create_sdl_window();

SDL_Renderer *create_sdl_renderer(SDL_Window *window);

void rendering_matrices(const CellMatrix_t read_matrix,
                        SDL_Renderer *p_renderer);
#endif // !SDL_HANDLER_H
