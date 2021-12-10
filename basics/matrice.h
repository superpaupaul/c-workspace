
typedef struct t_matrice{
    int lignes;
    int colonnes;
    int** tab2d;
} Matrice;

void fillInMatrixWithUserInput(Matrice * mat);

void printMatrix(Matrice mat);

void allocateMatrix(Matrice * mat);