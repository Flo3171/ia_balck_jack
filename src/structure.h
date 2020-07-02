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

/**
 * \enum OuiNon
 * \brief vaut soit oui soit non
 */

typedef enum OuiNon{
    NON = 0,/*!non*/
    OUI = 1/*!oui*/
}OuiNon;

/**
 * \struct Parametre
 * \brief regroupe tout les paramètre et les règle liée au jeu du black jack
 */

typedef struct Parametre
{
    int nbJeuParSabot;/*! Indique le nombre de jeux de 52 cartes que contient chacun des sabot*/
    int nbJoueur;/*! Indique le nombre de joueur autour de la table*/
    int nbCarteBrule;/*! Indique le nombre de cartes que le croupier brule au début de chaque partie*/
    OuiNon abandont;/* Indique si l'abandont est autorisé ou non*/
    int nbPaireMaxi;/* Indique le nombre de paire maximum qu'il est possible de spliter (mettre -1 si il n'y a pas de limite)*/
    OuiNon doublerPaire; /*! Indique si il est possible de doubler après avoir spliter une paire*/
    long miseMini; /*! Indique la mise minimum pour une partie*/
    long miseMaxi;/*! Indique la mise maximum pour une partie*/
    long pactoleInitial;/*! Indique la somme d'argent que le joueur possède quand il commence a jouer*/
    int positionUtilisateur; /*! Indique l'indice de la position de l'utilisateur (nombre entier entre 0 et nbjoueur-1), si il n'y a pas d'utilisateur mettre -1*/
    int nbpartie; /*! Indique le nombre de partie de black jack qui seront jouée*/
}Parametre;


#endif //_STRUCTURE_H_