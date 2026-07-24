/**********************************************************************************
Ejercicio 3 – números Amigos
Dos números A y B se llaman números amigos si la suma de los divisores propios de
uno da como resultado el otro, y viceversa.
Divisores propios: Son todos los números menores que el número dado que lo dividen
exactamente (excluyendo el propio número).
¿Como se si es divisor propio, preguntaran seguramente?, bueno si por cada paso, nro %i
=0 se cumple que es divisor propio.
Ejemplo
Buscamos los i tales que 220 % i == 0, con i desde 1 hasta 219.
Divisores propios encontrados:
1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110, ahora la suma de estos divisores da 284
Les propongo armar alguna función por ejemplo que se llame SumaDivisores, que
devuelva ese 284 y si la suma de los números pasados da igual, serán amigos.
Por ejemplo, 220 y 284 son números amigos porque la suma de los divisores propios de
220 (1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110) es 284, y la suma de los divisores propios de 284
(1, 2, 4, 71, 142) es 220
**********************************************************************************/

#include <stdio.h>

int sumaDivisores(int num);

int main()
{
    int numA, numB;
    printf("**********/Bienvenido a Numeros amigos!!/***************\n\n");
    printf("Ingrese el numero A para saber si es numero amigo:\n\n");
    scanf("%d", &numA);
    printf("Ingrese el numero B para saber si es numero amigo:\n\n");
    scanf("%d", &numB);
    int sumaA = sumaDivisores(numA);
    int sumaB = sumaDivisores(numB);
    if (sumaA == numB && sumaB == numA)
    {
        printf("Son numeros amigos!!\n\n");
    }
    else
    {
        printf("No son numeros amigos!! :(\n\n");
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