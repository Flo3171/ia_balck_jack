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
 * \param CarteListeChainee *liste : pointeur sur la liste à supprimer
 * \return void
*/

void afficheListeChainee(CarteListeChaine *liste);

#endif //_LISTE_CHAINEE_H_