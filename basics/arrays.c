#include<stdio.h>
#include<stdlib.h>
#include "arrays.h"
#define c 3
#define l 3

void allocateStatic(int tab[l][c]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            scanf("%d",&tab[i][j]);
        }
    }
}


int** allocateTab(int lignes, int col){
    
    int** tableau = malloc(lignes*sizeof(int));

    for(int i = 0; i < lignes; i++){
        tableau[i] = malloc(col*sizeof(int));
    }

    return tableau;
}

void allocateTabVoid(int*** out, int lignes, int col){
    int ** tableau = (int**)malloc(lignes*sizeof(int*));
    
    for(int i = 0; i < lignes; i++){
        tableau[i] = (int*)malloc(col*sizeof(int));
    }
    *out = tableau;
}

void allocateTabVoidV2(int *** tab, int lignes, int colonnes){
    *(tab) = (int **)malloc(lignes*sizeof(int*));
    for(int i = 0; i < lignes; i++){
        (*tab)[i] = (int *)malloc(colonnes * sizeof(int));
    }
}

void fillInTabWithUserInput(int **tab, int lignes, int col){
    for(int i = 0; i < lignes; i++){
        for(int j = 0; j < col; j++){
            printf("Entrez une valeur dans [%d][%d]\n",i,j);
            scanf("%d",&tab[i][j]); 
        }
    }
}

void printArray(int **tab, int lignes, int col){
    printf("Voici la matrice résultante\n");
    for(int i = 0; i < lignes; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t",tab[i][j]); 
        }
        printf("\n");
    }
}

void printStaticArray(int tab[l][c]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d\t",tab[i][j]); 
        }
        printf("\n");
    }
}

void freeArray(int **tab, int lignes){
    for(int i = 0; i < lignes; i++){
        free(tab[i]);
    }
    free(tab);
}





