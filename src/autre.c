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

void choisirParametre(Parametre *parametre, Caractere caractereJoueur[])
{
    printf("\nVoici les caractere des different joueur :\n\t\t MISE \t JOUE\n");
    char mise[50], joue[50];
    for (int i = 0; i < parametre->nbJoueur; i++)
    {
        switch (caractereJoueur[i].mise)
        {
        case MISE_HUMAIN:
            strcpy(mise, "Humain");
            break;

        case MINI:
            strcpy(mise, "Mise mini");
            break;

        case DOUBLE_SI_PERT:
            strcpy(mise, "Double si pert");
            break;
         
        
        default:
            strcpy(mise, "Inconue");
            break;
        }

        switch (caractereJoueur[i].joue)
        {
        case JOUE_HUMAIN:
            strcpy(joue, "Humain");
            break;

        case PASSE:
            strcpy(joue, "Passe");
            break;

        case DEALER:
            strcpy(joue, "Dealer");
            break;

        case BASIQUE:
            strcpy(joue, "Basique");
            break;
        
        default:
            strcpy(joue, "Inconue");
            break;
        }
        printf("Joueur %d :\t%s \t%s\n",i, mise, joue);
    }
    
    char continuer = 1;
    char retour = 12, retourOuiNon = 0;
    char chaineAAficher[50];
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
        afficheArgent(chaineAAficher, parametre->miseMini, -1);
        printf("7-Mise minimum : \t\t %s\n", chaineAAficher);
        afficheArgent(chaineAAficher, parametre->miseMaxi, -1);
        printf("8-Mise maximum : \t\t%s\n", chaineAAficher);
        afficheArgent(chaineAAficher, parametre->pactoleInitial, -1);
        printf("9-Pactole initial : \t\t%s\n", chaineAAficher);
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

 void setJoueur(Joueur *joueur, Mise caractereMise, Joue caractereJoue, long pactole, MainListeChaine *mainJoueur, Decision choixJoueur, long mise)
{
    joueur->caractere.mise = caractereMise;
    joueur->caractere.joue = caractereJoue;
    joueur->pactole = pactole;
    joueur->mainJoueur = mainJoueur;
    joueur->choixJoueur = choixJoueur;
    joueur->mise = mise;
    joueur->assurance = 0;
    joueur->dataIA.gainDernierePartie = 0;
}