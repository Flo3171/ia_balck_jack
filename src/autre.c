/**
 * \file autre.c
 * \brief ficher source contenant les fonctions n'allant nul part d'autre
 * \author Florian.C
 * \version v1.0
 * \date 27 juin 2020
*/

#include "main.h"

int nbAleatoire(int mini, int maxi)
{
    return (rand()%(maxi - mini +1)) + mini;
}