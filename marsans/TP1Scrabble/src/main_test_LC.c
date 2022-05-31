/******************************************************************************/
/* Main de test des LC                                                        */
/******************************************************************************/
#include "LC.h"


int main(void)
    {
    Cellule *c = NULL;

    afficheLC(c);
    
    printf("--------------------------\n");

    c = ajouteEnTeteLC(c, "bob");
    c = ajouteEnTeteLC(c, "robert");
    afficheLC(c);

    printf("--------------------------\n");


    c = ajouteEnTeteLC(c, "jiojoihiuhiu");
    c = ajouteEnTeteLC(c, "iojijo");
    afficheLC(c);

    printf("--------------------------\n");

    
	printf("Je cherche 'oui': %d comparaisons\n", chercheMotLC(c,"oui"));
	printf("Je cherche 'robert': %d comparaisons\n", chercheMotLC(c,"robert"));

    return 0;
    }





