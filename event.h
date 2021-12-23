#ifndef EVENT_H
#define EVENT_H

#include "biblio.h"
#include "world.h"
#include "fonction_score.h"

void handle_event(SDL_Event *event, world_t *world, FILE* fichier);

void update_data(world_t *world);

#endif