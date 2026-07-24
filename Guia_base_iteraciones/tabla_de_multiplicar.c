#include <stdio.h>

int main() {
    int i, n, hasta;
    printf("\tIngrese un numero entero para multiplicar:\n");
    scanf("%d",&n);

    printf("\tHasta que numero queres ver su tabla de multiplicar?:\n");
    scanf("%d",&hasta);

    for ( i = 1; i <= hasta; i++)
    {
        printf("\t%d x %d = %d \n", n, i, n* i);
    }

    return 0;
    
}