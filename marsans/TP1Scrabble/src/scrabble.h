/******************************************************************************/
/*                                                                            */
/******************************************************************************/

#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NBL 100 // 100 lettres dans un jeu de scrabble (sans jokers)
#define MAXLENMOT 7 // Taille max des mots de notre jeu
#define FACT_MAXLENMOT 5040 // Factorielle de MAXLENMOT = nb de mots possibles

/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/





/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/

/* Tire une main aléatoire, sans repioche                                     */
/* Reçoit: le mot à remplir, la longueur du mot à construire                  */
void main_aleatoire(char *main_alea, int len);

/* Calcule les permutations d'un mot                                          */
/* Reçoit: la main aléatoire, le tableau de combinaisons à remplir,           */
/*         et la taille des mots à fabriquer.                                 */
/* Renvoie: le nombre de combinaisons trouvées                                */
int calcule_combi(char *main_alea, char combi[FACT_MAXLENMOT][MAXLENMOT+1], int taille_cible);
/* Sous-fonction récursive, pas touche                                        */
void rec_calc_combi(char *main_alea, int posmain, char *main_copie, char combi[FACT_MAXLENMOT][MAXLENMOT+1], int *poscombi, char *chemin, int taille_cible);














#endif

