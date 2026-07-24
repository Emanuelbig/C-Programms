#include <stdio.h>

float Area_rectangulo(float altura, float base);
/*Calcular el area de un rectangulo dado su base y
altura.Formula base * altura, tener en cuenta que
no pueden ser 0 ambos */
// otro ej ingreso N num y determinar cuales son primos (divisible por 1 y por si mismo)
int main()
{
    float base, altura, resultado;
    printf("Ingrese la altura del rectangulo\n");
    scanf("%f", &altura);
    if (altura <= 0)
    {
        printf("Esta mal");
    }
    else

    {

        printf("Ingrese la base del rectangulo\n");
        scanf("%f", &base);
        if (base <= 0)
        {
            printf("Esta mal");
        }
        else
        {
            resultado = Area_rectangulo(altura, base);
            printf("El area del rectangulo con base %.2f y altura %.2f es %.2f", base, altura, resultado);
        }
    }
}

float Area_rectangulo(float altura, float base)
{
    return base * altura;
}