// otro ej ingreso N num entre 1 y 100 determinados por el usuario y determinar cuales son primos (divisible por 1 y por si mismo)
#include <stdio.h>
int primos(int num);
void mostrar(int num);
int main()
{
    int num, cantidad;

    printf("Ingresar la cantidad de numeros que desea entre 1 y 100 (con 0 finaliza):\n");
    scanf("%d", &cantidad);
    if (cantidad < 1 || cantidad > 100)
    {
        printf("Cantidad fuera del rango permitido.\n");
        return 1;
    }

    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d", &num);

        mostrar(num);
    }

    return 0;
}

int primos(int num)
{

    if (num < 2)
        return 0;

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return 0; // no es primo
    }

    return 1; // sí es primo
}

void mostrar(int num)
{
    if (primos(num))
    {
        printf("%d es primo\n\n", num);
    }
    else
    {
        printf("%d no es primo\n\n", num);
    }
}