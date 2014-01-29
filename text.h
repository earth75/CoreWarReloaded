#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


typedef enum {solid, shaded, blended} textquality;

SDL_Surface *drawtext(TTF_Font* fonttodraw, char fgR, char fgG, char fgB, char fgA, char bgR, char bgG, char bgB, char bgA, char text[], textquality quality);

TTF_Font* loadfont(char* file, int ptsize);


