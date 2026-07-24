#include <stdio.h>
int main()
{
    int num, suma = 0, contador = 0;
    float promedio;
    do
    {
        printf("\tCargar un valor positivo:\n");
        scanf("%d", &num);

        if (num >= 0)
        {
            suma += num;
            contador++;
        }

    } while (num >= 0);
    promedio = suma / contador;

    printf("El promedio de los positivos ingresados es: %.2f", promedio);

    return 0;
}
