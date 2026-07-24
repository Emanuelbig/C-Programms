/*
---------------------------------------------------------------
---------------------------------------------------------------
 Temas cubiertos:
   ✅ Estructuras
   ✅ Punteros
   ✅ Memoria dinámica (malloc / realloc / free)
   ✅ Ordenamiento de vectores de estructuras
   ✅ Búsquedas (lineal)
   ✅ Copia de estructuras
   ✅ Matrices
---------------------------------------------------------------
---------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///--------------------------------------------------------------
/// 🧱 ESTRUCTURA BASE
///--------------------------------------------------------------

typedef struct {
    int codigo;
    char nombre[30];
    char apellido[30];
    int dni;
    char destino[20];
    int prioridad; // 1 = preferencial, 0 = regular
} Pasajero;

///--------------------------------------------------------------
/// 🧩 CARGA Y VISUALIZACIÓN
///--------------------------------------------------------------

void cargarPasajeros(Pasajero v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i].codigo = i + 1;
        printf("\nPasajero %d:\n", i + 1);
        printf("Nombre: "); scanf("%s", v[i].nombre);
        printf("Apellido: "); scanf("%s", v[i].apellido);
        printf("DNI: "); scanf("%d", &v[i].dni);
        printf("Destino: "); scanf("%s", v[i].destino);
        v[i].prioridad = rand() % 2; // genera 0 o 1
    }
}

void mostrarLista(Pasajero v[], int n, char titulo[]) {
    printf("\n===== %s =====\n", titulo);
    for (int i = 0; i < n; i++) {
        printf("%3d | %-10s %-10s | DNI:%d | %-10s | Prioridad:%d\n",
               v[i].codigo, v[i].nombre, v[i].apellido, v[i].dni,
               v[i].destino, v[i].prioridad);
    }
}

///--------------------------------------------------------------
/// 🔍 BÚSQUEDA POR DNI (LINEAL)
///--------------------------------------------------------------

int buscarPorDni(Pasajero v[], int n, int dni) {
    for (int i = 0; i < n; i++) {
        if (v[i].dni == dni)
            return i; // devuelve el índice
    }
    return -1; // no encontrado
}

///--------------------------------------------------------------
/// 🔁 COPIA DE UN VECTOR DE ESTRUCTURAS
///--------------------------------------------------------------

void copiarLista(Pasajero destino[], Pasajero origen[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

///--------------------------------------------------------------
/// ⚙️ ORDENAMIENTOS DE ESTRUCTURAS
///--------------------------------------------------------------

// Ordena por prioridad (1 primero)
void ordenarPorPrioridad(Pasajero v[], int n) {
    Pasajero aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j].prioridad > v[i].prioridad) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

// Ordena alfabéticamente por apellido
void ordenarPorApellido(Pasajero v[], int n) {
    Pasajero aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(v[i].apellido, v[j].apellido) > 0) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

///--------------------------------------------------------------
/// 💾 MEMORIA DINÁMICA
///--------------------------------------------------------------

/*
malloc: reserva memoria fija
realloc: cambia tamaño de la memoria
free: libera memoria
*/

Pasajero* reservarMemoria(int cantidad) {
    Pasajero *ptr = (Pasajero*) malloc(sizeof(Pasajero) * cantidad);
    if (ptr == NULL) {
        printf("Error de memoria\n");
        exit(1);
    }
    return ptr;
}

Pasajero* aumentarMemoria(Pasajero *ptr, int nuevaCant) {
    ptr = (Pasajero*) realloc(ptr, sizeof(Pasajero) * nuevaCant);
    if (ptr == NULL) {
        printf("Error al ampliar memoria\n");
        exit(1);
    }
    return ptr;
}

///--------------------------------------------------------------
/// 🧮 MATRICES
///--------------------------------------------------------------

void mostrarMatriz(int filas, int cols, int m[filas][cols]) {
    printf("\nMatriz %dx%d:\n", filas, cols);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

///--------------------------------------------------------------
/// 🧭 PUNTEROS (RECORDATORIO)
///--------------------------------------------------------------

void ejemploPunteros() {
    int x = 5;
    int *p = &x;
    printf("\nDireccion de x: %p | Valor de x: %d\n", p, *p);
    *p = 20;
    printf("Nuevo valor de x: %d\n", x);
}

///--------------------------------------------------------------
/// 🧩 MAIN DE PRUEBA
///--------------------------------------------------------------

int main() {
    int n = 5;
    Pasajero *lista = reservarMemoria(n);
    cargarPasajeros(lista, n);

    printf("\n--- Lista original ---\n");
    mostrarLista(lista, n, "Original");

    printf("\n--- Ordenada por prioridad ---\n");
    ordenarPorPrioridad(lista, n);
    mostrarLista(lista, n, "Por prioridad");

    printf("\n--- Ordenada alfabéticamente ---\n");
    ordenarPorApellido(lista, n);
    mostrarLista(lista, n, "Por apellido");

    int dniBuscado;
    printf("\nIngrese DNI a buscar: ");
    scanf("%d", &dniBuscado);
    int pos = buscarPorDni(lista, n, dniBuscado);
    if (pos >= 0)
        printf("Encontrado: %s %s (Posicion %d)\n", lista[pos].nombre, lista[pos].apellido, pos);
    else
        printf("No encontrado\n");

    ejemploPunteros();

    //  Ampliar vector dinámico
    printf("\nAmpliando lista a 8 pasajeros...\n");
    lista = aumentarMemoria(lista, 8);
    for (int i = 5; i < 8; i++) {
        lista[i].codigo = i + 1;
        strcpy(lista[i].nombre, "Extra");
        strcpy(lista[i].apellido, "Nuevo");
        lista[i].dni = 10000 + i;
        strcpy(lista[i].destino, "Bariloche");
        lista[i].prioridad = 0;
    }
    mostrarLista(lista, 8, "Lista ampliada");

    free(lista);
    return 0;
}


///--------------------------------------------------------------
/// 🧩 OTRAS COSAS
///--------------------------------------------------------------
//Ejercicio del avion 5 con carga manual y automatica------------
/*
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

*/
//Ejercicio 4 estructuras
/*
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

*/
//Ejercicio 3 estructuras     ----------------------------------- 
/*
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
*/
//Ejercicio basico de punteros----------------------------------- 

/*
void cubo(int *num);
int main() {
    int a = 5;

    printf("El valor original de a es: %i\n",a);
    cubo(&a);
    printf("El nuevo valor cubo de a es: %i\n",a);
    //printf("%i\n",*apt);
    //printf("%p\n",apt); //imprime la direccion de a en hexadecimal
    //printf("%p\n",&a); //imprime la direccion de a en hexadecimal
    return 0;
}

void cubo (int *num)
{
    *num = *num * *num * *num;
}
*/
//---------------------------------------------------------------
//Ejercicio del avion estructuras 5------------------------------
/*
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
            printf("❌ Capacidad invalida. Debe ser entre 25 y 40.\n");
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

*/

//Funcion Aleatoria----------------------------------------------
/*
int numAleatorio();

int numAleatorio()
{
    return (rand() % 200 )+ 1 ;
}

int numAleatorio(int min, int max);

int numAleatorio(int min, int max)
{
    // Fórmula para un rango inclusivo: (rand() % (rango)) + min
    // Rango = (max - min + 1)
    return (rand() % (max - min + 1)) + min;
}

*/
//---------------Ejercicio 5 de punteros-----------------------
/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h> // Necesario para rand() y srand()

#define TAM 10

int numAleatorio(int min, int max);
void cargarVector(int vec[]);
void ListarVector(int vec[]);

int main()
{
    int vector[TAM];
    srand(time(NULL));
    cargarVector(vector);
    ListarVector(vector);
    return 0;
}

int numAleatorio(int min, int max)
{
    // Fórmula para un rango inclusivo: (rand() % (rango)) + min
    // Rango = (max - min + 1)
    return (rand() % (max - min + 1)) + min;
}

void cargarVector(int vec[]){
    for (int i = 0; i < TAM; i++)
    {
        *(vec+ i)=numAleatorio(25,75);
    }
    printf("Vector cargado.\n\n");
}

void ListarVector(int vec[]){
    printf("Mostrando valores y direcciones de memoria:\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("El vector %i tiene asignado el numero %i y su direccion de memoria es %p\n",i+1,*(vec+i),(void *)(vec+i));
    }
}
*/

//----------------------- Codigo del primer parcial----------------------------------------------------------
/*
-------------------------Funcion hecha por el profesor del preparcial------------------------------------------

int ExisteValor(int num, int v[MAX], int m);

int ExisteValor(int num, int v[CAP_MAX], int TamActual) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (TamActual==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < TamActual; i++)
        {
            if (v[i] == num) // Verificar si el número ya existe en el vector
            {
                return i;
                // Si existe, retornar la posicion donde se encuentra para despues incrementar
                // el contador en esa posicion en el vector contador
            }
        }
        return -1; // Si no existe, retornar -1 y como es un valor fuera de rango no se incrementa el contador
    }
}
---------------------------------------------------------------------------------------------------------------
-------------------------Funcion hecha por mi para comprobar si se repite un numero ------------------------------------------
int ExisteValor(int num, int v[], int tam);

int ExisteValor(int num, int v[], int tam) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (tam==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            if (v[i] == num) // Verificar si el número ya existe en el vector
            {
                return i;
                // Si existe, retornar la posicion donde se encuentra para despues incrementar
                // el contador en esa posicion en el vector contador
            }
        }
        return -1; // Si no existe, retornar -1 y como es un valor fuera de rango no se incrementa el contador
    }
}
---------------------------------------------------------------------------------------------------------------
-------------------------Funcion para cargar vectores sin que se repitan------------------------------------------

void CargarSinRepetirNumeros(int v[], int tam);

void CargarSinRepetirNumeros(int v[], int tam)
{
    int num, i= 0;

    while (i<tam)
    {
        num = numAleatorio();
        ExisteValor(num, v, i);

        if (ExisteValor(num, v, i)==-1)
        {
            v[i]=num;
            i++;
    
        }
               
    }

    for (int i = 0; i < tam; i++)
    {
        printf("Numero ID atleta: %d\n", v[i]);
    }
    
}

int ExisteValor(int num, int v[], int tam) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (tam==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            if (v[i] == num) // Verificar si el número ya existe en el vector
            {
                return i;
                // Si existe, retornar la posicion donde se encuentra para despues incrementar
                // el contador en esa posicion en el vector contador
            }
        }
        return -1; // Si no existe, retornar -1 y como es un valor fuera de rango no se incrementa el contador
    }
}
----------------------------------------------------------------------------------------------------------------
-------------------------Funcion para cargar vectores de forma basica------------------------------------------

void MostrarVector(int v[], int tam);

void MostrarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("vector1[%d] con valor %d\n",i+1,v[i]);
    }
    
}
----------------------------------------------------------------------------------------------------------------
------------------------------------------Parcial del bingo resuelto--------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int CANT_NUM = 7;
const int MIN_NUM = 1;
const int MAX_NUM = 18;
const int PREMIO_MAX = 1400000;
const int PRECIO_BOLETO = 5;

int generar_aleatorio_entre(int vmin, int vmax);
void generar_aletorios_sr(int vec[], int tam, int vmin, int vmax);
int buscar_coincidencias(int vec1[], int vec2[], int tam);
void mostrar_premios(int coincidencias, int max_coincidencias);
void mostrar_vector(int vec[], int tam, const char msj[]);

int main() {
  srand(time(NULL));
  int boleto[CANT_NUM], sorteo[CANT_NUM];
  generar_aletorios_sr(boleto, CANT_NUM, MIN_NUM, MAX_NUM);
  generar_aletorios_sr(sorteo, CANT_NUM, MIN_NUM, MAX_NUM);
  mostrar_vector(boleto, CANT_NUM, "Boleto generado: ");
  mostrar_vector(sorteo, CANT_NUM, "Números sorteados: ");
  int coincidencias = buscar_coincidencias(boleto, sorteo, CANT_NUM);
  mostrar_premios(coincidencias, CANT_NUM);
}

void mostrar_vector(int vec[], int tam, const char msj[]) {
  printf(msj);
  for (int i = 0; i < tam; ++i) {
    printf("%d ", vec[i]);
  }
  puts("");
}

int generar_aleatorio_entre(int vmin, int vmax) {
  return rand() % (vmax - vmin + 1) + vmin;
}

void generar_aletorios_sr(int vec[], int tam, int vmin, int vmax) {
  for (int i = 0; i < tam; ++i) {
    int n = generar_aleatorio_entre(vmin, vmax);
    int c = 0;
    while (c < i) {
      if (vec[c] == n) {
        c = 0;
        n = generar_aleatorio_entre(vmin, vmax);
      } else {
        c++;
      }
    }
    vec[i] = n;
  }
}

int buscar_coincidencias(int vec1[], int vec2[], int tam) {
  int coincidencias = 0;
  for (int i = 0; i < tam; ++i) {
    for (int j = 0; j < tam; ++j) {
      if (vec1[i] == vec2[j])
        coincidencias++;
    }
  }
  return coincidencias;
}

void mostrar_premios(int coincidencias, int max_coincidencias) {
  printf("Cantidad de coincidencias: %d\n", coincidencias);
  if (coincidencias == max_coincidencias) {
    printf("¡Felicitaciones! Premio: $%d\n", PREMIO_MAX);
  } else if (coincidencias == (max_coincidencias - 1)) {
    printf("¡Felicitaciones! Premio: $%d\n", (int)(PREMIO_MAX * .2));
  } else if (coincidencias == (max_coincidencias - 2)) {
    printf("¡Felicitaciones! Premio: $%d\n", (int)(PREMIO_MAX * .03));
  } else if (coincidencias == (max_coincidencias - 3)) {
    printf("¡Felicitaciones! Premio: $%d\n", PRECIO_BOLETO);
  } else {
    puts("Sin premio.");
  }*/