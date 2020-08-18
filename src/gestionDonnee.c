/**
 * \file gestionDonnee.c
 * \brief ficher source contenant les fonctions ralatives à le gestion des donnée
 * \author Florian.C
 * \version v1.0
 * \date 4 juillet 2020
*/

#include "main.h"

Caractere *chargeParametre(char nomFichier[], Parametre *parametre)
{
    FILE *fichier = NULL;
    fichier = fopen(nomFichier, "r");

    if (fichier == NULL)
    {
        printf("Imposible d'ouvrir le ficher");
        exit(EXIT_FAILURE);
    }

    fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d\n", &(parametre->nbJeuParSabot), &(parametre->nbJoueur), &(parametre->nbCarteBrule), &(parametre->abandont), &(parametre->nbPaireMaxi), &(parametre->doublerPaire), &(parametre->miseMini), &(parametre->miseMaxi), &(parametre->pactoleInitial), &(parametre->positionUtilisateur), &(parametre->nbPartie));

    Caractere *caractereJoueur = (Caractere*)malloc(sizeof(Caractere)*parametre->nbJoueur);

    for (int i = 0; i < parametre->nbJoueur; i++)
    {
        fscanf(fichier, "%d %d ", &caractereJoueur[i].mise, &caractereJoueur[i].joue);
    }
    

    fclose(fichier);
    return caractereJoueur;
}

