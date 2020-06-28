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

int main(){
    srand(time(NULL));
    printf("*********************PROGAM START*********************\n");


    
    Carte* sabot = melangeCarte(2);
    for (int  i = 0; i < 4*2; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%d  ", sabot[i*13 +j]);
        }
        printf("\n");
        
    }
    return EXIT_SUCCESS;
}
