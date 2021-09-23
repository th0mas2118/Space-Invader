#include "fonctions_SDL.h"

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer){
	SDL_Surface * image = SDL_LoadBMP(nomfichier);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	return texture;
}
