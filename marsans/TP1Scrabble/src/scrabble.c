/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#include "./scrabble.h"

/* quantité de chaque lettre                                                  */
char scrabble[NBL+1]="aaaaaaaaabbccdddeeeeeeeeeeeeeeeffgghhiiiiiiiijklllllmmmnnnnnnooooooppqrrrrrrssssssttttttuuuuuuvvwxyz";

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


/******************************************************************************/
/* CALC_COMBI                                                                 */
/******************************************************************************/
int calcule_combi(char *main_alea, char combi[FACT_MAXLENMOT][MAXLENMOT+1], int taille_cible)
{
    int poscombi=0;
    char main_copie[100], chemin[100];
    strcpy(main_copie, main_alea);
    rec_calc_combi(main_alea, 0, main_copie, combi, &poscombi, chemin, taille_cible);
    return poscombi;
}

void rec_calc_combi(char *main_alea, int posmain, char *main_copie, char combi[FACT_MAXLENMOT][MAXLENMOT+1], int *poscombi, char *chemin, int taille_cible)
{
    int i;

    if(posmain==taille_cible)
        {
        chemin[posmain]='\0';
        strcpy(combi[*poscombi], chemin);
        (*poscombi)++;
        return;
        }

    for(i=0; i!=MAXLENMOT; i++)
        {
        if(main_copie[i]==' ')
            continue;

        chemin[posmain] = main_copie[i];
        main_copie[i] = ' ';
        rec_calc_combi(main_alea, posmain+1, main_copie, combi, poscombi, chemin, taille_cible);
        main_copie[i] = main_alea[i];
        }
}


