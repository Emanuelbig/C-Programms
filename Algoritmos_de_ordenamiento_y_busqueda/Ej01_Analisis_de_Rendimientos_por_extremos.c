/*
    Se registraron las puntuaciones de 50 participantes en un certamen tecnico.
    Se desea analizar los mejores y peores desempenios.

    -Generar un vector de 50 elementos con valores aleatorios entre 1 y 500
    -Calcular y mostrar el promedio de los valores mas altos, inclusive 250 al 500
    y el promedio el de los mas bajos que 250.

    Utilizar subAlgoritmos y funciones para desarrollar el programa.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define PUNTUACIONES 50

int numAleatorio();

void CargarVector(int v[], int tam);

void OrdenarMenoraMayor(int v[], int tam);

void OrdenarMayoraMenor(int v[], int tam);

void MostrarVector(int v[], int tam);

void promedioPeores(int v[]);

void promedioMejores(int v[]);

int main ()
{
    srand(time(NULL));
    int participantes[PUNTUACIONES];
    CargarVector(participantes, PUNTUACIONES);
    OrdenarMenoraMayor(participantes, PUNTUACIONES);
//    MostrarVector(participantes, PUNTUACIONES);
    promedioPeores(participantes);
    OrdenarMayoraMenor(participantes, PUNTUACIONES);
    promedioMejores(participantes);

    return 0;
}

int numAleatorio()
{
    return (rand() % 500 )+ 1 ;
}

void CargarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]=numAleatorio();
    }
    
}

void MostrarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("vector1[%d] con valor %d\n",i+1,v[i]);
    }
    
}

void OrdenarMenoraMayor(int v[], int tam)
{
    for (int i = 0; i < tam -1; i++)
    {
        // Luego se compara sucesivamente con los demás elementos,
        // intercambiándolos cuando es necesario.
        for (int j = i+1 ; j < tam; j++)
        {
            if (v[i] > v[j]) 
            { // swap:
            int aux = v[j];
            v[j] = v[i]; // nuevo valor de pivote
            v[i] = aux;
            }
        }

        
        
    }

}

void OrdenarMayoraMenor(int v[], int tam)
{
    for (int i = 0; i < tam -1; i++)
    {
        // Luego se compara sucesivamente con los demás elementos,
        // intercambiándolos cuando es necesario.
        for (int j = i+1 ; j < tam; j++)
        {
            if (v[i] < v[j]) 
            { // swap:
            int aux = v[j];
            v[j] = v[i]; // nuevo valor de pivote
            v[i] = aux;
            }
        }

        
        
    }

}

void promedioPeores(int v[])
{
    int suma= 0, promedio;
    for (int i = 0; i < PUNTUACIONES - 25; i++)
    {
        suma += v[i];
    }
    promedio = suma / 25;

    printf("\nLas peores puntuaciones fueron:\n");
    for (int i = 0; i < PUNTUACIONES - 25; i++)
    {
        printf("numero %d , puntuacion: %d,\n",i+1,v[i]);
    }

    printf("\n El promedio de todos los peores fue: %d\n",promedio);
    
}

void promedioMejores(int v[])
{
    int suma= 0, promedio;
    for (int i = 0; i < PUNTUACIONES - 25; i++)
    {
        suma += v[i];
    }
    promedio = suma / 25;

    printf("\nLas mejores puntuaciones fueron:\n");
    for (int i = 0; i < PUNTUACIONES - 25; i++)
    {
        printf("numero %d , puntuacion: %d,\n",i+1,v[i]);
    }

    printf("\n El promedio de todos los mejores fue: %d\n",promedio);
    
}
