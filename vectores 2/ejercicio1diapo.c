/*
1. Escribir una función que reciba como
parámetro un vector de enteros y el
tamaño definido por Uds. y calcule la
suma de todos los elementos del vector.
( Utilizar Funciones)

2. Finalizado el ejercicio 1, armar una
función que calcule el Promedio
*/

#include<stdio.h>
#include<stdlib.h>

#define tamano 5

int suma(int v[], int tam);

int promedio(int sum, int cont);

int main()
{
    int vector[tamano]={5,10,20,30,40};

    printf("El vector de 5 posiciones tiene estos datos:\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("Vector[%d] con valor: %d\n",i+1,vector[i]);
    }
    
    printf("Su suma es: %d\n",suma(vector,tamano));

    printf("Su promedio es: %d\n",promedio(suma(vector,tamano),tamano));

    return 0;
}

int suma(int v[], int tam)
{
    int suma=0;
    for (int i = 0; i < tam; i++)
    {
        suma += v[i];
    }
    
    return suma;
}

int promedio(int sum, int cont)
{
    return sum / cont;
}