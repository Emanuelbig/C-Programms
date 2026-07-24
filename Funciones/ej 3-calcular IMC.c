/*Objetivo:
Crear un programa que calcule el Índice de Masa
Corporal (IMC) de una persona y lo clasifique según
su valor

Indicaciones:
1.Definir una función calcular IMC(peso, altura) que
retorne el IMC usando la fórmula:
IMC = Peso / Altura

2.Definir otra función clasificar IMC(imc) que reciba el
resultado y retorne un texto con la categoría
correspondiente, según esta tabla:
IMC (kg/m²)           Clasificación
Menor a 18.5          Bajo peso
18.5 a 24.9           Peso normal
25.0 a 29.9           Sobrepeso
30.0 a 34.9           Obesidad grado I
35.0 a 39.9           Obesidad grado II
40.0 o más            Obesidad grado III (mórbida)

*/
#include <stdio.h>
float calcularIMC(float peso, float altura);
void clasificarIMC(float imc);

int main()
{
    float peso, altura, imc;
    printf("\tBienvenido al programa que calcula indice corporal\n\n");
    printf("Por favor ingrese su peso:\n");
    scanf("%f",&peso);
    printf("Por favor ingrese su altura:\n");
    scanf("%f", &altura);

    imc = calcularIMC(peso, altura);
    clasificarIMC(imc);

    printf("\nSu IMC es de %.2f", imc);

}

float calcularIMC(float peso, float altura)
{
    return peso / (altura*altura);
}

void clasificarIMC(float imc)
{
    if (imc < 18.5)
    {
        printf("\nBajo peso\n");
    }
    else
    {
        if (imc > 18.5 && imc < 24.9)
        {
            printf("\nPeso normal\n");
        }
        else
        {
            if (imc > 25 && imc < 29.9)
            {
                printf("\nSobrepeso\n");
            }
            else
            {
                if (imc > 30 && imc < 34.9)
                {
                    printf("\nObesidad grado I\n");
                }
                else
                {
                    if (imc > 35 && imc < 39.9)

                    {
                        printf("\nObesidad grado II\n");
                    }
                    else
                    {
                        if (imc > 39.9)
                        {
                            printf("\nObesidad grado III\n");
                        }
                        else
                        {
                            printf("\nTe re equivocaste\n");
                        }
                    }
                }
            }
        }
    }
}