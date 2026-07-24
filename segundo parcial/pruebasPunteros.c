#include <stdio.h>
//apuntadores en c
//llamadas por valor
//llamadas por referencia
void cubo(int *num);
int main() {
    int a = 5;

    printf("El valor original de a es: %i\n",a);
    cubo(&a);
    printf("El nuevo valor cubo de a es: %i\n",a);
    //printf("%i\n",*apt);
    //printf("%p\n",apt); //imprime la direccion de a en hexadecimal
    //printf("%p\n",&a); //imprime la direccion de a en hexadecimal
    return 0;
}

void cubo (int *num)
{
    *num = *num * *num * *num;
}

