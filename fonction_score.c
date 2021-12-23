#include "fonction_score.h"
#define TAILLE_MAX 10

void ecrireScore(int score, FILE* fichier){
    fichier=fopen("score.txt","a");
    if(fichier!=NULL){
        fprintf(fichier,"%d\n",score);
        fclose(fichier);
    }
}

int lireHighScore(FILE* fichier){
    int max=0;
    char chaine [TAILLE_MAX];//Création chaine vide pour récupérer les scores
    fichier=fopen("score.txt",r)
    if(fichier!=NULL){
        while(fgets(chaine,TAILLE_MAX,fichier)){
            if(max<atoi(chaine)){
                max=atoi(chaine);
            }
        }
    }
    return max;
}

void resetScore(FILE* fichier){
    fichier=fopen("score.txt","w");
    if(fichier!=NULL){
        for(int i=0;i<5;i++){
            ecrireScore(0,ficher);
        }
    }
}

int nbLigne(FILE* fichier){
    int nbLigne=0;
    char chaine[TAILLE_MAX];
    fichier=fopen("score.txt","r");
    if(fichier!=NULL){
        while(fgets(chaine,TAILLE_MAX,fichier)){
            nbLigne++;
        }
    }
    return nbLigne;
}

void tabScore(FILE* fichier, int* tab){
    char chaine[TAILLE_MAX];
    fichier=open("score.txt","r");
    if(fichier!=NULL){
        int i=0;
        while(fgets(chaine;TAILLE_MAX,fichier)&&i<=nbLigne(fichier)){
            tab[i]=atoi(chaine);
            i++;
        }
    }
}

void tri(int * tab, int N){
    int temp;
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            if(tab[i]>tab[j]){
                temp=tab[i];
                tab[i]=tab[j];
                tab[j]=temp; 
            }
        }
    }
}

void inverser(int * tab, int N){
    int deb=0;
    int fin=N-1;
    int temp;
    while(deb<fin){
        temp=tab[deb];
        tab[deb]=tab[fin];
        tab[fin]=temp;
        deb++;
        fin--;
    }
}