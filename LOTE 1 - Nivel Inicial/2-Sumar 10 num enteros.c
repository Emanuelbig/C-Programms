/*Sumar 10 números enteros
Leer 10 valores enteros usando for, sumar solo los impares de ese lote y mostrar
el total de esos impares.

Alumno: Emanuel Morano Sole
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, suma = 0;

    // Bucle para leer los 10 números enteros
    for (i = 1; i <= 10; i++)
    {
        printf("ingrese el numero entero %d:", i);
        scanf("%d", &num);

        // Para verificar si es numero impar
        if (num % 2 !=0) // si la division entre 2 no da 0, es impar 
        {
            suma += num; // es para ir acumulando la suma
        }
    }

    printf ("la suma de los numeros impares es: %d", suma); 
    return 0;
}