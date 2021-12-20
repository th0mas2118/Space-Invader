#ifndef RESSOURCES_H
#define RESSOURCES_H
#include "biblio.h"

typedef struct ressources_s
{
	SDL_Texture *background;
	SDL_Texture *vaisseau;
	SDL_Texture *ennemi;
	SDL_Texture *missile;
	TTF_Font *font;
} ressources_t;

void clean_ressources(ressources_t *ressources);

void init_ressources(SDL_Renderer *renderer, ressources_t *ressources);

void apply_background(SDL_Renderer *renderer, ressources_t *ressources);

#endif