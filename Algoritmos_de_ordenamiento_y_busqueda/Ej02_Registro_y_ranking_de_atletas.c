/*
    Se realiza una competencia de atletismo con 10 atletas. Por cada uno se conoce:
    
    -El ID de los atletas, como dato unico e irrepetible
    -El tiempo en segundos que tardo en completar la carrera.(vector numerico).

    Se pide:

    1. Cargar en 2 vectores paralelos:
        -El ID de los atletas.
        -El tiempo en segundos que tardo en completar la carrera. (vector numerico)
        
    2. Mostrar el listado original (ID y tiempo por atleta.)
    
    3.Ordenar los vectores de menor a mayor tiempo (el que corrio mas rapido primero), 
    manteniendo la relacion entre ID y tiempo.
    
    4.Mostrar el ranking ordenado, indicando la posicion 1,2 etc, nombre del atleta y su tiempo.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

const int CANTIDAD = 15;
//const int SEGUNDOS = 15;

int numAleatorio();

void CargarVector(int v[], int tam);

void CargarSinRepetirNumeros(int v[], int tam);

int ExisteValor(int num, int v[], int tam);

void MostrarVectores(int v[], int v2[], char v3[], int tam);

int main ()
{
    srand(time(NULL));
    int atletas[CANTIDAD], tiempo[CANTIDAD];
    //nombres de los atletas.
    char nombres_atletas[15][20]= {
        "Luciano", "Martina", "Rocio", "Juan", "Tomas",
        "Agustina", "Pedro", "Valentina", "Carlos", "Sofia", "Paula", "Fernando",
        "Ricardo", "Claudio", "Emanuel"
    };
    CargarSinRepetirNumeros(atletas, CANTIDAD);
    CargarVector(tiempo, CANTIDAD);

    MostrarVectores(atletas, tiempo, nombres_atletas, CANTIDAD);

    return 0;
}

int numAleatorio()
{
    return (rand() % 200 )+ 1 ;
}

void CargarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        v[i]=numAleatorio();
    }
    
}

void CargarSinRepetirNumeros(int v[], int tam)
{
    int num, i= 0;

    while (i<tam)
    {
        num = numAleatorio();
        ExisteValor(num, v, i);

        if (ExisteValor(num, v, i)==-1)
        {
            v[i]=num;
            i++;
    
        }
               
    }

    for (int i = 0; i < tam; i++)
    {
        printf("Numero ID atleta: %d\n", v[i]);
    }
    
}

int ExisteValor(int num, int v[], int tam) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (tam==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            if (v[i] == num) // Verificar si el número ya existe en el vector
            {
                return i;
                // Si existe, retornar la posicion donde se encuentra para despues incrementar
                // el contador en esa posicion en el vector contador
            }
        }
        return -1; // Si no existe, retornar -1 y como es un valor fuera de rango no se incrementa el contador
    }
}

void MostrarVectores(int v[], int v2[], char v3[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("ID: %d\t\tNombre Atleta: %c\t\tTiempo: %d\n",v[i],v3[i],v2[i]);
    }
    
}