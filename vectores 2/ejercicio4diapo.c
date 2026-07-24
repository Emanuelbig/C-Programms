/*
4. Escribir 2 funciones que reciban como parámetro un vector de enteros y su
tamaño de 100 posiciones, si lo define con #define, no será necesario pasarlo.
El rango de valores que se ingresarán al vector, serán entre 10 a 40 en forma
aleatoria.
Encuentre el valor máximo y el mínimo, una vez encontrado, realice una función
que muestre en que posiciones se repite el máximo.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define posiciones 100
int numAle();
void cargarVector(int v[],int tam);
int main()
{
    int vector[posiciones];
    srand(time(NULL));
    cargarVector(vector,posiciones);

    //Encontramos valores max y min
    int max =vector[0],min=vector[0];

    for (int i = 0; i < posiciones; i++)
    {
        if (vector[i] > max)
        {
            max = vector[i];
        }
        else if (vector[i]<min)
        {
            min = vector[i];
        }
                
    }
    
    for (int i = 0; i < posiciones; i++)
    {
        if (vector[i]==max)
        {
            printf("La posicion en donde esta el max es %d\n con valor %d",i+1,vector[i]);
        }
        
    }

    for (int i = 0; i < posiciones; i++)
    {
        printf("Vector[%d] con valor %d\n",i+1,vector[i]);      

    }
    
    

}
int numAle()
{
    return (rand() % 31 )+10;
}
void cargarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]=numAle();
    }
    
}