/*Cargar hasta ingresar cero
Cargar números enteros hasta que se ingrese un 0. Al final, mostrar la sumatoria
de esa carga total.

Alumno: Emanuel Morano Sole
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, sumar=0;
    printf("Ingrese numeros enteros, si ingresa el 0 se corta y se suman los numeros: \n");

    while (1)
    {   
        
        scanf("%d", &i);
    

        if(i==0){
            break ; // con esto termina el buclee
            // sumar += i; 
        }
        printf("Has ingresado el %d \n",i);
        sumar += i;
        printf("Siga ingresando numeros enteros:\n");
    }
    printf("La suma de los numeros es: %d", sumar);
    printf("El programa ha finalizado");

    return 0;
}