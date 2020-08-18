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
 * \fn void joueBlackJack(Parametre parametre, Caractere caractereJoueur[])
 * \brief permet de jouer au black jacke, joue le nombre de manche voulue
 * 
 * \param Parametre parametre : les paramètres qui doivent être appliqués à la partie
 * \param Caractere caractereJoueur : tableau contenant les caractères de chaque joueur
 * \return void
 */

void joueBlackJack(Parametre parametre, Caractere caractereJoueur[]);

/**
 * \fn void partie(Parametre parametre, Sabot *sabot, Joueur tableauJoueur[], CarteListeChaine *mainDealer)
 * \brief joue une partie de black jack
 * 
 * \param Parametre parametre : les paramètre qui doivent être appliqués à la partie 
 * \param Sabot *sabot : sabot contenant les cartes qui seront distribuée au joueurs
 * \param Joueur tableauJoueur[] : tableau contenant les différent joueur
 * \param CarteListeChaine *mainDealer :  liste chainée qui contient les carte du dealer
 * \return void
*/

void partie(Parametre parametre, Sabot *sabot, Joueur tableauJoueur[], CarteListeChaine *mainDealer);

/**
 * \fn char verifieDecision(Decision choixJoueur, CarteListeChaine *mainJoueur, long pactoleJoueur, long miseJoueur, Parametre parametre)
 * \brief permet de détemine si un joueur à le droit de prendre la décision qu'il veut prendre
 * 
 * \param Decision choixJoueur : décison prise par le joueur 
 * \param CarteListeChainee *mainJoueur : main du joueur à traiter
 * \param long pactoleJoueur : argent que le joueur possède
 * \param long miseJoueur : mise du joueur
 * \param Parametre parametre : parametre utilisé pour cette partie
 * \return char : 1 si l'action est imposible, 0 sinon
 */

char verifieDecision(Decision choixJoueur, CarteListeChaine *mainJoueur, long pactoleJoueur, long miseJoueur, Parametre parametre);

/**
 * \fn void appliqueDecision(Decision choixJoueur, CarteListeChaine *mainATraiter, Joue caractereJoue, long *miseJoueur, MainListeChaine *mainJoueur, Parametre parametre,  Sabot *sabot)
 * \brief on applique la décision qui à été prise par le joueur
 * 
 * \param Decision choixJoueur : choix fait par le joueur
 * \param CarteListeChainee *mainATraiter : main du joueur à traiter
 * \param Joue caractereJoue : caractère du joueur pour jouer
 * \param long *miseJoueur : mise du joueur
 * \param MainListeChaine *mainJoueur : pointeur sur la liste chainée de main associée au joueur
 * \param Parametre parametre : parametre utilisé pour cette partie
 * \param Sabot *sabot : sabot contenant les cartes qui seront distrubuée au joueurs
 * \return void
 */

void appliqueDecision(Decision choixJoueur, CarteListeChaine *mainATraiter, Joue caractereJoue, long *miseJoueur, MainListeChaine *mainJoueur, Parametre parametre,  Sabot *sabot);

/**
 * \fn float determineVainqueur(CarteListeChaine *mainJoueur, Decision choixJoueur, Parametre parametre, CarteListeChaine *mainDealer)
 * \brief détermine si le joueur a gagné ou perdu
 * 
 * \param CarteListeChaine *mainJoueur : main du joueur dont on veut savoir si elle a gagné ou non
 * \param Decision choixJoueur : décision que le joueur à prise
 * \param Parametre parametre : parametre utilisé pour cette partie 
 * \param CarteListeChaine *mainDealer : pointeur sur la liste chainée contenant la main du dealer
 * \return float : revoie un coeficient qui appliqué a ça mise donne ce que le joueur va gagner ou perdre
 */

float determineVainqueur(CarteListeChaine *mainJoueur, Decision choixJoueur, Parametre parametre, CarteListeChaine *mainDealer);


#endif //_PARTIE_H_