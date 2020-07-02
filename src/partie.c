/**
 * \file partie.c 
 * \brief ficher source contenant les fonction en raport avec une partie
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

#include "main.h"

void joueBlackJack(Parametre parametre)
{
    /*! On initialise les tableaux et les variables qui seront utilisée au cour du jeu*/
    Carte *sabot = (Carte*) malloc(sizeof(Carte) * parametre.nbJeuParSabot);
    int callstackSabot = 0;
    int *pactole = (int*) malloc(sizeof(int)*parametre.nbJoueur);
    for (int  i = 0; i < parametre.nbJoueur; i++)
    {
        pactole[i] = parametre.pactoleInitial;
    }

    /*! On appelle autant de fois que souhaité la fonction "partie"*/
    for (int i = 0; i < parametre.nbpartie; i++)
    {
        partie(parametre, sabot, &callstackSabot);
    }
    

    

    free(sabot);
    free(pactole);
}

void partie(Parametre parametre, Carte sabot[], int *callStackSabot)
{
    
}