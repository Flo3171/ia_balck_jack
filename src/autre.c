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

void choisirParametre(Parametre *parametre)
{
    char continuer = 1;
    char retour = 12, retourOuiNon = 0;
    while (continuer)
    {
        /* On affiche les paramètres actuels */
        printf("\nVoici les parametres actuels\n");
        printf("1-Nombre de jeu par sabot : \t%d\n", parametre->nbJeuParSabot);
        printf("2-Nombre de joueur : \t\t%d\n", parametre->nbJoueur);
        printf("3-Nombre de cartes brulee : \t%d\n", parametre->nbCarteBrule);
        printf("4-Abandont autorise : \t\t");
        afficheOuiNon(parametre->abandont);
        printf("\n");
        printf("5-Nombre de paire maximum : \t");
        if (parametre->nbPaireMaxi == -1)   
        {
            printf("pas de limite\n");
        }
        else
        {
            printf("%d\n", parametre->nbPaireMaxi);
        }
        printf("6-Doubler sur une paire : \t");
        afficheOuiNon(parametre->doublerPaire);
        printf("\n");
        printf("7-Mise minimum : \t\t");
        afficheArgent(parametre->miseMini);
        printf("\n");
        printf("8-Mise maximum : \t\t");
        afficheArgent(parametre->miseMaxi);
        printf("\n");
        printf("9-Pactole initial : \t\t");
        afficheArgent(parametre->pactoleInitial);
        printf("\n");
        printf("10-Position de l'utilisateur : \t");
        if (parametre->positionUtilisateur == -1)
        {
            printf("Pas d'utilisateur\n");
        }
        else
        {
            printf("%d\n", parametre->positionUtilisateur);
        }
        printf("11-Nombre de partie jouee : \t%d\n\n", parametre->nbPartie);

        /* On propose à l'utilisateur de modifier les paramètre*/
        retour = acquisitionSansMessage(1, 12, "Entrez le numeros du parametre que vous souhaitez modifier, entrer 12 pour quitter");

        switch (retour)
        {
        case 1:
            parametre->nbJeuParSabot = acquisitionSansMessage(1, 1000, "Combien y a il de jeu par sabot ?\n");
            break;
        case 2:
            parametre->nbJoueur = acquisitionSansMessage(1, NB_JOUEUR_MAXI, "Combien y a il de joueur ?\n");
            break;
        case 3:
            parametre->nbCarteBrule = acquisitionSansMessage(1, 1000, "Combien y a il de carte brulee ?\n");
            break;
        case 4:
            retourOuiNon = acquisitionSansMessage(1, 2, "L'abandon est il autorise ?\n1-Oui\n2-Non\n");
            if (retourOuiNon == 1)
            {
                parametre->abandont = OUI;
            }
            else if (retourOuiNon == 2)
            {
                parametre->abandont = NON;
            }
            break;
        case 5:
            parametre->nbPaireMaxi = acquisitionSansMessage(-1, 100, "Quel est le nombre de paires maximun (mettre -1 si il n'y a pas de limite)\n");
            break;
        case 6:
            retourOuiNon = acquisitionSansMessage(1, 2, "Peut on doubler sur une paire ?\n1-Oui\n2-Non\n");
            if (retourOuiNon == 1)
            {
                parametre->doublerPaire = OUI;
            }
            else if (retourOuiNon == 2)
            {
                parametre->doublerPaire = NON;
            }
            break;
        case 7:
            parametre->miseMini = 100*acquisitionSansMessage(1, LONG_MAX, "Quel est la mise minimum ?\n");
            break;
        case 8:
            parametre->miseMaxi = 100*acquisitionSansMessage(1, LONG_MAX, "Quel est la mise maximum ?\n");
            break;
        case 9:
            parametre->pactoleInitial = 100*acquisitionSansMessage(1, LONG_MAX, "Quel est le pactole initial ?\n");
            break;
        case 10:
            parametre->positionUtilisateur = acquisitionSansMessage(-1, NB_JOUEUR_MAXI, "Quel est la position de l'utilisateur ?(mettre -1 si il n'y a pas d'utilisateur)\n");
            break;
        case 11:
            parametre->nbPartie = acquisitionSansMessage(1, LONG_MAX, "Combien de partie voulez vous jouer ?\n");
            break;
        default:
            /*On contrôle que les paramètre sont cohérent*/
            if (parametre->miseMini > parametre->miseMaxi)
            {
                printf("La mise minimum est superieur a la mise maximum, veuillez modifier cela");
            }
            else if (parametre->positionUtilisateur > parametre->nbJoueur)
            {
                printf("La position du joueur doit etre plus petite que le nombre de joueur");
            }
            else
            {
                continuer = 0;
            }
            break;
        }


    }
    
    


}

void setParametre(Parametre *parametre, int nbJeuParSabot, int nbJoueur, int nbCarteBrule, OuiNon abandont, int nbPaireMaxi, OuiNon doublerPaire, long miseMini, long miseMaxi, long pactoleInitial, int positionUtilisateur, int nbPartie)
{
    parametre->nbJeuParSabot = nbJeuParSabot;
    parametre->nbJoueur = nbJoueur;
    parametre->nbCarteBrule = nbCarteBrule;
    parametre->abandont = abandont;
    parametre->nbPaireMaxi = nbPaireMaxi;
    parametre->doublerPaire = doublerPaire;
    parametre->miseMini = miseMini;
    parametre->miseMaxi = miseMaxi;
    parametre->pactoleInitial = pactoleInitial;
    parametre->positionUtilisateur = positionUtilisateur;
    parametre->nbPartie = nbPartie;
}

long acquisitionDoubleSecurisee()
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
        valeurRetour = acquisitionDoubleSecurisee();
    } while (valeurRetour < mini || valeurRetour > maxi);
    return valeurRetour;
    
}

void setJoueur(Joueur *joueur, Caractere caractere, long pactole, CarteListeChaine *mainJoueur, Decision choixJoueur, long mise)
{
    joueur->caractere = caractere;
    joueur->pactole = pactole;
    joueur->mainJoueur = mainJoueur;
    joueur->choixJoueur = choixJoueur;
    joueur->mise = mise;
}