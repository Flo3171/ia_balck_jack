/**
 * \file ia.c 
 * \brief ficher source contenant les fonctions en raport avec l'utilisateur (acquisition, affichage et choix)
 * \author Florian.C
 * \version v1.0
 * \date 4 août 2020
*/

#include "main.h"

long acquisitionLongSecurisee()
{
    char nombreTexte[100] = {0};
    fgets(nombreTexte, 100, stdin);
    long nombre = strtol(nombreTexte, NULL, 10);
    if (nombre == 0 && nombreTexte[0]!='0'){
        nombre = -1;
    }

    /* On vide de buffer*/
    char c = nombreTexte[strlen(nombreTexte) - 1];
    while (c != '\n' && c != EOF)
    {
        c = getchar(); 
    }
    
    return nombre;
}


long acquisitionSansMessage(long mini, long maxi, char consigne[])
{
    long valeurRetour = 0;
    do
    {
        printf("%s\n", consigne);
        valeurRetour = acquisitionLongSecurisee();
    } while (valeurRetour < mini || valeurRetour > maxi);
    return valeurRetour;
    
}

long choixMiseUtilisateur(Joueur joueur, Parametre parametre)
{
    long choix = 0;
    printf("Vous avez ");
    afficheArgent(joueur.pactole);
    printf(" euro \n");
    do
    {
        choix = 100*acquisitionSansMessage(0, parametre.miseMaxi, "Combien voulez vous miser :");
    } while (choix != 0 && (choix < parametre.miseMini || choix > parametre.miseMaxi || choix > joueur.pactole ));
    return choix;
}

Decision decisionJeuHumain(CarteListeChaine *mainJoueur,Carte carteDealer, Parametre parametre)
{
    printf("\nVous avez : ");
    afficheMain(mainJoueur, -1);
    printf("\nCela vaut (point) : %d", pointFinalMain(mainJoueur));
    printf("\nLe dealeur a : "); 
    switch (carteDealer)
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
                printf("%d ", carteDealer);
                break;
            }
            
    printf("\nQuelle est votre decision ?\n1-Passer\n2-Tirer\n3-Doubler\n4-Splitter\n5-Abandonner");
    switch (acquisitionSansMessage(1, 5, ""))
    {
    case 1:
        return PASSER;
        break;
    case 2:
        return TIRER;
        break;
    case 3:
        return DOUBLER;
        break;
    case 4:
        return SPLITTER;
        break;
    case 5:
        return ABANDONNER;
        break;

    default:
        return PASSER;
        break;
    }
}

