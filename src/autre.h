#ifndef _AUTRE_H_
#define _AUTRE_H_

/**
 * \file autre.h
 * \brief ficher header contenant les prototypes des fonctions n'allant nul part d'autre
 * \author Florian.C
 * \version v1.0
 * \date 27 juin 2020
*/

/**
 * \brief renvoie un nombre aléatoire entre 2 bornes
 * \fn int nbAleatoire(int mini, int maxi)
 * 
 * \param int mini : valeur la plus petite que le nombre renvoyé peut prendre
 * \param int maxi : valeur la plus grande que le nambre renvoyé peut prendre
 * \return int : nombre aléatoire entre mini et maxi
*/
int nbAleatoire(int mini, int maxi);

/**
 * \fn void choisirParametre(Parametre *parametre, Caractere caractereJoueur[])
 * \brief affiche une interface qui permet a l'utilisateur de regler les paramètre de la partie
 * 
 * \param Parametre *parametre : pointeur sur la variable qui contient les paramètre
 * \param Caractere caractereJoueur : tableau indiquant les cartacère des joueur
 * \return void
*/

void choisirParametre(Parametre *parametre, Caractere caractereJoueur[]);

/**
 * \fn void setParametre(Parametre *parametre, int nbJeuParSabot, int nbJoueur, int nbCarteBrule, OuiNon abandont, int nbPaireMaxi, OuiNon doublerPaire, long miseMini, long miseMaxi, long pactoleInitial, int positionUtilisateur, int nbPartie)
 * \brief parmet d'atibuer une valeur a une variable de type Parametre
 * 
 * \param Parametre *parametre : pointeur sur la variable de type parametre à modifier 
 * \param int nbJeuParSabot : valeur que l'on veut donner à parametre.nbJeuParSabot
 * \param int nbJoueur : valeur que l'on veut donner à parametre.nbJoueur
 * \param int nbCarteBrule : valeur que l'on veut donner à parametre.nbCarteBrule
 * \param OuiNon abandont : valeur que l'on veut donner à parametre.abandont
 * \param int nbPaireMaxi : valeur que l'on veut donner à parametre.nbPaireMaxi
 * \param OuiNon doublerPaire : valeur que l'on veut donner à parametre.doublerPaire
 * \param long miseMini : valeur que l'on veut donner à parametre.miseMini
 * \param long miseMaxi : valeur que l'on veut donner à parametre.miseMaxi
 * \param long pactoleInitial : valeur que l'on veut donner à parametre.pactoleInitial
 * \param int positionUtilisateur : valeur que l'on veut donner à parametre.positionUtilisateur
 * \param int nbPartie : valeur que l'on veut donner à parametre.nbPartie
 * \return void
*/

void setParametre(Parametre *parametre, int nbJeuParSabot, int nbJoueur, int nbCarteBrule, OuiNon abandont, int nbPaireMaxi, OuiNon doublerPaire, long miseMini, long miseMaxi, long pactoleInitial, int positionUtilisateur, int nbPartie);

/** 
 * \fn void setJoueur(Joueur *joueur, Mise caractereMise, Joue caractereJoue, long pactole, MainListeChaine *mainJoueur, Decision choixJoueur, long mise)
 * \brief modifie une variable de type joueur 
 * 
 * \param Joueur *joueur : pointeur sur la variable joueur à modifier
 * \param Mise caractereMise : carctère du joueur quand il mise
 * \param Joue caractereJoue : carctère du joueur quand il joue
 * \param long pactole : pactole du joueur
 * \param MainListeChaine *mainJoueur : pointeur sur le premier élément de la liste chainée contenant les main du joueur  
 * \param Decision choixJoueur : action que le joueur va faire
 * \param long mise : mise du joueur pour la partie
 * \return void
 */

void setJoueur(Joueur *joueur, Mise caractereMise, Joue caractereJoue, long pactole, MainListeChaine *mainJoueur, Decision choixJoueur, long mise);


#endif //_AUTRE_H_