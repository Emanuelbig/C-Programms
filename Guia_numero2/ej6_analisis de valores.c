/*******************************************************************
Ejercicio 6 – Análisis de una secuencia de valores
Un analista económico registra montos diarios de ventas y necesita conocer el valor más
alto, el más bajo y la media del rango para tomar decisiones.
media = (min + max) / 2
Pedí al usuario cuántos montos desea ingresar.
Luego, implemente
• float maximo(float a, float b) y int minimo(float a, float b) para ir comparando
valores,
• float .CalculaMediaDelRango (float mínimo,float maximo)
*******************************************************************/
#include <stdio.h>

float maximo(float a, float b);
float minimo(float a, float b);
float calcularMediaRango(float minimo, float maximo);
int main()
{
    float num, max, min;
    int cantVentas;
    printf("Ingrese la cantidad de ventas que realizo:\n\n");
    scanf("%d", &cantVentas);
    for (int i = 1; i <= cantVentas; i++)
    {
        printf("Ingrese precio de venta %d de %d\n\n", i, cantVentas);
        scanf("%f", &num);
        max = maximo(num, max);
        min = minimo(num, min);
    }
    printf("El numero mayor es %.2f\n\n", max);
    printf("El numero menor es %.2f\n\n", min);
    printf("La media de rango es %.2f\n\n", calcularMediaRango(min, max));
}

float maximo(float a, float b)
{

    if (a > b)
    {
        b = a;
    }

    return b;
}

float minimo(float a, float b)
{

    if (a < b)
    {
        b = a;
    }

    return b;
}

float calcularMediaRango(float minimo, float maximo)
{
    float resultado = (minimo + maximo) / 2;
    return resultado;
}