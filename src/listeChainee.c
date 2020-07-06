/**
 * \file listeChainee.c 
 * \brief ficher source contenant les fonction en raport avec les listes chainée
 * \author Florian.C
 * \version v1.0
 * \date 7 juillet 2020
*/

#include "main.h"

CarteListeChaine *initialistationListeChainee()
{
    CarteListeChaine *liste = malloc(sizeof(*liste));

    if (liste == NULL){
        printf("ERREUR CREATION LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    liste->nbElement = 0;

    return liste;
}

void insertionListeChainee(CarteListeChaine *liste, Carte carteAAjouter)
{
    ElementCarteListeChaine *nouveauElement = malloc(sizeof(*nouveauElement));
    if (liste == NULL || nouveauElement == NULL)
    {
        printf("ERREUR AJOUT LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    nouveauElement->carte = carteAAjouter;
    nouveauElement->suivant = liste->premier;
    
    liste->premier = nouveauElement;
    liste->nbElement ++;
}

void supprimeListeChainee(CarteListeChaine *liste)
{
    if (liste == NULL)
    {
        printf("ERREUR SUPPRESION LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    if (liste->premier != NULL)
    {
        ElementCarteListeChaine *aSupprimer  = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
        liste->nbElement --;
    }
}

void supprimeToutListeChainee(CarteListeChaine *liste)
{
    if (liste == NULL)
    {
        printf("ERREUR SUPPRESION TOUTE LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    while (liste->premier != NULL)
    {
        supprimeListeChainee(liste);
    }
}

void afficheListeChainee(CarteListeChaine *liste)
{
    if (liste == NULL)
    {
        printf("ERREUR AFFICHAGE LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }

    ElementCarteListeChaine *actuel = liste->premier;

    printf("La liste chainee contient : \n");
    while (actuel != NULL)  
    {
        printf("%d\n", actuel->carte);
        actuel = actuel->suivant;
    }
    printf("Fin liste chainee\n");
}