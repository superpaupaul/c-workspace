/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LC.h"
#include "tabh.h"
#include "scrabble.h"



/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(int argc, char **argv)
{
    int nbmots=0; // nombre de mots chargés
    int ret;    // valeur de retour de sscanf
    FILE *f;    // descripteur de fichier
    TabH th; // table de hachage
    int taille_tab_h;// taille de la table de hachage
    char str[1000], mot[50];

/* INITIALISATION DE LA FONCTION DE TIRAGE ALEATOIRE                          */
    srand(time(NULL));


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
/* SCRABBLE - C'EST ICI QUE VOUS TRAVAILLEZ                                   */
/******************************************************************************/
    char main_alea[100];
    main_aleatoire(main_alea,MAXLENMOT);
    printf("Vos lettres: %s\n\n",main_alea);
    printf("Tapez ENTREE --------\n");
    getchar();

    char combi[FACT_MAXLENMOT][MAXLENMOT+1]; //Ici toutes les combinaisons possibles
    int nbcombi, j;

    nbcombi = calcule_combi(main_alea,combi,5); // toutes les combis de 5 lettres
    printf("\n\nPour %d lettres, %d possibilités.\n", 5, nbcombi);

    for(j=0; j!=nbcombi; j++)
        {
        printf(" %s\n",combi[j]);
/******************************************************************************/
/* ICI COMPLETEZ EN CHERCHANT CHAQUE COMBINAISON DANS VOTRE TABLE DE HACHAGE  */
/******************************************************************************/
        }



    return 0;
    }
