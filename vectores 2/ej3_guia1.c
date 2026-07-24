/*Ejercicio 3: Buscar un número específico
Objetivo: Aplicar búsqueda dentro de un vector.
Consigna:
1. Crear un vector de 50 elementos con números aleatorios entre 50 y 100.
2. Solicitar al usuario que ingrese un número, entre esos rangos, validar
3. Verificar en la búsqueda, si ese número se encuentra en el vector.
4. Informar si fue encontrado y en qué posición o posiciones aparece, si estuviese
más de una vez.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define elementos 50

int numAleatorio();
void cargarVector(int v[],int tam);

int main()
{
    int vector1[elementos];
    int numeroBuscado;
    int encontrado = 0;

    srand(time(NULL));

    cargarVector(vector1,elementos);

    //Ingresa numero y se valida si esta en el rango
    do
    {
        printf("Ingrese un numero entre 50 y 100 para la busqueda:\n");
        scanf("%d",&numeroBuscado);
        if (numeroBuscado < 50 || numeroBuscado >100)
        {
            printf("Numero fuera de rango!!!, ingrese un numero entre 50 y 100 para la busqueda:\n");
            scanf("%d",&numeroBuscado);
        }
        
    } while (numeroBuscado < 50 || numeroBuscado >100 );
    
    printf("\nBuscando el número %d en el vector...\n\n", numeroBuscado);

    for (int i = 0; i < elementos; i++)
    {
        if (vector1[i]==numeroBuscado)
        {
            printf("El numero se ha encontrado en la posicion %d",i);
            encontrado = 1;
        }
        
    }
    
}

int numAleatorio()
{
    return (rand() % 51) + 50;
}

void cargarVector(int v[],int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]= numAleatorio();
    }
    
}