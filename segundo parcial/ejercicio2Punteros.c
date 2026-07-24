#include <stdio.h>
void potencia(int *base, int *exponente, int *resultado);
int main(){
    int base,exponente,resultado;
    puts("\nCalculo de pontencia:");
    printf("Ingrese la base:\n");
    scanf("%i",&base);
    printf("Ingrese el exponente:\n");
    scanf("%i",&exponente);
    potencia(&base,&exponente,&resultado);
    printf("El resultado de la potencia %i a la %i es: %.i\n",base,exponente,resultado);

    return 0;
}

void potencia(int *base, int *exponente, int *resultado){
    *resultado=1;
    for(int i=0;i<*exponente;i++){
        *resultado= *base * *resultado;
    }
}