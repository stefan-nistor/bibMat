#ifndef GMATRIX_H_INCLUDED
#define GMATRIX_H_INCLUDED




#include "matrix.h"
#include <winbgim.h>
#include <graphics.h>
#include <iomanip>
int col, row, matAy, matBy;
matrice mat;
COLORREF bgcolor;

bool input_a = false, input_b = false, eng = false;

void printMatrix    (matrice , int , int , int );
void colorInput     (int);
void kbinValxy      (char*, int, int, int&, int);
void kbinMat        (matrice&, int);
void notSquareError (matrice );
bool isButton       (int, int, int, int);
bool colorPick      (int, int);

void colorInput (int in){
    int dis = 25, tw, th;
    if (in == 100){
        settextstyle(0,0,8);
        setcolor(COLOR(20, 148, 20));
        th=textheight("A");
        outtextxy (100,(125-th)/2+dis,"A");

        settextstyle(0,0,8);
        setcolor(COLOR(255,255,253));
        tw=textwidth("B");
        th=textheight("B");
        outtextxy( 1500 - tw,(125-th)/2+dis,"B");
        settextstyle(0,0,2);
        setcolor(WHITE);
        return;
    }

    if (in == 800){
        settextstyle(0,0,8);
        setcolor(COLOR(255,255,254));
        th=textheight("A");
        outtextxy (100,(125-th)/2+dis,"A");

        settextstyle(0,0,8);
        setcolor(COLOR(20, 148, 20));
        tw=textwidth("B");
        th=textheight("B");
        outtextxy( 1500 - tw,(125-th)/2+dis,"B");
        settextstyle(0,0,2);
        setcolor(WHITE);
        return;
    }
    settextstyle(0,0,2);
    setcolor(WHITE);
}

void printMatrix (matrice m, int x, int y, int off = 30)
{
    side == 100 ? x = 100 : x = 800;
    int dis = 0;
    y += 30;
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j< m.col; j++){
            bgiout << std::setprecision(3) << m.elt[i][j];
            outstreamxy(x + dis * 20, y);
            dis += 5;
        }
        y += off;
        dis = 0;
    }
    //side == 100 ? lastax = x, lastay = y : lastbx = x, lastby = y;
    if(side == 100)
        lastax = x, lastay = y;
    if(side == 800)
        lastbx = x, lastby = y;
}

void kbinValxy(char* text, int x, int y, int& val, int dis = 0){

    outtextxy(x,y,text);
    char c[8] ;
    int tw = textwidth(text), i = 0;
    c[i] = getch();
    while(int(c[i]) != 13){
        if (c[i] >= '0' && c[i] <= '9') {
            bgiout << c[i];
            outstreamxy(tw + x + dis * 10, y);
            dis += 2;
            i++;
        }
        c[i] = getch();
    }
    val = atoi(c);
}

void kbinMat(matrice &m, int side) {
    setfillstyle(SOLID_FILL, bgcolor);
    int x, y = 150, dis, k;
    char c[100];

    if(side == 100)
        bar(100 - 1,125,780,875);
    if(side == 800)
        bar(781,125,1550,875);

    side == 100 ? x = 100 : x = 800;
    setcolor(WHITE);

    if(!eng) {
        kbinValxy("Nr linii: ", x, y, row);
        y += 30;
        kbinValxy("Nr coloane: ", x, y, col);
        y += 30;
        outtextxy(x, y, "Introduceti elementele:");
    }
    else
    {
        kbinValxy("Lines: ", x, y, row);
        y += 30;
        kbinValxy("Collums: ", x, y, col);
        y += 30;
        outtextxy(x, y, "Enter the elements:");
    }
    m.col = col, m.row = row, y += 30, dis = 0;
    for(int ii = 0; ii < row; ii++)
    {
        for(int j = 0; j < col; j++)
        {
            k=0;
            c[k] = getch();

            while(int(c[k]) != 13)
            {
                bgiout << c[k];
                outstreamxy(x + dis * 10, y);
                dis+=2;
                k++;
                c[k] = getch();
            }

            m.elt[ii][j] = atoi(c);
            //bgiout<<"\t";
            outstreamxy(x + dis * 20, y);
            dis += 5;

        }
        y+=30;
        dis=0;
    }

    setfillstyle(SOLID_FILL, bgcolor);
    if(side == 100){
        bar(100-1,125,780,875);
        outtextxy(side, 125, "A = ");
        printMatrix(m,100, 135);
    }
    else if(side == 800)
    {
        bar(781,125,1550,875);
        outtextxy(side, 125, "B = ");
        printMatrix(m,side, 135);
    }
    matAy = lastay;
    matBy = lastby;
    //side == 100 ? lastax = x, lastay = y + 30 : lastbx = x, lastby = y + 30;
}

bool isButton(int x, int y, int nr_but, int dis = 60) {
    return (x > 1550 && x < 1550 + 320
            && y > 125 + (nr_but - 1) * dis
            && y < 175 + (nr_but - 1) * dis);
}

bool colorPick(int x, int y){
    if(getpixel(x,y) != WHITE && getpixel(x,y) != RGB(90, 60, 90)) {
        bgcolor = getpixel(x, y);
        return true;
    }
    return false;
}

void notSquareError (matrice m){
    if (m == A){
        if(!eng)
            outtextxy(100, lastay + 30, "Matricea nu este patratica!");
        else
            outtextxy(100, lastay + 30, "The Matrix is not square");
        lastay+=30;
    }
    else if (m == B){
        if (!eng)
            outtextxy(800, lastby + 30, "Matricea nu este patratica!");
        else
            outtextxy(800, lastby + 30, "The Matrix is not Square");
        lastby += 30;
    }
}

#endif // GMATRIX_H_INCLUDED
