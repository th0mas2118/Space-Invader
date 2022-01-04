#include "world.h"

void init_data(world_t *world){
    world->gameover=0;
    world->score=0;
    world->vaisseau=malloc(sizeof(sprite_t));  
    world->etat_partie=EN_COURS;
    world->compteur=0;
    world->timer=0;
    for(int i =0;i<NB_ENEMIES;i++){
        world->enemies[i]=malloc(sizeof(sprite_t));
    }
    for(int i=0;i<NB_MISSILES;i++){
        world->missile[i]=malloc(sizeof(sprite_t));
    }
    init_sprite(world->vaisseau,SCREEN_WIDTH/2,SCREEN_HEIGHT-SHIP_SIZE,SHIP_SIZE,SHIP_SIZE,0,1);
    init_missile(world);
    init_enemies(world->enemies);
}

void init_music(world_t *world){
    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
    {
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        SDL_Quit();
    }
    world->music = Mix_LoadMUS("music/bushido.mp3");
    if (world->music == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
    }
    world->volume = 50;
    Mix_VolumeMusic(world->volume);
    Mix_PlayMusic(world->music, -1);
}

int is_game_over(world_t *world)
{
	return world->gameover;
}

int generate_number(int a, int b)
{
	return rand() % (b - a) + a;
}

void init_missile(world_t *world){
    for(int i=0;i<NB_MISSILES;i++){
        init_sprite(world->missile[i],world->vaisseau->x,world->vaisseau->y-(SHIP_SIZE/2),MISSILE_SIZE,MISSILE_SIZE,MISSILE_SPEED,0);
    }
}

void init_enemies(sprite_t *enemies[])
{
	for (int i = 0; i < NB_ENEMIES; i++)
	{
		init_sprite(enemies[i], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), (-SHIP_SIZE / 2 - i * VERTICAL_DIST), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1);
	}
}

int sprite_collide(sprite_t *sp2, sprite_t *sp1, world_t *world){
    if(sqrt(pow(sp1->x - sp2->x,2) + pow(sp1->y-sp2->y,2)) <= (sp1->h+sp2->h)/2){
        return 1;
    }
    return 0;
}

void handle_sprite_collide(sprite_t *sp1, sprite_t *sp2, world_t *world){
    if(sprite_collide(sp1,sp2,world)==1 && (sp1->is_visible ==1 && sp2->is_visible==1)){
        sp1->v=0;
        set_invisible(sp1);
        sp2->v=0;
        set_invisible(sp2);
        world->score +=1000;
    }
}

void depassement_enemies(world_t *world)
{
	for (int i = 0; i < NB_ENEMIES; ++i)
	{
		if (world->enemies[i]->y == SCREEN_HEIGHT + (SHIP_SIZE / 2))
		{
			world->enemies[i]->v = 0;
			world->enemies[i]->y = -SHIP_SIZE;
			set_invisible(world->enemies[i]);
			world->compteur++;
			if (world->etat_partie == EN_COURS)
			{
				world->score -= 500;
			}
		}
	}
}

void depassement_missile(world_t *world)
{
	for (int i = 0; i < NB_MISSILES; ++i)
	{
		if (world->missile[i]->y <= 0)
		{
			set_invisible(world->missile[i]);
		}
	}
}

void update_enemies(world_t *world)
{
	depassement_enemies(world);
	for (int i = 0; i < NB_ENEMIES; i++)
	{
		world->enemies[i]->y += world->enemies[i]->v;
		handle_sprite_collide(world->vaisseau, world->enemies[i], world);
		for (int j = 0 ; j < NB_MISSILES ; j++)
		{
			handle_sprite_collide(world->missile[j], world->enemies[i], world);
		}
	}
}

void update_missile(world_t *world){
    depassement_missile(world);
    for(int i=0;i<NB_MISSILES;i++){
        if(world->missile[i]->is_visible==0){
            world->missile[i]->y=world->vaisseau->y;
            world->missile[i]->x=world->vaisseau->x;
        }
        else{
            world->missile[i]->y -= world->missile[i]->v;
        }
    }
}


void clean_data(world_t *world){
    free(world->vaisseau);
    for(int i=0;i<NB_MISSILES;i++){
        free(world->missile[i]);
    }
    for(int i=0;i<NB_ENEMIES;i++){
        free(world->enemies[i]);
    }
}

void compute_game(world_t *world){
    if(world->vaisseau->is_visible==0){
        world->etat_partie=PERDU;
    }

    if(world->vaisseau->is_visible==1){
        world->etat_partie=PARFAIT;
        for(int i=0;i<NB_ENEMIES;i++){
            if(world->enemies[i]->is_visible==1){
                world->etat_partie=EN_COURS;
            }
        }
    }

    if(world->vaisseau->is_visible==1 && world->compteur!=0){
        world->etat_partie=GAGNE;
        for(int i=0;i<NB_ENEMIES;i++){
            if(world->enemies[i]->is_visible==1){
                world->etat_partie=EN_COURS;
            }
        }
    }
}

void update_data(world_t *world){
    compute_game(world);
    if (world->etat_partie != EN_COURS){
        ++world->timer;
    }
    if (world->timer > 500){
        world->gameover=1;
    }
    update_enemies(world);
    update_missile(world);
}
