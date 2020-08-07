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

void afficheMain(CarteListeChaine *mainJoueur, char nbCarteAAfficher)
{
    ElementCarteListeChaine *actuel = mainJoueur->premier;
    if (nbCarteAAfficher == -1) 
    {
        while (actuel != NULL)
        {
            switch (actuel->carte)
            {
            case AS:
                printf("AS ");
                break;
            case ROI:
                printf("ROI ");
                break;
            case DAME:
                printf("DAME ");
                break;
            case VALET:
                printf("VALET ");
                break;    
            default:
                printf("%d ", actuel->carte);
                break;
            }
            actuel = actuel->suivant;
        }
        
    }
    else
    {
        for (int i = 0; i < nbCarteAAfficher; i++)
        {
            switch (actuel->carte)
            {
            case AS:
                printf("AS ");
                break;
            case ROI:
                printf("ROI ");
                break;
            case DAME:
                printf("DAME ");
                break;
            case VALET:
                printf("VALET ");
                break;    
            default:
                printf("%d ", actuel->carte);
                break;
            }
            actuel = actuel->suivant;
        }
        
        
    }
    
    
}