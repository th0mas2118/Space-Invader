#ifndef BIBLIO_H
#define BIBLIO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "math.h"


#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SHIP_SIZE 32 //A MODIFIER
#define VERTICAL_DIST 2 * SHIP_SIZE//A MODIFIER
#define MISSILE_SIZE 8//A MODIFIER

#define NB_ENEMIES 10 //A MODIFIER
#define NB_MISSILES 15 //A MODIFIER

#define MISSILE_SPEED 10//A MODIFIER
#define MOVING_STEP 10//A MODIFIER
#define ENEMY_SPEED 1//A MODIFIER

#define PERDU 1
#define PARFAIT 2
#define GAGNE 3
#define EN_COURS 4

#endif