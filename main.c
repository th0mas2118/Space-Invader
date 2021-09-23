#include <stdbool.h>
#include "fonctions_SDL.h"

int main(){
    SDL_Window* fenetre;//Déclaration de la fenêtre
    SDL_Event evenements;//Evenements lié a la fenêtre
    bool terminer =false;
    if(SDL_Init(SDL_INIT_VIDEO)<0){//Initiaisaiton de la SDL
        printf("Erreur d'init SDL %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //Crée fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,SDL_WINDOW_RESIZABLE);
    if(fenetre==NULL){//Cas Error
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //Mise en place renderer
    SDL_Renderer* ecran;
    ecran= SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
    //Charge image
    SDL_Texture* fond = charger_image("fond.bmp",ecran);
    int i = 0;
    while(!terminer){
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran,fond,NULL,NULL);
        SDL_RenderPresent(ecran);
        if(i==0){
            printf("Affichage\n");
            i++;
        }
        SDL_PollEvent(&evenements);
        switch(evenements.type){
            case SDL_QUIT:
                terminer=true;break;
            case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;break;
                }
        }
    }

    //Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}