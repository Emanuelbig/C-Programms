#include <stdio.h>
struct perro {
    char nombre[30];
    int edadMeses;
    float peso;
} perro1={"chikorita",10,3.50},perro2={"tony",24,4.5};

int main(){
    printf("El nombre del perro es: %s \n",perro1.nombre);
    printf("La edad del perro es: %i meses \n",perro1.edadMeses);
    printf("El peso del perro es: %.2f kilos \n",perro1.peso);
    printf("el nombres es %s, tiene una edad de %i meses y pesa %.2f kilos\n",perro1.nombre,perro1.edadMeses,perro1.peso);
    printf("el nombres del mas grande es %s, tiene una edad de %i meses y pesa %.2f kilos\n",perro2.nombre,perro2.edadMeses,perro2.peso);
    return 0;
}