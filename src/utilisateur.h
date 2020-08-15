#ifndef _UTILISATEUR_H_
#define _UTILISATEUR_H_

/**
 * \file ia.c 
 * \brief ficher header contenant les prototypes des fonctions en raport avec l'utilisateur (acquisition, affichage et choix)
 * \author Florian.C
 * \version v1.0
 * \date 4 août 2020
*/

/**
 * \fn long acquisitionLongSecurisee()
 * \brief acquiert de manière sécurisée un long
 * 
 * \return long : le nombre saisi par l'utilisateur
*/

long acquisitionLongSecurisee();

/**
 * \fn long acquisitionSansMessage(long mini, long maxi, char consigne[])
 * \brief réalise l'acquisistion d'un long sans message d'erreur en affichant à l'utilisateur une consigne
 * 
 * \param long mini : valeur minimum que doit avoir la valeur saisie
 * \param long maxi : valeur maximum que doit avoir la valeur saisie
 * \param char consigne[] : message à afficher à l'utilisateur lors de l'acuisition
 * \return long : valeur saisi par l'utilisateur et qui à été controler pour être entre les deux bornes
*/

long acquisitionSansMessage(long mini, long maxi, char consigne[]);

/**
 * \fn long choixMiseUtilisateur(Joueur joueur, Parametre parametre)
 * \brief demande à l'utilisateur de choisir combien il veut miser pour la partie
 * 
 * \param Joueur joueur : joueur qui doit faire un choix
 * \param Parametre parametre : parametre de la partie
 * \return long : valeur misée par le joueur 
 */

long choixMiseUtilisateur(Joueur joueur, Parametre parametre);

/**
 * \fn Decision decisionJeuHumain(CarteListeChaine *mainJoueur,Carte carteDealer, Parametre parametre)
 * \brief revoie la décision faite par un joueur humain
 * 
 * \param CarteListeChainee *mainJoueur : pointeur sur la main du jouer a traiter
 * \param Carte carteDealer : carte visible du dealer
 * \param Parametre parametre : parametre de la partie
 * \return Decision : décision prise par le joueur
 */ 

Decision decisionJeuHumain(CarteListeChaine *mainJoueur,Carte carteDealer, Parametre parametre);

/**
 * \fn long choixAssuranceHumain(CarteListeChaine *mainJoueur, long miseJoueur)
 * \brief permet au joueur de type humain de choisir s'il prend une assurance
 * 
 * \param CarteListeChaine *mainJoueur : main du joueur
 * \param long miseJoueur : mise que le joueur à choisie au début de la partie
 * \return long : valeur de l'assurance prise par le joueur
 */

long choixAssuranceHumain(CarteListeChaine *mainJoueur, long miseJoueur);

#endif //_UTILISATEUR_H_