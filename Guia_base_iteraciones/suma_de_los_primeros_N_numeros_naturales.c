#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, suma = 0;
    printf("Porfavor ingresa un numero entero:");
    scanf("%d", &n);

    if (n > 0)
    {
        for (i = 0; i <= n; i++)
        {
            suma += i;
        }

        printf("la suma de los primeros numeros de %d son: %d ", n, suma);
    }
    else
    {
        printf("No se admiten numeros enteros negativos para este ejercicio");
    }
}