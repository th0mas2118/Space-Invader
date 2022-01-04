#include "renderer.h"

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, world_t *world){
    init_ttf();
    init_sdl(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
    init_data(world);
    init_ressources(*renderer,ressources);
    init_music(world);
}

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, world_t *world){
	clean_data(world);
	clean_ressources(ressources);
	clean_sdl(renderer, window);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world, ressources_t *ressources){
    clear_renderer(renderer);

    apply_background(renderer,ressources);
    apply_sprite(renderer, ressources->vaisseau, world->vaisseau);
    for(int i=0;i<NB_MISSILES;i++){
        apply_sprite_missile(renderer,ressources->missile,world->missile[i]);
    }
    for(int i=0;i<NB_ENEMIES;i++){
        apply_sprite(renderer, ressources->ennemi, world->enemies[i]);
    }
    //SCORE
    char *str =malloc(sizeof(char)*20);
    sprintf(str,"Score : %d",world->score);
    apply_text(renderer,0,0,100,30,str,ressources->font);
    //HIGHSCORE
    char *high=malloc(sizeof(char)*30);
    FILE* pFile;
    pFile=fopen("score.txt","r");
    sprintf(high,"HighScore : %d",lireHighScore(pFile));
    apply_text(renderer,0,40,150,30,high,ressources->font);
    //Message état fin de jeu
    if(world->etat_partie==PERDU){
        apply_text(renderer,10,0,200,100, "You lose!",ressources->font);
    }
    if(world->etat_partie==PARFAIT || world->etat_partie==GAGNE){
        apply_text(renderer,10,0,200,100,"You win !",ressources->font);
    }
    update_screen(renderer);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
    if(sprite->is_visible==1){
        apply_texture(texture,renderer, sprite->x-(SHIP_SIZE/2),sprite->y-(SHIP_SIZE/2));
    }
}

void apply_sprite_missile(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
	if (sprite->is_visible == 1)
	{
		apply_texture(texture, renderer, sprite->x - (MISSILE_SIZE / 2), sprite->y - (MISSILE_SIZE / 2));
    }
}
