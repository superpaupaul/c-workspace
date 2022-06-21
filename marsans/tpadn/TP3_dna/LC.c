/******************************************************************************/
/* LC.c                                                                       */
/******************************************************************************/
#include"./LC.h"


/******************************************************************************/
/* nouvelleCellule                                                            */
/******************************************************************************/
Cellule * nouvelleCellule(int index,int id_seq)
{
   Cellule *c = (Cellule *) malloc(sizeof(Cellule)); // allocation cellule
   c->suiv = NULL; // par sécurité, la cellule n'a pas de suivant
   c->index = index;
   c->seq_id = id_seq;
   //c->mot = (char *)malloc(strlen(mot)+1); // allocation mot
   //strcpy(c->mot, mot); // copie du mot
   return c;
}

/******************************************************************************/
/* ajouteMotLC                                                                */
/******************************************************************************/
Cellule * ajouteEnTeteLC(Cellule *l, int index, int id_seq)
{

	Cellule *c = nouvelleCellule(index, id_seq);
   c->suiv = l;
   return c;                                        
}

/******************************************************************************/
/* afficheLC                                                                  */
/******************************************************************************/
void afficheLC(Cellule *l)
{
   if(l == NULL)
   {
      return;
   }
   printf("SEQ:%d / POS: %d\n",l->seq_id, l->index);
   afficheLC(l->suiv);
/* ICI VOTRE CODE (10 lignes)                                                 */
}

/******************************************************************************/
/* chercheMotLC - renvoie nb comparaison, >0 si trouvé, <=0 sinon             */
/******************************************************************************/
int  chercheMotLC(Cellule *l, char *mot)
{
   int comparaisons = 0;
   while(l)
   {
      comparaisons++;
      if(strcmp(l->mot,mot) == 0)
      {
         return comparaisons;
      }
      l = l->suiv;
   }
   return -comparaisons;
}
