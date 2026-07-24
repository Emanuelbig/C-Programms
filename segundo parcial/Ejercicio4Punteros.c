/*
Realizar un programa en C que trabaje con un vector de 10 números enteros.
Cargar el vector con valores aleatorios entre 1 y 100.
Mostrar cada elemento del vector junto con la dirección de memoria donde
está almacenado.
Usar notación con punteros para acceder a los elementos del vector.
Requisitos:
No usar índices directos en el acceso a los valores (ejemplo: vec[i]), sino
punteros (*(vec+i)).
Utilizar la función rand() para la generación de los números aleatorios.
Desarrollarlo, simplemente en el propio main, para poder ver como funciona
lo pedido
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h> // Necesario para rand() y srand()

#define TAM 10

int numAleatorio();

int main()
{
    int vector[TAM];
    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
    {
        *(vector + i)=numAleatorio();
    }
    printf("Mostrando valores y direcciones de memoria:\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("El vector %i tiene asignado el numero %i y su direccion de memoria es %p\n",i+1,*(vector+i),(void *)(vector+i));
    }
    return 0;
}

int numAleatorio()
{
    return (rand() % 100 )+ 1 ;
}