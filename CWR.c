#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);


    window = SDL_CreateWindow(
        "CodeWarsReloaded",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,
        800,
        0
    );


    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
