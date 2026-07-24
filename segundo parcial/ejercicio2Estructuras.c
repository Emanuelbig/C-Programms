#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_DESC 30
#define MAX_PRODUCTOS 100

typedef struct {
    int codigo;
    char descripcion[CANT_DESC];
    float precio;
} productos;

void cargarProductos(productos inventario[], int n);
void mostrarProductos(productos inventario[], int n);
int buscarProductos(productos inventario[], int n, int codigo_buscado);

int main(){
    productos inventario[MAX_PRODUCTOS];
    int n_productos=0;
    int codigo_buscado=0;
    int indice_encontrado=-1;

    printf("Cuantos productos desea ingresar? (max %d): \n", MAX_PRODUCTOS);
    scanf("%i", &n_productos);

    if (n_productos <= 0 || n_productos > MAX_PRODUCTOS) {
        printf("Cantidad invalida. Adios.\n");
        return 1; // Termina el programa con error
    }

    cargarProductos(inventario, n_productos);
    mostrarProductos(inventario, n_productos);
    
    printf("\n--- Buscar Producto ---\n");
    printf("Ingrese el codigo del producto a buscar: ");
    scanf("%d", &codigo_buscado);
    indice_encontrado = buscarProductos(inventario, n_productos, codigo_buscado);

    if (indice_encontrado != -1) {
        // Si lo encontramos (índice no es -1)
        printf("\n✅ Producto Encontrado:\n");
        printf("------------------------\n");
        printf("Codigo:      %d\n", inventario[indice_encontrado].codigo);
        printf("Descripcion: %s\n", inventario[indice_encontrado].descripcion);
        printf("Precio:      $%.2f\n", inventario[indice_encontrado].precio);
    } else {
        // Si no lo encontramos
        printf("\n❌ Producto con codigo %d no encontrado.\n", codigo_buscado);
    }

    return 0;
}

void cargarProductos(productos inventario[], int n) {
    printf("\n--- Carga de %d Productos ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Codigo: ");
        scanf("%d", &inventario[i].codigo);

        // --- Manejo del buffer de 'scanf' ---
        // Consumimos el '\n' que dejó el scanf("%d") 
        // para que 'fgets' funcione correctamente.
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 
        // --- Fin del manejo ---

        printf("  Descripcion: ");
        // Usamos fgets para leer strings con espacios
        fgets(inventario[i].descripcion, 30, stdin);
        
        // 'fgets' guarda el '\n' (Enter) al final. Lo removemos:
        inventario[i].descripcion[strcspn(inventario[i].descripcion, "\n")] = '\0';

        printf("  Precio: ");
        scanf("%f", &inventario[i].precio);
    }
}

void mostrarProductos(productos inventario[], int n) {
    printf("\n--- Listado de Productos (Total: %d) ---\n", n);
    printf("==================================================\n");
    printf("%-10s | %-25s | %s\n", "CODIGO", "DESCRIPCION", "PRECIO");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        // Usamos formato de alineación para que se vea como tabla
        printf("%-10d | %-25s | $%.2f\n",
               inventario[i].codigo,
               inventario[i].descripcion,
               inventario[i].precio);
    }
    printf("==================================================\n");
}

int buscarProductos(productos inventario[], int n, int codigo_buscado) {
    for (int i = 0; i < n; i++) {
        if (inventario[i].codigo == codigo_buscado) {
            return i; // ¡Encontrado! Retornamos la posición
        }
    }
    return -1; // No se encontró
}