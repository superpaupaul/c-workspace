#include "main_wordblitz_grafik.h"

/******************************************************************************/
/* miseEnMajuscules                                                           */
/******************************************************************************/
void miseEnMajuscules(char *str)
    {
    char *ptr;
    for(ptr=str;*ptr!='\0';ptr++)
        *ptr = toupper(*ptr);
    }

/******************************************************************************/
/* miseEnMinuscules                                                           */
/******************************************************************************/
void miseEnMinuscules(char *str)
    {
    char *ptr;
    for(ptr=str;*ptr!='\0';ptr++)
        *ptr = tolower(*ptr);
    }

/******************************************************************************/
/* MAIN                                                                       */
/******************************************************************************/
int main(int argc, char *argv[])
    {
    FILE *f=fopen("../data/dictionnaire_fr_ss_accents","r"); 
    Noeud * racine = nouveauNoeud();
    char str[100];
    char line[100];
    char timestr[10];
    posDamier d, precd;
    Point p, precp, poschrono={170,10}, posmots={5,10};
    clock_t debut, present;
    int i,postr, fin;
    char m[4][4],trace[4][4];
    int ret;
    TabH th; // table de hachage
    int taille_tab_h = 320000;// taille de la table de hachage*
    int nbmots;
    char mot[50];
    

    ouvrir_fenetre(1200,600);
    initTabH(&th,taille_tab_h);

    if(!f)
        {
        printf("Erreur ouverture dico\n");
        return 1;
        }

    while(fgets(line,100,f))
        {
        ret = sscanf(line,"%s\n",str);
        if(ret==1)
            {
                miseEnMajuscules(str);
                ajouteMotTabH(&th,str);
            }
        }
        printf("Dictionnaire chargé\n");
/******************************************************************************/
/* calcul Matrice de jeu                                                      */
/******************************************************************************/

    srand(time(NULL));
    genereMatrice(m);
    dessinerDam(m);
    actualiser();

    debut = clock();
    fin = 0;
    while(1)
        {
        postr = 0;
        initDam(trace);
        while(1)
            {
            reinitialiser_evenements();
            // captation
            traiter_evenements();
            p = clic_a_eu_lieu();

/* Gestion du compte à rebours                                                */
            present = clock();
            sprintf(timestr,"%ld",GAME_TIME-(present-debut)/CLOCKS_PER_SEC);
            dessiner_rectangle(poschrono,70,40,rouge);
            afficher_texte(timestr,30,poschrono,blanc);
            actualiser();
/* Si temps dépassé, c'est fini                                               */
            if((present-debut)/CLOCKS_PER_SEC>=GAME_TIME)
                {
                fin = 1;
                break;
                }

/* Si aucun événement souris, on relance                                      */
            if(p.x==-1 || p.y==-1)
                continue;

/* Sinon, je lis la position damier cliquée                                   */
            d = screen2posDamier(p);
/*             printf("%d %d = L%d C%d\n",p.x,p.y, d.l, d.c); */
/* Si c'est hors du damier, le mot str est complet, le chercher ds dico       */
            if(!estDansDamier(d))
                {
                str[postr]='\0';
                break;
                }

/* Sinon, si emplacement déjà cliqué, on attend un autre click                */
            if(trace[d.l][d.c]!=0)
                continue;

/* Sinon, si case neuve cliquée, si pas la première                           */
            if(postr!=0)
                {
/* Si on n'est pas voisin avec la précédente, on reboucle                     */
                if(!sontVoisins(d, precd))
                    continue;

/* Sinon c'est bon, on allume et on dessine le trait                          */
                allumerLettre(d, m);
                dessiner_ligne_epaisse(p,precp,2);
                }
/* Si c'est la première, on se contente de l'allumer                          */
            else
                allumerLettre(d, m);

            actualiser();

/* Stockage de la lettre cliqueée                                             */
            str[postr] = m[d.l][d.c];
/* Mémorisation qu'on est passé par là                                        */
            trace[d.l][d.c] = 1;
            postr++;
            precp = p;
            precd = d;
            }

/* Si partie finie                                                            */
        if(fin)
            break;

/******************************************************************************/
/* On dispose maintenant d'un mot str propre dont il faut chercher s'il existe*/
/* Je cherche le mot str dans la structure de données                         */
/* A VOUS DE COMPLETER LA CONDITION CI-DESSOUS */
/******************************************************************************/
        if(chercheMotTabH(&th,str) > 0)
        {
            printf("%s OK\n",str); 
            afficher_texte(str,15,posmots,blanc);
            posmots.y += 15;
        }
        dessinerDam(m);
        actualiser();
        }


/* Recherche de toutes les solutions!                                         */
    chemins(m,racine);
    attendre_clic();
    fermer_fenetre();
    }
