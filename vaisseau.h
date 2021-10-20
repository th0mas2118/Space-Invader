#pragma once
#include "fonctions_SDL.h"

//Structure vaisseau
typedef struct vaisseau_s vaisseau_t;
struct vaisseau_s{
    int vie;
    int vitesse;
    SDL_Rect DestR;
};


//Fonction gestion vaisseau
void Depart(vaisseau_t*, int W, int H, int V);
void deplacerGauche(vaisseau_t* v);
void deplacerDroite(vaisseau_t* v);