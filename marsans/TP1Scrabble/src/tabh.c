/******************************************************************************/
/* Fonctions de hachage                                                       */
/******************************************************************************/
#include "tabh.h"


/******************************************************************************/
/* initialisation de la table de hachage                                      */
/******************************************************************************/
int initTabH(TabH *th, int taille)
    {
/* ALLOCATION DE LA TABLE DE HACHAGE                                          */
    th->tab = (Cellule **)calloc(taille,sizeof(Cellule*));
    th->taille = taille;
    return 1;
    }

/******************************************************************************/
/* ajoute un mot dans la table de H                                           */
/******************************************************************************/
void ajouteMotTabH(TabH *th, char *mot)
    {
    unsigned long long int h; // reçoit le résultat du hachage
/* ICI VOUS HACHEZ LE MOT LU AFIN D'OBTENIR UN INDICE DANS LA TABLE           */
/* PUIS VOUS AJOUTEZ CE MOT DANS LA LC SE TROUVANT A CET INDICE.              */

    }

/******************************************************************************/
/* cherche mot dans TabH:                                                     */
/*   renvoie un >0 si trouvé, vaut le nombre de comparaisons effectuées       */
/*   renvoie un <0 si pas trouvé, vaut le nombre de comparaisons effectuées   */
/******************************************************************************/
int chercheMotTabH(TabH *th, char *mot)
    {
    unsigned long long int h;
/******************************************************************************/
/* ICI, VOUS HACHEZ LE MOT RECU ET RECHERCHEZ CE MOT DANS LA BONNE LISTE      */
/* CHAINEE DE VOTRE TABLE DE HACHAGE                                          */
/******************************************************************************/

    return 0; // à modifier
    }

/******************************************************************************/
/* hachage                                                                    */
/******************************************************************************/
unsigned long long int hachage(char *mot)
{
    unsigned long long int som=0, unite;
    int base; // base dans laquelle on calcule

    return som;
}

