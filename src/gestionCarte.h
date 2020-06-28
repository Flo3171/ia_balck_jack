#ifndef _GESTION_CARTE_H_
#define _GESTION_CARTE_H_

/**
 * \file gestionCarte.h 
 * \brief ficher header contenant les prototype des fonctions concertant la gestion des cartes
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

/**
 * \fn Carte* melangeCarte(char nbPaquetsParSabot)
 * \brief mélange les carte afin d'obtenir un tableau de carte mélangé
 * 
 * \param char nbPaquetsParSabot : indique le nombres de jeux de cartes utilisé dans un sabot
 * \return Carte * : pointeur sur le tableau de carte qui a été
*/

Carte* melangeCarte(char nbPaquetsParSabot);

#endif //_GESTION_CARTE_H_