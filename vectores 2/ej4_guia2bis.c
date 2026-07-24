/*
Suma de posiciones específicas entre dos vectores
Enunciado:
Generar dos vectores de 120 elementos cada uno, cargados aleatoriamente con números
enteros entre 1 y 100. Crear un nuevo vector llamado resultado, donde cada elemento
sea la suma del elemento en posición par del primer vector con el elemento en la misma
posición impar del segundo vector. Por ejemplo, resultado[0] = vector1[0] + vector2[1],
resultado[2] = vector1[2] + vector2[3], y así sucesivamente, una vez realizado informar
el vector resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamano 120

int numAleatorio();
void cargarVector(int v[]);
void sumaPareImpar(int v[],int v2[],int resultado[]);

int main()
{
    srand(time(NULL));
    int vector1[tamano];
    int vector2[tamano];
    int resultado[tamano];
    cargarVector(vector1);
    cargarVector(vector2);
    sumaPareImpar(vector1,vector2,resultado);

    for (int i = 0; i <= tamano; i+=2)
    {
        printf("resultado[%d] = %d ( vector1[%d]= %d + vector2[%d]=%d )\n",i,resultado[i],i,vector1[i],i+1,vector2[i]);
    }
    
    return 0;
}

int numAleatorio()
{
    return (rand() % 100) +1;
}

void cargarVector(int v[])
{
    for (int i = 0; i < tamano; i++)
    {
        v[i]= numAleatorio();
    }
    
}

void sumaPareImpar(int v[],int v2[],int resultado[])
{

    for (int i = 0; i < tamano; i+=2)
    {
        resultado[i] = v[i]+v2[i+1];
        
    }
    

}