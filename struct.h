#ifndef STRUCT_H
#define STRUCT_H

#define WIDTH_WINDOW 600
#define HEIGHT_WINDOW 600 
#define VITESSEV 5

typedef struct Jeu{
	SDL_Window* fenetre;
	SDL_Renderer* ecran;
	SDL_Texture* fond;
	Mix_Music* music;
	Uint8 volume;
} Jeu;


#endif