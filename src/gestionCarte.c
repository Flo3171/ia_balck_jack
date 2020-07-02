/**
 * \file gestionCarte.c 
 * \brief ficher soucre contenant les fonctions concertant la gestion des cartes
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/
#include "main.h"


Carte* melangeCarte(char nbPaquetsParSabot, Carte sabot[])
{
    int nbCarteSabot = NB_CARTE_PAQUETS * nbPaquetsParSabot;
    int curseurSabot = 0, aEchanger = 0;
    Carte carteTampon = SANS_VALEUR;
    if (sabot == NULL){ /*! Si le tableau n'a pas déja été crée alors on le crée*/
       sabot = (Carte*) malloc(sizeof(Carte) * nbPaquetsParSabot); 
    }
    /*! On place dans le tableau toutes les cartes qu'il doit contenir*/
    for (int i = 0; i < nbPaquetsParSabot * NB_FAMILLE_PAQUETS; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
           sabot[curseurSabot] = j;
            curseurSabot ++; 
        }
    }
    
    /*! On mélange les cartes du tableau avec la méthode de Fisher-Yates */
    for (int i = nbCarteSabot - 1; i >= 1; i--)
    {
       aEchanger = nbAleatoire(0, i);
       carteTampon = sabot[i];
       sabot[i] = sabot[aEchanger];
       sabot[aEchanger] = carteTampon; 
    }
    return sabot;
}

Carte piocheCarte(Carte sabot[], int *callStackSabot, char nbPaquetsParSabot)
{
    *callStackSabot -= 1;
    /*! Si le sabot est vide on le remplie de carte*/
    if (*callStackSabot == -1){
        melangeCarte(nbPaquetsParSabot, sabot);
        *callStackSabot = NB_CARTE_PAQUETS*nbPaquetsParSabot -1;
    }
    return sabot[*callStackSabot];   
}

