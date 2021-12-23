#ifndef FONCTION_SCORE_H
#define FONCTION_SCORE_H

#include "biblio.h"

void ecrireScore(int score, FILE* fichier);

void lireHighScore(FILE* fichier);

void resetScore(FILE*fichier);

int nbLigne(FILE* fichier);

void tabScore(FILE* fichier, int* tab);

void tri(int * tab, int N);

void inverser(int * tab, int N);
#endif