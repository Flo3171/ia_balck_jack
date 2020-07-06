/**
 * \file gestionDonnee.c
 * \brief ficher source contenant les fonctions ralatives à le gestion des donnée
 * \author Florian.C
 * \version v1.0
 * \date 4 juillet 2020
*/

#include "main.h"

void chargeParametre(char nomFichier[], Parametre *parametre)
{
    FILE *fichier = NULL;
    fichier = fopen(nomFichier, "r");

    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d", &(parametre->nbJeuParSabot), &(parametre->nbJoueur), &(parametre->nbCarteBrule), &(parametre->abandont), &(parametre->nbPaireMaxi), &(parametre->doublerPaire), &(parametre->miseMini), &(parametre->miseMaxi), &(parametre->pactoleInitial), &(parametre->positionUtilisateur), &(parametre->nbPartie));

        fclose(fichier);
    }
    else
    {
        printf("Imposible d'ouvrir le ficher");
    }
    
    

}

