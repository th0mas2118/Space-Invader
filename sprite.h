#ifndef SPRITE_H
#define SPRITE_H
#include "biblio.h"

typedef struct sprite_s
{
	int x;			/*!< Abscisses par rapport au centre de l'image.*/
	int y;			/*!< Ordionnée par rapport au centre de l'image. */
	int h;			/*!< Hauteur du sprite. */
	int w;			/*!< Largeur du sprite. */
	int v;			/*!< Vitesse de déplacement verticale. */
	int is_visible; /*!< Visibilité du sprite. */
} sprite_t;

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v, int visible);

void set_invisible(sprite_t *sprite);

void set_visible(sprite_t *sprite);

#endif