#ifndef MAIN_H_
#define MAIN_H_

/**
 * \file main.h
 * \brief ficher la déclaration des contrante et l'inclusion des haeder du projet
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

//Déclaration des contsantes
#define NB_CARTE_PAQUETS 52
#define NB_FAMILLE_PAQUETS 4
#define NB_JOUEUR_MAXI 7

//Inclusion des structures
#include "structure.h"


//Inclusion des bibliothèques standard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>


//Inclusion des bibliothèques crées pour le projet
#include "partie.h"
#include "gestionCarte.h"
#include "autre.h"
#include "affichage.h"
#include "gestionDonnee.h"
#include "listeChainee.h"


#endif //MAIN_H_