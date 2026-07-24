/*Contar positivos y negativos
Ingresar 10 números enteros y mostrar cuántos son positivos y cuántos negativos,
determina quien tuvo más.

Alumno: Emanuel Morano*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, negativos = 0, positivos = 0;

    for (i = 1; i <= 10; i++)
    {
        printf("Ingrese el numero entero %d:\n", i);
        scanf("%d", &num);

        if (num > 0)
        {
            positivos++;
        }
        else if (num < 0)
        {
            negativos++;
        }
    }

    printf("Cantidad de numeros positivos es %d\n", positivos);
    printf("Cantidad de numeros negativos es %d\n", negativos);

    if (positivos > negativos)
    {
        printf("Hubo mas numeros positivos\n");
    }
    else if (positivos < negativos)
    {
        printf("Hubo mas numeros negativos\n");
    }
    else
    {
        printf("Hay la misma cantidad de negativos y positivos\n");
    }
    return 0;
}