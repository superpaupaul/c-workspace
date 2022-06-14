/******************************************************************************/
/*                                                                            */
/******************************************************************************/

#ifndef WORDBLITZ_H
#define WORDBLITZ_H

#include <stdio.h>
#include "scrabble.h"
#include "WT.h"
#include "grafik.h"
#include "../lib/libgraphique.h"





/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/




/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
/* Tire des lettre aléatoirement et en remplit la matrice                     */
void genereMatrice(char m[4][4]);


/* Fonction récursive de recherche de solutions                               */
int recChemins(posDamier d, char m[4][4], int matvisite[4][4], int prof, char *chemin, Noeud *);
/* Lancement de la recherche de solutions                                     */
int chemins(char m[4][4], Noeud *);

/* Affiche à l'écran le mot solution trouvé lors du parcours récursif         */
void afficheChemin(char *ch, int prof);














#endif

