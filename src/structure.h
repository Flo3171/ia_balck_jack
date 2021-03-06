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
 * \enum Decision
 * \brief décision du joueur lorsque c'est sont tour de parler
 */

typedef enum Decision{
    PASSER = 0, /*! Le joueur passe (son tour est alors fini)*/
    TIRER = 1, /*! Le joueur tire une carte supplémentaire*/
    DOUBLER = 2,/*! Le joueur doble ça mise et tire une unique carte*/
    SPLITTER = 3,/*! Si le joueur à une paire il sépare ces deux cartes et les jouent comme deux jeux indépendant*/
    ABANDONNER = 4/*! Si autorisé par les paramètre, je joueur quitte la partie et récupère la moitiée de sa mise*/
}Decision;

/** 
 * \enum Mise
 * \brief caractère d'un joueur pour miser
 */

typedef enum Mise{
    MISE_HUMAIN = 0,/*! le joueur est humain*/
    MINI = 1,/*! l'ia mise toujour le minimum*/
    DOUBLE_SI_PERT = 2 /*! l'ia mise le double de ce qu'elle a mise a la partie précédente si elle à perdu */
}Mise;

/**
 * \enum Joue
 * \brief caractère d'un joueur pour jouer durant la partie
*/

typedef enum Joue{
    JOUE_HUMAIN = 0, /*! Le joueur est un humain*/
    PASSE = 1, /*! L'ia passe tout le temps*/
    DEALER = 2, /*! L'ia joue comme un dealer tire sur un 16 soft et reste sur un 17*/ 
    BASIQUE = 3/*! L'ia joue selon les règles les plus basiques (sans compter les cartes)*/
}Joue;

/**
 * \struct Sabot
 * \brief sabot contenant les cartes qui seront distribuée
 */

typedef struct Sabot
{
    Carte *tableauCarte; /*! Pointeur sur le tableau de carte qui contient les cartes du sabot */
    int callStackSabot; /*! Indice dans le tableau de la carte à distribuer */
    int nbPaquetParSabot; /*! le nombre de paquet de carte qui sont mis dans le sabot */
}Sabot;


/**
 * \struct Caractere
 * \brief caractère d'un joueur permet de savoir comment il va se comporter pour miser ou pour jouer
 */

typedef struct Caractere
{
    Mise mise;/*! caractère lors de la mise*/
    Joue joue;/*! catactère lors de la partie*/
}Caractere;


/**
 * \struct ElementCarteListeChaine
 * \brief un élément de la liste chainée qui contient des cartes
*/

typedef struct ElementCarteListeChaine ElementCarteListeChaine;
struct ElementCarteListeChaine
{
    Carte carte; /*! Valeur de la carte qui est contenu par cet élément de la liste chainée*/
    ElementCarteListeChaine *suivant;/*! Pointeur sur l'élément suivant de la liste chainée*/
};


/**
 * \struct CarteListeChaine
 * \brief le premier élément de la liste chainée qui contient des cartes
*/

typedef struct CarteListeChaine
{
    ElementCarteListeChaine *premier;/*! Pointeur sur le premier élément de la liste chainé du même nom*/
    double nbElement; /*! Le nombre l'émément dans la liste*/
}CarteListeChaine;

/**
 * \struct ElementMainListeChaine
 * \brief un élément de la liste chainée contenant une liste chainé contenant des cartes
 */

typedef struct ElementMainListeChaine ElementMainListeChaine;
struct ElementMainListeChaine
{
    CarteListeChaine *mainJoueur; /*! donne la liste chainée contenant la main du joueur */
    ElementMainListeChaine *suivant; /*! élément suivant dans la liste chainée*/

};

/**
 * \struct MainListeChaine
 * \brief premier élément de la liste chainée contenant des liste chainée contenant des carte
 */

typedef struct MainListeChaine
{
    ElementMainListeChaine *premier;/*! Pointeur sur le premier élément de la liste chainée*/
    int nbElement; /*! Nombre d'élément contenue dans la liste chainée*/

}MainListeChaine;

/**
 * \struct DataIA 
 * \brief permet de stoker toutes les informations dont les ia on besion pour fonctionner
 */

typedef struct DataIA
{
    long gainDernierePartie; /*! valeur qui a été gagner lors de la dernièrepartie */
}DataIA;


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
    int nbPartie; /*! Indique le nombre de partie de black jack qui seront jouée*/
}Parametre;

/**
 * \struct Joueur   
 * \brief regroupe toutes les information relative à un joueur
*/

typedef struct Joueur
{
    Caractere caractere; /*! facon de jouer qu'aura le joueur (humain ou ia et quel type d'ia)*/
    long pactole; /*! Somme d'argent que le joueur possède*/
    MainListeChaine *mainJoueur; /*! pointeur sur le premier élément de la liste chainée qui contient toutes les main du joueur*/
    Decision choixJoueur; /*! Action que le joueur à choisi de faire lorsque c'est sont tour de parler*/
    long mise; /*! mise choisie par le joueur pour la partie*/
    long assurance; /*! Indique la valeur de l'assurance prise par le joueur */
    DataIA dataIA; /*! contient toutes les information nésécaire au fonctionement des fonctions d'ia */


}Joueur;

/**
 * \struct Point
 * \brief nombre de point que vaut une main (peut valoir plusieur nombre à la fois a cause des As qui vallent 1 ou 11)
 */

typedef struct Point
{
    char nbPoint;
    char nbAs;
}Point;





#endif //_STRUCTURE_H_