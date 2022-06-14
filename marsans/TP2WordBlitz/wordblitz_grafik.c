/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#include "wordblitz_grafik.h"



/******************************************************************************/
/* genereMatrice - génère une matrice de jeu aléatoire                        */
/******************************************************************************/
void genereMatrice(char m[4][4])
    {
    char alea16[16];
    int i;

    main_aleatoire(alea16, 16);
    for(i=0; i!=4; i++)
        {
        memcpy(m[i],alea16+4*i,4);
/*         m[i][4] = '\0'; */
        }
    }


/******************************************************************************/
/* afficheChemin - affiche à l'écran graphique un mot donné                   */
/******************************************************************************/
void afficheChemin(char *ch, int prof)
    {
/*     int i; */
    static Point p = {310,0};

/*     int val = calculeValeur(ch,prof); */

    ch[prof+1] = '\0';
    afficher_texte(ch, 15, p, blanc);
    p.y += 15;
    if(p.y>585)
        {
        p.y=0;
        p.x += 100;
        }

    actualiser();
/*     printf("%s\n",ch); */
/*     for(i=0; i<=prof; i++) */
/*         fprintf(stderr,"%c",ch[i]); */
/*     fprintf(stderr," %d\n",val); */
    }

/******************************************************************************/
/* chemin - visite tous les mots possibles de la grille                       */
/******************************************************************************/
int chemins(char m[4][4],  Noeud *racine)
    {
    posDamier d;
    int matvisite[4][4]={{0}}; // matrice des positions visitées (1 ou 0)
    int nbchemins=0;
    char chemin[16]; // le mot constitué au fur et à mesure du parcours

    /******************************************************************************/
    /* A VOUS DE COMPLETER - APPEL(S) A LA FONCTION REC                           */
    /******************************************************************************/
    for(d.l = 0; d.l < 4; d.l++)
    {
        for(d.c = 0; d.c < 4; d.c++)
        {
            nbchemins += recChemins(d,m,matvisite,0,chemin,racine);            
        }
    }

    printf("Nombre de chemins obtenus : \n");
    printf("%d\n",nbchemins);
    return nbchemins;
    }


/******************************************************************************/
/* recChemins - fonction récursive appelée par chemins                        */
/******************************************************************************/
int recChemins(posDamier d, char m[4][4], int matvisite[4][4], int prof, char *chemin, Noeud *n)
{
    if(d.c < 0 || d.c > 3 || d.l < 0 || d.l > 3)
    {
        return 0;   
    }
    if(matvisite[d.l][d.c] == 1)
    {
        return 0;
    }
    int res = 1;
    matvisite[d.l][d.c] = 1;
    chemin[prof] = m[d.l][d.c];
    //posDamier voisins[8] = {(posDamier){.l = d.l-1,.c = d.c-1},(posDamier){.l = d.l-1,.c = d.c},(posDamier){.l = d.l-1,.c = d.c+1},(posDamier){.l = d.l,.c = d.c-1},(posDamier){.l = d.l,.c = d.c+1},(posDamier){.l = d.l+1,.c = d.c-1},(posDamier){.l = d.l+1,.c = d.c},(posDamier){.l = d.l+1,.c = d.c+1}};
    for(int l = -1; l <= 1; l++)
    {
        for(int c = -1; c <= 1; c++)
        {
            posDamier posVoisin;
            posVoisin.l = d.l + l;
            posVoisin.c = d.c + c;
            res += recChemins(posVoisin,m,matvisite,prof + 1, chemin,n);
        }
    }

    matvisite[d.l][d.c] = 0;
    return res;
}

