/**
 * \file ia.c 
 * \brief ficher source contenant les fonctions en raport avec l'inteligence artificielle
 * \author Florian.C
 * \version v1.0
 * \date 4 août 2020
*/

#include "main.h"

long choixMise(Joueur joueur, Parametre parametre)
{
    switch (joueur.caractere.mise)
    {
    case MISE_HUMAIN:
        return choixMiseUtilisateur(joueur, parametre);
        break;
    case MINI:
        return choixMiseMini(joueur, parametre);
        break;
    case DOUBLE_SI_PERT:
        return choixMiseDoubleSiPert(joueur, parametre);
        break;
    
    default:
        return parametre.miseMini;
        break;
    }
}

long choixMiseMini(Joueur joueur, Parametre parametre)
{
    if (joueur.pactole < parametre.miseMini){
        return 0;
    }
    else
    {
        return parametre.miseMini;
    }
    
}

long choixMiseDoubleSiPert(Joueur joueur, Parametre parametre)
{
    long mise = 0;
    if (joueur.dataIA.gainDernierePartie < 0)
    {
        mise = -joueur.dataIA.gainDernierePartie*2;
    }
    else if (joueur.dataIA.gainDernierePartie == 0 && joueur.mise != 0)
    {
        mise = joueur.mise;
    }
    else
    {
        mise = parametre.miseMini;
    }
    
    if (mise > joueur.pactole)
    {
        mise = parametre.miseMini;
    }
    if (mise > joueur.pactole)
    {
        mise = 0;
    }
    return mise;
}

Decision decisionJeu(Joue caractereJoue, CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre)
{
    switch (caractereJoue)
    {
    case JOUE_HUMAIN:
        return decisionJeuHumain(mainJoueur, carteDealer, parametre);
        break;
    case DEALER:
        return decisionJeuDealer(mainJoueur, carteDealer, parametre);
        break;
    
    default:
        return PASSER;
        break;
    }
}

Decision decisionJeuPasse(CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre)
{
    return PASSER;
}

Decision decisionJeuDealer(CarteListeChaine *mainJoueur ,Carte carteDealer, Parametre parametre)
{
    if(pointFinalMain(mainJoueur) >= 17){
        return PASSER;
    }
    else
    {
        return TIRER;
    }
    
}

long choixAssurance(CarteListeChaine *mainJoueur, long miseJoueur, Joue caractereJoue)
{
    switch (caractereJoue)
    {
    case JOUE_HUMAIN:
        choixAssuranceHumain(mainJoueur, miseJoueur);
        break;
    
    default:
        return 0;
        break;
    }
}

