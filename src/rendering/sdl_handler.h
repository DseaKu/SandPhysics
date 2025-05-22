#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H

#include "../../includes/sdl_utils.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

SDL_Window *create_sdl_window();

SDL_Renderer *create_sdl_renderer(SDL_Window *window);
#endif // !SDL_HANDLER_H
