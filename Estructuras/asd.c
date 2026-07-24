#include <stdio.h>

#include <stdlib.h>

#include<time.h> // esto es necesario para trabajar el aleatorio, porque se usa el tiempo

// Tamaño de la matriz

#define FILAS 8

#define COLUMNAS 8

int main() {

    // Crear una matriz 8x8 de colores RGB

    int pantalla[FILAS][COLUMNAS][3]; // [3] para los componentes R, G, B o sea tridimensional

    int x,y;

    srand(time(NULL));

  

    for (x = 0; x < FILAS; x++) {

        for ( y = 0; y < COLUMNAS; y++) {

            // Asignar colores ficticios

            pantalla[x][y][0] = rand()%(255-1+1)+1;  // Rojo - Red

            pantalla[x][y][1] = rand()%(255-1+1)+1;;   // Verde - Green

            pantalla[x][y][2] = rand()%(255-1+1)+1;;   // Azul  - Blue

        }

    }

 

   for (x = 0; x < FILAS; x++) 

   {

        for ( y = 0; y < COLUMNAS; y++) {

            printf("( %3d,%3d,%3d )-", pantalla[x][y][0], pantalla[x][y][1], pantalla[x][y][2]);

        }

        printf("\n");

    }

    return 0;

}

/*

Crear una matriz de 8x8 para simular un espacio de pantalla y 

asignarle tres valores de color a cada píxel para 

representar los componentes de color rojo, verde y azul (RGB). 

*/

// Tamaño de la matriz