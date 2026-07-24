/*
6. Invertir un vector: Escribe un programa en C que cargue un vector
de 20 posiciones, cargados con números al azar entre 20 y 90,.
Leer ese vector de números enteros y lo invierta en otro vector, es
decir, el primer elemento pasará a ser el último, el segundo elemento
pasará a ser el penúltimo, y así sucesivamente; dejar los valores
invertidos en ese nuevo vector.
Utilizar una función para cargar el vector original llamado CargaVector,
otra función para invertir el vector, llamada InvertirVector y una única
función para mostrar cada uno de los vectores llamada MostrarVector.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define indice 20

int numAle();//20 y 90

int CargarVector(int v[], int tam);

int InvertirVector(int v[], int v2[], int tam);

void MostrarVector(int v[],int v2[], int tam);

int main()
{
    int vector1[indice];
    srand(time(NULL));
    CargarVector(vector1,indice);
    int vector2[indice];
    InvertirVector(vector1,vector2,indice);
    MostrarVector(vector1,vector2,indice);
    return 0;
}

int numAle()
{
    return (rand() % 71)+20;
}

int CargarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]=numAle();
    }
    
}

int InvertirVector(int v[],int v2[],int tam)
{
    int j = tam -1;

    for (int i = 0; i < tam; i++)
    {
        v2[j] = v[i];
        j--;
    }
    
}

void MostrarVector(int v[],int v2[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("vector1[%d] con valor %d\n",i+1,v[i]);
    }
    
    printf("El vector invertido:\n");

        for (int i = 0; i < tam; i++)
    {
        printf("vectorInvertido[%d] con valor %d\n",i+1,v2[i]);
    }
}
