#include <stdio.h>
#include <time.h>
#include <stdlib.h> // Necesario para rand() y srand()

#define TAM 10

int numAleatorio(int min, int max);
void cargarVector(int vec[]);
void ListarVector(int vec[]);

int main()
{
    int vector[TAM];
    srand(time(NULL));
    cargarVector(vector);
    ListarVector(vector);
    return 0;
}

int numAleatorio(int min, int max)
{
    // Fórmula para un rango inclusivo: (rand() % (rango)) + min
    // Rango = (max - min + 1)
    return (rand() % (max - min + 1)) + min;
}

void cargarVector(int vec[]){
    for (int i = 0; i < TAM; i++)
    {
        *(vec+ i)=numAleatorio(25,75);
    }
    printf("Vector cargado.\n\n");
}

void ListarVector(int vec[]){
    printf("Mostrando valores y direcciones de memoria:\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("El vector %i tiene asignado el numero %i y su direccion de memoria es %p\n",i+1,*(vec+i),(void *)(vec+i));
    }
}