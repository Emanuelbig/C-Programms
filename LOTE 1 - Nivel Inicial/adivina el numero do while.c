#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, nSecret;
    srand(time(NULL));
    nSecret = rand() % 10 + 1;
    do
    {
        printf("\tEl juego de la adivinanza:\n\tAdivina el numero del 1 al 10\n");
        printf("\tPor favor inserte un numero del 1 al 10:\n");
        scanf("%d", &n);
        n++;
        if (nSecret != n)
        {
            printf("\tincorrecto, try again bruh\n");
        }
    } while (nSecret != n);
    {
        printf("\tfelicitaciones lo ha logrado en %d intentos\n", n);
    }
    return 0;
}