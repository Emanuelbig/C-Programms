#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX 10
#define MIN 1
#define CAP_MAX 5
/*
Desarrollar un programa en lenguaje C que utilice vectores y funciones para resolver el siguiente problema:

1.Se debe cargar un vector de 5 posiciones con números enteros aleatorios
generados entre 1 y 10, sin que se repitan.
2.El proceso de generación debe realizarse automáticamente utilizando la función rand(), y finalizar cuando el vector esté completo con 5 valores únicos.
3.Mientras se generan los números, se debe llevar el registro de cuántas veces
fue generado cada número que finalmente se guardó en el vector principal
con un vector paralelo llamado contador.

Para esto se utilizará un segundo vector de 5 posiciones( contador),
donde cada posición indicará la cantidad de veces que se generó el número
correspondiente del primer vector (incluyendo repeticiones previas).

Si un número se genera más de una vez pero ya está en el vector principal,
no se vuelve a guardar, pero sí se incrementa su contador correspondiente en el segundo vector.
4.Al finalizar, el programa debe mostrar:
El contenido del vector principal (con los 5 números generados sin repeticiones).
El contenido del vector de conteo, en paralelo, mostrando cuántas veces
fue generado cada número del vector principal hasta completar el llenado.
*/
// ───── Prototipos ─────
int randInt(int min, int max);
void cargaVector(int v[MAX], int contador[MAX], int m);
int ExisteValor(int num, int v[MAX], int m);
void MostrarVector(int v[CAP_MAX], int m, char *titulo);
// ──────────────────────
int main()
{
    int vec[CAP_MAX];
    int contador[CAP_MAX] = {0};         // Vector para contar las repeticiones de cada número
    srand(time(NULL));                   // Inicializar la semilla aleatoria para números pseudo-aleatorios
    cargaVector(vec, contador, CAP_MAX); // Cargar el vector con números aleatorios
    MostrarVector(vec, CAP_MAX, "Contenido del Vector Datos");         // Mostrar el contenido del vector
    MostrarVector(contador, CAP_MAX,"Contenido del Vector contador" ); // Mostrar el contenido del vector de conteo
    return 0;
}

int randInt(int min, int max)
{
    int temp;
    // chequeo de los limites cualquier cosa se invierte
    if (min > max)
    { // Si el mínimo es mayor que el máximo, los intercambiamos
        // para asegurar que min sea menor o igual a max
        temp = min;
        min = max;
        max = temp;
    }
    return rand() % (max - min + 1) + min;
}
void cargaVector(int v[CAP_MAX], int contador[CAP_MAX], int m)
{
    int num, i = 0, pos;
    while (i < m)
    {
        num = randInt(MIN, MAX);      // Generar un número aleatorio entre 1 y 10
        pos = ExisteValor(num, v, i); // Verificar si el número ya existe en el vector
        if (pos!=-1)                      // Verificar si el número ya existe en el vector
        {
            contador[pos]++; // Si existe, incrementar el contador en la posición correspondiente
        }
        else
        {                 
            v[i] = num;    // Si no existe, lo agrego al vector
            contador[i]++; // Incrementar el contador del número generado
            i++;           // Incrementar el índice del vector principal
        }
        printf("num=%d, pos=%d, contador[%d]= %d, v[%d]=%d\n", num, pos, i-1, contador[i-1], i-1, v[i-1]);
        //getch(); // Esperar a que el usuario presione una tecla para continuar
    }
}

void MostrarVector(int v[CAP_MAX], int m, char *titulo) // aqui lo muestro los vectores cada uno con su titulo
{
    int i;
    printf("\n %s\n",titulo); // Titulo del vector a mostrar
    for (i = 0; i < m; i++)
    {
        printf("vec[%2d]=%2d\n ", i, v[i]);
    }
    printf("\n------------------------\n");
}

int ExisteValor(int num, int v[CAP_MAX], int TamActual) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (TamActual==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < TamActual; i++)
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