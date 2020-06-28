#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

/**
 * \file structure.h
 * \brief ficher la déclaration des structures des énumération
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

/**
 *\enum Carte
 *\brief Les différentes cartes possible d'un jeu de 52 cartes
 *
 * Au black jack, la couleur des cartes ne chage rien au jeu, donc se n'est pas la peine de l'enregistrer
 * 
 */

typedef enum Carte
{
    SANS_VALEUR = 0,  /*!Carte par défaut, pour une carte vide  */
    DEUX = 2, /*! Carte d'une valeur de 2*/
    TROIS = 3, /*! Carte d'une valeur de 3*/
    QUATRE = 4, /*! Carte d'une valeur de 4*/
    CINQ = 5,/*! Carte d'une valeur de 5*/
    SIX = 6,/*! Carte d'une valeur de 6*/
    SEPT = 7,/*! Carte d'une valeur de 7*/
    HUIT = 8,/*! Carte d'une valeur de 8*/
    NEUF = 9,/*! Carte d'une valeur de 9*/
    DIX = 10,/*! Carte d'une valeur de 10*/
    VALET = 11, /*! Carte d'une valeur d'un valet*/
    DAME = 12,/*! Carte d'une valeur d'une dame*/
    ROI = 13, /*! Carte d'une valeur d'un roi*/
    AS = 1/*! Carte d'une valeur de 11 en soft et 1 en hard*/
}Carte;

#endif //_STRUCTURE_H_