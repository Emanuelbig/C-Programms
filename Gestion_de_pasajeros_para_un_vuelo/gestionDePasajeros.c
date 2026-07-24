/*
Gestión de Pasajeros para un Vuelo
La aerolínea AeroSur debe organizar el embarque de pasajeros para un vuelo con destino
a Bariloche.
En el sistema se registran inicialmente los 50 pasajeros que adquirieron su boleto, y se
debe preparar la lista de embarque y la lista de espera según la capacidad de la
aeronave.

Descripción del problema:
1. El programa debe cargar los datos de 50 pasajeros, cada uno con la siguiente
información:

o Código del pasajero (entero)
o Nombre y apellido
o DNI
o Destino
o Prioridad de embarque (1 = preferencial, 0 = regular)

2. Luego, el sistema solicitará al usuario ingresar la capacidad de la aeronave, que
puede ser entre 25 y 40 pasajeros.

3. A partir de los datos cargados, se deberán generar dos nuevas listas:
o Lista de embarque: contendrá a los primeros pasajeros que podrán
abordar el vuelo (según el orden de registro y prioridad).
o Lista de espera: contendrá a los pasajeros que no podrán viajar en este
vuelo y deberán esperar un próximo.

4. Finalmente, el programa deberá mostrar:
o La lista completa de pasajeros registrados.
o La lista de embarque (capacidad completa de la nave).
o La lista de espera (resto de pasajeros).
pág. 2

Estructura sugerida
Se deberá definir una estructura para representar a cada pasajero:

typedef struct {
 int codigo;
 char nombre[30];
 char apellido[30];
 int dni;
 char destino[20];
 int prioridad; // 1 = preferencial, 0 = regular
} Pasajero;

Se recomienda utilizar vectores de estructuras para almacenar las tres listas:
• Pasajero todos[50];
• Pasajero embarque[40];
• Pasajero espera[50];
Funcionalidades mínimas sugeridas:
• void cargarPasajeros(Pasajero v[], int n);
• void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[], int n,
int capacidad);
• void mostrarLista(Pasajero v[], int n, char titulo[]);
Consideraciones opcionales (para ampliar):
• Priorizar pasajeros con prioridad 1 al llenar la lista de embarque.
• Validar que la capacidad ingresada esté entre 25 y 40.
• Generar datos aleatorios si se desea evitar ingreso manual.
¿Para qué sirve el campo prioridad?
El campo sirve para distinguir pasajeros preferenciales de los pasajeros comunes.
• Prioridad 1 → Pasajeros preferenciales (embarcan primero).
• Prioridad 0 → Pasajeros regulares (embarcan si quedan asientos disponibles).
Este dato lo pueden generar en forma aleatoria
¿Cómo se decide quién embarca y quién queda en lista de espera?
Cuando cargas los 50 pasajeros, el programa debe llenar la lista de embarque
respetando dos criterios:
1. Primero entran los pasajeros con prioridad 1 (hasta llenar la capacidad del avión).
2. Si aún quedan asientos, se completan con los pasajeros con prioridad 0, en
orden de registro (es decir, como si fuera una cola natural).
Una vez que se completa la capacidad del avión, el resto de los pasajeros pasa a la lista
de espera.


Crear todos los datos de forma aleatoria y no tener que ingresarlos a mano

*/

// Las librerias
#include <stdio.h>
#include <math.h>
#include <string.h>  // Para funciones de manejo de cadenas como strcmp y strcpy
#include <stdbool.h> // Para usar el tipo de dato booleano (true/false)
#include <ctype.h>   // Para funciones como tolower, toupper, etc. (no se usa pero es bueno tenerlo)
#include <stdlib.h>  // Para system("clear") o system("cls")
#include <time.h>    // Para la función time() y srand()

/* Constantes globales */
#define TODOS 50
#define EMBARQUE 40
#define ESPERA 50

typedef struct
{
    int codigo;
    char nombre[30];
    char apellido[30];
    int dni;
    char destino[20];
    int prioridad; // 1 = preferencial, 0 = regular
} Pasajero;

/*Prototipos*/
// void cargarPasajeros(Pasajero v[], int n); forma manual
void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[], int n, int capacidad);
void mostrarLista(Pasajero v[], int n, char titulo[]);
void ale(int vec[], int n, int min, int max);
void generarDatosAleatorios(Pasajero v[], int n); //para organizar mejor


int main()
{

    Pasajero todos[TODOS];
    Pasajero embarque[EMBARQUE];
    Pasajero espera[ESPERA];
    int capacidad;
    //int aleatorios[TODOS];

    srand(time(NULL)); // semilla para los numeros aleatorios
    generarDatosAleatorios(todos, TODOS); // genero todos los datos aleatorios

    // Pedimos al usuario la capacidad de la aeronave (entre 25 y 40)
    printf("Ingrese la capacidad de la aeronave (entre 25 y 40): ");
    scanf("%d", &capacidad);

    while (capacidad < 25 || capacidad > 40)
    {
        printf("Capacidad invalida. Ingrese un valor entre 25 y 40: ");
        scanf("%d", &capacidad);
    }

    // cargarPasajeros(todos, TODOS); si lo quiero hacer de forma manual.
    generarListas(todos, embarque, espera, TODOS, capacidad);
    mostrarLista(todos, TODOS, "Lista Completa de Pasajeros:");
    mostrarLista(embarque, capacidad, "Lista de Embarque:");
    mostrarLista(espera, ESPERA, "Lista de Espera:");

    return 0;
}

/*void cargarPasajeros(Pasajero v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese los datos del pasajero %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &v[i].codigo);
        printf("Nombre: ");
        scanf("%s", v[i].nombre);
        printf("Apellido: ");
        scanf("%s", v[i].apellido);
        printf("DNI: ");
        scanf("%d", &v[i].dni);
        printf("Destino: ");
        scanf("%s", v[i].destino);
        printf("Prioridad (1 = preferencial, 0 = regular): ");
        scanf("%d", &v[i].prioridad);
        while (v[i].prioridad != 0 && v[i].prioridad != 1)
        {
            printf("Prioridad invalida. Ingrese 1 para preferencial o 0 para regular: ");
            scanf("%d", &v[i].prioridad);
        }
        printf("\n");
    }
}*/

void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[], int n, int capacidad)
{
    int contEmbarque = 0;
    int contEspera = 0;

    // Primero llenamos con pasajeros de prioridad 1
    for (int i = 0; i < n; i++)
    {
        if (todos[i].prioridad == 1 && contEmbarque < capacidad)
        {
            embarque[contEmbarque++] = todos[i];
        }
    }

    // Segundo llenamos con pasajeros de prioridad 0
    for (int i = 0; i < n; i++)
    {
        if (todos[i].prioridad == 0 && contEmbarque < capacidad)
        {
            embarque[contEmbarque++] = todos[i];
        }
        else if (contEmbarque >= capacidad)
        {
            espera[contEspera++] = todos[i];
        }
    }
}

void mostrarLista(Pasajero v[], int n, char titulo[])
{

    printf("%s\n", titulo);
    for (int i = 0; i < n; i++)
    {
        printf("Codigo: %d, Nombre: %s, Apellido: %s, DNI: %d, Destino: %s, Prioridad: %d\n",
               v[i].codigo, v[i].nombre, v[i].apellido, v[i].dni, v[i].destino, v[i].prioridad);
    }
    printf("\n");
}

void ale(int vec[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        vec[i] = (rand() % (max - min + 1)) + min;
    }
    // Ordenar el vector de forma ascendente
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] > vec[j])
            {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    // Eliminar duplicados
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] != vec[i + 1])
        {
            vec[j++] = vec[i];
        }
    }
    n = j;
}

void generarDatosAleatorios(Pasajero v[], int n)
{
    const char *nombres[] = {"Ana", "Luis", "Carlos", "Marta", "Sofia", "Jorge", "Lucia", "Pedro", "Elena", "Diego"};
    const char *apellidos[] = {"Gomez", "Perez", "Rodriguez", "Lopez", "Garcia", "Martinez", "Sanchez", "Ramirez", "Torres", "Flores"};
    const char *destinos[] = {"Bariloche", "Cordoba", "Mendoza", "Salta", "Ushuaia", "Iguazu", "Rosario", "Mar del Plata", "Neuquen", "Tucuman"};
    int aleatorios[n];

    srand(time(NULL)); // semilla para los numeros aleatorios

    ale(aleatorios, n, 1, 1000); // genero codigos

    for (int i = 0; i < n; i++)
    {
        v[i].codigo = aleatorios[i];
        // Asignamos nombres, apellidos y destinos aleatorios
        strcpy(v[i].nombre, nombres[rand() % 10]);
        strcpy(v[i].apellido, apellidos[rand() % 10]);
        v[i].dni = aleatorios[i];
        strcpy(v[i].destino, destinos[rand() % 10]);
        v[i].prioridad = rand() % 2; // Prioridad aleatoria (0 o 1)
    }
}

/*Hecho por Ema*/