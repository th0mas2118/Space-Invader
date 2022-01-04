#include "ressources.h"

void clean_ressources(ressources_t *ressources){
    clean_texture(ressources->background);
    clean_texture(ressources->vaisseau);
    clean_texture(ressources->ennemi);
    clean_texture(ressources->missile);
    clean_font(ressources->font);
}

void init_ressources(SDL_Renderer *renderer, ressources_t *ressources){
    ressources->background=load_image("ressources/fond.bmp",renderer);
    ressources->vaisseau=load_image("ressources/spaceship.bmp",renderer);
    ressources->ennemi=load_image("ressources/enemy.bmp",renderer);
    ressources->missile=load_image("ressources/missile.bmp",renderer);
    ressources->font=load_font("ressources/arial.ttf",24);
}

void apply_background(SDL_Renderer *renderer, ressources_t *ressources){
    if(ressources->background!=NULL){
        apply_texture(ressources->background,renderer,0,0);
    }
}