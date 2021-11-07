#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


Jeu jeu;

void init(); 

void initFond();

void initMusic();

SDL_Texture *charger_image(const char* nomfichier, SDL_Renderer* renderer);

SDL_Texture *charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b);