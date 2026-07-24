#include <stdio.h>
void valorabsoluto(int *num, int *resultado);
int main(){
    int num,resultado;
    do {
        printf("Valor absoluto de tu numero entero\n");
        printf("Ingrese un numero entero:\n");
        scanf("%i",&num);
        valorabsoluto(&num,&resultado);
        printf("El valor absoluto de tu numero entero es: %i \n",resultado);
        printf("Si queres salir del programa apreta 5 y mete enter\n"); 
    } while(num != 5);
        puts("Te fuiste del programa");
    return 0;
}

void valorabsoluto(int *num, int *resultado){
    
    if (*num>0) {
        *resultado = *num; 
    } else {
        *resultado = *num * (-1); 
    }
}
