#include "SDL.h"

int main(int argc, char* argv[])
{
	// initialise
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }


    // create the window
    SDL_Window* window = SDL_CreateWindow(
        "My Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        768,
        0);

    if (!window) {
        SDL_Log("Failed to create the window: %s", SDL_GetError());
        return 1;
    }


    // configure the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );


    if (!renderer) {
        SDL_Log("Failed to create the renderer: %s", SDL_GetError());
        return 1;
    }


    //draws a light blue screen
    SDL_SetRenderDrawColor(
        renderer,
        184, 242, 230,    // RGB
        255                // A
    );

    // clear the back buffer
    SDL_RenderClear(renderer);

    // show the window
    SDL_RenderPresent(renderer);

    // delay 5 secs
    SDL_Delay(5000);

    // destroy the window
    SDL_DestroyWindow(window);

    // destroy the renderer
    SDL_DestroyRenderer(renderer);

    // Always be sure to clean up
    SDL_Quit();


	return 0;
}