#include <stdio.h>// Standard Input/Output. La necesitas para printf (mostrar en pantalla) y 
                  // scanf (leer del teclado).

#include <stdlib.h>// Standard Library. Clave para rand() (generar número aleatorio), 
                   // srand() (inicializar el generador) y exit() (si algo falla).
#include <time.h>// La usamos para time(NULL). Esto nos da un número (la hora actual) 
                 // para "sembrar" (srand) el generador aleatorio y que no dé siempre los mismos 
                 // números.

#include <string.h>// (TEMA DE EXAMEN: STRINGS). Fundamental. 
                   // La necesitas para strcpy() (String Copy).

#include <stdbool.h>// Nos da el tipo de dato bool (para true y false), que es más limpio que 
                    // usar 1 y 0 para las banderas.

typedef struct
{
    int codigo;
    char nombre[30];
    char apellido[30];
    int dni;
    char destino[20];
    int prioridad; // 1 = preferencial, 0 = regular
} Pasajero;

//struct {...}: Es la palabra clave para crear un "paquete" de variables de distintos tipos.

//typedef ... Pasajero;: Es un "alias". En lugar de escribir struct a_realmente_largo_nombre 
// ... cada vez, ahora podemos escribir simplemente Pasajero.

//¿Qué creamos? Un nuevo tipo de dato. Ya no es un int o un char. Es un Pasajero. 
// Un Pasajero ocupa en memoria el espacio de todos sus campos juntos (4 bytes para codigo, 
// 30 para nombre, 30 para apellido, 4 para dni, 20 para destino y 4 para prioridad... 
// ¡unos 92 bytes por pasajero!).

int main()
{
    // 1. Declaración de los Vectores de Estructuras
    Pasajero todos[MAX_PASAJEROS];
    Pasajero embarque[MAX_CAPACIDAD];
    Pasajero espera[MAX_PASAJEROS];
    
    // ...
}

//Vectores de Estructuras: Aquí no tienes un vector de int. Tienes un vector donde CADA "casilla" 
// es una estructura Pasajero completa (de 92 bytes). todos es un bloque de memoria gigante 
// de 50 * 92 bytes.

// 2. Variables de Conteo y Capacidad
    int capacidad;
    int pasajerosA_Bordo = 0;
    int pasajerosEnEspera = 0;

// 3. Semilla Aleatoria
    srand(time(NULL));

//Estas variables son clave. capacidad la define el usuario. pasajerosA_Bordo y 
// pasajerosEnEspera nos dirán cuántos pasajeros realmente hay en las listas de 
// embarque y espera. Sus tamaños máximos son 40 y 50, pero su contenido real será menor. 
   