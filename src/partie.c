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
    if (parametre.positionUtilisateur != -1)
            {
                printf("\nDebut de la partie\n");
            }
    Decision decisionDealer = PASSER;
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
            
            /* On applique ce qu'il veut faire*/
            appliqueDecision(&tableauJoueur[i], parametre, sabot, callStackSabot);
        } while (tableauJoueur[i].choixJoueur != PASSER && tableauJoueur[i].choixJoueur != DOUBLER && tableauJoueur[i].choixJoueur != ABANDONNER);
    }
    /* Le dealer tire ces carte*/
    Point pointMainDealer;
    if (parametre.positionUtilisateur != -1)
            {
                printf("\nLe dealer a : ");
                afficheMain(mainDealer, -1);
                printf("\n");
            }
    do
    {
        pointMainDealer = pointMain(mainDealer);
        if(pointMainDealer.nbPoint + pointMainDealer.nbAs*10 >= 17 ){
            decisionDealer = PASSER;
        }
        else
        {
            decisionDealer = TIRER;
            insertionListeChainee(mainDealer, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));
            if (parametre.positionUtilisateur != -1)
            {
                printf("Le dealer tire : ");
                afficheMain(mainDealer, 1);
                printf("\n");
            }
        }
        
    } while (decisionDealer != PASSER);

    /* On evalue les main par raport a celle du dealer et on paye tout le monde*/
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        tableauJoueur[i].pactole += (double)(determineVainqueur(&tableauJoueur[i], parametre, mainDealer) * tableauJoueur[i].mise);
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
            if (parametre.positionUtilisateur != -1)
            {
                printf("Imposible de tirer vous avez déja plus de 21 points");
            }
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
            if (parametre.positionUtilisateur != -1)
            {
                printf("Imposible de doubler");
            }
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
            if (parametre.positionUtilisateur != -1)
            {
                printf("Imposible de splitter");
            }
            return 1;
        }
        break;
    case ABANDONNER:
        if (joueur.mainJoueur->nbElement == 2 && parametre.abandont == OUI)
        {
            return 0;
        }
        else
        {
            return 1;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Imposible d'abandoner");
            }
        }  
        break;
    default:
        if (parametre.positionUtilisateur != -1)
            {
                printf("Désision incorecte");
            }
        return 1;
        break;
    }
}

void appliqueDecision(Joueur *joueur, Parametre parametre,  Carte sabot[], int *callStackSabot)
{
    switch (joueur->choixJoueur)
    {
    case TIRER:
        insertionListeChainee(joueur->mainJoueur, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));
        if (joueur->caractere.joue == JOUE_HUMAIN){
            printf("\nVous obtenez : ");
            afficheMain(joueur->mainJoueur, 1);
        }
        break;
    case DOUBLER:
        insertionListeChainee(joueur->mainJoueur, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));
        joueur->mise *= 2;
        if (joueur->caractere.joue == JOUE_HUMAIN){
            printf("\nVous obtenez :");
            afficheMain(joueur->mainJoueur, 1);
        }
        break;
    case SPLITTER:
        /*panik*/
        break;
    
    default:
        break;
    }
}

float determineVainqueur(Joueur *joueur, Parametre parametre, CarteListeChaine *mainDealer)
{
    int pointDealer = pointFinalMain(mainDealer);
    int pointJoueur = pointFinalMain(joueur->mainJoueur);
    float coeffPaye = 0;

    if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez %d point, le dealer en a %d\n", pointJoueur, pointDealer);
            }

    if (joueur->choixJoueur == ABANDONNER)
    {
        coeffPaye = -0.5;
        if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez Abandonner, vous conserver donc la moitiee de votre mise\n");
            }
    }
    else if (pointDealer == 21 && mainDealer->nbElement == 2)
    {
        if (pointJoueur == 21 && joueur->mainJoueur->nbElement == 2)
        {
            coeffPaye = 0;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Le dealer a fait un black jack naturel et vous aussi il y a donc égalite vous conservez votre mise\n");
            }
        }
        else
        {
            coeffPaye = -1;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Le dealer a fait un black jack naturel et pas vous, vous perdez donc votre mise\n");
            }
        }    
    }
    else
    {
        if (pointJoueur == 21 && joueur->mainJoueur->nbElement == 2)
        {
            coeffPaye = 1.5;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez fait un black Jack naturel, vous ganger donc une fois et demi votre mise\n");
            }
        }
        else if ((pointJoueur > pointDealer || pointDealer > 21) && pointJoueur <= 21)
        {
            coeffPaye = 1;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez plus de point que le dealer ou il a brule vous gagner donc une fois votre mise\n");
            }
        }
        else if (pointJoueur == pointDealer && pointJoueur <= 21)
        {
            coeffPaye = 0;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez autant de point que le dealer vous conserevez donc votre mise\n");
            }
        }
        else
        {
            coeffPaye = -1;
            if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez moin de point que le dealer ou vous avez brule, vous perdez donc votre mise\n");
            }
        }   
    }
    return coeffPaye;
}