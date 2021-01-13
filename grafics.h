#ifndef GRAFICS_GRAFICS_H
#define GRAFICS_GRAFICS_H
#include <graphics.h>
#include <winbgim.h>
#include "vector.h"
#include "gmatrix.h"

void desenare()
{
    unsigned int tw,th;

    setfillstyle(2,WHITE);
    bar(480,60,1440,200);
    settextstyle(0,0,10);
    tw=textwidth("BibMat");
    th=textheight("BibMat");
    outtextxy((960-tw)/2+480,(140-th)/2+60,"BibMat");

    setfillstyle(5,WHITE);
    bar(480,260,1440,400);
    tw=textwidth("Vectori");
    th=textheight("Vectori");
    outtextxy((960-tw)/2+480,(140-th)/2+260,"Vectori");

    setfillstyle(5,WHITE);
    bar(480,460,1440,600);
    tw=textwidth("Matrice");
    th=textheight("Matrice");
    outtextxy((960-tw)/2+480,(140-th)/2+460,"Matrice");


    setfillstyle(5,WHITE);
    bar(480,660,1440,800);
    tw=textwidth("Exit");
    th=textheight("Exit");
    outtextxy((960-tw)/2+480,(140-th)/2+660,"Exit");
}

void desenareVectori()
{
    int i,dis=200;
    setbkcolor(RGB(11, 59, 12));
    cleardevice();
    int tw,th;
    setcolor(WHITE);
    setfillstyle(7,GREEN);
    bar(300,0,1200,100);
    settextstyle(0,0,10);
    tw=textwidth("Vectori");
    th=textheight("Vectori");
    outtextxy((900-tw)/2+300,(100-th)/2,"Vectori");
    setfillstyle(10,WHITE);
    bar(10,900,110,960);
    settextstyle(0,0,2);
    tw=textwidth("Meniu");
    th=textheight("Meniu");
    outtextxy((100-tw)/2+10,(60-th)/2+900,"Meniu");
    setfillstyle(7,GREEN);
    bar(1500,0,1920,1000);
    setfillstyle(1,BLACK);
    bar(50,200,1450,800);
    for(i=1;i<=3;i++)
    {
        bar(1550,dis,1870,50+dis);
        setcolor(WHITE);
        if(i==1)
        {
            tw=textwidth("BubbleSort");
            th=textheight("BubbleSort");
            outtextxy((320-tw)/2+1550,(50-th)/2+dis,"BubbleSort");
        }
        if(i==2)
        {
            tw=textwidth("InsertSort");
            th=textheight("InsertSort");
            outtextxy((320-tw)/2+1550,(50-th)/2+dis,"InsertSort");
        }
        if(i==3)
        {
            tw=textwidth("SelectionSort");
            th=textheight("SelectionSort");
            outtextxy((320-tw)/2+1550,(50-th)/2+dis,"SelectionSort");
        }
        dis+=100;
    }
}

void paginaVectori()
{
    setactivepage(2);
    setvisualpage(2);
    desenareVectori();
    int ok=0,x,y,readI=0;
    vector v;
    do
    {
        if(readI==0&&ok==0)
        {
            readInterval(v);
            printVect(v);
            readI=1;
        }
        if(readI==1)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                if(x>=1550&&x<=1870&&y>=200&&y<=250)
                    bubbleSort(v,0);
                else
                if(x>=1550&&x<=1870&&y>=300&&y<=350)
                    insertSort(v,0);
                else
                if(x>=1550&&x<=1870&&y>=400&&y<=450)
                    selectionSort(v,0);
            }
        }
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

void languageSelectMenu(){

    int tw, th;
    setactivepage(0);
    cleardevice();
    settextstyle(0,0,10);
    setvisualpage(0);

    setfillstyle(5,WHITE);
    bar(480,260,1440,400);
    tw=textwidth("Romana");
    th=textheight("Romana");
    outtextxy((960-tw)/2+480,(140-th)/2+260,"Romana");

    setfillstyle(5,WHITE);
    bar(480,460,1440,600);
    tw=textwidth("English");
    th=textheight("English");
    outtextxy((960-tw)/2+480,(140-th)/2+460,"English");

    setfillstyle(10,WHITE);
    bar(10,900,110,960);
    settextstyle(0,0,2);
    setcolor(WHITE);
    tw=textwidth("Meniu");
    th=textheight("Meniu");
    outtextxy((100-tw)/2+10,(60-th)/2+900,"Meniu");

    setfillstyle(8,WHITE);
    bar(110,900,210,960);
    settextstyle(0,0,2);
    setcolor(WHITE);
    tw=textwidth("Exit");
    th=textheight("Exit");
    outtextxy((290-tw)/2+10,(60-th)/2+900,"Exit");
}

void bgSelectMenu(){
    int tw,th;
    setactivepage(5);
    setvisualpage(5);
    cleardevice();

    setfillstyle(10,WHITE);
    bar(10,900,110,960);
    settextstyle(0,0,2);
    setcolor(WHITE);
    tw=textwidth("Meniu");
    th=textheight("Meniu");
    if(!eng)
        outtextxy((100-tw)/2+10,(60-th)/2+900,"Meniu");
    else
        outtextxy((100-tw)/2+10,(60-th)/2+900,"Menu");

    setfillstyle(8,WHITE);
    bar(110,900,210,960);
    settextstyle(0,0,2);
    setcolor(WHITE);
    tw=textwidth("Exit");
    th=textheight("Exit");
    outtextxy((290-tw)/2+10,(60-th)/2+900,"Exit");
    settextstyle(0,0,5);
    setcolor(WHITE);

    if(eng) {
        tw = textwidth("Choose background color");
        th = textheight("Choose background color");
        outtextxy(1920/4, (100 - th) / 2, "Choose background color");
    }
    if(!eng){
        tw = textwidth("Alege culoarea de fundal");
        th = textheight("Alege culoarea de fundal");
        outtextxy(1920/4, (100 - th) / 2, "Alege culoarea de fundal");
    }

    int l = 150, x1 = 1920/4, x2 = x1 + l, y = 300;

    rectangle(x1-1,y-1, x1 + l + 1, y + l + 1);
    rectangle(x1 + l + 100 - 1 ,y-1, x1 + 2*l + 100 + 1, y + l + 1);
    rectangle(x1 + 2*l + 200 - 1,y-1, x1 + 3*l + 200 + 1, y + l + 1);
    rectangle(x1 + 3*l + 300 - 1,y-1, x1 + 4*l + 300 + 1, y + l + 1);
    ///1
    setfillstyle(SOLID_FILL,RGB (0,0,0));
    bar(x1, y, x1 + l, y + l);
    ///2
    setfillstyle(SOLID_FILL,RGB (0,0,128));
    bar(x1 + l + 100,y, x1 + 2*l + 100, y + l);
    ///3
    setfillstyle(SOLID_FILL,RGB (0, 128, 0));
    bar(x1 + 2*l + 200,y,x1 + 3*l + 200, y + l);
    ///4
    setfillstyle(SOLID_FILL,RGB(0, 128, 128));
    bar(x1 + 3*l + 300,y,x1 + 4*l + 300, y + l);

    y += l + 50;
    rectangle(x1-1,y-1, x1 + l + 1, y + l + 1);
    rectangle(x1 + l + 100 - 1 ,y-1, x1 + 2*l + 100 + 1, y + l + 1);
    rectangle(x1 + 2*l + 200 - 1,y-1, x1 + 3*l + 200 + 1, y + l + 1);
    rectangle(x1 + 3*l + 300 - 1,y-1, x1 + 4*l + 300 + 1, y + l + 1);
    ///5
    setfillstyle(SOLID_FILL,RGB (128,0,0));
    bar(x1, y, x1 + l, y + l);
    ///6
    setfillstyle(SOLID_FILL,RGB (1, 36, 86));
    bar(x1 + l + 100,y, x1 + 2*l + 100, y + l);
    ///7
    setfillstyle(SOLID_FILL,RGB(0, 0, 255));
    bar(x1 + 2*l + 200,y,x1 + 3*l + 200, y + l);
    ///8
    setfillstyle(SOLID_FILL,RGB(95, 60, 93));
    bar(x1 + 3*l + 300,y,x1 + 4*l + 300, y + l);
}

void desenareMatrici()
{
    int tw,th, dis = 200;
    setactivepage(3);
    setvisualpage(3);
    setbkcolor(bgcolor);
    cleardevice();

    settextstyle(0,0,10);
    setcolor(WHITE);
    tw=textwidth("Matrice");
    th=textheight("Matrice");
    if(!eng)
        outtextxy((960-tw)/2 + 300,(100-th)/2,"Matrice");
    else
        outtextxy((960-tw)/2 + 300,(100-th)/2,"Matrix");


    setfillstyle(10,WHITE);
    bar(10,900,110,960);
    settextstyle(0,0,2);
    setcolor(WHITE);
    tw=textwidth("Meniu");
    th=textheight("Meniu");
    if(!eng)
        outtextxy((100-tw)/2+10,(60-th)/2+900,"Meniu");
    else
        outtextxy((100-tw)/2+10,(60-th)/2+900,"Menu");

    setfillstyle(8,WHITE);
    bar(110,900,210,960);
    settextstyle(0,0,2);
    setcolor(WHITE);
    tw=textwidth("Exit");
    th=textheight("Exit");
    outtextxy((290-tw)/2+10,(60-th)/2+900,"Exit");

    dis = 25;
    settextstyle(0,0,8);
    setcolor(COLOR(255,255,254));
    tw=textwidth("A");
    th=textheight("A");
    outtextxy (100,(125-th)/2+dis,"A");


    settextstyle(0,0,8);
    setcolor(COLOR(255,255,253));
    tw=textwidth("B");
    th=textheight("B");
    outtextxy( 1500 - tw,(125-th)/2+dis,"B");

    setcolor(WHITE);
    settextstyle(0,0,2);
    line(780,125,780,875);

    dis = 125;
    for(int i = 1; i<=13; i++){
        fout << i << ' ' << dis << '\n';
        setfillstyle(0,COLOR(0, 0, i));
        rectangle(1550, dis, 1870, 50 + dis);
        floodfill(1551,dis+1,WHITE);
        if (i == 1)
        {
            tw=textwidth("Determinant");
            th=textheight("Determinant");
            outtextxy((320-tw)/2+1550,(50-th)/2+dis,"Determinant");

        }
        if (i == 2)
        {
            if(!eng) {
                tw = textwidth("Matricea transpusa");
                th = textheight("Matricea transpusa");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Matricea transpusa");
            }
            else
            {
                tw = textwidth("Transpose");
                th = textheight("Transpose");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Transpose");
            }

        }
        if (i == 3)
        {
            if(!eng) {
                tw = textwidth("Matricea adjuncta");
                th = textheight("Matricea adjuncta");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Matricea adjuncta");
            }
            else
            {
                tw = textwidth("Find Adjoint Matrix");
                th = textheight("Find Adjoint Matrix");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Find Adjoint Matrix");
            }
        }
        if (i == 4)
        {
            if(!eng) {
                tw = textwidth("Matricea inversa");
                th = textheight("Matricea inversa");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Matricea inversa");
            }
            else
            {
                tw = textwidth("Find Inverse Matrix");
                th = textheight("Find Inverse Matrix");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Find Inverse Matrix");
            }
        }
        if( i == 5)
        {
            if(!eng) {
                tw = textwidth("Suma diag. principala");
                th = textheight("Suma diag. principala");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Suma diag. principala");
            }
            else
            {
                tw = textwidth("Sum of 1st diag");
                th = textheight("Sum of 1st diag");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Sum of 1st diag");
            }
        }
        if(i == 6)
        {
            if(!eng){
                tw=textwidth("Suma diag. secundara");
                th=textheight("Suma diag. principala");
                outtextxy((320-tw)/2+1550,(50-th)/2+dis,"Suma diag. secundara");
            }
            else
            {
                tw=textwidth("Sum of 2nd diag");
                th=textheight("Sum of 2nd diag");
                outtextxy((320-tw)/2+1550,(50-th)/2+dis,"Sum of 2nd diag");
            }
        }
        if(i == 7)
        {

            if(!eng) {
                tw = textwidth("Suma elementelor");
                th = textheight("Suma elementelor");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Suma elementelor");
            }
            else
            {
                tw = textwidth("Sum of the elements");
                th = textheight("Sum of the elements");
                outtextxy((320 - tw) / 2 + 1550, (50 - th) / 2 + dis, "Sum of the elements");
            }
        }
        if(i == 8)
        {
            tw=textwidth("A x B");
            th=textheight("A x B");
            outtextxy((160-tw)/2+1550,(50-th)/2+dis,"A x B");

            line(1550+160,dis,1550+160, dis + 50);

            tw=textwidth("B x A");
            th=textheight("B x A");
            outtextxy((480-tw)/2+1550 ,(50-th)/2+dis,"B x A");
        }

        if(i == 9)
        {
            tw=textwidth("A + B");
            th=textheight("A + B");
            outtextxy((320-tw)/2+1550,(50-th)/2+dis,"A + B");
        }
        if(i == 10)
        {
            if(!eng){
                tw=textwidth("Ridica la putere");
                th=textheight("Ridica la putere");
                outtextxy((320-tw)/2+1550,(50-th)/2+dis,"Ridica la putere");
            }
            else
            {
                tw=textwidth("Raise to the power");
                th=textheight("Raise to the power");
                outtextxy((320-tw)/2+1550,(50-th)/2+dis,"Raise to the power");
            }
        }
        if(i == 11)
        {
            tw=textwidth("Reset A");
            th=textheight("Reset A");
            outtextxy((160-tw)/2+1550,(50-th)/2+dis,"Reset A");

            line(1550+160,dis,1550+160, dis + 50);

            tw=textwidth("Reset B");
            th=textheight("Reset B");
            outtextxy((480-tw)/2+1550 ,(50-th)/2+dis,"Reset B");
        }

        dis += 60;
    }
}

void paginaMatrici() {
    int ok = 0, x, y;
    setbkcolor(RGB(90, 60, 90));
    setvisualpage(3);
    setactivepage(3);
    languageSelectMenu();
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex(), y = mousey();
            ///Meniu
            if (x >= 10 && x <= 110 && y >= 900 && y <= 1000) {
                ok = 1;
                input_a = input_b = false;
                cleardevice();
                setactivepage(1);
                setvisualpage(1);
                return;
            }
            ///Exit
            if (x >= 110 && x <= 210 && y >= 900 && y <= 1000) {
                ok = 1;
                closegraph();
                fout << "Process finished with exit code 0.";
                fout.close();
                exit(EXIT_SUCCESS);
                return;
            }
            if (x >= 480 && x <= 1440 && y >= 260 && y <= 400) {
                ok = 1;
                eng = false;
            }
            if (x >= 480 && x <= 1440 && y >= 460 && y <= 600) {
                ok = 1;
                eng = true;
            }

        }
    } while (!ok);

    ok = 0;
    bgSelectMenu();
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex(), y = mousey();
            ///Meniu
            if (x >= 10 && x <= 110 && y >= 900 && y <= 1000) {
                ok = 1;
                input_a = input_b = false;
                cleardevice();
                setactivepage(1);
                setvisualpage(1);
                return;
            }
            ///Exit
            if (x >= 110 && x <= 210 && y >= 900 && y <= 1000) {
                ok = 1;
                closegraph();
                fout << "Process finished with exit code 0.";
                fout.close();
                exit(EXIT_SUCCESS);
                return;
            }
            if(colorPick(x,y))
                ok = 1;

        }
    } while (!ok);

    ok = 0;
    desenareMatrici();
    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex(), y = mousey();
            ///Meniu
            if (x >= 10 && x <= 110 && y >= 900 && y <= 1000) {
                ok = 1;
                input_a = input_b = false;
                cleardevice();
                setactivepage(1);
                setvisualpage(1);
                return;
            }
            ///Exit
            if (x >= 110 && x <= 210 && y >= 900 && y <= 1000) {
                ok = 1;
                closegraph();
                fout << "Process finished with exit code 0.";
                fout.close();
                exit(EXIT_SUCCESS);
                return;
            }
            ///partea stanga
            if (getpixel(x, y) == COLOR(255, 255, 254)) {
                side = 100;
                colorInput(side);
                if (!input_a)
                    kbinMat(A, side);
                mat = A;
                input_a = true;
                fout << "A = \n";
                printfMat(A);
                continue;
            }
            ///partea dreapta
            if (getpixel(x, y) == COLOR(255, 255, 253)) {
                side = 800;
                colorInput(side);
                if (!input_b)
                    kbinMat(B, side);
                mat = B;
                input_b = true;
                fout << "B = \n";
                printfMat(B);
                continue;
            }
            ///Reset when full
            if(lastay >= 800) {
                setfillstyle(SOLID_FILL,bgcolor);
                bar(100 - 1, matAy, 780, 875);
                lastay = matAy;
            }
            if(lastby >= 800) {
                setfillstyle(SOLID_FILL,bgcolor);
                bar(781,matBy,1550,875);
                lastby = matBy;
            }
            ///Meniu operatii
            if (input_a || input_b) {
                ///Determinant
                if (isButton(x, y, 1)) {
                    if (mat.col == mat.row) {
                        double det = determinant(mat, mat.col);
                        bgiout << det;
                        int tw = textwidth("det(A) = ");

                        if (mat == A) {
                            outtextxy(100, lastay + 30, "det(A) = ");
                            outstreamxy(100 + tw, lastay + 30);
                            lastax = 100 + tw, lastay += 30;
                            fout << "Det(A) = " << det << '\n';
                        }
                        if (mat == B) {
                            outtextxy(800, lastby + 30, "det(b) = ");
                            outstreamxy(800 + tw, lastby + 30);
                            lastbx = 800 + tw, lastby += 30;
                            fout << "Det(B) = " << det << '\n';
                        }
                    } else notSquareError(mat);
                }
                ///Transpusa
                if (isButton(x, y, 2)) {

                    if (mat == A) {
                        if (!eng)
                            outtextxy(100, lastay + 30, "Matricea transpusa este: ");
                        else
                            outtextxy(100, lastay + 30, "Transpose: ");
                        lastay += 30;
                        printMatrix(transpose(mat), lastax, lastay);
                        fout << "transpusa(A):\n";
                        printfMat(transpose(A));
                    }
                    if (mat == B) {
                        if (!eng)
                            outtextxy(800, lastby + 30, "Matricea transpusa este: ");
                        else
                            outtextxy(800, lastby + 30, "Transpose: ");
                        lastby += 30;
                        printMatrix(transpose(mat), lastbx, lastby);
                        fout << "transpusa(B):\n";
                        printfMat(transpose(B));
                    }
                }
                ///Adjuncta
                if (isButton(x, y, 3)) {
                    if (mat.col != mat.row) {
                        fout << "Matricea nu este patratica!\n";
                        notSquareError(mat);
                    } else {
                        if (mat == A) {
                            if (!eng)
                                outtextxy(100, lastay + 30, "Matricea adjuncta este: ");
                            else
                                outtextxy(100, lastay + 30, "The adjoint Matrix is: ");
                            lastay += 30;
                            printMatrix(adjuncta(mat), lastax, lastay);
                            fout << "adjuncta(A):\n";
                            printfMat(adjuncta(A));
                        }
                        if (mat == B) {
                            if (!eng)
                                outtextxy(800, lastby + 30, "Matricea adjuncta este: ");
                            else
                                outtextxy(800, lastby + 30, "The adjoint Matrix is: ");
                            lastby += 30;
                            printMatrix(adjuncta(mat), lastbx, lastby);
                            fout << "adjuncta(B):\n";
                            printfMat(adjuncta(B));
                        }
                    }
                }
                ///Inversa
                if (isButton(x, y, 4)) {
                    if (mat.col != mat.row) {
                        fout << "Matricea nu este patratica!\n";
                        notSquareError(mat);
                    } else {
                        if (mat == A) {
                            if(!eng)
                                outtextxy(100, lastay + 30, "Matricea inversa este: ");
                            else
                                outtextxy(100, lastay + 30, "The Inverse of A is: ");
                            lastay += 30;
                            printMatrix(inversa(mat), lastax, lastay);
                            fout << "inversa(A):\n";
                            printfMat(inversa(A));
                        }
                        if (mat == B) {
                            if(!eng)
                                outtextxy(800, lastby + 30, "Matricea inversa este: ");
                            else
                                outtextxy(800, lastay + 30, "The Inverse of B is: ");
                            lastby += 30;
                            printMatrix(inversa(mat), lastbx, lastby);
                            fout << "inversa(B)\n";
                            printfMat(inversa(B));
                        }
                    }
                }
                ///Suma diag PP
                if (isButton(x, y, 5)) {
                    if (mat.col != mat.row) {
                        fout << "Matricea nu este patratica!\n";
                        notSquareError(mat);
                    } else {
                        if (!eng) {
                            int tw = textwidth("Suma diagonalei principale este: ");
                            bgiout << sumDiagPP(mat);
                            if (mat == A) {
                                outtextxy(100, lastay + 30, "Suma diagonalei principale este: ");
                                outstreamxy(100 + tw, lastay + 30);
                                lastay += 30;
                                fout << "SumaDiagPrincipala(A): " << sumDiagPP(A) << '\n';
                            }
                            if (mat == B) {
                                outtextxy(800, lastby + 30, "Suma diagonalei principale este: ");
                                outstreamxy(800 + tw, lastby + 30);
                                lastby += 30;
                                fout << "SumaDiagPrincipala(B): " << sumDiagPP(B) << '\n';
                            }
                        } else {
                            int tw = textwidth("Sum of first diagonal is: ");
                            bgiout << sumDiagPP(mat);
                            if (mat == A) {
                                outtextxy(100, lastay + 30, "Sum of first diagonal is: ");
                                outstreamxy(100 + tw, lastay + 30);
                                lastay += 30;
                                fout << "SumaDiagPrincipala(A): " << sumDiagPP(A) << '\n';
                            }
                            if (mat == B) {
                                outtextxy(800, lastby + 30, "Sum of first diagonal is: ");
                                outstreamxy(800 + tw, lastby + 30);
                                lastby += 30;
                                fout << "SumaDiagPrincipala(B): " << sumDiagPP(B) << '\n';
                            }
                        }

                    }
                }
                ///Suma diag Sec
                if (isButton(x, y, 6)) {
                    if (mat.col != mat.row) {
                        fout << "Matricea nu este patratica!\n";
                        notSquareError(mat);
                    } else {
                        if (!eng) {
                            int tw = textwidth("Suma diagonalei secundare este: ");
                            bgiout << sumDiagSec(mat);
                            if (mat == A) {
                                outtextxy(100, lastay + 30, "Suma diagonalei secundare este: ");
                                outstreamxy(100 + tw, lastay + 30);
                                lastay += 30;
                                fout << "SumaDiagSecundara(A): " << sumDiagSec(A) << '\n';
                            }
                            if (mat == B) {
                                outtextxy(800, lastby + 30, "Suma diagonalei secundare este: ");
                                outstreamxy(800 + tw, lastby + 30);
                                lastby += 30;
                                fout << "SumaDiagSecundara(B): " << sumDiagSec(B) << '\n';
                            }
                        } else {
                            int tw = textwidth("Sum of second diagonal is: ");
                            bgiout << sumDiagSec(mat);
                            if (mat == A) {
                                outtextxy(100, lastay + 30, "Sum of second diagonal is: ");
                                outstreamxy(100 + tw, lastay + 30);
                                lastay += 30;
                                fout << "SumaDiagSecundara(A): " << sumDiagSec(A) << '\n';
                            }
                            if (mat == B) {
                                outtextxy(800, lastby + 30, "Sum of second diagonal is: ");
                                outstreamxy(800 + tw, lastby + 30);
                                lastby += 30;
                                fout << "SumaDiagSecundara(B): " << sumDiagSec(B) << '\n';
                            }
                        }
                    }
                }
                if (isButton(x, y, 7)) {
                    // || (x > 1550 && x < 1870 && y > 485 && y < 485 + 50 )
                    int tw;
                    if(!eng)
                        tw = textwidth("Suma elementelor este: ");
                    else
                        tw = textwidth("Sum of the matrix's elements is: ");
                    if (mat == A) {
                        if(!eng){
                            bgiout << sumElem(mat);
                            outtextxy(100, lastay + 30, "Suma elementelor este: ");
                            outstreamxy(100 + tw, lastay + 30);
                        }
                        else {
                            bgiout << sumElem(mat);
                            outtextxy(100, lastay + 30, "Sum of the matrix's elements is: ");
                            outstreamxy(100 + tw, lastay + 30);
                        }
                        lastay += 30;
                        fout << "sumaElemente(A): " << sumElem(A) << '\n';
                    }
                    if (mat == B) {
                        if (!eng) {
                            outtextxy(800, lastby + 30, "Suma elementelor este: ");
                            outstreamxy(800 + tw, lastby + 30);
                        }
                        else{
                            outtextxy(800, lastby + 30, "Sum of the matrix's elements is: ");
                            outstreamxy(800 + tw, lastby + 30);
                        }
                        lastby += 30;
                        fout << "sumaElemente(B): " << sumElem(B) << '\n';
                    }
                }
                ///Produs A x B (A.col == B.row)
                if (x > 1550 && x < 1550 + 160 && y > 605 - 60 && y < 655 - 60) {
                    if (A.col != B.row) {
                        if (mat == A) {
                            if(!eng)
                                outtextxy(100, lastay + 30, "Eroare: A.nrColoane != B.nrLinii!");
                            else
                                outtextxy(100, lastay + 30, "Error: A.colls != B.rows!");
                            fout << "Eroare: A.nrColoane != B.nrLinii!\n";
                            lastay += 30;
                        }
                        if (mat == B) {
                            if(!eng)
                                outtextxy(100, lastby + 30, "Eroare: A.nrColoane != B.nrLinii!");
                            else
                                outtextxy(100, lastby + 30, "Error: A.colls != B.rows!");
                            fout << "Eroare: A.nrColoane != B.nrLinii!\n";
                            lastby += 30;
                        }
                    } else {
                        if (mat == A) {
                            outtextxy(100, lastay + 30, "A x B = ");
                            lastay += 30;
                            printMatrix(product(A, B), lastax, lastay);
                        }
                        if (mat == B) {
                            outtextxy(800, lastby + 30, "A x B = ");
                            lastby += 30;
                            printMatrix(product(A, B), lastbx, lastby);
                        }
                    }
                }
                ///Produs B x A (B.col == A.row)
                if (x > 1550 + 160 && x < 1870 && y > 605 - 60 && y < 655 - 60) {
                    if (B.col != A.row) {
                        if (mat == A) {
                            if(!eng)
                                outtextxy(100, lastay + 30, "Eroare: B.nrColoane != A.nrLinii!");
                            else
                                outtextxy(100, lastay + 30, "Error: B.colls != A.rows");
                            fout << "Eroare: B.nrColoane != A.nrLinii!\n";
                            lastay += 30;
                        }
                        if (mat == B) {
                            if(!eng)
                                outtextxy(800, lastby + 30, "Eroare: B.nrColoane != A.nrLinii!");
                            else
                                outtextxy(800,lastby+30, "Error: B.colls != A.rows");
                            fout << "Eroare: B.nrColoane != A.nrLinii!\n";
                            lastby += 30;
                        }
                    } else {
                        if (mat == A) {
                            outtextxy(100, lastay + 30, "B x A = ");
                            lastay += 30;
                            printMatrix(product(B, A), lastax, lastay);
                        }
                        if (mat == B) {
                            outtextxy(800, lastby + 30, "B x A = ");
                            lastby += 30;
                            printMatrix(product(B, A), lastbx, lastby);
                        }
                    }
                }
                ///Suma A + B
                if (isButton(x, y, 9)) {
                    if (A.col != B.col && A.row != B.row) {
                        if (mat == A) {
                            if(!eng)
                                outtextxy(100, lastay + 30, "A si B trebuie sa fie de aceeasi dimensiune");
                            else
                                outtextxy(100, lastay + 30, "A and B must be of the same size ");
                            lastay += 30;
                            fout << "sum(A+B) nu se poate calcula!\n";
                        }
                        if (mat == B) {
                            if(!eng)
                                outtextxy(800, lastby + 30, "Nu se poate calcula!");
                            else
                                outtextxy(800, lastay + 30, "A and B must be of the same size ");
                            lastay += 30;
                            fout << "sum(A+B) nu se poate calcula!\n";
                        }
                    } else {
                        fout << "sum(A+B) = \n";
                        printfMat(A + B);
                        if (mat == A) {
                            outtextxy(100, lastay + 30, "A + B = ");
                            lastay += 30;
                            printMatrix(sum(A, B), lastax, lastay);

                        }
                        if (mat == B) {
                            outtextxy(800, lastby + 30, "A + B = ");
                            lastby += 30;
                            printMatrix(sum(A, B), lastbx, lastby);
                        }
                    }
                }
                ///Putere
                if (isButton(x, y, 10)) {
                    int exp, dis = 0;
                    if (mat == A) {
                        if(!eng)
                            kbinValxy("Introduceti Exponent: ", 100, lastay + 30, exp);
                        else
                            kbinValxy("Raise to the power of: ", 100, lastay + 30, exp);

                        lastay += 30;
                        printMatrix(pow(A, exp), lastax, lastay);
                        fout << "pow(A, " << exp << ") =\n";
                        printfMat(pow(A, exp));
                    }
                    if (mat == B) {
                        if(!eng)
                            kbinValxy("Introduceti Exponetul: ", 800, lastby + 30, exp);
                        else
                            kbinValxy("Raise to the power of: ", 800, lastby + 30, exp);
                        lastby += 30;
                        printMatrix(pow(B, exp), lastbx, lastby);
                        fout << "pow(B, " << exp << ") =\n";
                        printfMat(pow(B, exp));
                    }
                }
                ///Reset side A
                if (x > 1550 && x < 1550 + 160 && y > 725 && y < 775) {
                    side = 100;
                    colorInput(side);
                    fout << "Reseting Matrix A...\n";
                    kbinMat(A, side);
                    mat = A;
                }
                ///Reset side B
                if (x > 1550 + 160 && x < 1550 + 320 && y > 725 && y < 775) {
                    side = 800;
                    colorInput(side);
                    fout << "Reseting Matrix B...\n";
                    kbinMat(B, side);
                    mat = B;
                }
            }
        }
    }while (!ok);
}

void pagina() {
    int x, y, ok = 0;

    setactivepage(1);
    setvisualpage(1);
    settextstyle(0, 0, 10);

    do {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();

            if (x >= 480 && x <= 1440 && y >= 260 && y <= 400) {
                ok = 1;
                paginaVectori();
            }

            if (x >= 480 && x <= 1440 && y >= 460 && y <= 600) {
                ok = 1;
                paginaMatrici();
            }

            if (x >= 480 && x <= 1440 && y >= 660 && y <= 800) {
                ok = 1;
                closegraph();
                exit(EXIT_SUCCESS);
                return;
            }
        }
    } while (ok == 0);

    pagina();
}

void desenarePagina()
{
    initwindow(1920,1000);
    setactivepage(1);
    setbkcolor(RGB(90, 60, 90));
    cleardevice();
    desenare();
    setactivepage(2);
    setbkcolor(RGB(5, 9, 92));
    cleardevice();
    desenareVectori();
    setactivepage(3);
    setbkcolor(RGB(15, 159, 92));
    cleardevice();
    //desenareMatrici();
    pagina();
    getch();
    closegraph();
}
#endif //GRAFICS_GRAFICS_H