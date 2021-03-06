/******************************************************************************/
/* WT.H                                                                       */
/******************************************************************************/

#ifndef WT_H
#define WT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LC.h"




/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct noeud {
    struct noeud *fils[5];
    int            * tabFlags[5];
    Cellule      * cell;    
    char            term;
}Noeud;





/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
/* Crée un nouveau noeud                                                      */
Noeud *nouveauNoeud();
/* Ajoute un mot dans l'arbre                                                 */
void ajouteMotArbre(Noeud *racine,char *str, int prof, int index, int id_seq);
/* Cherche un mot dans l'arbre                                                */
Noeud* chercheMotArbre(Noeud *racine,char *str,int cmpt);




#endif

