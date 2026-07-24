#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBROS 100

typedef struct {
    int codigo;
    char titulo[40];
    char autor[30];
    int anio;
    int activo; //1 =disponible, 0 =dado de baja
} Libro;

void alta(Libro libros[], int *n);
void baja(Libro libros[], int n);
void modificacion(Libro libros[], int n);
void listarActivos(Libro libros[], int n);
void listarGeneral(Libro libros[], int n);
void buscarPorAutor(Libro libros[], int n);

int main (){
    Libro libros[MAX_LIBROS];
    int n= 0; //cantidad de libros cargados
    int opcion;

    do
    {
        printf("\n===== MENU BIBLIOTECA =====\n"
                "1. Alta de libro\n"
                "2. Baja logica de libro\n"
                "3. Modificacion de libro\n"
                "4. Listado de libros activos\n"
                "5. Listado general\n"
                "6. Buscar por autor\n"
                "0. Salir\n"
                "Seleccione opcion\n");
        scanf("%i",&opcion);
        getchar();//limpiamos el buffer
        switch (opcion)
        {
        case 1:
            alta(libros,&n);
            break;
        case 2:
            baja(libros,n);
            break;
        case 3:
            modificacion(libros,n);
            break;
        case 4:
            listarActivos(libros,n);
            break;
        case 5:
            listarGeneral(libros,n);
            break;
        case 6:
            buscarPorAutor(libros,n);
            break;
        default:
            printf("Opcion invalida");
            break;
        }
    } while (opcion !=0);
    
    return 0;
}

void alta(Libro libros[], int *n){
    if (*n>=MAX_LIBROS)
    {
        printf("Nose pueden cargar mas libros\n");
        return;
    }

    Libro nuevo;
    printf("Ingrese codigo:\n");
    scanf("%i",&nuevo.codigo);
    getchar();
    printf("Ingrese titulo:\n");
    fgets(nuevo.titulo, 40, stdin);//lee una línea de texto completa (incluyendo los espacios) desde una fuente (en este caso, el teclado → stdin).
    //fgets(variable, tamaño, stdin);
    nuevo.titulo[strcspn(nuevo.titulo,"\n")]=0;
    printf("Autor:\n");
    fgets(nuevo.autor,30,stdin);
    nuevo.autor[strcspn(nuevo.autor,"\n")]=0;
    printf("Anio: ");
    scanf("%d", &nuevo.anio);
    getchar();

    nuevo.activo = 1;
    libros[*n] = nuevo;
    (*n)++;

    printf("Libro agregado correctamente.\n");
    
}

void baja(Libro libros[], int n){
    int codigo;
    printf("Ingrese el codigo del libro a dar de baja: ");
    scanf("%d", &codigo);
    getchar();

    for (int i = 0; i < n; i++)
    {
        if (libros[i].codigo == codigo)
        {
            libros[i].activo=0;
            printf("Libro %s dado de baja\n",libros[i].titulo);
            return;
        }
        
    }

    printf("Nose encontro el libro con ese codigo\n");
    
}

void modificacion(Libro libros[], int n){
    int codigo;
    printf("Ingrese el codigo del libro a modificar:");
    scanf("%i",&codigo);
    getchar();

    for (int i = 0; i < n; i++)
    {
        if(libros[i].codigo == codigo){
            printf("Modificar titulo (actual: %s): ", libros[i].titulo);
            fgets(libros[i].titulo, 40, stdin);
            libros[i].titulo[strcspn(libros[i].titulo, "\n")] = 0;

            printf("Modificar autor (actual: %s): ", libros[i].autor);
            fgets(libros[i].autor, 30, stdin);
            libros[i].autor[strcspn(libros[i].autor, "\n")] = 0;

            printf("Libro modificado correctamente.\n");
            return;
        }
        
    }

    printf("No se encontro un libro con ese codigo.\n");
    
}

void listarActivos(Libro libros[], int n) {
    printf("\n--- Libros activos ---\n");
    for (int i = 0; i < n; i++) {
        if (libros[i].activo == 1) {
            printf("Codigo: %d | Titulo: %s | Autor: %s | Anio: %d\n",
                   libros[i].codigo, libros[i].titulo, libros[i].autor, libros[i].anio);
        }
    }
}

void listarGeneral(Libro libros[], int n) {
    printf("\n--- Listado general ---\n");
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d | Titulo: %s | Autor: %s | Anio: %d | Estado: %s\n",
               libros[i].codigo, libros[i].titulo, libros[i].autor, libros[i].anio,
               libros[i].activo ? "Activo" : "Inactivo");
    }
}

void buscarPorAutor(Libro libros[], int n) {
    char autor[30];
    printf("Ingrese el nombre del autor: ");
    fgets(autor, 30, stdin);
    autor[strcspn(autor, "\n")] = 0;// elimina el salto de línea que guarda fgets

    printf("\n--- Libros activos de %s ---\n", autor);
    int encontrados = 0;
    for (int i = 0; i < n; i++) {
        if (libros[i].activo == 1 && strcmp(libros[i].autor, autor) == 0) {
            printf("Codigo: %d | Titulo: %s | Anio: %d\n",
                   libros[i].codigo, libros[i].titulo, libros[i].anio);
            encontrados = 1;
        }
    }
    if (!encontrados)
        printf("No se encontraron libros activos de ese autor.\n");
}