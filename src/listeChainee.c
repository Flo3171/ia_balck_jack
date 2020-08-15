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
    CarteListeChaine *liste = (CarteListeChaine*)malloc(sizeof(*liste));

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
    ElementCarteListeChaine *nouveauElement = (ElementCarteListeChaine*)malloc(sizeof(*nouveauElement));
    if (liste == NULL || nouveauElement == NULL)
    {
        printf("ERREUR AJOUT LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    nouveauElement->suivant = liste->premier;
    nouveauElement->carte = carteAAjouter;
    
    
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
    videListeChainee(liste);
    free(liste);
}

void afficheListeChainee(CarteListeChaine *liste)
{
    if (liste == NULL)
    {
        printf("ERREUR AFFICHAGE LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }

    ElementCarteListeChaine *actuel = liste->premier;

    printf("La liste chainee contient %d element : \n", liste->nbElement);
    while (actuel != NULL)  
    {
        printf("%d\n", actuel->carte);
        actuel = actuel->suivant;
    }
    printf("Fin liste chainee\n");
}

void videListeChainee(CarteListeChaine *liste)
{
    if (liste == NULL)
    {
        printf("ERREUR VIDAGE LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    while (liste->premier != NULL)
    {
        supprimeListeChainee(liste);
    }
}


MainListeChaine *initialistationMain()
{
    MainListeChaine *liste = (MainListeChaine*)malloc(sizeof(*liste));

    if (liste == NULL){
        printf("ERREUR CREATION MAIN");
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    liste->nbElement = 0;
}

void ajouteMain(MainListeChaine *liste, CarteListeChaine *mainAAjouter)
{
    ElementMainListeChaine *nouveauElement = (ElementMainListeChaine*)malloc(sizeof(*nouveauElement));
    if (nouveauElement == NULL)
    {
        printf("ERREUR AJOUT MAIN");
        exit(EXIT_FAILURE);
    }
    nouveauElement->suivant = liste->premier;
    if (mainAAjouter == NULL)
    {
        nouveauElement->mainJoueur = initialistationListeChainee();    
    }
    else
    {
        nouveauElement->mainJoueur = mainAAjouter;
    }

    liste->premier = nouveauElement;
    liste->nbElement ++;
}

void retireMain(MainListeChaine *liste)
{
    if (liste == NULL)
    {
        printf("ERREUR SUPPRESION LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    
    if (liste->premier != NULL){
        ElementMainListeChaine *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        supprimeToutListeChainee(aSupprimer->mainJoueur);
        free(aSupprimer);
        liste->nbElement --;
    }
}

void videMain(MainListeChaine *liste)
{
    if (liste == NULL){
        printf("ERREUR VIDAGE LISTE CHAINEE");
        exit(EXIT_FAILURE);
    }
    while (liste->premier != NULL)
    {
        retireMain(liste);
    }
    
}

void supprimeToutMain(MainListeChaine *liste)
{
    videMain(liste);
    free(liste);
}

