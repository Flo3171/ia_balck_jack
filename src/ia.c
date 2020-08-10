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

Decision decisionJeu(Joueur joueur,Carte carteDealer, Parametre parametre)
{
    switch (joueur.caractere.joue)
    {
    case JOUE_HUMAIN:
        return decisionJeuHumain(joueur,carteDealer, parametre);
        break;
    case PASSE:
        return decisionJeuPasse(joueur,carteDealer, parametre);
        break;
    
    default:
        return PASSER;
        break;
    }
}

Decision decisionJeuPasse(Joueur joueur, Carte carteDealer, Parametre parametre)
{
    return PASSER;
}

Decision decisionJeuDealer(Joueur joueur,Carte carteDealer, Parametre parametre)
{
    Point pointMainJoueur = pointMain(joueur.mainJoueur);
    if(pointMainJoueur.nbPoint + pointMainJoueur.nbAs*10 >= 17/*si le nombre de point est supérieur à 17*/){
        return PASSER;
    }
    else
    {
        return TIRER;
    }
    
}

