/*
5. Producto escalar: El producto escalar entre dos vectores se obtiene
multiplicando componente a componente y luego sumando los resultados.
Si tienes dos vectores A y B, el producto escalar se calcula como sigue:
A · B = A1 * B1 + A2 * B2 + A3 * B3 + ... Por ejemplo, si tienes A = (1, 2,
3) y B = (4, 5, 6), el producto escalar de los vectores sería A · B = 1 * 4 +
2 * 5 + 3 * 6 = 4 + 10 + 18 = 32.,
Se pide desarrollar un programa que pueda dar solución al cálculo del
Producto Escalar
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define indice 5

int main()
{
    int vector1[indice]={2,5,10,15,20};
    int vector2[indice]={10,10,10,10,10};
    int vector3[indice];

    for (int i = 0; i < indice; i++)
    {
        vector3[i]= vector1[i] * vector2[i];
    }

    int suma=0;

    for (int i = 0; i < indice; i++)
    {
        suma += vector3[i];
    }
    
    printf("Los vectores multiplicados entre sus indices generando el vector 3 quedan:\n");

    for (int i = 0; i < indice; i++)
    {
        printf("Vector3[%d] con producto: %d\n",i+1,vector3[i]);
    }
    
    printf("La suma de todos estos indices es: %d",suma);
    
    return 0;
}