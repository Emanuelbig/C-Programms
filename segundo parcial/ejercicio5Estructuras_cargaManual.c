#include <stdio.h>
#include <string.h>

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
void cargarPasajeros(Pasajero v[], int n);
void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[], int n, int capacidad, int *cantEmbarque, int *cantEspera);
void mostrarLista(Pasajero v[], int n, char titulo[]);

int main() {
    Pasajero todos[MAX_PASAJEROS];
    Pasajero embarque[MAX_EMBARQUE];
    Pasajero espera[MAX_PASAJEROS];
    int capacidad;
    int cantEmbarque = 0, cantEspera = 0;

    // 1️⃣ Cargar los 50 pasajeros manualmente
    cargarPasajeros(todos, MAX_PASAJEROS);

    // 2️⃣ Pedir capacidad del avión
    do {
        printf("\nIngrese la capacidad del avion (25 a 40): ");
        scanf("%d", &capacidad);
        if (capacidad < 25 || capacidad > 40)
            printf("❌ Capacidad invalida. Debe ser entre 25 y 40.\n");
    } while (capacidad < 25 || capacidad > 40);

    // 3️⃣ Generar listas
    generarListas(todos, embarque, espera, MAX_PASAJEROS, capacidad, &cantEmbarque, &cantEspera);

    // 4️⃣ Mostrar resultados
    mostrarLista(todos, MAX_PASAJEROS, "LISTA COMPLETA DE PASAJEROS");
    mostrarLista(embarque, cantEmbarque, "LISTA DE EMBARQUE");
    mostrarLista(espera, cantEspera, "LISTA DE ESPERA");

    return 0;
}

// -------------------------------------------------------------

void cargarPasajeros(Pasajero v[], int n) {
    printf("=== CARGA DE PASAJEROS ===\n");

    for (int i = 0; i < n; i++) {
        printf("\nPasajero #%d\n", i + 1);
        v[i].codigo = i + 1;

        printf("Nombre: ");
        getchar(); // limpia el salto de linea pendiente
        fgets(v[i].nombre, 30, stdin);
        v[i].nombre[strcspn(v[i].nombre, "\n")] = 0; // elimina el '\n'

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

        // Validar prioridad
        if (v[i].prioridad != 0 && v[i].prioridad != 1) {
            printf("⚠️ Valor invalido, se establece prioridad regular.\n");
            v[i].prioridad = 0;
        }
    }

    printf("\n✅ Se cargaron %d pasajeros correctamente.\n\n", n);
}

// -------------------------------------------------------------

void generarListas(Pasajero todos[], Pasajero embarque[], Pasajero espera[],
                   int n, int capacidad, int *cantEmbarque, int *cantEspera) {

    int i;

    // 1️⃣ Primero los de prioridad 1
    for (i = 0; i < n && *cantEmbarque < capacidad; i++) {
        if (todos[i].prioridad == 1) {
            embarque[*cantEmbarque] = todos[i];
            (*cantEmbarque)++;
        }
    }

    // 2️⃣ Luego los de prioridad 0
    for (i = 0; i < n && *cantEmbarque < capacidad; i++) {
        if (todos[i].prioridad == 0) {
            embarque[*cantEmbarque] = todos[i];
            (*cantEmbarque)++;
        }
    }

    // 3️⃣ Los demás van a lista de espera
    for (i = 0; i < n; i++) {
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
