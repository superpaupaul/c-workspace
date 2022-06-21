/******************************************************************************/
/* LISTES CHAINEES                                                            */
/******************************************************************************/

#ifndef LC_H
#define LC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct cellule {
    char mot; // INDEX pour DEFI C
    int index; 
    int seq_id;
    struct cellule * suiv;
    } Cellule;


/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
Cellule *nouvelleCellule(int index,int id_seq);
Cellule *ajouteEnTeteLC(Cellule *l, int index,int id_seq);
void afficheLC(Cellule *l);
int  chercheMotLC(Cellule *l, char *mot); // renvoie le nb de comparaisons, <=0 si pas trouvé







#endif

