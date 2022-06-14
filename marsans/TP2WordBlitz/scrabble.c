/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#include "./scrabble.h"

/* quantité de chaque lettre                                                  */
char scrabble[NBL+1]="AAAAAAAAABBCCDDDEEEEEEEEEEEEEEEFFGGHHIIIIIIIIJKLLLLLMMMNNNNNNOOOOOOPPQRRRRRRSSSSSSTTTTTTUUUUUUVVWXYZ";

/******************************************************************************/
/* MAIN_ALEATOIRE                                                             */
/******************************************************************************/
void main_aleatoire(char *main, int len)
{
    char copyscrabble[NBL+1];
    int i,pos;

    strcpy(copyscrabble, scrabble);
    for(i=0; i!=len; i++)
        {
        pos = rand()%NBL;
        if(copyscrabble[pos]==' ')
            {
            i--;
            continue;
            }
        main[i] = copyscrabble[pos];
        copyscrabble[pos] = ' ';
        }
    main[i] = '\0';
}
