/*
Programacion 1
Desarrollar un programa en lenguaje C que utilice vectores y funciones para resolver el siguiente problema:
1. Se debe cargar un vector de 5 posiciones con numeros enteros generados al azar entre 1 y 10, sin que se repitan
2. El proceso de generacion debe realizarse automaticamente usando la funcion rand(), hasta que el vector se llene
con 5 valores unicos. El ingreso debe cortarse automaticamente al cumplir esta condicion
3. Existe un segundo vector de 5 posiciones, en el cual deberan contabilizar la cantidad de veces que salieron los
numeros generados hasta llegar a completar el primer vector.
4. Al finalizar la carga el programa debe :

Mostrar el contenido del vector de 5 elementos sin repeticiones.
Mostrar el segundo vector en paralelo con el primer, donde cada posicion indique cuantas veces fue generado cada 
numero que se encuentra en el vector 1.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define tamano 5

//1. Se debe cargar un vector de 5 posiciones con numeros enteros generados al azar entre 1 y 10, sin 
//que se repitan

int numAleatorio();
int existe(int vector[],int tam, int numero);

int main()
{
    int vector[tamano];
    int contador[tamano];
    int apariciones[11]={0}; // índices: 0 1 2 3 4 5 6 7 8 9 10
    int pos=0;
    srand(time(NULL));

    while (pos<tamano)
    {
        int nuevo = numAleatorio();
        apariciones[nuevo]++;  // cuento cuántas veces salió ese número

        if (!existe(vector,pos,nuevo))//"Si el número NO EXISTE en el vector..."
        {
            vector[pos]=nuevo;
            contador[pos] = apariciones[nuevo];  // guardo cuántas veces salió ese número
            pos++;
        }
        
    }

    printf("\nNumero\t| Veces generado hasta ser guardado\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < tamano; i++)
    {
        printf("%d\t| %d\n", vector[i], contador[i]);
    }
    
    //3. Existe un segundo vector de 5 posiciones, en el cual deberan contabilizar la cantidad de veces que 
    //salieron los numeros generados hasta llegar a completar el primer vector.
    
}

int numAleatorio()
{
    return (rand() %10) + 1;
}

int existe(int vector[],int tam, int numero)
{
    for (int i = 0; i < tam; i++)
    {
        if (vector[i]==numero)
        {
            return 1; //si existe
        }
        
    }
    return 0;//No existe
}