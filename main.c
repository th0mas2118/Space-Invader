#include <stdbool.h>
#include "fonctions_SDL.h"
#include "ennemi.h"
#include "vaisseau.h"

int main(){
    SDL_Event evenements;//Evenements lié a la fenêtre
    bool terminer =false;


    //Initialisation et création de la SDL, la fenêtre, le renderer
    init();
    //Charge image
    initFond();
    //Charge la musique 
    initMusic();
    Mix_PlayMusic(jeu.music, -1); // Joue notre musique 
    

    //Fond vert
    Uint8 r = 0, g = 0, b = 0;

    //Initialisation du vaisseau
    vaisseau_t *player=malloc(sizeof(vaisseau_t));
    //Depart(joueur, largeur écran, vitesse)
    Depart(player, 600,600, VITESSEV);
    //Charger vaisseau
    SDL_Texture* vaisseau = charger_image_transparente("img/vaisseau.bmp",jeu.ecran,r,g,b);


    //Initialisation des ennemis
    ennemi_t* tabEnnemi[NBENNEMI];
    int x = 0, y = 10;
    for (int i = 0; i < NBENNEMI; ++i) 
    {
        tabEnnemi[i] = malloc(sizeof(ennemi_t));
        initEnnemi(tabEnnemi[i], x, y);
        x += WIDTH_WINDOW/NBENNEMI;
    }  


    int ticks = 0, fps = 0, ticksDepart = 0, ticksArrive = 0, difference = 0;
    ticks = SDL_GetTicks();
    //Boucle principale
    while(!terminer){
        ticksDepart = SDL_GetTicks();
        SDL_RenderClear(jeu.ecran);
        SDL_RenderCopy(jeu.ecran, jeu.fond, NULL, NULL);
        SDL_RenderCopy(jeu.ecran,vaisseau,NULL,&player->DestR);

        for (int i = 0; i < NBENNEMI; ++i) {
            SDL_RenderCopy(jeu.ecran, tabEnnemi[i]->imageEnnemi, NULL, &tabEnnemi[i]->destR);
        } 

        SDL_RenderPresent(jeu.ecran);
        SDL_PollEvent(&evenements);
        switch(evenements.type){
            case SDL_QUIT:
                terminer=true;break;
            case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;
                        break;
                    case SDLK_UP:
                        if (jeu.volume<MIX_MAX_VOLUME)
                        {
                            jeu.volume++;
                        }break;
                    case SDLK_DOWN:
                        if (jeu.volume>0)
                        {
                            jeu.volume--;
                        }break;
                    case SDLK_LEFT:
                        deplacerGauche(player);
                        //SDL_Delay(10); 
                        break;
                    case SDLK_RIGHT:
                        deplacerDroite(player);
                        //SDL_Delay(10);
                        break;
                    case SDLK_p:
                        Mix_PauseMusic();
                        break;
                    case SDLK_r:
                        Mix_ResumeMusic();
                        break;
                    
                }
        }
        /*Mise à jour du volume*/
        Mix_VolumeMusic(jeu.volume);

        /* Gestion des fps, 60fps */
        if (SDL_GetTicks() < ticks+1000) {
            fps++;
        } else {
            printf("fps : %d\n", fps);
            ticks = SDL_GetTicks();
            fps = 0;
        }
        ticksArrive = SDL_GetTicks();
        difference = ticksArrive - ticksDepart;
        if (difference > 16) {
            difference = 16;
        }
        //Pour avoir environ 60 fps
        SDL_Delay(16 - difference);
    }

    //Quitter SDL
    for (int i = 0; i < NBENNEMI; ++i) {
        free(tabEnnemi[i]); //Libérer en mémoire les ennemis
    }
    free(player); //Libérer en mémoire le joueur
    Mix_FreeMusic(jeu.music); // Libére en mémoire notre musique
    Mix_CloseAudio();
    SDL_DestroyRenderer(jeu.ecran);
    SDL_DestroyWindow(jeu.fenetre);
    SDL_Quit();
    return 0;
}