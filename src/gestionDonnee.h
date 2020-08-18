#ifndef _GESTION_DONNEE_H_
#define _GESTION_DONNEE_H_

/**
 * \file gestionDonnee.h
 * \brief ficher source contenant les prototypes des fonctions ralatives à le gestion des donnée
 * \author Florian.C
 * \version v1.0
 * \date 4 juillet 2020
*/

/**
 * \fn Caractere *chargeParametre(char nomFichier[], Parametre *parametre)
 * \brief charge les parametres lu dans un fichier dans une variable de type Parametre
 * 
 * \param char nomFicher[]]): chaine de caractère contenant le chemin d'accès du ficher
 * \param Parametre *parametre : varriable de type Parametre dans laquel on va mettre les données lue dans le ficher    
 * \return Caractre * : pointeur sur le tableau de caracère qui a été crée
*/

Caractere *chargeParametre(char nomFichier[], Parametre *parametre);

#endif //_GESTION_DONNEE_H_