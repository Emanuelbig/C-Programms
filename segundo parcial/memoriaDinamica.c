/*Asignacion de memoria dinamica*/
#include <stdio.h>
#include <stdlib.h> //libreria que usa malloc
#include <string.h>
#define length 2
int size;

struct dog {
    char name[20];
    char *p_name;
} dogs[length];

int main(){
    for (int i = 0; i < length; i++)
    {
        printf("Ingrese el nombre del perro\n");
        scanf("%s",dogs[i].name);
        size=strlen(dogs[i].name); //te dice el tamanio de la palabra (cantidad de letras)
        printf("%i\n",size); //imprimimos la cantidad de letras
        dogs[i].p_name=malloc((size+1) * sizeof(char)); //dogs[i].p_name: Estás accediendo al puntero p_name (un char *) del perro actual (i).
        // En este momento, ese puntero no apunta a ningún sitio válido.
        //malloc(...): Estás llamando a la función "Memory Allocation" (Asignación de Memoria) para pedirle al sistema operativo un bloque de memoria del "Heap" (la memoria dinámica).
        //sizeof(char) es siempre 1 (un char ocupa 1 byte).O sea, estás pidiendo exactamente size bytes (ej: 4 bytes para "Fido").
        //=: El puntero dogs[i].p_name ahora "apunta" a la dirección de memoria de ese nuevo bloque que malloc te acaba de reservar.
        if (NULL==dogs[i].p_name)
        {
            printf("Error al asignar memoria\n");
        }else
        {
            strcpy(dogs[i].p_name,dogs[i].name);
            //strcpy: Estás llamando a la función "String Copy" (Copiar Cadena).
            //dogs[i].p_name: Este es el destino. Es el puntero al bloque de memoria vacío que acabas de reservar con malloc.
            //dogs[i].name: Este es el origen. Es el string original (ej: "Fido") que está guardado en el arreglo char name[20].
            //La acción: strcpy copia los caracteres ('F', 'i', 'd', 'o') y también el carácter nulo final (\0) desde dogs[i].name hacia la nueva memoria apuntada por dogs[i].p_name.
            //En resumen (Línea 2): Estás copiando el nombre del perro desde su ubicación original (name) a la nueva ubicación de memoria dinámica (p_name).

            //¿Por qué estás haciendo esto?
            //El objetivo es tener dos copias del nombre:

            //dogs[i].name: Una copia en un bloque de memoria estático de 20 bytes (que puede estar desperdiciando espacio si el nombre es corto).

            //dogs[i].p_name: Una copia en un bloque de memoria dinámico de tamaño exacto (lo que ahorra memoria).
            printf("Memoria asignada\n");
        }
        
        
    }

    for (int i = 0; i < length; i++)
    {
        printf("El nombre del perro es: %s\n",dogs[i].p_name);
        /* code */
    }
    
    
    
    return 0;
}