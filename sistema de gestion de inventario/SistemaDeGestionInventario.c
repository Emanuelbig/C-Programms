/*
Material: Programacion I
Practica Estructuras: Sistema de Gestion de Inventario
Alumno: Emanuel Morano Sole
INSPT UTN
*/

// Las librerias
#include <stdio.h>
#include <math.h>
#include <string.h>  // Para funciones de manejo de cadenas como strcmp y strcpy
#include <stdbool.h> // Para usar el tipo de dato booleano (true/false)
#include <ctype.h>   // Para funciones como tolower, toupper, etc. (no se usa pero es bueno tenerlo)
#include <stdlib.h>  // Para system("clear") o system("cls")

/* Constantes globales */
#define MAX_NOMBRE 50
#define MAX_TIPO 30
#define MAX_ITEMS 100
#define PESO_MAXIMO 50.0f

// Estructura para representar un item
typedef struct
{
    char nombre[MAX_NOMBRE];
    char tipo[MAX_TIPO];
    int valor;
    float peso;
    int rareza;
    bool activo; // Para la baja lógica
} Item;

// Prototipos
void mostrarMenu();
void limpiarBufferEntrada();
float calcularPesoActual(const Item inventario[], int numItems);
void agregarItem(Item[], int *numItems);
void listarItems(Item inventario[], int *numItems);
void buscarPorNombre(Item inventario[], int *numItems);
void listarPorTipo(Item inventario[], int *numItems);
void calcularValorTotal(Item inventario[], int *numItems);
void darDeBajaItem(Item inventario[], int *numItems);
void ordenarInventario(Item inventario[], int *numItems);

// Main
int main()
{
    Item inventario[MAX_ITEMS]; // Vector que almacena todos los ítems.
    int numItems = 0;           // Contador de cuántos ítems hemos agregado.
    int opcion;

    do
    {
        mostrarMenu();
        printf("Ingrese una opcion ⚔️ 👑: \n");
        scanf("%d", &opcion);
        limpiarBufferEntrada(); // para leer cadenas después.

// Limpiar la consola para una mejor experiencia de usuario
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        switch (opcion)
        {
        case 1:
            agregarItem(inventario, &numItems);
            break;
        case 2:
            listarItems(inventario, numItems);
            break;
        case 3:
            buscarPorNombre(inventario, numItems);
            break;
        case 4:
            listarPorTipo(inventario, numItems);
            break;
        case 5:
            calcularValorTotal(inventario, numItems);
            break;
        case 6:
            darDeBajaItem(inventario, numItems);
            break;
        case 7:
            ordenarInventario(inventario, numItems);
            break;
        case 8:
            printf("¡Hasta la proxima aventura!\n");
            break;
        default:
            printf("[X] Opcion no valida. Intente de nuevo.\n");
            break;
        }

        if (opcion != 8)
        {
            printf("\nPresione Enter para continuar...");
            getchar(); // apretar enter para continuar
        }

    } while (opcion != 8);

    return 0;
}

void mostrarMenu()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    printf(
        "+--------------------------------------------------+\n"
        "|      GESTION DE INVENTARIO DE AVENTURERO ⚔️ 👑  |\n"
        "|      1. Agregar nuevo item                       |\n"
        "|      2. Listar todos los items activos           |\n"
        "|      3. Buscar item por nombre                   |\n"
        "|      4. Listar items por tipo                    |\n"
        "|      5. Calcular valor total del inventario      |\n"
        "|      6. Dar de baja un item                      |\n"
        "|      7. Ordenar inventario                       |\n"
        "|      8. Salir                                    |\n"
        "+--------------------------------------------------+\n");
}

void limpiarBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float calcularPesoActual(const Item inventario[], int numItems) {
    float pesoTotal = 0.0f;
    for (int i = 0; i < numItems; i++) {
        if (inventario[i].activo) {
            pesoTotal += inventario[i].peso;
        }
    }
    return pesoTotal;
}

void agregarItem(Item inventario[], int *numItems)
{
    printf("AGREGAR ITEM ⚔️ 👑\n");
    
    if (*numItems >= MAX_ITEMS) {
        printf("⚔️ Error: El inventario esta lleno. No podes agregar mas items.\n");
        return; 
    }

    Item nuevoItem; // variable temporal
    nuevoItem.activo = true; // nuevo ítem siempre está activo.

    printf("Ingrese nombre: ");
    fgets(nuevoItem.nombre, MAX_NOMBRE, stdin);
    nuevoItem.nombre[strcspn(nuevoItem.nombre, "\n")] = 0; // Elimina el salto de línea de fgets

    printf("Ingrese tipo (Armadura, Pocion, Arma, Libro): ");
    fgets(nuevoItem.tipo, MAX_TIPO, stdin);
    nuevoItem.tipo[strcspn(nuevoItem.tipo, "\n")] = 0;

    printf("Ingrese valor (monedas de oro): ");
    scanf("%d", &nuevoItem.valor);

    printf("Ingrese peso (kg): ");
    scanf("%f", &nuevoItem.peso);
    
}