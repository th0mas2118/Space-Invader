#include "vaisseau.h"

void Depart(vaisseau_t* v, int W, int H, int V){
    v->DestR.x=W/2;//Positionne le vaisseau au milieu
    v->DestR.y=H-150;
    v->DestR.w=120;
    v->DestR.h=120;
    v->vitesse=V;
}

void deplacerGauche(vaisseau_t* v){
    if(v->DestR.x>0){
        v->DestR.x=v->DestR.x-v->vitesse;
    }
}
void deplacerDroite(vaisseau_t* v){
    if(v->DestR.x<600-v->DestR.w){
        v->DestR.x=v->DestR.x+v->vitesse;
    }
}