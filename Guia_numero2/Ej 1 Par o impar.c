/*El centro de estudiantes de tu facu esta organizando un sorteo y necesita una funcion que clasifique si un numero de inscripcion
es par o impar. la decision afecta a que grupo de premios accede la persona si es par al grupo A, sino al B

Escribi un programa que permita ingresar un numero entero e implemente una funcion int Espar(int n) que informe si
es par o impar, luego retornara una respuesta, pueden si quieren sin obligacion utilizar la libreria bool, con
otro tipo de valor esperado.

Mostrar num par o impar

y una funcion maximos que determine el maximo de los 2.*/

#include <stdio.h>
#include <stdbool.h>
bool Espar(int n);
int Maximos(int grupoA, int grupoB);

int main()
{
    int n, grupoA = 0, grupoB = 0, numfor = 0;

    printf("Cuantos numeros quiere ingresar?");
    scanf("%d", &numfor);
    for (int i = 0; i < numfor; i++)
    {
        printf("Ingrese el numero para saber su condicion:");
        scanf("%d", &n);
        if (Espar(n))
        {
            grupoA++;
        }
        else
        {
            grupoB++;
        }
    }
    printf("Total del grupo A=%d\n", grupoA);
    printf("Total del grupo B=%d\n", grupoB);    
    Maximos(grupoA,grupoB);
    return 0;
}

bool Espar(int n)
{
    return n % 2 == 0;
}

int Maximos(int grupoA, int grupoB) {
    if (grupoA > grupoB)
    {
        printf("Grupo A ganador");
    } else if (grupoB > grupoA)
    {
        printf("Grupo B ganador");
    }else {
        printf("Empate");
    }
    return 0;
}