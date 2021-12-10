#define c 3
#define l 3




void allocateStatic(int tab[l][c]);

int** allocateTab(int lignes, int col);

void allocateTabVoid(int*** out, int lignes, int col);

void allocateTabVoidV2(int *** tab, int lignes, int colonnes);

void fillInTabWithUserInput(int **tab, int lignes, int col);

void printArray(int **tab, int lignes, int col);

void printStaticArray(int tab[l][c]);

void freeArray(int **tab, int lignes);