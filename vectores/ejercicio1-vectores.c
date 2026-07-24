#include <stdio.h>

/*
Consigna: Escribir una funcion que reciba como parametro un vector de enteros y el tama;o definido por Uds, y
calcule la suma de todos los elementos del vector.

parte 2: Finalizado el ejercicio 1, arma una funcion que calcule el promedio.

*/
#define TAMANO_VECTOR 5

int vector(int[], int);

int main()
{
    int vectores [TAMANO_VECTOR] = {20, 30, 24, 45, 44};
    vector(vectores,TAMANO_VECTOR);

    
    return 0;
}

int vector(int vec[], int tam) {

    int suma = 0, promedio = 0;

    for (int i = 0; i < tam; i++)
    {
        printf("Se muestra %d\n\n", vec[i]);
        suma +=  vec[i];
        promedio = suma / 5;        
    }
    
    printf("La suma es %d\n",suma);
    printf("El promedio es %d\n",promedio); 
    return 0;
}

/*Simulen 10 mil tiradas con 2 dados y decir cuantas veces
salio cada num*/