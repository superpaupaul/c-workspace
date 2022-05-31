/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LC.h"
#include "tabh.h"



/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(int argc, char **argv)
{
    int nbmots; // nombre de mots chargés
    int ret;    // valeur de retour de sscanf
    FILE *f;    // descripteur de fichier
    TabH th; // table de hachage
    int taille_tab_h;// taille de la table de hachage
    char str[1000], mot[50];

/* GESTION DES ARGUMENTS                                                      */
    if(argc!=2 || sscanf(argv[1],"%d",&taille_tab_h)!=1 || taille_tab_h<=0)
        {
        fprintf(stderr,"Usage: %s taille_de_la_table_de_hachage\n",argv[0]);
        return 0;
        }
    
/* INITIALISATION DE LA TABLE DE HACHAGE À LA TAILLE DONNÉE                   */
    initTabH(&th, taille_tab_h);


/* OUVERTURE FICHIER DICTIONNAIRE                                             */
    f = fopen("../data/dictionnaire_fr_ss_accents","r");
    if(!f)
        {
        fprintf(stderr,"fopen dictionnaire raté\n");
        return 1;
        }

/* CHARGEMENT DU DICTIONNAIRE DANS LE TABLEAU                                 */
    nbmots=0;
    while(fgets(str, 1000, f)) // Lecture d'une ligne du fichier
        {
        ret=sscanf(str,"%s\n",mot); // Lecture du mot sur la ligne
        if(ret==1)
            {
            ajouteMotTabH(&th, mot);
            nbmots++;
            }
        }
    fclose(f); // Fermeture du descripteur de fichier

    printf("%d mots chargés\n",nbmots);

/******************************************************************************/
/* STATISTIQUES                                                               */
/******************************************************************************/
/* À vous d'écrire un code permettant d'afficher:                             */
/*   - la longueur max des LC de la table de hachage                          */
/*   - la longueur moyenne des LC non vides                                   */
/*   - le pourcentage de LC vides                                             */
/*   - le pourcentage de LC contenant au plus 2 mots                          */

    return 0;
}
