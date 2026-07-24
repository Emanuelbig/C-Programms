/*Ejercicio 03
Suma de los primeros N números naturales
Objetivo: Usar for y acumulador.
Enunciado: Solicitar al usuario un número entero N y mostrar la suma de los primeros N números naturales. (suponemos que el usuario no se equivoca en este ingreso)
Si lograste llegar a realizar bien el ejercicio, te pido lo evoluciones y valides el ingreso, no permitiendo el ingreso de números negativos.
*/

#include <stdio.h>

int main()
{
    int i, N, suma = 0;
    printf("Ingrese el num entero positivo");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        suma += i;
        printf("%d +", i);
    }
    printf("La suma de los primeros %d numeros es: %d", N, suma);
    return 0;
}
