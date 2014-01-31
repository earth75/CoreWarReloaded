#include "text.h"
#include "RedCode.h"

#define MAINWIN_WIDTH 1280
#define MAINWIN_HEIGHT 800




int main(int argc, char* argv[]) {

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *fondSurface = NULL;
    SDL_Texture *fondTex = NULL;

    char quit = 0;

    TTF_Font* tech;
    SDL_Surface *surftext = NULL;
    SDL_Texture *textTexture;

    SDL_Rect TextLocation;


    printf("ok");
    Instruction Core[CORESIZE+1];
    printf("ok");
    initMARS(&Core);

    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();
    char* text = malloc(17 * sizeof(char));
    strcpy(text, "CoreWarsReloaded");

    window = SDL_CreateWindow(
        "CoreWarReloaded",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        MAINWIN_WIDTH,
        MAINWIN_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );


    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    fondSurface = IMG_Load("C:/Users/Alexis/Documents/Projets C/CoreWarReloaded/bin/Debug/fond_dark.png");

    fondTex = SDL_CreateTextureFromSurface(renderer, fondSurface);
    SDL_FreeSurface(fondSurface);

    tech = loadfont("C:/Users/Alexis/Documents/Projets C/CoreWarReloaded/bin/Debug/kongtext.ttf", 20);
	surftext = drawtext(tech, 255, 255, 255, 70, 0, 0, 0, 0, text, solid);
	textTexture = SDL_CreateTextureFromSurface(renderer, surftext);

	TextLocation.h = surftext->h;
    TextLocation.w = surftext->w;
    TextLocation.x = 20;
    TextLocation.y = 20;

    SDL_FreeSurface(surftext);

    while (!quit) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
                switch(e.type){
                case SDL_QUIT:
                                quit = 1;
                                break;
                case SDL_TEXTINPUT:
                                break;
                case (SDL_KEYDOWN):
                                if(e.key.keysym.sym == SDLK_ESCAPE) quit = 1;
                                break;
                    }
                }


    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, fondTex, NULL, NULL);
    SDL_RenderCopy(renderer, textTexture, NULL, &TextLocation);
    SDL_RenderPresent(renderer);
    }


    SDL_DestroyTexture(fondTex);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
