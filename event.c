#include "event.h"

void handle_event(SDL_Event *event, world_t *world, FILE *fichier){
    Uint8 *keystates;
    while(SDL_PollEvent(event)){
        if(event->type==SDL_QUIT){
            world->gameover=1;
        }
        
        if(event->type==SDL_KEYDOWN){
            if(event->key.keysym.sym==SDLK_RIGHT && world->vaisseau->x+SHIP_SIZE/2 <SCREEN_WIDTH){
                //printf("right\n");
                world->vaisseau->x= world->vaisseau->x +MOVING_STEP;
            }
            if(event->key.keysym.sym==SDLK_r){
                resetScore(fichier);
            }
            if(event->key.keysym.sym==SDLK_LEFT && world->vaisseau->x-SHIP_SIZE/2 >0){
                //printf("left\n");
                world->vaisseau->x=world->vaisseau->x-MOVING_STEP;
            }
            if(event->key.keysym.sym==SDLK_ESCAPE){
                world->gameover=1;
            }
            if (event->key.keysym.sym == SDLK_SPACE && world->vaisseau->is_visible == 1)
			{
				//printf("La touche espace est appuyée ! \n");
				for (int i = 0; i < NB_MISSILES - 1; i++)
				{
					if (world->missile[0]->is_visible == 0)
					{
						world->missile[i]->is_visible = 1;
						world->missile[i]->v = MISSILE_SPEED;
						i = NB_MISSILES - 1;
					}
					else if (world->missile[i]->is_visible == 1 && world->missile[i + 1]->is_visible == 0)
					{
						world->missile[i + 1]->is_visible = 1;
						world->missile[i + 1]->v = MISSILE_SPEED;
						i = NB_MISSILES - 1;
					}
				}
			}
        }
    }
}