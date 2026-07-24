#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASAJEROS 50
#define MAX_EMBARQUE 40

// Estructura del pasajero
typedef struct {
    int codigo;
    char nombre[30];
    char apellido[30];
    int dni;
    char destino[20];
    int prioridad; // 1 = preferencial, 0 = regular
} Pasajero;

// Prototipos de funciones
void cargarPasajeros(Pasajero v[], int n);
void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[], int n, int capacidad, int *cantEmbarque, int *cantEspera);
void mostrarLista(Pasajero v[], int n, char titulo[]);

int main() {
    Pasajero todos[MAX_PASAJEROS];
    Pasajero embarque[MAX_EMBARQUE];
    Pasajero espera[MAX_PASAJEROS];
    int capacidad;
    int cantEmbarque = 0, cantEspera = 0;

    srand(time(NULL)); // Inicializa números aleatorios

    // 1️⃣ Cargar los 50 pasajeros
    cargarPasajeros(todos, MAX_PASAJEROS);

    // 2️⃣ Pedir capacidad del avión
    do {
        printf("Ingrese la capacidad del avion (25 a 40): ");
        scanf("%d", &capacidad);
        if (capacidad < 25 || capacidad > 40)
            printf("Capacidad invalida. Debe ser entre 25 y 40.\n");
    } while (capacidad < 25 || capacidad > 40);

    // 3️⃣ Generar listas de embarque y espera
    generarListas(todos, embarque, espera, MAX_PASAJEROS, capacidad, &cantEmbarque, &cantEspera);

    // 4️⃣ Mostrar las listas
    mostrarLista(todos, MAX_PASAJEROS, "LISTA COMPLETA DE PASAJEROS");
    mostrarLista(embarque, cantEmbarque, "LISTA DE EMBARQUE");
    mostrarLista(espera, cantEspera, "LISTA DE ESPERA");

    return 0;
}

// -------------------------------------------------------------

void cargarPasajeros(Pasajero v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i].codigo = i + 1;
        sprintf(v[i].nombre, "Nombre%d", i + 1);
        sprintf(v[i].apellido, "Apellido%d", i + 1);
        v[i].dni = 30000000 + rand() % 5000000;
        strcpy(v[i].destino, "Bariloche");
        v[i].prioridad = rand() % 2; // 0 o 1 aleatorio
    }
    printf("✅ Se cargaron %d pasajeros automaticamente.\n\n", n);
}

// -------------------------------------------------------------

void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[],
                   int n, int capacidad, int *cantEmbarque, int *cantEspera) {

    int i;

    // 1️⃣ Agregar primero los de prioridad 1
    for (i = 0; i < n && *cantEmbarque < capacidad; i++) {
        if (todos[i].prioridad == 1) {
            embarque[*cantEmbarque] = todos[i];
            (*cantEmbarque)++;
        }
    }

    // 2️⃣ Luego llenar con los de prioridad 0 si quedan lugares
    for (i = 0; i < n && *cantEmbarque < capacidad; i++) {
        if (todos[i].prioridad == 0) {
            embarque[*cantEmbarque] = todos[i];
            (*cantEmbarque)++;
        }
    }

    // 3️⃣ El resto pasa a lista de espera
    for (i = 0; i < n; i++) {
        int encontrado = 0;
        // verificar si está en embarque
        for (int j = 0; j < *cantEmbarque; j++) {
            if (todos[i].codigo == embarque[j].codigo) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            espera[*cantEspera] = todos[i];
            (*cantEspera)++;
        }
    }
}

// -------------------------------------------------------------

void mostrarLista(Pasajero v[], int n, char titulo[]) {
    printf("\n==============================\n");
    printf("%s\n", titulo);
    printf("==============================\n");
    for (int i = 0; i < n; i++) {
        printf("%02d | %s %s | DNI: %d | Destino: %s | Prioridad: %s\n",
               v[i].codigo,
               v[i].nombre,
               v[i].apellido,
               v[i].dni,
               v[i].destino,
               v[i].prioridad ? "Preferencial" : "Regular");
    }
    printf("------------------------------\nTotal: %d pasajeros\n\n", n);
}
