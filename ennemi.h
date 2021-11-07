#include "fonctions_SDL.h"

#define NBENNEMI 10

typedef struct ennemi_s ennemi_t;
struct ennemi_s{
	int vie;
	SDL_Rect destR;
	SDL_Texture* imageEnnemi; 
};

//Fonction de gestion des ennemis

void initEnnemi(ennemi_t* ennemi, int x, int y);
 