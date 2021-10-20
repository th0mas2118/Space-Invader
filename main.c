#include <stdbool.h>
#include "fonctions_SDL.h"
#include "vaisseau.h"
#define VITESSEV 5


int main(){
    //Pour image transparente
    Uint8 r = 0, g = 0, b = 0;
    SDL_Window* fenetre;//Déclaration de la fenêtre
    SDL_Event evenements;//Evenements lié a la fenêtre
    bool terminer =false;
    
    vaisseau_t *player=malloc(sizeof(vaisseau_t));
    //Depart(joueur, largeur écran, vitesse)
    Depart(player, 600,600, VITESSEV);
    /*Structure ennemi
    typedef struct ennemi_s emmeni_t;
    struct ennemi_s{
        bool vie;
    };*/

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

    //Charger vaisseau
    SDL_Texture* vaisseau = charger_image_transparente("vaisseau.bmp",ecran,r,g,b);

    //player->posx=SrcV.x;


    //Boucle principale
    while(!terminer){
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran,fond,NULL,NULL);
        SDL_RenderCopy(ecran,vaisseau,NULL,&player->DestR);
        SDL_RenderPresent(ecran);
        SDL_PollEvent(&evenements);
        switch(evenements.type){
            case SDL_QUIT:
                terminer=true;break;
            case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;break;
                    case SDLK_LEFT:deplacerGauche(player);SDL_Delay(10); break;
                    case SDLK_RIGHT:deplacerDroite(player);SDL_Delay(10);
                    break;
                }
        }
    }

    //Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}