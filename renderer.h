#ifndef RENDERER_H
#define RENDERER_H

#include "biblio.h"
#include "world.h"
#include "ressources.h"
#include "fonction_score.h"

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, world_t *world);

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, world_t *world);

void refresh_graphics(SDL_Renderer *renderer, world_t *world, ressources_t *ressources);

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);

void apply_sprite_missile(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);

#endif