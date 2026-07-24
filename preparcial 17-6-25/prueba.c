#include <stdio.h>

int suma(int n1, int n2);
void mostrar();

int main()
{
    mostrar();
}

int suma(int n1, int n2)
{
    int suma;
    suma = n1 + n2;
    return suma;
}

void mostrar()

{
    int num1 = 3, num2 = 5;
    printf("la suma es %d ", suma(num1, num2));
}