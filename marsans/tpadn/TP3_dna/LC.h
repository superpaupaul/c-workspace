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
    char *mot;
    struct cellule * suiv;
    } Cellule;


/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
Cellule *nouvelleCellule(char *mot);
Cellule *ajouteEnTeteLC(Cellule *l, char *mot);
void afficheLC(Cellule *l);
int  chercheMotLC(Cellule *l, char *mot); // renvoie le nb de comparaisons, <=0 si pas trouvé







#endif

