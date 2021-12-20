#ifndef EVENT_H
#define EVENT_H

#include "biblio.h"
#include "world.h"

void handle_event(SDL_Event *event, world_t *world);

void update_data(world_t *world);

#endif