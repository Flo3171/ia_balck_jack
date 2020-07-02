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
 * \fn void partie(Parametre parametre, Carte sabot[], int callStackSabot)
 * \brief joue une partie de black jack
 * 
 * \param Parametre parametre : les paramètre qui doivent être appliqués à la partie 
 * \param Carte sabot[] : tableau contenant les cartes du sabot
 * \param int *callStackSablot : pointeur sur l'indice du tableau ou piocher la carte suivant
 * \return void
*/

void partie(Parametre parametre, Carte sabot[], int *callStackSabot);




#endif //_PARTIE_H_