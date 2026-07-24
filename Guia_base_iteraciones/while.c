#include <stdio.h>
int main()
{
    int n;
    printf("si queres que el programa no se apague ingresa siempre un numero entre 1 y 10:\n");
    scanf("%d", &n);
    while (n <= 10)
    {
        printf("Segui escribiendo un numero, el programa sigue vivo\n");
        scanf("%d", &n);

        if (n > 10)
        {
            printf("rompiste el programa papi, ya murio\n");
        }
    }
    return 0;
}