#ifndef WORLD_H
#define WORLD_H
#include "biblio.h"
#include "sprite.h"
#include <SDL2/SDL_mixer.h>

typedef struct world_s
{
	sprite_t *vaisseau;					/*!< Sprite du vaisseau. */
	sprite_t *enemies[NB_ENEMIES];	/*!< Tableau d'ennemies. */
	sprite_t *missile[NB_MISSILES]; /*!< Sprite du missile. */
	int gameover;					/*!< Champ indiquant si l'on est à la fin du jeu. */
	int score;						/*!< Score.*/
	int etat_partie;
	int compteur;
	int timer;
	Mix_Music* music;
	Uint8 volume;
} world_t;

void init_data(world_t *world);

void clean_data(world_t *world);

int is_game_over(world_t *world);

void init_missile(world_t *world);

void init_enemies(sprite_t *enemies[]);

int generate_number(int a, int b);

void depassement_enemies(world_t *world);

void depassement_missile(world_t *world);

int sprite_collide(sprite_t *sp2, sprite_t *sp1, world_t *world);

void handle_sprite_collide(sprite_t *sp1, sprite_t *sp2, world_t *world);

void update_enemies(world_t *world);

void update_missile(world_t *world);

void compute_game(world_t *world);

void update_data(world_t *world);

void init_music(world_t *world);

#endif
