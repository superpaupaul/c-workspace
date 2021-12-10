#include<stdio.h>
#include<stdlib.h>
#include "matrice.h"
#include "arrays.c"


void fillInMatrixWithUserInput(Matrice * mat){
    for(int i = 0; i < mat->lignes; i++){
        for(int j = 0; j < mat->colonnes; j++){
            printf("Entrez une valeur dans [%d][%d]\n",i,j);
            scanf("%d", &(mat->tab2d[i][j])) ; 
        }
    }
    printf("Voici la matrice résultante\n");
}

void printMatrix(Matrice mat){
    printArray(mat.tab2d, mat.lignes, mat.colonnes);
}

void allocateMatrix(Matrice * mat){
    allocateTabVoidV2(&(mat->tab2d),mat->lignes,mat->colonnes);
}