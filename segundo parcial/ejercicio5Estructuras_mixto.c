#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASAJEROS 50
#define MAX_EMBARQUE 40

typedef struct {
    int codigo;
    char nombre[30];
    char apellido[30];
    int dni;
    char destino[20];
    int prioridad; // 1 = preferencial, 0 = regular
} Pasajero;

// Prototipos
void cargarPasajerosManual(Pasajero v[], int n);
void cargarPasajerosAleatorio(Pasajero v[], int n);
void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[], int n, int capacidad, int *cantEmbarque, int *cantEspera);
void mostrarLista(Pasajero v[], int n, char titulo[]);

int main() {
    srand(time(NULL)); // inicializa números aleatorios

    Pasajero todos[MAX_PASAJEROS];
    Pasajero embarque[MAX_EMBARQUE];
    Pasajero espera[MAX_PASAJEROS];
    int capacidad;
    int cantEmbarque = 0, cantEspera = 0;
    int modo;

    printf("=== GESTION DE PASAJEROS - AEROSUR ===\n");
    printf("1. Carga manual\n2. Carga aleatoria\nSeleccione modo: ");
    scanf("%d", &modo);

    if (modo == 1) {
        cargarPasajerosManual(todos, MAX_PASAJEROS);
    } else {
        cargarPasajerosAleatorio(todos, MAX_PASAJEROS);
    }

    // Capacidad del avión
    do {
        printf("\nIngrese la capacidad del avion (25 a 40): ");
        scanf("%d", &capacidad);
        if (capacidad < 25 || capacidad > 40)
            printf("❌ Capacidad invalida. Debe ser entre 25 y 40.\n");
    } while (capacidad < 25 || capacidad > 40);

    // Generar listas
    generarListas(todos, embarque, espera, MAX_PASAJEROS, capacidad, &cantEmbarque, &cantEspera);

    // Mostrar resultados
    mostrarLista(todos, MAX_PASAJEROS, "LISTA COMPLETA DE PASAJEROS");
    mostrarLista(embarque, cantEmbarque, "LISTA DE EMBARQUE");
    mostrarLista(espera, cantEspera, "LISTA DE ESPERA");

    return 0;
}

// -------------------------------------------------------------
// CARGA MANUAL
void cargarPasajerosManual(Pasajero v[], int n) {
    printf("\n=== CARGA MANUAL DE PASAJEROS ===\n");

    for (int i = 0; i < n; i++) {
        printf("\nPasajero #%d\n", i + 1);
        v[i].codigo = i + 1;

        printf("Nombre: ");
        getchar();
        fgets(v[i].nombre, 30, stdin);
        v[i].nombre[strcspn(v[i].nombre, "\n")] = 0;

        printf("Apellido: ");
        fgets(v[i].apellido, 30, stdin);
        v[i].apellido[strcspn(v[i].apellido, "\n")] = 0;

        printf("DNI: ");
        scanf("%d", &v[i].dni);

        printf("Destino: ");
        getchar();
        fgets(v[i].destino, 20, stdin);
        v[i].destino[strcspn(v[i].destino, "\n")] = 0;

        printf("Prioridad (1 = preferencial, 0 = regular): ");
        scanf("%d", &v[i].prioridad);

        if (v[i].prioridad != 0 && v[i].prioridad != 1) {
            printf("⚠️ Valor invalido, se establece prioridad regular.\n");
            v[i].prioridad = 0;
        }
    }
    printf("\n✅ Se cargaron %d pasajeros manualmente.\n", n);
}

// -------------------------------------------------------------
// CARGA ALEATORIA
void cargarPasajerosAleatorio(Pasajero v[], int n) {
    char *nombres[] = {"Juan", "Ana", "Luis", "Sofia", "Carlos", "Lucia", "Pedro", "Maria", "Diego", "Valentina"};
    char *apellidos[] = {"Perez", "Gomez", "Lopez", "Diaz", "Rodriguez", "Fernandez", "Mendez", "Ruiz", "Silva", "Torres"};
    char *destinos[] = {"Bariloche", "Cordoba", "Mendoza", "Salta", "Iguazu"};

    printf("\n=== CARGA AUTOMATICA DE PASAJEROS ===\n");

    for (int i = 0; i < n; i++) {
        v[i].codigo = i + 1;
        strcpy(v[i].nombre, nombres[rand() % 10]);
        strcpy(v[i].apellido, apellidos[rand() % 10]);
        v[i].dni = 10000000 + rand() % 30000000;
        strcpy(v[i].destino, destinos[rand() % 5]);
        v[i].prioridad = rand() % 2;
    }

    printf("✅ Se generaron %d pasajeros aleatoriamente.\n", n);
}

// -------------------------------------------------------------
// GENERAR LISTAS
void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[],
                   int n, int capacidad, int *cantEmbarque, int *cantEspera) {

    // Primero los de prioridad 1
    for (int i = 0; i < n && *cantEmbarque < capacidad; i++) {
        if (todos[i].prioridad == 1) {
            embarque[*cantEmbarque] = todos[i];
            (*cantEmbarque)++;
        }
    }

    // Luego los de prioridad 0
    for (int i = 0; i < n && *cantEmbarque < capacidad; i++) {
        if (todos[i].prioridad == 0) {
            embarque[*cantEmbarque] = todos[i];
            (*cantEmbarque)++;
        }
    }

    // Los demás van a lista de espera
    for (int i = 0; i < n; i++) {
        int estaEnEmbarque = 0;
        for (int j = 0; j < *cantEmbarque; j++) {
            if (todos[i].codigo == embarque[j].codigo) {
                estaEnEmbarque = 1;
                break;
            }
        }
        if (!estaEnEmbarque) {
            espera[*cantEspera] = todos[i];
            (*cantEspera)++;
        }
    }
}

// -------------------------------------------------------------
// MOSTRAR LISTA
void mostrarLista(Pasajero v[], int n, char titulo[]) {
    printf("\n==============================\n");
    printf("%s\n", titulo);
    printf("==============================\n");

    for (int i = 0; i < n; i++) {
        printf("%02d | %-10s %-10s | DNI: %d | Destino: %-10s | Prioridad: %s\n",
               v[i].codigo,
               v[i].nombre,
               v[i].apellido,
               v[i].dni,
               v[i].destino,
               v[i].prioridad ? "Preferencial" : "Regular");
    }

    printf("------------------------------\nTotal: %d pasajeros\n\n", n);
}
