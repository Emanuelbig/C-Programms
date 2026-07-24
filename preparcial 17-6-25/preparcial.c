/*
Programacion 1
Desarrollar un programa en lenguaje C que utilice vectores y funciones para resolver el siguiente problema:
1. Se debe cargar un vector de 5 posiciones con numeros enteros generados al azar entre 1 y 10, sin que se repitan
2. El proceso de generacion debe realizarse automaticamente usando la funcion rand(), hasta que el vector se llene
con 5 valores unicos. El ingreso debe cortarse automaticamente al cumplir esta condicion
3. Existe un segundo vector de 5 posiciones, en el cual deberan contabilizar la cantidad de veces que salieron los
numeros generados hasta llegar a completar el primer vector.
4. Al finalizar la carga el programa debe :asm

Mostrar el contenido del vector de 5 elementos sin repeticiones.
Mostrar el segundo vector en paralelo con el primer, donde cada posicion indique cuantas veces fue generado cada numero
que se encuentra en el vector 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAMANO 5

int NumeroAleatorio();
void titulo();
int existe (int vector [], int tam, int num);
int main()
{
    
    int valores[TAMANO], contador[TAMANO] = {0}; // vector 5 posiciones
    int i, j, pos =0;
    srand(time(NULL));
    titulo();
    // Mostrar contenido del vector sin repeticiones.
    // Mostrar el segundo vector donde indique la posicion de cada numero.

    while (pos < 5)
    {
        valores[TAMANO] = NumeroAleatorio();
        if(!existe(valores, pos, NumeroAleatorio()))
        {
            valores[pos]=NumeroAleatorio();
            pos++;
        }
    }
    printf("Vector con numeros unicos");
    
    for (int i = 1; i <= 5; i++)
    {
        printf("%d",valores[i]);
        for ( j = 0; j < 5; j++)
        {
            if (valores[i]==NumeroAleatorio())
            {
                contador [i]++;
            }
            
        }
        
    }
    printf("\n");
    printf("Numeros | Frecuencia\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%d\t | %d\n",valores[i], contador[i]);
    }
    
    return 0;
}

int NumeroAleatorio()
{
    int numAle = (rand() % 10) + 1;
    int resultado = numAle;
    return resultado;
}

void titulo()
{
    printf("Bienvenido al Preparcial de la muerte\n\n");
}

int existe (int vector [], int tam, int num)
{
    for (int i = 0; i < tam; i++)
    {
        if (vector [i] == num)
        {
            return 1;
        }
        
    }
    return 0;
}