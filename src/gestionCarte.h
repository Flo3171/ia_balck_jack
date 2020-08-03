#ifndef _GESTION_CARTE_H_
#define _GESTION_CARTE_H_

/**
 * \file gestionCarte.h 
 * \brief ficher header contenant les prototype des fonctions concertant la gestion des cartes
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

/**
 * \fn Carte* melangeCarte(char nbPaquetsParSabot, Carte sabot[])
 * \brief mélange les carte afin d'obtenir un tableau de carte mélangé
 * 
 * \param char nbPaquetsParSabot : indique le nombres de jeux de cartes utilisé dans un sabot
 * \param Carte sabot[] : tableau qui contient les cartes du sabot (mettre NULL si le tableau n'a pas encore été crée)
 * \return Carte * : pointeur sur le tableau de carte qui a été
*/

Carte* melangeCarte(char nbPaquetsParSabot, Carte sabot[]);

/**
 * \fn Carte piocheCarte(Carte sabot[], int* callStackSabot, char nbPaquetsParSabot)
 * \brief pioche une carte dans le sabot et renvoie la carte qui a été piochée
 * 
 * \param Carte sabot[] : tableau contenant les cartes du sabot
 * \param int* callStackSabot : pointeur sur le call stack sabot
 * \param char nbPaquetsParSabot : indique le nombres de jeux de cartes utilisé dans un sabot
 * \return Carte : renvoie la carte qui à été piochée
 * 
 */

Carte piocheCarte(Carte sabot[], int* callStackSabot, char nbPaquetsParSabot);

/**
 * \fn void distubutionInitialCartes(Joueur tableauJoueur[], CarteListeChaine *mainDealer, Parametre parametre, Carte sabot[], int* callStackSabot)
 * \brief distibue les cartes au différent joueur et au deleur au début de la partie
 * 
 * \param Joueur tableauJoueur[] : tableau contenant tout les joueurs
 * \param CarteListeChaine *mainDealer : liste chainée qui contient les cartes du dealer
 * \param Parametre parametre : parametre utilisé pour la partie
 * \param Carte sabot[] : tableau contenant les cartes du sabot
 * \param int* callStackSabot : pointeur sur le call stack sabot
 * \return void
 * 
 */

void distubutionInitialCartes(Joueur tableauJoueur[], CarteListeChaine *mainDealer, Parametre parametre, Carte sabot[], int* callStackSabot);

#endif //_GESTION_CARTE_H_