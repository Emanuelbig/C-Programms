/*Promedio de 5 notas
Leer 5 notas float con for, luego realizarlo con ciclo while, calcular el promedio y
mostrar si aprueba (≥ 6) o no.

Alumno: Emanuel Morano Sole
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, notaAcumuladas = 0;
    float promedio;

    for (i = 1; i <= 5; i++)
    {
        printf("Ingrese la nota %d:", i);
        scanf("%d", &num);
        notaAcumuladas += num;
    }
    promedio = notaAcumuladas / 5.0f;

    if (promedio >= 6)
    {
        printf("Usted ha aprobado la materia con exito.\n");
    }
    else
    {
        printf("No aprobo la materia, lo siento.\n");
    }

    printf("Su promedio es de: %.2f \n", promedio);

    return 0;
}