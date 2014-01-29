#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define MAINWIN_WIDTH 1280
#define MAINWIN_HEIGHT 800

int main(int argc, char* argv[]) {

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;


    SDL_Init(SDL_INIT_VIDEO);


    window = SDL_CreateWindow(
        "CoreWarReloaded",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        MAINWIN_WIDTH,
        MAINWIN_HEIGHT,
        0
    );


    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bitmapSurface = SDL_LoadBMP("test.bmp");

    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
    SDL_RenderPresent(renderer);
    }


    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
