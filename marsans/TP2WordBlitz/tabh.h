/******************************************************************************/
/* tabh.h                                                                     */
/******************************************************************************/
#ifndef TABH_H
#define TABH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./LC.h"

/******************************************************************************/
/* structure TabH                                                             */
/******************************************************************************/
typedef struct {
    Cellule **tab;
    unsigned int taille;
    } TabH;

/******************************************************************************/
/* initialisation de la table de hachage                                      */
/******************************************************************************/
int initTabH(TabH *th, int taille);

/******************************************************************************/
/* ajout d'un mot dans la table de H                                          */
/******************************************************************************/
void ajouteMotTabH(TabH *th, char *mot);

/******************************************************************************/
/* cherche mot dans TabH:                                                     */
/*   renvoie un >0 si trouvé, vaut le nombre de comparaisons effectuées       */
/*   renvoie un <0 si pas trouvé, vaut le nombre de comparaisons effectuées   */
/******************************************************************************/
int chercheMotTabH(TabH *th, char *mot);

/******************************************************************************/
/* fonction de hachage                                                        */
/******************************************************************************/
unsigned long long int hachage(char *mot);

#endif
