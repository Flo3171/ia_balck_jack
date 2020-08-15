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
 * \fn Decision decisionJeu(Joue caractereJoue, CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par le joueu qu'elle que soit sont caractère
 * 
 * \param Joue caractereJoue : caractère du Joueur
 * \param CarteListeChainee *mainJoueur : pointeur sur la main du joueur à traiter
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decison : choix qui à été fait par le joueur
 */

Decision decisionJeu(Joue caractereJoue, CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre);

/** 
 * \fn Decision decisionJeuPasse(CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par le joueur dont le caractère est PASSE
 * 
 * \param CarteListeChainee *mainJoueur : pointeur sur la main du joueur à traiter
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decison : choix qui à été fait par le joueur
 */

Decision decisionJeuPasse(CarteListeChaine *mainJoueur, Carte carteDealer, Parametre parametre);

/** 
 * \fn Decision decisionJeuDealer(CarteListeChaine *mainJoueur ,Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par le joueur dont le caractère est DEALER
 * 
 * \param CarteListeChaine *mainJoueur : main pour laquel le joueur doit prendre une décision
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decison : choix qui à été fait par le joueur
 */

Decision decisionJeuDealer(CarteListeChaine *mainJoueur ,Carte carteDealer, Parametre parametre);

/**
 * \fn long choixAssurance(CarteListeChaine *mainJoueur, long miseJoueur, Joue caractereJoue)
 * \brief permet au joueur de choisir s'il veut prendre l'assurance ou non
 * 
 * \param CarteListeChaine *mainJoueur : carte que le joueur à en main
 * \param long miseJoueur : mise que le joueur à choisi pour cette partie
 * \param Joue carcetreJoue : caractère du joueur pour jouer
 * \return long : valeur de l'assurance prise par le joueur
 */

long choixAssurance(CarteListeChaine *mainJoueur, long miseJoueur, Joue caractereJoue);

#endif //_IA_H_