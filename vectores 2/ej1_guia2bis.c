/*
1. Elementos en posiciones impares de un arreglo
Enunciado:
Generar un arreglo (vector) de 50 elementos cargado aleatoriamente con números
enteros entre 50 y 250. Mostrar los elementos que se encuentran en posiciones impares
(índices 1, 3, 5, ..., 49) y calcular la suma total de esos elementos.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define elemento 50

int numAle();
void cargarV(int v[]);
void mostrarImpares(int v[], int suma);

int main()
{
    int vector1[elemento];
    srand(time(NULL));
    cargarV(vector1);
    int suma=0;
    mostrarImpares(vector1, suma);
    return 0;
}
int numAle()
{
    return (rand() % 201)+50;
}

void cargarV(int v[])
{
    for (int i = 0; i < elemento; i++)
    {
        v[i]=numAle();
    }
    
}

void mostrarImpares(int v[], int suma)
{
    printf("Los elementos impares son:\n");
    for (int i = 1; i < elemento; i++)
    {
        if (i % 2 != 0)
        {
            printf("vector1[%d] con valor %d\n",i,v[i]);
            suma+= v[i];
        }
        
    }

    printf("La suma de los valores de los indices impares del vector es: %d\n",suma);
    
}