/******************************************************************************/
/* LC.c                                                                       */
/******************************************************************************/
#include"./LC.h"


/******************************************************************************/
/* nouvelleCellule                                                            */
/******************************************************************************/
Cellule * nouvelleCellule(char *mot)
{
   Cellule *c = (Cellule *) malloc(sizeof(Cellule)); // allocation cellule
   c->suiv = NULL; // par sécurité, la cellule n'a pas de suivant
   c->mot = (char *)malloc(strlen(mot)+1); // allocation mot
   strcpy(c->mot, mot); // copie du mot
   return c;
}

/******************************************************************************/
/* ajouteMotLC                                                                */
/******************************************************************************/
Cellule * ajouteEnTeteLC(Cellule *l, char *mot)
{
	Cellule *c = nouvelleCellule(mot);
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
   printf("%s\n",l->mot);
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
