/* Simular 10 mil tiradas con 2 dados y decir cuantas veces salio cada num */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tirar_dado();
// Actualizamos las firmas para que reciban el array correctamente
void simular_10miltiradas(int cont[]);
void mostrar_resultados(int cont[]);

int main() {
    // Inicializamos el array en 0 para limpiar la basura de memoria
    int cont[11] = {0};

    srand(time(NULL)); // Inicializamos la semilla de números aleatorios
  
    // Le pasamos el mismo array a ambas funciones
    simular_10miltiradas(cont);
    mostrar_resultados(cont);

    return 0;
}

int tirar_dado() {
    // rand() % 6 genera de 0 a 5. Le sumamos 1 para que sea de 1 a 6.
    return (rand() % 6) + 1;
}

void simular_10miltiradas(int cont[]) {
    int cantidad_tiradas = 10000;
    for (int i = 0; i < cantidad_tiradas; i++) {
        // Llamamos a tu función tirar_dado() dos veces
        int tirada = tirar_dado() + tirar_dado();
        
        // Le restamos 2 porque el índice 0 del array corresponde a la suma 2
        cont[tirada - 2]++; 
    }
}

void mostrar_resultados(int cont[]) {
    for (int i = 0; i < 11; i++) {
        // Le sumamos 2 al índice para mostrar la suma real de los dados
        printf("El %d salio %d veces \n", i + 2, cont[i]);
    }
}