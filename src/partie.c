/**
 * \file partie.c 
 * \brief ficher source contenant les fonctions en raport avec une partie
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

#include "main.h"

void joueBlackJack(Parametre parametre)
{
    /*! On initialise les tableaux et les variables qui seront utilisée au cour du jeu*/
    Carte *sabot = (Carte*) malloc(sizeof(Carte) * parametre.nbJeuParSabot * NB_CARTE_PAQUETS);
    int callstackSabot = 0;

    /*! On initialise le tableaux contenant les joueur*/
    Joueur *tableauJoueur = (Joueur*) malloc(sizeof(Joueur) * parametre.nbJoueur);
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        /*! On initialise chaque joueur selon les parametre de la partie */
        if (parametre.positionUtilisateur == i){
            setJoueur(&tableauJoueur[i], HUMAIN, parametre.pactoleInitial, initialistationListeChainee(), PASSER, parametre.miseMini);
        }
        else
        {
            setJoueur(&tableauJoueur[i], PASSE, parametre.pactoleInitial, initialistationListeChainee(), PASSER, parametre.miseMini);
        }
        /*printf("%d %d %d %d\n", tableauJoueur[0].caractere, tableauJoueur[0].choixJoueur, tableauJoueur[0].mise, tableauJoueur[0].pactole);*//*permet de controler que les joueur on été crée correctement */
    }
    /* On crée la main du dealer*/
    CarteListeChaine *mainDealer = initialistationListeChainee();

    /*! On appelle autant de fois que souhaité la fonction "partie"*/
    for (int i = 0; i < parametre.nbPartie; i++)
    {
        partie(parametre, sabot, &callstackSabot, tableauJoueur, mainDealer);
    }
    

    
    /* On libère tout l'espace qui à été utilisé au début de la fonction */
    free(sabot);
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        supprimeToutListeChainee(tableauJoueur[i].mainJoueur);
    }
    supprimeListeChainee(mainDealer);
    
    free(tableauJoueur);
}

void partie(Parametre parametre, Carte sabot[], int *callStackSabot, Joueur tableauJoueur[], CarteListeChaine *mainDealer)
{
    /* On distibue deux cartes à chaque joueur et une au dealer*/
    distubutionInitialCartes(tableauJoueur, mainDealer, parametre, sabot, callStackSabot);
    
}