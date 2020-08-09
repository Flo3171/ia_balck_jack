/**
 * \file partie.c 
 * \brief ficher source contenant les fonctions en raport avec une partie
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

#include "main.h"

void joueBlackJack(Parametre parametre)
{
    /*! On initialise les tableaux et les variables qui seront utilisée au cour du jeu*/
    Carte *sabot = (Carte*) malloc(sizeof(Carte) * parametre.nbJeuParSabot * NB_CARTE_PAQUETS);
    int callstackSabot = 0;

    /*! On initialise le tableaux contenant les joueur*/
    Joueur *tableauJoueur = (Joueur*) malloc(sizeof(Joueur) * parametre.nbJoueur);
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        /*! On initialise chaque joueur selon les parametre de la partie */
        if (parametre.positionUtilisateur == i){
            setJoueur(&tableauJoueur[i], MISE_HUMAIN, JOUE_HUMAIN, parametre.pactoleInitial, initialistationListeChainee(), PASSER, parametre.miseMini);
        }
        else
        {
            setJoueur(&tableauJoueur[i], MINI, PASSE, parametre.pactoleInitial, initialistationListeChainee(), PASSER, parametre.miseMini);
        }
        /*printf("%d %d %d %d\n", tableauJoueur[0].caractere, tableauJoueur[0].choixJoueur, tableauJoueur[0].mise, tableauJoueur[0].pactole);*//*permet de controler que les joueur on été crée correctement */
    }
    /* On crée la main du dealer*/
    CarteListeChaine *mainDealer = initialistationListeChainee();

    /*! On appelle autant de fois que souhaité la fonction "partie"*/
    for (int i = 0; i < parametre.nbPartie; i++)
    {
        partie(parametre, sabot, &callstackSabot, tableauJoueur, mainDealer);
    }
    

    
    /* On libère tout l'espace qui à été utilisé au début de la fonction */
    free(sabot);
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        supprimeToutListeChainee(tableauJoueur[i].mainJoueur);
    }
    supprimeListeChainee(mainDealer);
    
    free(tableauJoueur);
}

void partie(Parametre parametre, Carte sabot[], int *callStackSabot, Joueur tableauJoueur[], CarteListeChaine *mainDealer)
{
    /* Chaqu'un des joueur choisit combien il mise durant cette partie */
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        tableauJoueur[i].mise = choixMise(tableauJoueur[i], parametre);
    }
    
    /* On distibue deux cartes à chaque joueur et une au dealer*/
    distubutionInitialCartes(tableauJoueur, mainDealer, parametre, sabot, callStackSabot);

    /* C'est le tour de chaque joueur de parler et d'anoncer ce qu'il veut faire */
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        do
        {
            do
            {
                /* Le joueur décide de ce qu'il veut faire*/
                tableauJoueur[i].choixJoueur = decisionJeu(tableauJoueur[i], mainDealer->premier->carte, parametre);
            } while (verifieDecision(tableauJoueur[i],  parametre)/* on verifie que le joueur est bien autoriser a faire ce qu'il veut faire */);
            
            /* On applique ce qu'il veut faire (et on verifie que cela est correcte*/
        } while (tableauJoueur[i].choixJoueur != PASSER && tableauJoueur[i].choixJoueur != DOUBLER);
        
    }
    
    /* On vide les main des joueur et du dealer pour etre prêt pour la partie suivante */
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
           videListeChainee(tableauJoueur[i].mainJoueur); 
    }
    videListeChainee(mainDealer);
    
}

char verifieDecision(Joueur joueur, Parametre parametre)
{
    /*1 si l'action est imposible, 0 sinon*/
    switch (joueur.choixJoueur)
    {
    case PASSER:
        return 0;
        break;
    case TIRER:
        if (pointMain(joueur.mainJoueur).nbPoint <= 21)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    case DOUBLER:
        if (pointMain(joueur.mainJoueur).nbPoint <= 21 && joueur.pactole >= joueur.mise * 2 && joueur.mainJoueur->nbElement == 2)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        break;
    case SPLITTER:
        if (joueur.mainJoueur->nbElement == 2 && joueur.mainJoueur->premier->carte == joueur.mainJoueur->premier->suivant->carte && joueur.pactole >= joueur.mise * 2)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
        
        break;
    case ABANDONNER:
        if (joueur.mainJoueur->nbElement == 2)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
        break;
        
        
    
    default:
        return 1;
        break;
    }
}