#ifndef GRAFICS_GMATRIX_H
#define GRAFICS_GMATRIX_H
#include "matrix.h"
#include <winbgim.h>
#include <graphics.h>
int tw_lin, tw_col, col, row;
matrice mat;

void desenareMatrici();
void paginaMatrici();


void desenareMatrici()
{
    setbkcolor(RGB(11, 79, 62));
    cleardevice();
    int tw,th;
    setfillstyle(7,GREEN);
    bar(480,0,1440,100);
    settextstyle(0,0,10);
    tw=textwidth("Matrici");
    th=textheight("Matrici");
    outtextxy((960-tw)/2+480,(100-th)/2,"Matrici");
    setfillstyle(10,WHITE);
    bar(10,900,110,960);
    settextstyle(0,0,2);
    tw=textwidth("Meniu");
    th=textheight("Meniu");
    outtextxy((100-tw)/2+10,(60-th)/2+900,"Meniu");
}

void kbinMat(matrice &m)
{
    int i = 0, dis = 0, x = 100, y = 120, j = 0;
    char c[10];

    setcolor(WHITE);
    tw_lin = textwidth("Introduceti numarul de linii: ");
    outtextxy(x,y,"Introduceti numarul de linii: ");
    c[i] = getch();
    while(int(c[i]) != 13)
    {
        bgiout << c[i];
        outstreamxy(tw_lin + x + dis * 10,y);
        dis += 2;
        i++;
        c[i] = getch();
    }
    row = atoi(c);


    dis = 0; i = 0, y += 30;
    setcolor(WHITE);
    tw_col = textwidth("Introduceti numarul de coloane: ");
    outtextxy(x,y,"Introduceti numarul de coloane: ");

    c[i] = getch();
    while(int(c[i]) != 13)
    {
        bgiout << c[i];
        outstreamxy(tw_col + x + dis * 10,y);
        dis+=2;
        i++;
        c[i] = getch();
    }
    col = atoi(c);

    y += 30;
    setcolor(WHITE);
    tw_col = textwidth("Introduceti elementele: ");
    outtextxy(x,y,"Introduceti elementele:");

    m.col = col; m.row = row;
    y += 30, dis = 0; int k = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            c[i] = getch();

            while(int(c[k]) != 32)
            {
                if(c[k] == '\n')
                    dis = 0, y += 30;
                bgiout << c[k];
                outstreamxy(x + dis * 10, y);
                dis+=2;
                k++;
                c[k] = getch();
            }
            m.elt[i][j] = atoi(c);
            std::cout << atoi(c) << '_';
        }
    }

}



void paginaMatrici()
{
    int ok = 0, x, y;
    setactivepage(3);
    setvisualpage(3);
    desenareMatrici();
    kbinMat(mat);
    printMat(mat);
    //std::cout << mat.row << ' ' << mat.col;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x>=10&&x<=110&&y>=900&&y<=1000)
            {
                ok=1;
                setactivepage(1);
                setvisualpage(1);
            }
        }
    }while(ok==0);
}




#endif //GRAFICS_GMATRIX_H
