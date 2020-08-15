#ifndef _LISTE_CHAINEE_H_
#define _LISTE_CHAINEE_H_

/**
 * \file listeChainee.h 
 * \brief ficher header contenant les prototypes des fonctions en raport avec les listes chainée
 * \author Florian.C
 * \version v1.0
 * \date 7 juillet 2020
*/

/**
 * \fn CarteListeChaine *initialistationListeChainee()
 * \brief inisialise une liste chainée en créant tout les objets nécéssaires et renvoie un pointeur sur la liste
 * 
 * \return CarteListeChaine :  pointeur sur la liste
*/

CarteListeChaine *initialistationListeChainee();

/**
 * \fn void insertionListeChainee(CarteListeChaine *liste, Carte carteAAjouter)
 * \brief insert une carte dans une liste chainée
 * 
 * \param CarteListeChainee *liste : pointeur sur la liste à modifier
 * \param Carte carteAAjouter : valeur de la carte à ajouer à la liste chainée
 * \return void
*/

void insertionListeChainee(CarteListeChaine *liste, Carte carteAAjouter);

/**
 * \fn void supprimeListeChainee(CarteListeChaine *liste)
 * \brief supprime un élémement d'une liste chainée
 * 
 * \param CarteListeChainee *liste : pointeur sur la liste à modifier
 * \return void
*/

void supprimeListeChainee(CarteListeChaine *liste);

/**
 * \fn void supprimeToutListeChainee(CarteListeChaine *liste)
 * \brief supprime tout les élément d'une liste chainé ainsi que le premier élément
 * 
 * \param CarteListeChainee *liste : pointeur sur la liste à supprimer
 * \return void
*/

void supprimeToutListeChainee(CarteListeChaine *liste);

/**
 * \fn void afficheListeChainee(CarteListeChaine *liste)
 * \brief affiche le contenue d'une liste chainée
 * 
 * \param CarteListeChainee *liste : pointeur sur la liste à afficher
 * \return void
*/

void afficheListeChainee(CarteListeChaine *liste);

/**
 * \fn void videListeChainee(CarteListeChaine *liste)
 * \brief vide une liste chainée de tout ces elements
 * 
 * \param CarteListeChainee *liste : pointeur sur la liste à vider
 * \return void
 */

void videListeChainee(CarteListeChaine *liste);

/**
 * \fn MainListeChaine *initialistationMain()
 * \brief initilalise une liste chainée de type MainListeChaine
 * 
 * \return MainListeChaine * : pointeur sur la liste chainée qui vien d'être crée
 */

MainListeChaine *initialistationMain();

/**
 * \fn void ajouteMain(MainListeChaine *liste, CarteListeChaine *mainAAjouter)
 * \brief ajoute un élément a la liste chainée de main
 * 
 * \param MainListeCjaine *liste : liste chainée de main à laquel on veut ajouter une main
 * \param CarteListeChaine *mainAAjouter : pointeur sur la liste chainée de carte a ajouter si ce parametre vait NULL alors la liste sera crée
 * \return void
 */

void ajouteMain(MainListeChaine *liste, CarteListeChaine *mainAAjouter);

/**
 * \fn void retireMain(MainListeChaine *liste)
 * \brief retire une main d'une liste chainée de main+
 * 
 * \param MainListeChaine *liste : liste chainée de main dont on veut retirer un élément
 * \return void
 */

void retireMain(MainListeChaine *liste);

/**
 * \fn void videMain(MainListeChaine *liste)
 * \brief vide tout le contenu d'une liste chainée de main
 * 
 * \param MainListeChaine *liste : liste que l'on souhaite vider
 * \return void
 */

void videMain(MainListeChaine *liste);

/**
 * \fn void supprimeToutMain(MainListeChaine *liste)
 * \brief supprime la totalitée d'une liste chainée de main
 * 
 * \param MainListeChaine *liste : liste que l'on veut supprimer
 * \return void
 */

void supprimeToutMain(MainListeChaine *liste);

#endif //_LISTE_CHAINEE_H_