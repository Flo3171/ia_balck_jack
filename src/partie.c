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
            setJoueur(&tableauJoueur[i], MISE_HUMAIN, JOUE_HUMAIN, parametre.pactoleInitial, initialistationMain(), PASSER, parametre.miseMini);
        }
        else
        {
            setJoueur(&tableauJoueur[i], MINI, PASSE, parametre.pactoleInitial, initialistationMain(), PASSER, parametre.miseMini);
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
        supprimeToutMain(tableauJoueur[i].mainJoueur);
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

    /* si le dealer à un as on propose aux joueur de prendre une assurance*/
    if (mainDealer->premier->carte == AS){
        for (int i = 0; i < parametre.nbJoueur; i++)
        {
            tableauJoueur[i].assurance = choixAssurance(tableauJoueur[i].mainJoueur->premier->mainJoueur, tableauJoueur[i].mise, tableauJoueur[i].caractere.joue);
            if(tableauJoueur[i].mise + tableauJoueur[i].assurance > tableauJoueur[i].pactole){
                tableauJoueur[i].assurance = 0;
            }
        }
    }
    

    /* C'est le tour de chaque joueur de parler et d'anoncer ce qu'il veut faire */
    ElementMainListeChaine *mainATraiter = NULL;
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        if (tableauJoueur[i].mise > 0)  
        {  
            mainATraiter = tableauJoueur[i].mainJoueur->premier;
            do
            {
                do
                {
                    do
                    {
                        if (pointFinalMain(mainATraiter->mainJoueur) < 21)
                        {
                            /* Le joueur décide de ce qu'il veut faire*/
                            tableauJoueur[i].choixJoueur = decisionJeu(tableauJoueur[i].caractere.joue, mainATraiter->mainJoueur, mainDealer->premier->carte, parametre);
                        }
                        else if(pointFinalMain(mainATraiter->mainJoueur) == 21)
                        {
                            tableauJoueur [i].choixJoueur = PASSER;
                        }
                        else
                        {
                            tableauJoueur[i].choixJoueur = PASSER;
                            if (parametre.positionUtilisateur != -1)
                            {
                                printf("\nVous avez depase 21, vous avez donc perdu\n");
                            }
                        }
                    } while (verifieDecision(tableauJoueur[i].choixJoueur, mainATraiter->mainJoueur, tableauJoueur[i].pactole, tableauJoueur[i].mise,  parametre)/* on verifie que le joueur est bien autoriser a faire ce qu'il veut faire */);
                    
                    /* On applique ce qu'il veut faire*/
                    appliqueDecision(tableauJoueur[i].choixJoueur, mainATraiter->mainJoueur, tableauJoueur[i].caractere.joue, &tableauJoueur[i].mise, tableauJoueur[i].mainJoueur, parametre, sabot, callStackSabot);

                } while (tableauJoueur[i].choixJoueur != PASSER && tableauJoueur[i].choixJoueur != DOUBLER && tableauJoueur[i].choixJoueur != ABANDONNER && tableauJoueur[i].choixJoueur != SPLITTER);
                if (tableauJoueur[i].choixJoueur == SPLITTER)
                {
                    mainATraiter = tableauJoueur[i].mainJoueur->premier;
                }
                else
                {
                    mainATraiter = mainATraiter->suivant;    
                }
            } while (mainATraiter != NULL);
        }
    }
    

    /* Le dealer tire ces carte*/
    if (parametre.positionUtilisateur != -1)
            {
                printf("\nLe dealer a : ");
                afficheMain(mainDealer, -1);
                printf("\n");
            }
    do
    {
        if( pointFinalMain(mainDealer) >= 17 ){
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

    /* On paye les assurance */
    if(mainDealer->premier->suivant->carte == AS && mainDealer->nbElement == 2 && pointFinalMain(mainDealer) == 21){
        for (int i = 0; i < parametre.nbJoueur; i++)
        {
            tableauJoueur[i].pactole += tableauJoueur[i].assurance *2;
        }    
    }
    else
    {
        for (int i = 0; i < parametre.nbJoueur; i++)
        {
            tableauJoueur[i].pactole -= tableauJoueur[i].assurance;
        } 
    }
    

    /* On evalue les main par raport a celle du dealer et on paye tout le monde*/
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
        mainATraiter = tableauJoueur[i].mainJoueur->premier;
        while (mainATraiter != NULL)
        {
            if (tableauJoueur[i].mise > 0)
            {
                tableauJoueur[i].pactole += (double)(determineVainqueur(mainATraiter->mainJoueur, tableauJoueur[i].choixJoueur, parametre, mainDealer) * tableauJoueur[i].mise);    
            }
            mainATraiter = mainATraiter->suivant; 
        }
        
          
    }
    /* On vide les main des joueur et du dealer pour etre prêt pour la partie suivante */
    for (int i = 0; i < parametre.nbJoueur; i++)
    {
           videMain(tableauJoueur[i].mainJoueur); 
           tableauJoueur[i].assurance = 0;
    }
    videListeChainee(mainDealer);
    
}

char verifieDecision(Decision choixJoueur, CarteListeChaine *mainJoueur, long pactoleJoueur, long miseJoueur, Parametre parametre)
{
    /*1 si l'action est imposible, 0 sinon*/
    switch (choixJoueur)
    {
    case PASSER:
        return 0;
        break;
    case TIRER:
        if (pointMain(mainJoueur).nbPoint <= 21)
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
        if (pointMain(mainJoueur).nbPoint <= 21 && pactoleJoueur >= miseJoueur * 2 && mainJoueur->nbElement == 2)
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
        if (mainJoueur->nbElement == 2 && mainJoueur->premier->carte == mainJoueur->premier->suivant->carte && pactoleJoueur >= miseJoueur * 2)
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
        if (mainJoueur->nbElement == 2 && parametre.abandont == OUI)
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

void appliqueDecision(Decision choixJoueur, CarteListeChaine *mainATraiter, Joue caractereJoue, long *miseJoueur, MainListeChaine *mainJoueur, Parametre parametre,  Carte sabot[], int *callStackSabot)
{
    switch (choixJoueur)
    {
    case TIRER:
        insertionListeChainee(mainATraiter, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));
        if (caractereJoue == JOUE_HUMAIN){
            printf("\nVous obtenez : ");
            afficheMain(mainATraiter, 1);
        }
        break;
    case DOUBLER:
        insertionListeChainee(mainATraiter, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));
        *miseJoueur *= 2;
        if (caractereJoue == JOUE_HUMAIN){
            printf("\nVous obtenez :");
            afficheMain(mainATraiter, 1);
        }
        break;
    case SPLITTER:

        /* On crée une nouvelle main et on déplace la première carte de l'anciène mais dans cette nouvelle main*/
        ajouteMain(mainJoueur, NULL);
        insertionListeChainee(mainJoueur->premier->mainJoueur, mainATraiter->premier->carte);
        supprimeListeChainee(mainATraiter);

        /* On distibue une carte sur chaque jeu*/
        insertionListeChainee(mainATraiter, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));
        insertionListeChainee(mainJoueur->premier->mainJoueur, piocheCarte(sabot, callStackSabot, parametre.nbJeuParSabot));

        break;
    
    default:
        break;
    }
}

float determineVainqueur(CarteListeChaine *mainJoueur, Decision choixJoueur, Parametre parametre, CarteListeChaine *mainDealer)
{
    int pointDealer = pointFinalMain(mainDealer);
    int pointJoueur = pointFinalMain(mainJoueur);
    float coeffPaye = 0;

    if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez %d point, le dealer en a %d\n", pointJoueur, pointDealer);
            }

    if (choixJoueur == ABANDONNER)
    {
        coeffPaye = -0.5;
        if (parametre.positionUtilisateur != -1)
            {
                printf("Vous avez Abandonner, vous conserver donc la moitiee de votre mise\n");
            }
    }
    else if (pointDealer == 21 && mainDealer->nbElement == 2)
    {
        if (pointJoueur == 21 && mainJoueur->nbElement == 2)
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
        if (pointJoueur == 21 && mainJoueur->nbElement == 2)
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