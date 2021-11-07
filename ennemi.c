#include "ennemi.h"

void initEnnemi(ennemi_t* ennemi, int x, int y){
	printf("+1\n");
	ennemi -> vie = 1;
	ennemi -> destR.x = x;
	ennemi -> destR.y = y;
	ennemi -> destR.w = WIDTH_WINDOW/NBENNEMI;
	ennemi -> destR.h = WIDTH_WINDOW/NBENNEMI;
	ennemi -> imageEnnemi = charger_image("img/ennemy_spaceship.bmp", jeu.ecran);
} 