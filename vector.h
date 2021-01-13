#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED


std::ofstream g("dateVectori.txt",std::ios::trunc);

struct vect{
    int v[10000];
    int dim;
};

void interschimba(vect a,int i,int j)
{
    float dis=1400/(a.dim*1.0);
    setcolor(RED);
    line(50+dis/2+dis*i,800,50+dis/2+dis*i,800-a.v[i]);
    line(50+dis/2+dis*j,800,50+dis/2+dis*j,800-a.v[j]);
    delay(300);
    setcolor(BLACK);
    line(50+dis/2+dis*i,800,50+dis/2+dis*i,200);
    line(50+dis/2+dis*j,800,50+dis/2+dis*j,200);
    setcolor(RED);
    line(50+dis/2+dis*i,800,50+dis/2+dis*i,800-a.v[j]);
    line(50+dis/2+dis*j,800,50+dis/2+dis*j,800-a.v[i]);
    delay(300);
    setcolor(GREEN);
    line(50+dis/2+dis*i,800,50+dis/2+dis*i,800-a.v[j]);
    line(50+dis/2+dis*j,800,50+dis/2+dis*j,800-a.v[i]);
}



void printVect(vect a)
{
    int i;
    float dis=1400/(a.dim*1.0);
    setfillstyle(1,BLACK);
    bar(50,200,1450,801);
    setcolor(GREEN);
    for(i=0;i<a.dim;i++)
        line(50+dis/2+dis*i,800,50+dis/2+dis*i,800-a.v[i]);
}

void readInterval(vect &v)
{
    int i=0,dis=0,tw;
    char c[100];
    tw=textwidth("Citire random: ");
    setcolor(WHITE);
    settextstyle(0,0,2);
    c[i]=getch();
    while(int(c[i])!=13)
    {
        bgiout<<c[i];
        outstreamxy(tw+(700-tw)/2+50+dis*10,170);
        dis+=2;
        i++;
        c[i]=getch();
    }
    v.dim=atoi(c);
    for(i=0;i<v.dim;i++)
    {
        v.v[i]=rand()%600;
    }
}

void readfVect(vect &a)
{
    std::ifstream f("dateIntrareVectori.in");
    a.dim=0;
    while(!f.eof())
    {
        f>>a.v[a.dim];
        a.dim++;
    }
    a.dim--;
}

void PrintfVect(vect a)
{
    int i;
    g<<a.dim<<"\n";
    for(i=0;i<a.dim;i++)
        g<<a.v[i]<<" ";
    g<<"\n"<<"\n";
}

int sumVector(vect a)
{
    int sum=0,i;
    for(i=0;i<a.dim;i++)
        sum+=a.v[i];
    return sum;
}

int prodVector(vect a)
{
    int prod=1,i;
    for(i=0;i<a.dim;i++)
        prod*=a.v[i];
    return prod;
}

void scalarVect(vect a, int scalar)
{
    int i;
    for(i=0;i<a.dim;i++)
        a.v[i]*=scalar;
}

void SelectionSort(vect &a, bool sens) //sens == 0 - crescator
{
    int i,j,aux;
    for(i=0;i<a.dim-1;i++)
    {
        for(j=i+1;j<a.dim;j++)
        if(sens==0)
        {
            if(a.v[i]>a.v[j])
            {
                interschimba(a,i,j);

                aux=a.v[j];
                a.v[j]=a.v[i];
                a.v[i]=aux;
            }
        }
        else
        {
            if(a.v[i]<a.v[j])
            {
                interschimba(a,i,j);

                aux=a.v[j];
                a.v[j]=a.v[i];
                a.v[i]=aux;
            }
        }
    }
}

void BubbleSort(vect &a, bool sens) //sens == 0 - crescator
{
    int i,j,aux;
    for (i=0;i<a.dim-1;i++)
    {
        for (j=0;j<a.dim-i-1;j++)
            if(sens==0)
            {
                if (a.v[j]>a.v[j+1])
                {
                    interschimba(a,j,j+1);

                    aux=a.v[j];
                    a.v[j]=a.v[j+1];
                    a.v[j+1]=aux;
                }
            }
            else
            {
                if (a.v[j]<a.v[j+1])
                {
                    interschimba(a,j,j+1);

                    aux=a.v[j];
                    a.v[j]=a.v[j+1];
                    a.v[j+1]=aux;
                }
            }
    }
}

void InsertSort(vect &a, bool sens) //sens == 0 - crescator
{
    int i,key,j;
    for(i=1;i<a.dim;i++)
    {
        key=a.v[i];
        j=i-1;
        if(sens==0)
        {   while(j>=0&&a.v[j]>key)
            {
                a.v[j+1]=a.v[j];
                printVect(a);
                delay(150);
                j--;
            }
            a.v[j+1]=key;
            printVect(a);
            delay(150);
        }
        else
        {
             while(j>=0&&a.v[j]<key)
            {
                a.v[j+1]=a.v[j];
                printVect(a);
                delay(150);
                j--;
            }
            a.v[j+1]=key;
            printVect(a);
            delay(150);
        }
    }
}

int part(vect &a, int p, int q,bool sens)
{
    int x,i,j,aux;
    x=a.v[q];
    i=p-1;
    for(j=p;j<q;j++)
    {
        if(sens==0)
        {
            if(a.v[j]<x)
            {
                i++;
                interschimba(a,i,j);

                aux=a.v[i];
                a.v[i]=a.v[j];
                a.v[j]=aux;
            }
        }
        else
        {
           if(a.v[j]>x)
            {
                i++;
                interschimba(a,i,j);

                aux=a.v[i];
                a.v[i]=a.v[j];
                a.v[j]=aux;
            }
        }

    }
    interschimba(a,i+1,q);

    aux=a.v[i+1];
    a.v[i+1]=a.v[q];
    a.v[q]=aux;
    return i+1;
}

void QuickSort(vect &a, int p, int q, bool sens)
{
    int k;
    if(p<q)
    {
        k=part(a,p,q,sens);
        QuickSort(a,p,k-1,sens);
        QuickSort(a,k+1,q,sens);
    }
}

void unire(vect &v, int s, int m, int d,bool sens)
{
    int i,j,n1,n2,k;
    vect S,D;
    n1=m-s+1;
    n2=d-m;
    S.dim=n1;
    D.dim=n2;
    for(i=0;i<n1;i++)
        S.v[i]=v.v[s+i];
    for (j=0;j<n2;j++)
        D.v[j]=v.v[m+1+j];
    i=0;
    j=0;
    k=s;
    while (i<n1&&j<n2)
    {
        if(sens==0)
        {
            if (S.v[i]<=D.v[j])
            {
                v.v[k]=S.v[i];
                i++;
            }
            else
            {
                v.v[k]=D.v[j];
                j++;
            }
        }
        else
        {
            if (S.v[i]>=D.v[j])
            {
                v.v[k]=S.v[i];
                i++;
            }
            else
            {
                v.v[k]=D.v[j];
                j++;
            }
        }
        k++;
    }
    while (i<n1)
    {
        v.v[k]=S.v[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        v.v[k]=D.v[j];
        j++;
        k++;
    }
    printVect(v);
    delay(500);
}

void MergeSort(vect &v,int s,int d,bool sens)
{
    if(s<d)
    {
        int m=(s+d-1)/2;
        MergeSort(v,s,m,sens);
        MergeSort(v,m+1,d,sens);
        unire(v,s,m,d,sens);
    }
}

void shiftVect(vect &a, bool sens, int pozShift) //sens == 0 - dreapta
{
    int i,j;
    if(sens==0)
    {
        for(i=1;i<=pozShift;i++)
        {
            for(j=a.dim-1;j>0;j--)
                a.v[j]=a.v[j-1];
            for(j=0;j<a.dim-1;j++)
                a.v[j]=a.v[j+1];
            a.dim--;
            printVect(a);
            delay(150);
        }
    }
    else
    {
       for(i=1;i<=pozShift;i++)
        {
            for(j=0;j<a.dim-1;j++)
                a.v[j]=a.v[j+1];
            a.dim--;
            printVect(a);
            delay(150);
        }
    }
}


#endif // VECTOR_H_INCLUDED
