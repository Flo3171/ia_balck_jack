#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

/**
 * \file affichage.h
 * \brief ficher header contenant les prototypes des fonctions ralatives à l'affichage
 * \author Florian.C
 * \version v1.0
 * \date 1er juillet 2020
*/

/**
 * \fn afficheOuiNon(OuiNon ouiNon)
 * \brief affiche le contenu d'une variable de type OuiNon
 * 
 * \param OuiNon ouiNon : variable dont on veut afficher le contenue
 * \return void
*/

void afficheOuiNon(OuiNon ouiNon);

/**
 * \fn void afficheArgent(long argent)
 * \brief affiche de manière claire une somme d'argent
 * 
 * \param long argent : la somme d'argent à afficher
 * \return void
*/

void afficheArgent(long argent);



#endif //_AFFICHAGE_H_