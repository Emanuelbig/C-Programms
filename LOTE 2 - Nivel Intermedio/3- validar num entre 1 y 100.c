#include <stdio.h>
int main (){
    int num;
    do
    {
        printf("Ingrese un num dentro del rango permitido:\n");
        scanf("%d", &num);
        if (num >= 1 && num <=100 )
        {
            printf("Perfecto el numero ingresado %d esta dentro del rango\n", num);
        }
        else
        {
            printf("no esta dentro del rango\n");
        }
        
        
    } while (num != 999);

    printf("Salio del loop\n");
    return 0;
}