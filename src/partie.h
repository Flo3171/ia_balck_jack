#ifndef _PARTIE_H_
#define _PARTIE_H_

/**
 * \file partie.h 
 * \brief ficher header contenant les prototypes des fonctions en raport avec une partie
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

/**
 * \fn void joueBlackJack(Parametre parametre)
 * \brief permet de jouer au black jacke, joue le nombre de manche voulue
 * 
 * \param Parametre parametre : les paramètres qui doivent être appliqués à la partie
 * \param
 * \param
 * \param
 * \param
 * \return void
 */

void joueBlackJack(Parametre parametre);

/**
 * \fn void partie(Parametre parametre, Carte sabot[], int *callStackSabot, Joueur tableauJoueur[], CarteListeChaine *mainDealer)
 * \brief joue une partie de black jack
 * 
 * \param Parametre parametre : les paramètre qui doivent être appliqués à la partie 
 * \param Carte sabot[] : tableau contenant les cartes du sabot
 * \param int *callStackSabot : pointeur sur l'indice du tableau ou piocher la carte suivant
 * \param Joueur tableauJoueur[] : tableau contenant les différent joueur
 * \param CarteListeChaine *mainDealer :  liste chainée qui contient les carte du dealer
 * \return void
*/

void partie(Parametre parametre, Carte sabot[], int *callStackSabot, Joueur tableauJoueur[], CarteListeChaine *mainDealer);

/**
 * \fn char verifieDecision(Joueur joueur, Parametre parametre)
 * \brief permet de détemine si un joueur à le droit de prendre la décision qu'il veut prendre
 * 
 * \param Joueur joueur : joueur qui prend la désision
 * \param Parametre parametre : parametre utilisé pour cette partie
 * \return char : 1 si l'action est imposible, 0 sinon
 */

char verifieDecision(Joueur joueur, Parametre parametre);

/**
 * \fn void appliqueDecision(Joueur *joueur, Parametre parametre,  Carte sabot[], int *callStackSabot)
 * \brief on applique la décision qui à été prise par le joueur
 * 
 * \param Joueur *joueur : joueur qui prend la décision
 * \param Parametre parametre : parametre utilisé pour cette partie
 * \param Carte sabot[] : tableau contenant les cartes du sabot
 * \param int *callStackSabot : pointeur sur l'indice du tableau ou piocher la carte suivant
 * \return void
 */

void appliqueDecision(Joueur *joueur, Parametre parametre,  Carte sabot[], int *callStackSabot);



#endif //_PARTIE_H_