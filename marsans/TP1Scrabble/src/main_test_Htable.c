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
    // char * test = "dentifrice";
    // printf("%d comparaisons\n",chercheMotTabH(&th,test));

/******************************************************************************/
/* STATISTIQUES                                                               */
/******************************************************************************/
/* À vous d'écrire un code permettant d'afficher:                             */
/*   - la longueur max des LC de la table de hachage                          */
/*   - la longueur moyenne des LC non vides                                   */
/*   - le pourcentage de LC vides                                             */
/*   - le pourcentage de LC contenant au plus 2 mots                          */
    int longueur_max = 0;
    int somme_longueurs = 0;
    int nombre_lc = th.taille;
    int nombre_listes_vides = 0;
    int nombre_listes_plus_de_2_mots = 0;

    for(int i = 0; i < nombre_lc; i++)
    {
        Cellule* cell = th.tab[i];
        int taille_lc = 0;
        
        while(cell)
        {
            taille_lc++;
            cell = cell->suiv;
        }

        somme_longueurs += taille_lc;
        if(taille_lc > longueur_max)
            longueur_max = taille_lc;

        if(taille_lc == 1)
            nombre_listes_vides++;
        else if(taille_lc <= 3)
            nombre_listes_plus_de_2_mots++;
    }

    float longueur_moyenne = somme_longueurs / (float)nombre_lc;
    float pourcentage_listes_vides = ((float) (nombre_lc - nombre_listes_vides) / (float) nombre_lc) * 100.0;
    float pourcentage_listes_plus_de_2_mots = ((float) (nombre_lc - nombre_listes_plus_de_2_mots) / (float) nombre_lc) * 100.0;
    
    printf("Longueur max des listes : %d\n",longueur_max);
    printf("Longueur moyenne des listes : %f\n",longueur_moyenne);
    printf("Pourcentage de listes vides : %f% \n",pourcentage_listes_vides);
    printf("Pourcentage de listes contenant au plus 2 mots : %f% \n",pourcentage_listes_plus_de_2_mots);





    return 0;
}
