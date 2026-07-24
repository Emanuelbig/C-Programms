#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASAJEROS 20

typedef struct {
    int dni;
    char nombre[30];
    char destino[30];
    int asiento;
    int activo; // 1 = pasajero confirmado, 0 = canceló el vuelo
} Pasajero;

// Prototipos
void alta(Pasajero pasajeros[], int *n);
void baja(Pasajero pasajeros[], int n);
void modificacion(Pasajero pasajeros[], int n);
void listarActivos(Pasajero pasajeros[], int n);
void listarPorDestino(Pasajero pasajeros[], int n);
void listarGeneral(Pasajero pasajeros[], int n);
int asientoOcupado(Pasajero pasajeros[], int n, int asiento);

int main() {
    Pasajero pasajeros[MAX_PASAJEROS];
    int n = 0; // cantidad de pasajeros cargados
    int opcion;

    do {
        printf("\n===== SISTEMA DE VENTA DE PASAJES =====\n"
               "1. Alta (venta de pasaje)\n"
               "2. Baja lógica (cancelación)\n"
               "3. Modificación de datos\n"
               "4. Listado de pasajeros activos\n"
               "5. Listado por destino\n"
               "6. Listado general\n"
               "0. Salir\n"
               "Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch (opcion) {
            case 1: alta(pasajeros, &n); break;
            case 2: baja(pasajeros, n); break;
            case 3: modificacion(pasajeros, n); break;
            case 4: listarActivos(pasajeros, n); break;
            case 5: listarPorDestino(pasajeros, n); break;
            case 6: listarGeneral(pasajeros, n); break;
            case 0: printf("Saliendo del sistema...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    return 0;
}

// ===============================================
// ALTA - VENTA DE PASAJE
// ===============================================
void alta(Pasajero pasajeros[], int *n) {
    if (*n >= MAX_PASAJEROS) {
        printf("No se pueden cargar más pasajeros (vuelo completo).\n");
        return;
    }

    Pasajero nuevo;
    printf("Ingrese DNI: ");
    scanf("%d", &nuevo.dni);
    getchar();

    // Verificar si el DNI ya está cargado
    for (int i = 0; i < *n; i++) {
        if (pasajeros[i].dni == nuevo.dni) {
            printf("Ya existe un pasajero con ese DNI.\n");
            return;
        }
    }

    printf("Ingrese nombre: ");
    fgets(nuevo.nombre, 30, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;

    printf("Ingrese destino: ");
    fgets(nuevo.destino, 30, stdin);
    nuevo.destino[strcspn(nuevo.destino, "\n")] = 0;

    printf("Ingrese número de asiento (1 a 20): ");
    scanf("%d", &nuevo.asiento);
    getchar();

    // Validar asiento disponible
    if (nuevo.asiento < 1 || nuevo.asiento > 20) {
        printf("Número de asiento inválido.\n");
        return;
    }
    if (asientoOcupado(pasajeros, *n, nuevo.asiento)) {
        printf("El asiento %d ya está ocupado.\n", nuevo.asiento);
        return;
    }

    nuevo.activo = 1;
    pasajeros[*n] = nuevo;
    (*n)++;

    printf("Pasajero registrado correctamente.\n");
}

// ===============================================
// BAJA LÓGICA - CANCELACIÓN
// ===============================================
void baja(Pasajero pasajeros[], int n) {
    int dni;
    printf("Ingrese el DNI del pasajero a cancelar: ");
    scanf("%d", &dni);
    getchar();

    for (int i = 0; i < n; i++) {
        if (pasajeros[i].dni == dni) {
            if (pasajeros[i].activo == 0) {
                printf("El pasajero ya estaba cancelado.\n");
                return;
            }
            pasajeros[i].activo = 0;
            printf("Pasajero %s canceló su vuelo.\n", pasajeros[i].nombre);
            return;
        }
    }
    printf("No se encontró un pasajero con ese DNI.\n");
}

// ===============================================
// MODIFICACIÓN - CAMBIAR DESTINO O ASIENTO
// ===============================================
void modificacion(Pasajero pasajeros[], int n) {
    int dni;
    printf("Ingrese el DNI del pasajero a modificar: ");
    scanf("%d", &dni);
    getchar();

    for (int i = 0; i < n; i++) {
        if (pasajeros[i].dni == dni) {
            if (pasajeros[i].activo == 0) {
                printf("El pasajero canceló su vuelo, no puede modificarse.\n");
                return;
            }

            printf("Modificar destino (actual: %s): ", pasajeros[i].destino);
            fgets(pasajeros[i].destino, 30, stdin);
            pasajeros[i].destino[strcspn(pasajeros[i].destino, "\n")] = 0;

            int nuevoAsiento;
            printf("Modificar asiento (actual: %d): ", pasajeros[i].asiento);
            scanf("%d", &nuevoAsiento);
            getchar();

            if (nuevoAsiento < 1 || nuevoAsiento > 20) {
                printf("Número de asiento inválido.\n");
                return;
            }
            if (asientoOcupado(pasajeros, n, nuevoAsiento) && nuevoAsiento != pasajeros[i].asiento) {
                printf("El asiento %d ya está ocupado.\n", nuevoAsiento);
                return;
            }

            pasajeros[i].asiento = nuevoAsiento;
            printf("Datos modificados correctamente.\n");
            return;
        }
    }

    printf("No se encontró un pasajero con ese DNI.\n");
}

// ===============================================
// LISTADO DE PASAJEROS ACTIVOS
// ===============================================
void listarActivos(Pasajero pasajeros[], int n) {
    printf("\n--- Pasajeros activos (vuelo confirmado) ---\n");
    for (int i = 0; i < n; i++) {
        if (pasajeros[i].activo == 1) {
            printf("DNI: %d | Nombre: %s | Destino: %s | Asiento: %d\n",
                   pasajeros[i].dni, pasajeros[i].nombre, pasajeros[i].destino, pasajeros[i].asiento);
        }
    }
}

// ===============================================
// LISTADO POR DESTINO
// ===============================================
void listarPorDestino(Pasajero pasajeros[], int n) {
    char destino[30];
    printf("Ingrese destino: ");
    fgets(destino, 30, stdin);
    destino[strcspn(destino, "\n")] = 0;

    printf("\n--- Pasajeros con destino a %s ---\n", destino);
    int encontrados = 0;
    for (int i = 0; i < n; i++) {
        if (pasajeros[i].activo == 1 && strcmp(pasajeros[i].destino, destino) == 0) {
            printf("DNI: %d | Nombre: %s | Asiento: %d\n",
                   pasajeros[i].dni, pasajeros[i].nombre, pasajeros[i].asiento);
            encontrados = 1;
        }
    }

    if (!encontrados)
        printf("No se encontraron pasajeros activos con ese destino.\n");
}

// ===============================================
// LISTADO GENERAL (activos e inactivos)
// ===============================================
void listarGeneral(Pasajero pasajeros[], int n) {
    printf("\n--- Listado general ---\n");
    for (int i = 0; i < n; i++) {
        printf("DNI: %d | Nombre: %s | Destino: %s | Asiento: %d | Estado: %s\n",
               pasajeros[i].dni, pasajeros[i].nombre, pasajeros[i].destino,
               pasajeros[i].asiento, pasajeros[i].activo ? "Activo" : "Cancelado");
    }
}

// ===============================================
// FUNCIÓN AUXILIAR - Verifica si un asiento está ocupado
// ===============================================
int asientoOcupado(Pasajero pasajeros[], int n, int asiento) {
    for (int i = 0; i < n; i++) {
        if (pasajeros[i].activo == 1 && pasajeros[i].asiento == asiento) {
            return 1; // ocupado
        }
    }
    return 0; // libre
}
