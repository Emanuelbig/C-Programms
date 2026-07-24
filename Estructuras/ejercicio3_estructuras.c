/*
Ejercicio 3: ABM de Biblioteca
Una biblioteca necesita llevar un registro de los libros disponibles para
préstamo.
typedef struct {
 int codigo;
 char titulo[40];
 char autor[30];
 int anio;
 int activo; // 1 = disponible, 0 = dado de baja (ej: libro perdido o en reparación)
} Libro;
El programa debe implementar un menú ABM que permita:
1. Alta: Registrar un nuevo libro (activo = 1).
2. Baja lógica: Dar de baja un libro por código (activo = 0).
3. Modificación: Cambiar el título o el autor de un libro.
4. Listado de libros activos: Mostrar solo los disponibles.
5. Listado general: Mostrar todos los libros (incluidos inactivos).
6. Buscar por autor: Mostrar todos los libros activos de un autor
dado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
 int codigo;
 char titulo[40];
 char autor[30];
 int anio;
 int activo; // 1 = disponible, 0 = dado de baja (ej: libro perdido o en reparación)
} Libro;


int main()
{
    int opcion;
    
    do
    {
        printf("\n\t--- Menu Biblioteca ABM ---\n");
        printf("1. Alta: Registrar un nuevo libro\n");
        printf("2. Baja logica: Dar de baja un libro por codigo\n");
        printf("3. Modificacion: Cambiar el titulo o el autor de un libro\n");
        printf("4. Listado de libros activos: Mostrar solo los disponibles\n");
        printf("5. Listado general: Mostrar todos los libros (incluidos inactivos)\n");
        printf("6. Buscar por autor: Mostrar todos los libros activos de un autor dado\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\nAlta: Registrar un nuevo libro\n");
                // Lógica para registrar un nuevo libro
                printf("Ingrese los datos del libro:\n");
                Libro nuevoLibro;
                printf("Codigo: ");
                scanf("%d", &nuevoLibro.codigo);
                printf("Titulo: ");
                scanf(" %[^\n]", nuevoLibro.titulo);
                printf("Autor: ");
                scanf(" %[^\n]", nuevoLibro.autor);
                printf("Anio: ");
                scanf("%d", &nuevoLibro.anio);
                nuevoLibro.activo = 1; // Por defecto, el libro está activo
                // Aquí se puede agregar el libro a una lista o base de datos
                break;
            case 2:
                printf("\nBaja logica: Dar de baja un libro por codigo\n");
                printf("\nIngrese el codigo del libro a dar de baja: \n");
                // Lógica para dar de baja un libro por código
                int codigoBaja;
                scanf("%d", &codigoBaja);
                // Aquí se buscaría el libro por código y se cambiaría su estado a inactivo
                nuevoLibro.activo = 0; // Ejemplo de cambio de estado
                break;
            case 3:
                printf("Modificacion: Cambiar el titulo o el autor de un libro\n");
                printf("Ingrese el codigo del libro a modificar: \n");
                int codigoMod;
                scanf("%d", &codigoMod);
                // Lógica para modificar el título o el autor de un libro
                printf("Ingrese el nuevo titulo: ");
                scanf(" %[^\n]", nuevoLibro.titulo);
                printf("Ingrese el nuevo autor: ");
                scanf(" %[^\n]", nuevoLibro.autor);
                // aca actualizan los datos del libro en la lista o base de datos
                break;
            case 4:
                printf("Listado de libros activos: Mostrar solo los disponibles\n");
                // Lógica para mostrar solo los libros activos
                if(nuevoLibro.activo == 1) {
                    printf("Codigo: %d, Titulo: %s, Autor: %s, Anio: %d\n", nuevoLibro.codigo, nuevoLibro.titulo, nuevoLibro.autor, nuevoLibro.anio);
                } else {
                    printf("No hay libros activos.\n");
                }

                break;
            case 5:
                printf("Listado general: Mostrar todos los libros (incluidos inactivos)\n");
                // Lógica para mostrar todos los libros
                printf("Codigo: %d, Titulo: %s, Autor: %s, Anio: %d, Activo: %d\n", nuevoLibro.codigo, nuevoLibro.titulo, nuevoLibro.autor, nuevoLibro.anio, nuevoLibro.activo);
                break;
            case 6:
                printf("Buscar por autor: Mostrar todos los libros activos de un autor dado\n");
                // Lógica para buscar libros por autor
                char autorBuscado[30];
                printf("Ingrese el nombre del autor: ");
                scanf(" %[^\n]", autorBuscado);
                if(nuevoLibro.activo == 1 && strcmp(nuevoLibro.autor, autorBuscado) == 0) {
                    printf("Codigo: %d, Titulo: %s, Autor: %s, Anio: %d\n", nuevoLibro.codigo, nuevoLibro.titulo, nuevoLibro.autor, nuevoLibro.anio);
                } else {
                    printf("No se encontraron libros activos de ese autor.\n");
                }
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }
    } while (opcion !=7);
    
    return 0;
}