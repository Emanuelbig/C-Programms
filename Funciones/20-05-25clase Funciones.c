#include <stdio.h>
#include <time.h>
// Estamos viendo funciones en C.

/*Calcular un cuadrado de un numero crear una funcion que reciba un numero intero y retorne su cuadrado
desde main , solicitar un numero y  mostrar el resultado usando la funcion*/
int cuadrado(int num);
int main()
{
    int num, resultado;
    printf("ingrese un numero:\n");
    scanf("%d", &num);
    resultado = cuadrado(num);
    printf("El cuadrado de %d es %d\n", num, resultado);
    return 0;
}

// Las funciones se laburan afuera
int cuadrado(int c) // esta es la funcion, esta definidad en otro lado de la memoria no en main.
{
    return c*c;
}// La puedo llamar cuando quiera.