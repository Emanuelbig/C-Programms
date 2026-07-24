#include <stdio.h>

int main()
{
    int hora, minutos;

    // Pedir hora
    printf("\tPor favor ingrese la hora:\n");
    scanf("%d", &hora);
    while (hora < 0 || hora > 23)
    {
        printf("\tHora invalida. Por favor ingrese una hora entre 0 y 23:\n");
        scanf("%d", &hora);
    }

    printf("\tEsta correcta la hora\n");

    // Pedir minutos
    printf("\tAhora por favor ingrese los minutos:\n");
    scanf("%d", &minutos);
    while (minutos < 0 || minutos > 59)
    {
        printf("\tMinutos invalidos. Por favor ingrese un valor entre 0 y 59:\n");
        scanf("%d", &minutos);
    }

    printf("\tEstan correctos los minutos\n");

    // Evaluar horario laboral
    if (hora >= 9 && hora <= 17)
    {
        printf("\tEstas dentro del horario laboral que es %d:%d\n", hora, minutos);
    }
    else
    {
        printf("\tEstas fuera del horario laboral, disfruta tu tiempo libre!\n");
    }

    return 0;
}