#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_W 1920           // Defined as a placeholder. Both renderer and window adapts to SDL_WINDOW_FULLSCREEN_DESKTOP
#define WINDOW_H 1080
#define METAL_MULTIP 2
#define RECT_W 24
#define RECT_H 24

int main(int argc, char *argv[])
{
    // Seed random
    srand((unsigned) time(NULL));

    // Init SDL lib
    SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_SetHint(SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES, "1");
    bool quit = false;

    // Declare window and renderer
    SDL_Window *window;
    SDL_Renderer *renderer;

    // Initiate window and renderer
    window = SDL_CreateWindow("LAAAAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_RESIZABLE );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    // Get logical window size
    int window_w, window_h;
    SDL_GetWindowSize(window, &window_w, &window_h);
    printf("SDL_GetWindowSize -> w: %d // h: %d\n", window_w, window_h);

    // Get actual renderer dimensions
    int renderer_w, renderer_h;
    SDL_GetRendererOutputSize(renderer, &renderer_w, &renderer_h);
    printf("SDL_GetRendererOutputSize -> w: %d // h: %d\n", renderer_w, renderer_h);

    // check logical == physical dimensions
    if(!(renderer_w == window_w && renderer_h == window_h))
    {
      fprintf(stderr, "Logical and physical dimensions missmatch.\nExiting...\n");
      exit(EXIT_FAILURE);
    }

    // main app loop
    SDL_Event loop_event;
    while(!quit)
    {
        // Handle exit
        while(SDL_PollEvent(&loop_event))
        {
            if(loop_event.type == SDL_QUIT)
                quit = true;
        }

        // BACKGROUND COLOR
        SDL_SetRenderDrawColor(renderer, 123, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Render everything
        SDL_RenderPresent(renderer);
    }

    return 0;
}
