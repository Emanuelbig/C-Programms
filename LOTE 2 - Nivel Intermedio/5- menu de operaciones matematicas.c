#include <stdio.h>
int main()
{
    int opcion = 0;
    float numA, numB, operacion;
    printf("\t---Calculadora de Ema---\n");
    while (opcion != 5)
    {
        printf("1. Sumar 2 numeros\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese el 1er num:\n");
            scanf("%f", &numA);
            printf("Ingrese el 2do num:\n");
            scanf("%f", &numB);
            operacion = numA + numB;
            printf("La suma es: %.2f \n\n\n",operacion);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            printf("Ingrese el 1er num:\n");
            scanf("%f", &numA);
            printf("Ingrese el 2do num:\n");
            scanf("%f", &numB);
            if (numB != 0)
            {
                operacion = numA / numB;
            printf("La suma es: %.2f \n\n\n",operacion);
            } else 
            {
                printf("No se puede dividir por 0\n\n");
            }
            
            
            break;
        case 5:
            printf("Ha salido de la calculadora de Ema");
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    return 0;
}