#include "fonctions_SDL.h"

void init(){
    //SDL_Window* fenetre;//Déclaration de la fenêtre
    if(SDL_Init(SDL_INIT_VIDEO)<0){//Initiaisaiton de la SDL
        printf("Erreur d'init SDL %s",SDL_GetError());
        SDL_Quit();
    }
    //Crée fenêtre
    jeu.fenetre = SDL_CreateWindow("Covid Invader",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH_WINDOW,HEIGHT_WINDOW,SDL_WINDOW_RESIZABLE);
    if(jeu.fenetre==NULL){//Cas Error
        SDL_Quit();
    }
    //Mise en place renderer
    //SDL_Renderer* ecran;
    jeu.ecran= SDL_CreateRenderer(jeu.fenetre,-1,SDL_RENDERER_ACCELERATED);
    if(jeu.ecran==NULL){
        SDL_Quit();
    }
    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
	{
		SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
		SDL_Quit();
	}
}

void initFond(){
	jeu.fond = charger_image("img/fond.bmp",jeu.ecran);
}

void initMusic(){
	jeu.music = Mix_LoadMUS("music/bushido.mp3");
	if (jeu.music == NULL)
	{
	    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
	    Mix_CloseAudio();
	    SDL_Quit();
	}
	jeu.volume = 0;
	Mix_VolumeMusic(jeu.volume);
}

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer){
	//Déclaration et initialisation d'une surface qui servira à recueillir l'image
	SDL_Surface *tmp = NULL; 
	//Déclaration et initialisation d'une texture
	SDL_Texture *texture = NULL;
	tmp = SDL_LoadBMP(nomfichier);
	if(NULL == tmp)
	{
	    printf("Erreur SDL_LoadBMP : %s", SDL_GetError());
	    SDL_Quit();
	}
	texture = SDL_CreateTextureFromSurface(renderer, tmp);
	if(NULL == texture)
	{
	    printf( "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
	    SDL_Quit();
	}
	SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plus besoin */
	return texture;
}


SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b){
	SDL_Surface * obj = SDL_LoadBMP(nomfichier);
	SDL_SetColorKey(obj,SDL_TRUE,SDL_MapRGB(obj->format, r, g, b));
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, obj);
	return texture;
}


