/*Ejercicio 02
Contador del 1 al 100
Objetivo: Usar un ciclo for.
Enunciado: Mostrar por pantalla los números del 1 al 100, pero, en filas de 10 elementos
by EMAXXX*/
#include <stdio.h>
int main()
{
    int i, N = 100;
    for (i = 1; i <= N; i++)
    {
        printf("%d ", i);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }

    /* code */
    return 0;
}
