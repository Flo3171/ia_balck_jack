#ifndef _IA_H_
#define _IA_H_

/**
 * \file ia.h 
 * \brief ficher header contenant les prototypes des fonctions en raport avec l'inteligence artificielle
 * \author Florian.C
 * \version v1.0
 * \date 4 août 2020
*/

/**
 * \fn long choixMise(Joueur joueur, Parametre parametre)
 * \brief revoie la mise choisie par le joueeur (l'utilisateur ou l'inteligence artificielle)
 * 
 * \param Joueur joueur : joueur qui doit faire un choix
 * \param Parametre parametre : parametre de la partie
 * \return long : mise choisie par le joueur
 */

long choixMise(Joueur joueur, Parametre parametre);

/**
 * \fn long choixMiseMini(Joueur joueur, Parametre parametre)
 * \brief revoie la mise choisie par un joueur dont le caractère est mise minimum
 * 
 * \param Joueur joueur : joueur qui doit faire un choix
 * \param Parametre parametre : parametre de la partie
 * \return long : mise choisie par le joueur
 */ 

long choixMiseMini(Joueur joueur, Parametre parametre);

/** 
 * \fn Decision decisionJeu(Joueur joueur,Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par le joueu qu'elle que soit sont caractère
 * 
 * \param Joueur joueur : joueur qui doit faire prendre une décision
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decison : choix qui à été fait par le joueur
 */

Decision decisionJeu(Joueur joueur,Carte carteDealer, Parametre parametre);

/** 
 * \fn Decision decisionJeuPasse(Joueur joueur, Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par le joueur dont le caractère est PASSE
 * 
 * \param Joueur joueur : joueur qui doit faire prendre une décision
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decison : choix qui à été fait par le joueur
 */

Decision decisionJeuPasse(Joueur joueur, Carte carteDealer, Parametre parametre);

/** 
 * \fn Decision decisionJeuDealer(Joueur joueur,Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par le joueur dont le caractère est DEALER
 * 
 * \param Joueur joueur : joueur qui doit faire prendre une décision
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decison : choix qui à été fait par le joueur
 */

Decision decisionJeuDealer(Joueur joueur,Carte carteDealer, Parametre parametre);

#endif //_IA_H_