#include "text.h"

#define MAINWIN_WIDTH 1280
#define MAINWIN_HEIGHT 800




int main(int argc, char* argv[]) {

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *bitmapSurface = NULL;
    SDL_Texture *bitmapTex = NULL;

    char quit = 0;

    TTF_Font* courrier;
    TTF_Font* tech;
    SDL_Surface *surftext = NULL;
    SDL_Texture *textTexture;
    char buf[] = "CoreWarReloaded";
    SDL_Rect TextLocation;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


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

    bitmapSurface = SDL_LoadBMP("fond_dark.bmp");

    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

    tech = loadfont("Tech.ttf", 80);
    courrier = loadfont("C:/windows/fonts/cour.ttf", 80);
	surftext = drawtext(tech, 255, 255, 255, 70, 0, 0, 0, 0, buf, blended);
	textTexture = SDL_CreateTextureFromSurface(renderer, surftext);

	TextLocation.h = surftext->h;
    TextLocation.w = surftext->w;
    TextLocation.x = 100;
    TextLocation.y = 100;

    SDL_FreeSurface(surftext);

    while (!quit) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
                switch(e.type){
                case SDL_QUIT : quit = 1;
                                break;
                case (SDL_KEYDOWN) :
                                if(e.key.keysym.sym == SDLK_ESCAPE) quit = 1;
                                if(e.key.keysym.sym == SDLK_UP) TextLocation.y = TextLocation.y - 5;
                                if(e.key.keysym.sym == SDLK_DOWN) TextLocation.y = TextLocation.y + 5;
                                if(e.key.keysym.sym == SDLK_RIGHT) TextLocation.x = TextLocation.x + 5;
                                if(e.key.keysym.sym == SDLK_LEFT) TextLocation.x = TextLocation.x - 5;
                                break;
                    }
                }


    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
    SDL_RenderCopy(renderer, textTexture, NULL, &TextLocation);
    SDL_RenderPresent(renderer);
    }


    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
