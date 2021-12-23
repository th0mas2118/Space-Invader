#ifndef MAIN_C
#define MAIN_C
#include "biblio.h"
#include "world.h"
#include "ressources.h"
#include "renderer.h"
#include "event.h"
#include "fonction_score.h"
#include "audio.h"
#endif

int main(int argc, char *args[]){
    srand(time(NULL));
    SDL_Event event;
    world_t world;
    ressources_t ressources;
    SDL_Renderer *renderer;
    SDL_Window *Window;
    
    init(&Window, &renderer, &ressources, &world);
    //Demarrage musique
    playMusic("Ressources/musique/bushido.wav",world.audio);
    //Ouverture fichier score
    FILE * pFile;
    pFile=fopen("score.txt","r");
    if(pFile==NULL){
        resetScore(pFile);
    }


    while(!is_game_over(&world)){
        handle_event(&event,&world,pFile);
        update_data(&world);
        refresh_graphics(renderer, &world, &ressources);
        pause(10);
    }

    //La partie est fini

    ecrireScore(world.score,pFile);

    endAudio();
    clean(Window, renderer, &ressources, &world);

    return EXIT_SUCCESS;
}
