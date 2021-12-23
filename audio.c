#include "audio.h"

void initMusic(world_t *world){
    world->music=Mix_LoadMUS("ressouces/musique/bushido.mp3");
    if(world->music==NULL){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Erreur de chagement de la musique : %s"Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
    }
    world->volume=0;
    Mix_VolumeMusic(world->volume);
}