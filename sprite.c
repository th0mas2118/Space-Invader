#include "sprite.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v, int visible){
    sprite->x=x;
    sprite->y=y;
    sprite->w=w;
    sprite->h=h;
    sprite->v=v;
    sprite->is_visible=visible;
}

void set_visible(sprite_t *sprite){
    sprite->is_visible=1;
}

void set_invisible(sprite_t *sprite){
    sprite->is_visible=0;
}