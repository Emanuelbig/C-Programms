/*
Ejercicio 4: Suma de múltiplos de X
Objetivo: Trabajar con condiciones y acumuladores.
Consigna:
1. Crear un vector de 70 elementos con números aleatorios entre 1 y 500.
2. Calcular la suma total de los elementos que sean múltiplos de X., donde X lo
decidirá el usuario.
3. Mostrar luego solo los elementos que son múltiplos de la elección del usuario y la
suma obtenida.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define indice 70

int numAle();
int cargarvector(int v[], int tam);
//int multiplosde3(int v[], int tam);
int main()
{
    int vector[indice];
    srand(time(NULL));
    cargarvector(vector, indice);
    int x;
    int suma=0;
    printf("Indique que multiplo:\n");
    scanf("%d",&x);

    int vectorx[indice];
    int j=0;// con j hice un nuevo espacio para guardar los elementos que eran multiplos de x

    for (int i = 0; i < indice; i++)
    {
        if (vector[i] % x ==0)
        {
            vectorx[j]=vector[i]; //aca voy guardando en j
            suma+=vector[i];
            j++; // y aca voy contando cada num multiplo de X.
        }
        
    }

    printf("Vector con elementos multiplos de %d\n",x);
    for (int i = 0; i < j; i++)//aca en ves de indice puse j que fue donde guarde la cantidad de elementos
    {
        printf("Vectorx[%d] con elemento valor: %d\n",i+1,vectorx[i]);
    }
    
    
    return 0;
}

int numAle()
{
    return (rand() % 500) +1;
}

int cargarvector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i] = numAle();
    }
    
    return 0;
}