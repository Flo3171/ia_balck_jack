/**
 * \file main.c
 * \brief ficher contenant la fonction main
 * \author Florian.C
 * \version v1.0
 * \date 19 juin 2020
*/

/**
 * \fn int main(int argc, char *argv[])
 * \brief Entrée du programme
 * \author Florian.C
 *
 * \return EXIT_SUCCESS - Arrêt normal du programme
 */

#include "main.h"

int main(int argc, char *argv[]){
    srand(time(NULL));
    printf("*********************PROGRAM START*********************\n");
    char continuer = 1, retour = 0;
    Parametre parametre;
    Caractere *caractereJoueur = chargeParametre("data/default_parametre_7_ia.txt", &parametre);    
    while (continuer)
    {
        retour = acquisitionSansMessage(1, 3, "Quelle action souhaitez vous realiser ?\n1-JOUER\n2-Parametres\n3-Quitter");
        switch (retour)
        {
        case 1:
            joueBlackJack(parametre, caractereJoueur);
            break;
        case 2:
            choisirParametre(&parametre, caractereJoueur);
            break;
        
        default:
            continuer = 0;
            break;
        }

        
    }
    
    free(caractereJoueur);
    
    

    printf("\n**********************PROGRAM END**********************\n");
    return EXIT_SUCCESS;
}
