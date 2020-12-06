#ifndef BIBMAT_MATRIX_H
#define BIBMAT_MATRIX_H
#include <iostream>
#include <cmath>

struct matrice{
    int row = 0, col = 0;
    int elt[100][100]{} ;
};

matrice nullMatrix(int , int );
matrice null = nullMatrix(0,0);

void readMat    (int, int, matrice&);
void printMat   (matrice );
void readfMat   ();
void printfMat  (matrice );

int determinant   (matrice , int );
matrice transpose (matrice );
matrice adjuncta  (matrice );
matrice inversa   (matrice );

int sumDiagPP   (matrice );
int sumUDiagPP  (matrice );
int sumDiagSec  (matrice );
int sumUDiagSec (matrice );

matrice product (matrice , matrice );
matrice sum (int , matrice, matrice, ...);

///\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\\

matrice nullMatrix (int row = 0 , int col = 0) {
    matrice a;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            (i == j) ? a.elt[i][j] = 1 : a.elt[i][j] = 0;

    if (col == 0)
        a.row = a.col = row;
    else
        a.row = row, a.col = col;
    return a;
}

void readMat (int row, int col, matrice &a){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin>>a.elt[i][j];

    a.col = col;
    a.row = row;
}

void printMat (matrice m){
    std::cout << '\n';
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++)
            std::cout<<m.elt[i][j]<< ' ';
        std::cout<<'\n';
    }
    std::cout << '\n';
}
matrice minorant;
int determinant (matrice m, int n ){
    int det = 0;


    if(n == 1)
        return m.elt[0][0];

    if(n == 2)
        return ((m.elt[0][0] * m.elt[1][1]) - (m.elt[0][1] * m.elt[1][0]));

    for (int c = 0; c < n; c++) {
        int min_i = 0;
        for (int i = 1; i < n; i++) {
            int min_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == c)
                    continue;
                minorant.elt[min_i][min_j] = m.elt[i][j];
                min_j++;
            }
            min_i++;
        }

        det = det + (pow(-1, c) * m.elt[0][c] * determinant(minorant, n - 1));
    }

    return det;
}

matrice transpose(matrice m) {
    matrice t;
    t.col = m.row;
    t.row = m.col;

    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.col; ++j) {
            t.elt[j][i] = m.elt[i][j];
        }
    }
    return t;
}

matrice product (matrice a, matrice b) {
    if (a.col != b.row) {
        std::cout << "Matrix cannot be multiplied!\n";
        return _null;
    }
    matrice c;

    for (int i = 0; i < a.row; ++i) {
        for (int j = 0; j < b.col; ++j) {
            c.elt[i][j] = 0;
            for (int k = 0; k < b.row; ++k) {
                c.elt[i][j] += a.elt[i][j] * b.elt[i][j];
            }
        }
    }

    return c;
}

matrice operator  * (matrice &A, matrice &B) {
    return product(A,B);
}
#endif //BIBMAT_MATRIX_H