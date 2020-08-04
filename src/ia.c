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

