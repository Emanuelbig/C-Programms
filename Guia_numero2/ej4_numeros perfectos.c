/*******************************************************************
Ejercicio 4 - Números perfectos
Un número perfecto es aquel que es igual a la suma de sus divisores propios (como en
los números amigos, pero comparándose consigo mismo).
Por ejemplo, el número 28 es perfecto porque:
1 + 2 + 4 + 7 + 14 = 28
Un matemático desea identificar si un grupo de números ingresados por el usuario es
número perfecto.
Escribí un programa que:
Hay que recordar que este es un grupo de números que ingresaremos sin saber cuando
termina su ingreso, lo que si sabemos que la finalización se da si ingresamos el numero
999, el cual no debe ser evaluado por que es el corte de ingreso o fin de ingreso de datos.
1. Use una función int sumaDivisores(int n) para obtener la suma de los divisores
propios de ese número.
2. Compare si el número ingresado es igual a dicha suma.
3. Informe si el número es perfecto o no.
4. Informe también cuantos fueron en total los números propios que se ingresaron.
Ejemplos de números perfectos para probar
6
28
496
8128
*******************************************************************/
#include <stdio.h>

int sumaDivisores(int num);
void numerospropios(int num);

int main()
{
    int numeroPerfecto;
    printf("***Bienvenido a descubre el numero perfecto***\n\n");
    while (numeroPerfecto != 999)
    {
        printf("Ingrese numero para saber si es perfecto o no:\n");
        printf("ingresando 999 sale del programa\n\n");
        scanf("%d", &numeroPerfecto);
        sumaDivisores(numeroPerfecto);

        if (numeroPerfecto == sumaDivisores(numeroPerfecto) && numeroPerfecto)
        {
            printf("La suma es igual al numero ingresado, es un numero perfecto\n\n");
            numerospropios(numeroPerfecto);
        }
        else if (numeroPerfecto == 999)
        {
            printf("Usted ha salido del programa");
        }
        else
        {
            printf("No es un numero perfecto!\n\n");
        }
    }

    return 0;
}

int sumaDivisores(int num)
{
    int suma = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

void numerospropios(int num)
{
    int numpropcant = 0;
    // int suma = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            i++;
            numpropcant = i++;
        }
    }

    printf("Los numeros propios son %d\n\n", numpropcant);
}