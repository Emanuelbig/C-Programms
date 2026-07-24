#include <stdio.h>
int main()
{
    int contador = 0;
    float totalGastado, promedio, precios;
    do
    {
        printf("\nIngrese el precio del producto que va a comprar: \n");
        printf("\n---Para salir debe apretar 0 o un numero negativo---\n");
        scanf("%f", &precios);
        contador++;
        if (precios > 0)
        {
            contador++;
            totalGastado += precios;
        }

    } while (precios > 0);

    if (contador > 0)
    {
        promedio = totalGastado / contador;
        printf("\nEl total gastado es %.2f\n", totalGastado);
        printf("\nEl promedio de compra es de %.2f\n", promedio);
    }
    return 0;
}
