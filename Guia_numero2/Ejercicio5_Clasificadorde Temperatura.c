/****************************************************************************************
Ejercicio 5 – Clasificador de temperatura
Un sistema de climatización necesita clasificar la temperatura ambiente para activar 
distintos modos de funcionamiento.
Desarrollar una función void clasificarTemperatura(float temp) que, dada una 
temperatura, indique si es:
• Muy fría (< 5°C)
• Fría (de 5°C a <15°C)
• Agradable (de 15°C a <25°C)
• Calurosa (de 25°C a <35°C)
• Muy calurosa (≥35°C)
El resultado informarlo por la misma función
****************************************************************************************/
#include <stdio.h>

void clasificarTemperatura (float temp);
int main ()
{
    float temp ;
    system("chcp 65001 > nul");
    printf("\tClasificador de Temperatura\n\n");
    printf("Ingrese la temperatura ambiente para saber el estado:\n");
    scanf("%f",&temp);
    clasificarTemperatura(temp);
    return 0;
}

void clasificarTemperatura (float temp)
{
    if (temp < 5)
    {
        printf("Muy fría\n\n");
    }
    else if (temp > 5 && temp < 15)
    {
        printf("Fría\n\n");
    }
    else if (temp > 15 && temp < 25)
    {
        printf("Agradable\n\n");
    }
    else if ( temp > 25 && temp <35)
    {
        printf ("Calurosa\n\n");
    }
    else if (temp >= 35)
    {
        printf ("Muy calurosa\n\n");
    }
    
}