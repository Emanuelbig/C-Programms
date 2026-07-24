/************************************************
Ejercicio 02
Ejercicio: Cálculo del Mayor de X Números
Se desea desarrollar un programa en lenguaje C que permita calcular el mayor número
de una serie de valores enteros ingresados por el usuario.
Requisitos:
1. Solicitar al usuario la cantidad de números a evaluar (n).
2. Leer n valores enteros desde teclado.
3. Utilizar una función llamada mayor que:
o Reciba dos números enteros como parámetros.
o Devuelva el mayor de ambos.
4. Al finalizar, mostrar en pantalla el número máximo encontrado.
Consideraciones:
• Validar que el valor de n sea mayor que cero.
• Mostrar al usuario un mensaje indicando el número que debe ingresar en cada
paso (por ejemplo: "Ingrese un número <1> de <3>:").
• Usar estructuras de control y funciones auxiliares para mantener el código
modular.
 ***********************************************/
#include <stdio.h>
int mayorque(int numI, int mayor);
int main()
{
    int numE, numI, mayor = 0;
    do
    {
        printf("Ingrese la cantidad de numeros a evaluar:\n\n");
        scanf("%d", &numE);
        if (numE < 0)
        {
            printf("Numero invalido, ingrese un numero mayor a 0\n\n");
        }
    } while (numE < 0);
    for (int i = 1; i <= numE; i++)
    {
        printf("Ingrese el numero %d de %d\n\n", i, numE);
        scanf("%d", &numI);
        mayor = mayorque(numI, mayor);
    }
    printf("El mayor numero ingresado es: %d", mayor);
    return 0;
}

int mayorque(int numI, int mayor)
{
    if (numI > mayor)
    {
        mayor = numI;
    }
    return mayor;
}