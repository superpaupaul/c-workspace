/******************************************************************************/
/* WT.C                                                                       */
/******************************************************************************/

#include "WT.h"

void getAllFeuilles(Noeud * noeud)
{
    if(!noeud) // FEUILLE
    {
        return;
    }
    for(int i = 0; i < 5; i++)
    {
        if(noeud->tabFlags[i] == 0)
            return;
    }
    afficheLC(noeud->cell);
    for(int i = 0; i < 5; i++)
    {
        getAllFeuilles(noeud->fils[i]);
    }
}


/******************************************************************************/
/* nouveauNoeud                                                               */
/******************************************************************************/
Noeud *nouveauNoeud()
{
    Noeud * n = (Noeud *) malloc(sizeof(Noeud));
    int i;

    for(i=0;i!=5;i++)
        n->fils[i] = NULL;        
    n->term = 0;
    n->cell = NULL;
    for(int i = 0; i < 5; i++)
    {
        n->tabFlags[i] = 0;
    }
    return n;
}



/******************************************************************************/
/* ajouteMotArbre                                                             */
/******************************************************************************/
void ajouteMotArbre(Noeud *racine,char *str, int prof, int index,int id_seq)
{
    char TRAD[] = {0,5,1,5,5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,3};
    //             a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u
    if(prof < 5)
    {
        if(racine ->fils[TRAD[*str-'A']]==NULL){

            racine ->fils[TRAD[*str-'A']] = nouveauNoeud();

        }
        ajouteMotArbre(racine -> fils[TRAD[*str-'A']], str+1, prof + 1,index,id_seq);
    }

    if(racine->cell)
    {
        printf("[DEBUG] Ajoute En tete LC \n");
        racine->cell = ajouteEnTeteLC(racine->cell,index,id_seq);
    }
    else
    {
        printf("[DEBUG] nouvelle cellule \n");
        racine->cell = nouvelleCellule(index,id_seq);
    }

    racine->tabFlags[id_seq] = 1;
    return;
}



/******************************************************************************/
/* chercheMotArbre                                                            */
/******************************************************************************/
Noeud* chercheMotArbre(Noeud *racine,char *str,int cmpt)
{
    char TRAD[] = {0,5,1,5,5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,3};
    if( cmpt < 5 ){
        return chercheMotArbre(racine ->fils[TRAD[*str-'A']], str+1,cmpt+1);
    }
    return racine;
    
}
