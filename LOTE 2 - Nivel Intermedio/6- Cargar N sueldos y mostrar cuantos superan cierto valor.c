#include <stdio.h>
int main (){
    float sueldos = 0;
    int cantidad, contador = 0;
    printf("Coloque la cantidad de sueldos a ingresar: \n");
    scanf ("%d", &cantidad);
    for (int i = 1; i < cantidad; i++)
    {
        printf("Ingrese el sueldo %i :\n",i);
        scanf("%f", &sueldos);
        if (sueldos > 100000)
        {
            contador ++;
        }
        
    }
    printf("\nCantidad de sueldos mayores a $100000: %d\n", contador);
    return 0;
}