#ifndef GRAFICA_H_INCLUDED
#define GRAFICA_H_INCLUDED



void desenare()
{
    int tw,th,y;
    setfillstyle(2,WHITE);
    bar(480,60,1440,200);
    setfillstyle(5,WHITE);
    bar(480,260,1440,400);
    setfillstyle(5,WHITE);
    bar(480,460,1440,600);
    settextstyle(0,0,10);
    tw=textwidth("BibMat");
    th=textheight("BibMat");
    outtextxy((960-tw)/2+480,(140-th)/2+60,"BibMat");
    tw=textwidth("Vectori");
    th=textheight("Vectori");
    outtextxy((960-tw)/2+480,(140-th)/2+260,"Vectori");
    tw=textwidth("Matrici");
    th=textheight("Matrici");
    outtextxy((960-tw)/2+480,(140-th)/2+460,"Matrici");
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

void paginaMatrici()
{
    setactivepage(3);
    setvisualpage(3);
    int ok=0,x,y;
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

void pagina()
{
    int x,y,ok,i;
    vector a,b;
    a.dim=b.dim=0;
    setactivepage(1);
    setvisualpage(1);
    settextstyle(0,0,10);
    ok=0;
    do
    {
        if(ismouseclick(WM_MOUSEMOVE))
        {
            clearmouseclick(WM_MOUSEMOVE);
            x=mousex();
            y=mousey();
            if(a.dim>=15)
            {
                setcolor(RGB(95, 59, 92));
                for(i=0;i<=a.dim;i++)
                    circle(a.v[i],b.v[i],10);
                a.dim=b.dim=0;
            }
            if(!(x>=450&&x<=1450&&y>=250&&y<=410)&&!(x>=450&&x<=1450&&y>=450&&y<=610)&&!(x>=450&&x<=1480&&y>=50&&y<=210))
            {
                setcolor(WHITE);
                circle(x,y,10);
                a.v[a.dim++]=x;
                b.v[b.dim++]=y;
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(a.dim)
            {
                setcolor(RGB(95, 59, 92));
                for(i=0;i<=a.dim;i++)
                    circle(a.v[i],b.v[i],10);
                a.dim=b.dim=0;
            }
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x>=480&&x<=1440&&y>=260&&y<=400)
            {
                ok=1;
                paginaVectori();
            }
            else
            if(x>=480&&x<=1440&&y>=460&&y<=600)
            {
                ok=1;
                paginaMatrici();
            }
        }
    }while(ok==0);
    pagina();
}

void desenarePagina()
{
    initwindow(1920,1000);
    setactivepage(1);
    setbkcolor(RGB(95, 59, 92));
    cleardevice();
    desenare();
    setactivepage(2);
    setbkcolor(RGB(5, 9, 92));
    cleardevice();
    desenareVectori();
    setactivepage(3);
    setbkcolor(RGB(15, 159, 92));
    cleardevice();
    desenareMatrici();
    pagina();
    getch();
    closegraph();
}



#endif // GRAFICA_H_INCLUDED

