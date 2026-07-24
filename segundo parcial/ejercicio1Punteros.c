#include <stdio.h>

void intercambio(int *a,int *b);
int main(){

    int num1,num2;

    puts("Te pediremos ingresar 2 numeros enteros:");
    printf("Ingrese primer numero\n");
    scanf("%i",&num1);
    printf("Ingrese segundo numero\n");
    scanf("%i",&num2);

    //Valores originales
    puts("Valores originales que ingresaste:");
    printf("Numero 1: %i\n",num1);
    printf("Numero 2: %i\n",num2);

    intercambio(&num1,&num2);

    puts("Valores modificados:");
    printf("Numero 1: %i y su direccion de memoria es: %p\n",num1,(void *)&num1);
    printf("Numero 2: %i y su direccion de memoria es: %p\n",num2,(void *)&num2);

    return 0;
}

void intercambio(int *a,int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}