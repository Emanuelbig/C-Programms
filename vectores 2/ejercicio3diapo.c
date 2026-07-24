/*
3. Escribir una función que reciba como parámetro un vector de
enteros con 50 valores cargados al azar entre 10 y 20. Determine
cuantas veces se repite el mayor
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define elemento 50

int numAle();

int cargarVector(int v[],int tam);

int mayorEncontrado(int v[], int mayor, int tam);

int vecesRepetido(int v[], int cont, int tam,int mayor);

int main()
{
    srand(time(NULL));
    int vector[elemento];
    cargarVector(vector,elemento);

    //Determinamos el mayor
    int mayor=mayorEncontrado( vector, 0, elemento);
    /*for (int i = 0; i < elemento; i++)
    {
        if (vector[i]>mayor)
        {
            mayor=vector[i];
        }
        
    }*/

    //Determinamos cuantas veces se repite el mayor
    int contador=vecesRepetido(vector, 0, elemento,mayor);
    /*for (int i = 0; i < elemento; i++)
    {
        if (vector[i]==mayor)
        {
            contador++;
        }
        
    }*/

    printf("El vector es:\n");

    for (int i = 0; i < elemento; i++)
    {
        printf("Vector[%d] con valor: %d\n",i+1,vector[i]);
    }
    
    printf("Su numero mayor es: %d\n",mayor);

    printf("Su numero %d se repite %d veces\n",mayor, contador);

    return 0;
}

int numAle()
{
    return (rand() % 11) + 10;
}

int cargarVector(int v[],int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]=numAle();
    }
    return 0;
}

int mayorEncontrado(int v[], int mayor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (v[i]>mayor)
        {
            mayor=v[i];
        }
        
    }
    return mayor;
}

int vecesRepetido(int v[], int cont, int tam, int mayor)
{
    for (int i = 0; i < tam; i++)
    {
        if (v[i]==mayor)
        {
            cont++;
        }
        
    }
    return cont;
}