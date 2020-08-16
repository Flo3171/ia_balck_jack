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
 * \fn Sabot *initialisationSabot(int nbJeuParSabot)
 * \brief initialise une variable de type Sabot
 * 
 * \param int nbJeuParSabot : nombre de jeu de carte par sabot
 * \return Sabot *: pointeur sur le sabot qui à été créé
 */

Sabot *initialisationSabot(int nbJeuParSabot);

/**
 * \fn void melangeCarte(Sabot *sabot)
 * \brief mélange les carte afin d'obtenir un tableau de carte mélangé
 * 
 * \param Sabot *sabot : Sabot qui contient les cartes qui seront distribuée au joueurs
 * \return void
*/

void melangeCarte(Sabot *sabot);

/**
 * \fn Carte piocheCarte(Sabot *sabot)
 * \brief pioche une carte dans le sabot et renvoie la carte qui a été piochée
 * 
 * \param Sabot *sabot : sabot contenant les cartes qui seront distibuée au joueurs
 * \return Carte : renvoie la carte qui à été piochée
 * 
 */

Carte piocheCarte(Sabot *sabot);

/**
 * \fn void distubutionInitialCartes(Joueur tableauJoueur[], CarteListeChaine *mainDealer, Parametre parametre, Sabot *sabot)
 * \brief distibue les cartes au différent joueur et au deleur au début de la partie
 * 
 * \param Joueur tableauJoueur[] : tableau contenant tout les joueurs
 * \param CarteListeChaine *mainDealer : liste chainée qui contient les cartes du dealer
 * \param Parametre parametre : parametre utilisé pour la partie
 * \param Sabot *sabot : sabot qui contient toutes les cartes qui seront distribuée au joueurs
 * \return void
 * 
 */

void distubutionInitialCartes(Joueur tableauJoueur[], CarteListeChaine *mainDealer, Parametre parametre, Sabot *sabot);

/**
 * \fn Point pointMain(CarteListeChaine *mainJoueur)
 * \brief calcule le nombre de point que vaut une liste chainée de Carte au black Jack
 * 
 * \param CarteListeChaine *mainJoueur : liste chainé contenant la main à évaluer
 * \return Point : revoie le nombre de point que vaut la main
 */

Point pointMain(CarteListeChaine *mainJoueur);

/**
 * \fn char pointFinalMain(CarteListeChaine *mainJoueur)
 * \brief donne le nombre de point le plus intérésant pour le joueur que vaut une main
 * 
 * \param CarteListeChaine *mainJoueur : liste chainé contenant la main à évaluer
 * \return char : revoie le nombre de point de la main
 */

char pointFinalMain(CarteListeChaine *mainJoueur);

#endif //_GESTION_CARTE_H_