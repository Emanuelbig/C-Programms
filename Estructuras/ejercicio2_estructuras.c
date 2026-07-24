/*
Ejercicio 2: Inventario de Productos
Definir una estructura llamada Producto con los campos:
• Código (entero)
• Descripción (cadena de 30 caracteres)
• Precio (float)
El programa debe:
1. Cargar un arreglo de N productos (ingresado por teclado).
2. Mostrar la lista de productos.
3. Permitir buscar un producto por código y mostrar su información.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descripcion[30];
    float precio;
} Producto;

int main()
{
    int n;
    printf("Ingrese la cantidad de productos a cargar: ");
    scanf("%d", &n);
    Producto productos[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nIngrese los datos del producto %d:\n",i +1);
        printf("\nCodigo: ");
        scanf("%d", &productos[i].codigo);
        printf("Descripcion: ");
        scanf("%s", productos[i].descripcion);
        printf("Precio: ");
        scanf("%f", &productos[i].precio);
        printf("\n");
    }

    printf("Lista de productos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Codigo: %d, Descripcion: %s, Precio: %.2f\n", productos[i].codigo, productos[i].descripcion, productos[i].precio);
    }

    int codigoBuscado;
    printf("\nIngrese el codigo del producto a buscar: ");
    scanf("%d", &codigoBuscado);
    int encontrado = 0;
    for (int i = 0; i < n; i++)
    {
        if (productos[i].codigo == codigoBuscado)
        {
            printf("\nProducto encontrado: Codigo: %d, Descripcion: %s, Precio: %.2f\n", productos[i].codigo, productos[i].descripcion, productos[i].precio);
            encontrado = 1;
            //break;
        } else if (!encontrado)
        {
            printf("Producto no encontrado.\n");
        }
        
    }

    return 0;
}