#include <stdio.h>
int main()
{
    int edad, sueldo, antiguedad;
    printf("\tPara saber si se le puede otorgar un credito, le vamos a pedir los siguientes datos:\n");
    printf("\tIngrese su edad:\n");
    scanf("%d", &edad);
    if (edad >= 18 && edad <= 75)
    {
        printf("\tCumple con la edad para el credito\n");
        printf("Ingrese su sueldo:\n");
        scanf("%d", &sueldo);
        if (sueldo > 450000)
        {
            printf("\tSu sueldo cumple para el credito\n");
            printf("Ingrese su antiguedad en el trabajo:");
            scanf("%d", &antiguedad);
            if (antiguedad >= 2)
            {
                printf("\tFelicitaciones cumple con todas las condiciones para el credito!!\n");
            }
            else
            {
                printf("No cumple para recibir el credito por que no cuenta con la antiguedad minima necesaria para el otorgamiento");
            }
        }
        else
        {
            printf("Su sueldo no cumple para el credito");
        }
    }
    else
    {
        printf("Es menor de edad o ingreso mal su edad");
    }
    return 0;
}