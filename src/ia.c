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
    case PASSE:
        return choixMiseMini(joueur, parametre);
        break;
    
    default:
        return parametre.miseMini;
        break;
    }
}

long choixMiseMini(Joueur joueur, Parametre parametre)
{
    if (joueur.pactole >= parametre.miseMini){
        return 0;
    }
    else
    {
        return parametre.miseMini;
    }
    
}

Decision decisionJeu(Joue caractereJoue, CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre)
{
    switch (caractereJoue)
    {
    case JOUE_HUMAIN:
        return decisionJeuHumain(mainJoueur, carteDealer, parametre);
        break;
    case PASSE:
        return decisionJeuPasse(mainJoueur, carteDealer, parametre);
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

