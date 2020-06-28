/**
 * \file gestionCarte.c 
 * \brief ficher soucre contenant les fonctions concertant la gestion des cartes
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/
#include "main.h"


Carte* melangeCarte(char nbPaquetsParSabot)
{
    int nbCarteSabot = NB_CARTE_PAQUETS * nbPaquetsParSabot;
    int curseurSabot = 0, aEchanger = 0;
    Carte carteTampon = SANS_VALEUR;
    Carte* sabot = (Carte*) malloc(sizeof(Carte) * nbPaquetsParSabot);
    for (int i = 0; i < nbPaquetsParSabot * NB_FAMILLE_PAQUETS; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
           sabot[curseurSabot] = j;
            curseurSabot ++; 
        }
    }
    
    for (int i = nbCarteSabot - 1; i >= 1; i--)
    {
       aEchanger = nbAleatoire(0, i);
       carteTampon = sabot[i];
       sabot[i] = sabot[aEchanger];
       sabot[aEchanger] = carteTampon; 
    }
    

    
    return sabot;
}

