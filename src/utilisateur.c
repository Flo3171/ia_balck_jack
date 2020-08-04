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

