
#ifndef BIBMAT_MATRIX_H
#define BIBMAT_MATRIX_H

struct matrice{
    int elt[100][100];
    int row, col;
}mat;

//afisari + citiri

void readMat();
void printMat(matrice m);

void readfMat();
void printfMat(matrice m);

int det(matrice m);
matrice transpose (matrice m);
matrice inversa (matrice m);

int sumDiagPP (matrice m);
int sumUDiagPP (matrice m);
int sumDiagSec (matrice m);
int sumUDiagSec (matrice m);



#endif //BIBMAT_MATRIX_H
