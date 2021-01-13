#ifndef GRAFICS_MATRIX_H
#define GRAFICS_MATRIX_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <graphics.h>
#include <winbgim.h>
std::ofstream fout ("matrix_outstream.txt");

unsigned int lastax, lastay, lastbx, lastby, side;

struct matrice{
    unsigned int row, col;
    double elt[10][10];
}A,B, minorant;

matrice unit        (matrice );
matrice operator+   (const matrice&, const matrice&);
matrice operator*   (const matrice&, const matrice&);
bool operator==     (const matrice&, const matrice&);

void readMat        (int, int, matrice&);
void coutMat        (matrice );
void readfMat       ();
void printfMat      (matrice );

double determinant   (matrice , int );
matrice transpose   (matrice );
matrice cofactor    (matrice, int , int );
matrice adjuncta    (matrice );
matrice inversa     (matrice );

float sumDiagPP     (matrice );
float sumDiagSec    (matrice );
float sumElem       (matrice );

matrice product     (matrice , matrice );
matrice sum         (matrice , matrice );
matrice pow         (matrice , int );


matrice unit (matrice a){
    for(int i = 0; i < a.row; i++)
        for(int j = 0; j < a.col; j++)
            i == j ? a.elt[i][j] = 1 : a.elt[i][j] = 0;
    return a;
}

void readMat (int row, int col, matrice &m){
    std::cout << "Nr. Linii: \nNr.coloane: \nIntroduceti elementele: \n";
    std::cin >> row >> col;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin>>m.elt[i][j];
    m.col = col;
    m.row = row;
}

void coutMat (matrice m){

    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++)
            std::cout << m.elt[i][j]<< ' ';
        std::cout<<'\n';
    }
}

void printfMat (matrice m){
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++)
            fout << m.elt[i][j]<< '\t';
        fout <<'\n';
    }
}

double determinant (matrice m, int n){
    double det = 0;
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
    t.row = m.col;
    t.col = m.row;

    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.col; j++)
            t.elt[j][i] = m.elt[i][j];
    }
    return t;

}

matrice cofactor (matrice m, int p, int q){
    matrice temp; temp.row = temp.col = temp.col;
    int i = 0, j = 0;
    for(int row = 0; row < m.row; row++){
        for(int col = 0; col < m.col; col++) {
            if(row != p && col != q){
                temp.elt[i][j++] = m.elt[row][col];
                if(j == m.col - 1){
                    j = 0; i++;
                }
            }
        }
    }
    return temp;
}

matrice adjuncta(matrice m){
    matrice adj, temp;
    int n = adj.col = adj.row = m.col, sign = 1;

    if(n == 1){
        adj.elt[0][0] = 1;
        return adj;
    }

    if (n == 2 ){
        adj.elt[0][0] = m.elt[1][1];
        adj.elt[0][1] = m.elt[0][1] * -1;
        adj.elt[1][0] = m.elt[1][0] * -1;
        adj.elt[1][1] = m.elt[0][0];
        return adj;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = cofactor(m,i,j);
            sign = ((i+j) % 2 == 0) ? 1 : -1;
            adj.elt[i][j] = determinant(temp, n-1);
            adj.elt[i][j] *= sign;
        }
    }
    return adj;
}

matrice inversa (matrice m){
    int  n = m.col;
    float det = determinant(m, n);

    matrice inv;
    inv.row = inv.col = m.row;

    if (n == 2){
        inv.elt[0][0] =      m.elt[1][1] / (det);
        std::cout << inv.elt[0][0] << ' ';

        inv.elt[0][1] = -1 * m.elt[0][1] / (det);
        std::cout << inv.elt[0][1] << '\n';

        inv.elt[1][0] = -1 * m.elt[1][0] / (det);
        std::cout << inv.elt[1][0] << ' ';

        inv.elt[1][1] =      m.elt[0][0] / (det);
        std::cout << inv.elt[1][1] << '\n';

        return inv;
    }

    matrice adj = adjuncta(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv.elt[i][j] = adj.elt[i][j] / det;
        }
    }
    return inv;
}

float sumDiagPP (matrice m){
    if (m.row != m.col)
        return INT_MIN;

    float sum = 0;
    for(int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++) {
            if(i==j)
                sum += m.elt[i][j];
        }
    return sum;
}

float sumElem (matrice m){
    float sum = 0;
    for(int i = 0; i < m.row; i++)
        for(int j = 0; j < m.col; j++)
            sum += m.elt[i][j];
    return sum;
}

float sumDiagSec (matrice m){
    if (m.row != m.col)
        return INT_MIN;

    float sum = 0;
    for(int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++) {
            if(i + j == m.row - 1)
                sum += m.elt[i][j];
        }
    return sum;
}

bool operator== (const matrice&a, const matrice&b){
    if(a.col != b.col || a.row != b.row)    return false;

    for(int i = 0; i < a.col; i++)
        for(int j = 0; j < a.row; j++)
            if(a.elt[i][j] != b.elt[i][j])  return false;

    return true;
}

matrice operator+ (const matrice &a, const matrice &b){
    matrice sum = {}; sum.col = a.col, sum.row = a.row;
    for(int i = 0; i < a.row; i++){
        for(int j = 0; j < a.col; j++){
            sum.elt[i][j] = a.elt[i][j] + b.elt[i][j];
        }
    }
    return sum;
}

matrice operator* (const matrice&a, const matrice&b){
    matrice c = {}; c.row = a.row, c.col = b.col;
    for (int i = 0; i < c.row; ++i) {
        for (int j = 0; j < c.col; ++j) {
            c.elt[i][j] = 0;
            for (int k = 0; k < c.col; ++k) {
                c.elt[i][j] += a.elt[i][k] * b.elt[k][j];
            }
        }
    }
    return c;
}

matrice sum (matrice a, matrice b) {
    return a + b;
}

matrice product (matrice a, matrice b) {
    return a * b;
}

matrice pow (matrice a, int exp){
    matrice b; b.col = a.col; b.row = a.row;
    b = unit(b);
    while(exp--){
        b = b * a;
    }
    return b;
}

#endif //GRAFICS_MATRIX_H