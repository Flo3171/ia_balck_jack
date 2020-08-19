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

void afficheArgent(char chaine[], long argent, int taille)
{
    if (argent < 0)
    {
        argent = -argent;
        sprintf(chaine, "-%d,%02d", argent/100, argent%100);
    }
    else
    {
        sprintf(chaine, "%d,%02d", argent/100, argent%100);
    }

    if (taille != -1)
    {
        char chaineTampon[500] = {0}, chainEspace[500] = {0};
        strcpy(chaineTampon, chaine);
        int nbEspaceAAjouter = taille - strlen(chaineTampon);
        if (nbEspaceAAjouter < 0)
        {
            strcpy(chaineTampon, "ouf size");
            nbEspaceAAjouter = taille - strlen(chaineTampon);
        }
        for (int  i = 0; i < nbEspaceAAjouter; i++)
        {
            strcat(chainEspace, " ");
        }
        sprintf(chaine, "%s%s", chainEspace, chaineTampon);
    }
    
    
    
    
    
    
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


 void afficheResultat(Joueur tableauJoueur[], Parametre parametre, double duration)
 {
    char chainePactole[12], chaineGain[12], chaineGainPartie[12], chaineGainInvestisement[12], chaineGain1000Partie[12];
    long gain;

    printf("\n%d partie viennent d'etre jouee en %.3f ms\n", parametre.nbPartie, duration*1000);
    printf("\t    _______________________________________________________________________________\n");
    printf("\t   |   Pactole   |     Gain    | Gain/1Partie | Gain/1000Partie |Gain/investisement|\n");
    printf(" __________|_____________|_____________|______________|_________________|__________________|");
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        gain = tableauJoueur[i].pactole - parametre.pactoleInitial;
        afficheArgent(chainePactole, tableauJoueur[i].pactole, 11);
        afficheArgent(chaineGain, gain, 11);
        afficheArgent(chaineGainPartie, gain/parametre.nbPartie, 11);
        afficheArgent(chaineGain1000Partie, (long)((gain/(double)parametre.nbPartie)*1000), 11);
        afficheArgent(chaineGainInvestisement, (long)((gain/(double)parametre.pactoleInitial)*10000), 11);

        printf("\n| Joueur %d | %s | %s |  %s |     %s |     %s %%|", i, chainePactole, chaineGain, chaineGainPartie, chaineGain1000Partie, chaineGainInvestisement);
        printf("\n|__________|_____________|_____________|______________|_________________|__________________|");
    }
    printf("\n\n");
 }