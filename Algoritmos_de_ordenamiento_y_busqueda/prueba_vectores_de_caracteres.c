#include <stdio.h>

int main() {
    // Vector de 15 strings, cada uno puede tener hasta 19 letras + '\0'
    char nombres[15][20] = {
        "Luciano", "Martina", "Rocio", "Juan", "Tomas",
        "Agustina", "Pedro", "Valentina", "Carlos", "Sofia",
        "Paula", "Fernando", "Ricardo", "Claudio", "Emanuel"
    };

    // Mostrar todos los nombres
    for (int i = 0; i < 15; i++) {
        printf("Nombre %d: %s\n", i + 1, nombres[i]);
    }

    return 0;
}