#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED



struct vector{
    float v[10000];
    int dim;
};


void interschimba(vector a,int i,int j)
{
    float dis=1400/(a.dim*1.0);
    setcolor(BLACK);
    line(50+dis/2+dis*i,800,50+dis/2+dis*i,200);
    line(50+dis/2+dis*j,800,50+dis/2+dis*j,200);
    setcolor(GREEN);
    line(50+dis/2+dis*i,800,50+dis/2+dis*i,800-a.v[j]);
    line(50+dis/2+dis*j,800,50+dis/2+dis*j,800-a.v[i]);
}

void printVect(vector a)
{
    int i;
    float dis=1400/(a.dim*1.0);
    setfillstyle(1,BLACK);
    bar(50,200,1450,800);
    setcolor(GREEN);
    for(i=0;i<a.dim;i++)
        line(50+dis/2+dis*i,800,50+dis/2+dis*i,800-a.v[i]);
}

//de la tastatura
void readInterval(vector &v)
{
    int i=0,tw,dis=0;
    char c[100];
    setcolor(WHITE);
    tw=textwidth("Introduceti numarul de numere: ");
    outtextxy(100,120,"Introduceti numarul de numere: ");
    c[i]=getch();
    while(int(c[i])!=32)
    {
        bgiout<<c[i];
        outstreamxy(tw+100+dis*10,120);
        dis+=2;
        i++;
        c[i]=getch();
    }
    v.dim=atoi(c);
    for(i=0;i<v.dim;i++)
        v.v[i]=rand()%600;
}


//din fisier
void readfVect(vector &a)
{
    FILE * fin;
    fin=fopen("date.in","r");
    a.dim=0;
    while(!feof(fin))
    {
        fscanf(fin,"%d",&a.v[a.dim]);
        a.dim++;
    }
    fclose(fin);
}

int sumVector(vector a)
{
    int sum=0,i;
    for(i=0;i<a.dim;i++)
        sum+=a.v[i];
    return sum;
}

int prodVector(vector a)
{
    int prod=1,i;
    for(i=0;i<a.dim;i++)
        prod*=a.v[i];
    return prod;
}

void scalarVect(vector a, int scalar)
{
    int i;
    for(i=0;i<a.dim;i++)
        a.v[i]*=a.v[i];

}


void bubbleSort(vector &a, bool sens) //sens == 0 - crescator
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
                    delay(50);
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
                    delay(50);
                    aux=a.v[j];
                    a.v[j]=a.v[j+1];
                    a.v[j+1]=aux;
                }
            }
    }
}


void insertSort(vector &a, bool sens) //sens == 0 - crescator
{
    int i,key,j;
    for(i=1;i<a.dim;i++)
    {
        key=a.v[i];
        j=i-1;
        if(sens==0)
        {   while(j>=0&&a.v[j]>key)
            {
                interschimba(a,j,j+1);
                delay(50);
                a.v[j+1]=a.v[j];
                j--;
            }
            a.v[j+1]=key;
            printVect(a);
        }
        else
        {
             while(j>=0&&a.v[j]<key)
            {
                interschimba(a,j,j+1);
                delay(50);
                a.v[j+1]=a.v[j];
                j--;
            }
            a.v[j+1]=key;
            printVect(a);
        }
    }
}


void selectionSort(vector &a, bool sens) //sens == 0 - crescator
{
    int i,j,aux;
    for(i=0;i<a.dim-1;i++)
        for(j=i+1;j<a.dim;j++)
        if(sens==0)
        {
            if(a.v[i]>a.v[j])
            {
                interschimba(a,i,j);
                delay(50);
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
                delay(50);
                aux=a.v[j];
                a.v[j]=a.v[i];
                a.v[i]=aux;
            }
        }
}

void shiftVect(vector a, bool sens, int pozShift) //sens == 0 - dreapta
{
    int i,j,aux;
    if(sens==0)
    {
        for(i=1;i<=pozShift;i++)
        {
            aux=a.v[a.dim-1];
            for(j=a.dim-1;j>0;j--)
                a.v[j]=a.v[j-1];
            a.v[0]=aux;
        }
    }
    else
    {
       for(i=1;i<=pozShift;i++)
        {
            aux=a.v[0];
            for(j=0;j<a.dim-1;j++)
                a.v[j]=a.v[j+1];
            a.v[a.dim-1]=aux;
        }
    }
}



#endif // VECTOR_H_INCLUDED
