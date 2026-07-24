#include <stdio.h>

int main()
{
    int i, numEnt, min;

    for (int i = 0; i < 5; i++)
    {
        printf("Ingresa el numero entero %d:", i + 1);
        scanf("%d", &numEnt);

        if (i == 0 || numEnt < min) // operador o logico
        {
            min = numEnt;
        }
    }


    printf("El numero menor es %d", min);
    return 0;
}