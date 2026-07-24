/*Ejercicio 1: Contar números pares e impares
Objetivo: Practicar el uso de condicionales y conteo.
Consigna:
1. Crear un vector de 100 elementos cargado automáticamente con números
enteros entre 1 y 500.
2. Contar cuántos de esos números son pares y cuántos son impares.
3. A su vez guardar los pares en un vector de pares e impares en un vector de
impares
4. Mostrar los resultados por pantalla de estos vectores.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define elementos 100

int numAleatorio();
void cargarVector(int v[],int tam);
void separarPareImpar(int v[], int tam, int vecpar[], int vecimpar[], int *contadorp, int *contadori);

int main()
{
    int vector[elementos];
    int vectorpar[elementos];
    int vectorimpar[elementos];
    srand(time(NULL));
    int contadorpar = 0;
    int contadorimpar = 0;

    
    /*for (int i = 0; i < elementos; i++)
    {
        vector[i] = numAleatorio();
    }*/

    cargarVector(vector,elementos);//funcion que carga el vector general

    /*for (int i = 0; i < elementos; i++)
    {
        if (vector[i] % 2 == 0)
        {
            vectorpar[contadorpar] = vector[i];
            contadorpar++;
        }
        else
        {
            vectorimpar[contadorimpar] = vector[i];
            contadorimpar++;
        }
    }*/

    separarPareImpar(vector, elementos, vectorpar, vectorimpar, &contadorpar, &contadorimpar); //separamos con mod 2 = 0

    printf("Todos los numeros del vector general:\n");
    for (int i = 0; i < elementos; i++)
    {
        printf("%d\t|\n", vector[i]);
    }

    printf("Cantidad de numeros pares: %d\n",contadorpar);
    printf("Cantidad de numeros impares: %d\n",contadorimpar);

    printf("Vector de numeros pares:\n");
    for (int i = 0; i < contadorpar; i++)
    {
        printf("%d\t|\n", vectorpar[i]);
    }
        printf("Vector de numeros impares:\n");
    for (int i = 0; i < contadorimpar; i++)
    {
        printf("%d\t|\n", vectorimpar[i]);
    }
}

int numAleatorio()
{
    return (rand() % 500) + 1;
}

void cargarVector(int v[],int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i] = numAleatorio();
    }
}

void separarPareImpar(int v[], int tam, int vecpar[], int vecimpar[], int *contadorp, int *contadori)
{
        for (int i = 0; i < tam; i++)
    {
        if (v[i] % 2 == 0)
        {
            vecpar[*contadorp] = v[i];
            contadorp++;
        }
        else
        {
            vecimpar[*contadori] = v[i];
            contadori++;
        }
    }
}
