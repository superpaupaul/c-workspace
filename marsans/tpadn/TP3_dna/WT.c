/******************************************************************************/
/* WT.C                                                                       */
/******************************************************************************/

#include "WT.h"



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
    return n;
}




/******************************************************************************/
/* ajouteMotArbre                                                             */
/******************************************************************************/
void ajouteMotArbre(Noeud *racine,char *str, int prof)
{
    char TRAD[] = {0,5,1,5,5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,3};
    //             a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u
    if(prof < 5)
    {
        if(racine ->fils[TRAD[*str-'A']]==NULL){

            racine ->fils[TRAD[*str-'A']] = nouveauNoeud();
            printf("%d\n",TRAD[*str-'A']);

        }
        ajouteMotArbre(racine -> fils[TRAD[*str-'A']], str+1, prof + 1);
    }

    return;
}



/******************************************************************************/
/* chercheMotArbre                                                            */
/******************************************************************************/
int chercheMotArbre(Noeud *racine,char *str)
{
    char TRAD[] = {0,5,1,5,5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,3};    

    if()    
    return chercheMotArbre(racine ->fils[TRAD[*str-'A']],*str+1);
}
