/**
 * \file gestionCarte.c 
 * \brief ficher soucre contenant les fonctions concertant la gestion des cartes
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/
#include "main.h"

Sabot *initialisationSabot(int nbJeuParSabot)
{
    Sabot *sabot = (Sabot*)malloc(sizeof(Sabot));
    sabot->tableauCarte = (Carte*)malloc(sizeof(Carte) * nbJeuParSabot * NB_CARTE_PAQUETS);
    sabot->callStackSabot = 0;
    sabot->nbPaquetParSabot = nbJeuParSabot;

    return sabot;

}


void melangeCarte(Sabot *sabot)
{
    int nbCarteSabot = NB_CARTE_PAQUETS * sabot->nbPaquetParSabot;
    int curseurSabot = 0, aEchanger = 0;
    Carte carteTampon = SANS_VALEUR;
    /*! On place dans le tableau toutes les cartes qu'il doit contenir*/
    for (int i = 0; i < sabot->nbPaquetParSabot * NB_FAMILLE_PAQUETS; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
           sabot->tableauCarte[curseurSabot] = j;
            curseurSabot ++; 
        }
    }
    
    /*! On mélange les cartes du tableau avec la méthode de Fisher-Yates */
    for (int i = nbCarteSabot - 1; i >= 1; i--)
    {
       aEchanger = nbAleatoire(0, i);
       carteTampon = sabot->tableauCarte[i];
       sabot->tableauCarte[i] = sabot->tableauCarte[aEchanger];
       sabot->tableauCarte[aEchanger] = carteTampon; 
    }
}

Carte piocheCarte(Sabot *sabot)
{
    sabot->callStackSabot --;
    /*! Si le sabot est vide on le remplie de carte*/
    if (sabot->callStackSabot == -1){
        melangeCarte(sabot);
        sabot->callStackSabot = NB_CARTE_PAQUETS * sabot->nbPaquetParSabot -1;
    }
    return sabot->tableauCarte[sabot->callStackSabot];   
}

void distubutionInitialCartes(Joueur tableauJoueur[], CarteListeChaine *mainDealer, Parametre parametre, Sabot *sabot)
{
    /* On brule les carte au début de la partie */
    for (int i = 0; i < parametre.nbCarteBrule; i++)
    {
        piocheCarte(sabot);
    }
    /* On ajoute une main à chaque joueur */
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        ajouteMain(tableauJoueur[i].mainJoueur, NULL);
    }
    
    
    /* On distibue 2 carte à chaque joueur et au dealer*/
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < parametre.nbJoueur; j++)
        {
            if(tableauJoueur[j].mise > 0){
                insertionListeChainee(tableauJoueur[j].mainJoueur->premier->mainJoueur, piocheCarte(sabot));
            }    
        }
        insertionListeChainee(mainDealer, piocheCarte(sabot));        
    }
    
}

Point pointMain(CarteListeChaine *mainJoueur)
{
    Point pointMain;
    pointMain.nbAs = 0;
    pointMain.nbPoint = 0;

    ElementCarteListeChaine *actuel = mainJoueur->premier;

    while (actuel != NULL)
    {
        /* Traintement de la carte */
        switch (actuel->carte)
        {
        case AS:
            pointMain.nbAs ++;
            pointMain.nbPoint += 1;
            break;
        case VALET:
            pointMain.nbPoint += 10;
            break;
        case DAME:
            pointMain.nbPoint += 10;
            break;
        case ROI:
            pointMain.nbPoint += 10;
            break;
        default:
            pointMain.nbPoint += actuel->carte;
            break;
        }
        
        actuel = actuel->suivant;
    }

    return pointMain;
    
    
}

char pointFinalMain(CarteListeChaine *mainJoueur)
{
    Point point = pointMain(mainJoueur);
    while (point.nbPoint + point.nbAs *10 > 21 && point.nbAs != 0)
    {
        point.nbAs --;
    }
    char retour = point.nbPoint + (point.nbAs *10);
    return retour;
    
}

