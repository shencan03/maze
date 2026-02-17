#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define WINDOW_W 1920           // Defined as a placeholder. Both renderer and window adapts to SDL_WINDOW_FULLSCREEN_DESKTOP
#define WINDOW_H 1080
#define METAL_MULTIP 2

int renderer_w_px, renderer_h_px;

// Function to draw maze using SDL_Point* array
void draw_maze(SDL_Renderer *renderer, const SDL_Point *points, int count);

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    bool quit = false;

    // Declare window and renderer
    SDL_Window *window;
    SDL_Renderer *renderer;

    // Initiate window and renderer
    window = SDL_CreateWindow("LAAAAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_METAL | SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Get renderer drawable pixel size
    SDL_GetRendererOutputSize(renderer, &renderer_w_px, &renderer_h_px);
    printf("renderer w in pixels: %d\nrenderer h in pixels: %d\n", renderer_w_px, renderer_h_px);
    
    /*
    SDL_Point points[5];
    int xi, yi, i;
    i = 0; xi = 0; yi = 0;
    for(i = 0; i < 5;i++)
    {
        points[i] = (SDL_Point) {xi, yi};
        xi++;
        yi++;
    }
    */
    SDL_Point points[2];
    points[0] = (SDL_Point) {0, 0};
    points[1] = (SDL_Point) {renderer_w_px, renderer_h_px};

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

        // Draw lines
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        // SDL_RenderDrawLine(renderer, 0, 0, 0, 1);
        SDL_RenderDrawLines(renderer, points, 2);
        // Render everything
        SDL_RenderPresent(renderer);
    }
    return 0;
}

/*void draw_maze(SDL_Renderer *renderer, const SDL_Point *points, int count)
{
    
}
*/

