
#ifndef BIBMAT_VECTOR_H
#define BIBMAT_VECTOR_H

struct vector{
    int *v;
    int dim;
};

//de la tastatura
void readVect();
void printVect(vector v);

//din fisier
void readfVect();
void printfVect(vector v);

//operatii
int sumVect(vector v);
int prodVect(vector v);
void scalarVect(vector v, int scalar);

//Sortari
void bubbleSort(vector v, bool sens); //sens == 0 - crescator
void insertSort(vector v, bool sens); //sens == 0 - crescator
void selectionSort(vector v, bool sens); //sens == 0 - crescator

void shiftVect(vector v, bool sens) //sens == 0 - dreapta

#endif //BIBMAT_VECTOR_H
