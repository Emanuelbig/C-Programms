/*
Crear un vector de 100 elementos cargado automáticamente con números enteros entre 1 y 500.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define elemento 100

int numAleatorio();
void inicioVector(int v[], int tam);
void mostrarVector(int v[], int tam);
int main()
{
    int vector[elemento];
    inicioVector(vector, elemento);
    mostrarVector(vector, elemento);

    return 0;
}

int numAleatorio()
{
    return (rand() % 500) + 1;
}

void inicioVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i] = numAleatorio();
    }
}

void mostrarVector(int v[], int tam)
{
    printf("Los elementos del vector son:\n");
    //for (int i = 0; i < tam; i++)
    //{

        int i;
        printf("Contenido del vector:\n");
        for (i = 0; i < tam; i++)
        {
            printf("vec[%3d]=%4d\n ", i, v[i]);
        }
        printf("\n------------------------\n");

        // if (i % 10 ==0 && i != 0)
        // {
        //     printf("\n");
        //     printf("%4d",v[i]);
        // }

        // printf("%6d, ",v[i]);
    //}
}