#include <stdio.h>
#include <string.h>
#define TAM 30
struct perro {
    char nombre[TAM];
    int edadMeses;
    float peso;
} perros[3];

int main(){
    for(int i = 0; i<TAM ; i++)
    {
        printf("ingresa el nombre del perro %i:\n",i+1);
        scanf("%s",perros[i].nombre);
        printf("ingresa la edad del perro %i:\n",i+1);
        scanf("%i",&perros[i].edadMeses);
        printf("ingresa el peso del perro %i:\n",i+1);
        scanf("%f",&perros[i].peso);
    }

    for(int i = 0; i<TAM ; i++)
    {
        printf("El nombre del perro %i es %s\n",i+1,perros[i].nombre);
        printf("La edad del perro %i es %i\n",i+1,perros[i].edadMeses);
        printf("El peso del perro %i es %.2f\n",i+1,perros[i].peso);
    }

    return 0;
}