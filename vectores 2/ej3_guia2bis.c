/*
Edad con mayor frecuencia
Enunciado:
Ingresar 200 edades en un vector (valores enteros positivos). Determinar cuál es la edad
que más se repite (la de mayor frecuencia) e informar ese valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamano 200
#define contadorEdad 100

int edades();
int main()
{
    srand(time(NULL));
    int personas[tamano];
    int frecuencia[contadorEdad]={0};

    for (int i = 0; i < tamano; i++)
    {
        personas[i]=edades();
        frecuencia[personas[i]]++;
    }

    int edadrepetida= 0;
    int maxfrecuencia=0;


    for (int i = 0; i < 90; i++)
    {
        if (frecuencia[i]>maxfrecuencia)
        {
            maxfrecuencia=frecuencia[i];
            edadrepetida= i;
        }
        
    }

    printf("La edad que mas se repite es: %d\n",edadrepetida);

    printf("Se repite %d veces\n",maxfrecuencia);

    printf("Aca estan guardadas todas las edades:\n");

    for (int i = 0; i < tamano; i++)
    {
        printf("Persona %d con edad %d\n",i+1,personas[i]);
    }
    
    return 0;

}

int edades()
{
    return (rand() % 90)+1;
}