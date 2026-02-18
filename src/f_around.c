#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define WINDOW_W 1920           // Defined as a placeholder. Both renderer and window adapts to SDL_WINDOW_FULLSCREEN_DESKTOP
#define WINDOW_H 1080
#define METAL_MULTIP 2
#define RECT_W 24
#define RECT_H 24

int renderer_px_w, renderer_px_h;

int main(int argc, char *argv[])
{
    // Seed random
    srand((unsigned) time(NULL));

    // Init SDL lib
    SDL_Init(SDL_INIT_EVERYTHING);
    bool quit = false;

    // Declare window and renderer
    SDL_Window *window;
    SDL_Renderer *renderer;

    // Initiate window and renderer
    window = SDL_CreateWindow("LAAAAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_METAL | SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Get renderer drawable pixel size
    SDL_GetRendererOutputSize(renderer, &renderer_px_w, &renderer_px_h);
    printf("renderer w in pixels: %d\nrenderer h in pixels: %d\n", renderer_px_w, renderer_px_h);
    
    // main app loop
    SDL_Event loop_event;
    while(!quit)
    {
        // Handle exit
        SDL_PollEvent(&loop_event);
        if(loop_event.type == SDL_QUIT)
            quit = true;

        // BACKGROUND COLOR
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Render everything
        SDL_RenderPresent(renderer);
    }

    return 0;
}
