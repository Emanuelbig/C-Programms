/*Se pide desarrollar un algoritmo en PSeInt que permita procesar una serie de números
ingresados por el usuario bajo las siguientes condiciones:

 Instrucciones
1. El programa debe permitir ingresar como máximo 15 números enteros.
2. El ingreso de números termina si el usuario ingresa el valor especial 999, que
actúa como valor de corte (no debe contarse como número válido) o su máxima
cantidad permitida de ingresos que es 15.
3. Solo deben aceptarse valores entre 1 y 100 (ambos inclusive) para su evaluación
posterior.
o Si el número ingresado está fuera de ese rango (excepto 999), debe
mostrar un mensaje de error y volver a pedir un número sin contarlo
como válido.
4. Una vez finalizada la carga de datos (por alcanzar 15 números válidos o ingresar
999), el algoritmo debe:
o Informar cuántos números válidos fueron ingresados (tener en cuenta que
podrían haber sido 15 o menos).
o Indicar cuántos de esos valores son números primos.
o Indicar cuántos NO son números primos.
o Calcular e informar el porcentaje de números primos y el porcentaje de
no primos sobre el total de válidos.
 Definición útil
Un número primo es un número natural mayor que 1 que solo es divisible por 1 y por sí
mismo. Osea divisible como máximo 2 veces.
Un número natural es un número entero no negativo no incluimos al cero.
*/
#include <stdio.h>
int primos(int n);
void mostrar(int n);
int main()
{
    int i, n;
    for ( i = 1; i <= 5; i++)
    {

        printf("Ingrese el numero %d:\n", i);
        scanf("%d", &n);

        if (n == 999)
        {
            printf("Finalizo el programa\n");
            return 0;
        }
        else if (n > 100 || n < 1)
        {
            printf("Error, vuelva a insertar el numero por favor\n");
        }
        else if (n <= 100 && n >= 1)
        {
            printf("Esta ok\n");
        }

        //cont = i++;
  
    }
    printf("Fueron ingresados %d numeros\n",i-1);
    mostrar(n);
    return 0;
}

int primos(int n)
{

    if (n < 2)
        return 0;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0; // no es primo
    }

    return 1; // sí es primo
}

void mostrar(int n)
{
    if (primos(n))
    {
        printf("%d es primo\n\n", n);
    }
    else
    {
        printf("%d no es primo\n\n", n);
    }
}