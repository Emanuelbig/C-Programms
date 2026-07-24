/*Ejercicio 2: Promedio de los valores mayores a 100
Objetivo: Aplicar filtros y cálculos de promedio.
Consigna:
1. Crear un vector de 80 elementos con números aleatorios entre 50 y 200.
2. Calcular el promedio de todos los valores que sean mayores a 100.
3. Mostrar ese promedio. Si no hay valores mayores a 100, informar que no se puede
calcular.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamano 80

int numAleatorio();
void cargarVector(int v[],int tam);

int main()
{
    int vector1[tamano];
    srand(time(NULL));
    cargarVector(vector1,tamano);
    int suma=0;
    int cont=0;
    float promedio;

    //Promedio
    for (int i = 0; i < tamano; i++)
    {
        if (vector1[i]>100)
        {
            suma += vector1[i];
            cont++;
        }
        
    }

    //Muestro el promedio
    if (cont>0)
    {
        promedio = suma /cont;
        printf("El promedio de los valores mayores a 100 es: %.2f\n",promedio);
    }
    else
    {
        printf("No hay valores mayores a 100 , no se puede calcular\n");
    }

    //muestro el vector que le asigne valores
    printf("Valores del vector:\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("%d\n",vector1[i]);
    }
    
    
    return 0;  
    


}

int numAleatorio()
{
    return (rand() % 151) +50;
}

void cargarVector(int v[],int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]= numAleatorio();
    }
    
}