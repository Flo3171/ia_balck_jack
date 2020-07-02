/**
 * \file affichage.c
 * \brief ficher source contenant les fonctions ralatives à l'affichage
 * \author Florian.C
 * \version v1.0
 * \date 1er juillet 2020
*/

#include "main.h"

void afficheOuiNon(OuiNon ouiNon)
{
    if (ouiNon == OUI){
        printf("Oui");
    }
    else
    {
         printf("Non");
    }
    
}

void afficheArgent(long argent)
{
    printf("%d,%02d", argent/100, argent%100);
}