#include<stdio.h>
#include<stdlib.h>
#include "matrice.c"


int main(){
    // tab <=> &tab[0][0]
    /* TEST ALLOCATION STATIQUE
    int tab[l][c];
    allocateStatic(tab);
    printStaticArray(tab);
    */

   /* TEST ALLOCATION DYNAMIQUE EN NON-VOID
   int lignes = 3;
   int col = 3;
   int ** tab = allocateTab(lignes,col);
    fillInTabWithUserInput(tab,lignes,col);
    printArray(tab,lignes,col);
    freeArray(tab,lignes);
    */
   /* TEST ALLOCATION DYNAMIQUE EN VOID
   int lignes = 3;
   int col = 3;
   int ** tab;
   allocateTabVoid(&tab,lignes,col);
   fillInTabWithUserInput(tab,lignes,col);
   printArray(tab,lignes,col);
   freeArray(tab,lignes);
   */
    int** tab = NULL;
    Matrice mat;
    mat.lignes = l;
    mat.colonnes = c;
    mat.tab2d = tab;
    allocateMatrix(&mat);
    printf("Test\n");
    fillInMatrixWithUserInput(&mat);
    
    printMatrix(mat);
    return 0;
}