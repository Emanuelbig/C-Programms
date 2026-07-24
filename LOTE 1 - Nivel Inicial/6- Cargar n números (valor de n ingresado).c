/*Cargar n números (valor de n ingresado)
Ingresar n valores, que serán determinados por el usuario cargar esos valores con
un ciclo for y mostrar el máximo ingresado.

Alumno: Emanuel Morano Solé*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, numero, max;

    printf("Cuantos numeros vas a ingresar?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Ingresa el numero %d:", i + 1);
        scanf("%d", &numero);

        if (i == 0 || numero > max) // operador o logico
        {
            max = numero;
        }
    }

    printf("El numero maximo ingresado fue: %d\n", max);

    return 0;
}