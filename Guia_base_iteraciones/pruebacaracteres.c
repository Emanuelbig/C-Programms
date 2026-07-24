#include <stdio.h>

const int CANT = 4;
const char* vector[CANT] = {"Rober", "Ema", "Richi", "Pepe"};

int main()
{
    

    printf("\tNombres\n");
    for (int i = 0; i < CANT; i++)
    {
        printf("%s\n", vector[i]);
    }

    return 0;
}

//Preguntar al profe si esta bien