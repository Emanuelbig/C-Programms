/*
Ejercicio 1: Registro de Estudiantes
Definir una estructura llamada Alumno que contenga:
• Nombre (cadena de 30 caracteres)
• Legajo (entero)
• Nota promedio (float)
Escribir un programa que:
1. Permita cargar los datos de 5 alumnos.
2. Liste en pantalla todos los alumnos con sus datos.
3. Muestre el alumno con el mejor promedio.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//ESTRUCTURA
typedef struct
{
    char nombre[30];
    int legajo;
    float notaPromedio;
}Alumno;

//PROTOTIPOS:

//en este cargo los datos de cada alumno
void cargarAlumnos(Alumno alumnos[], int cantidad);
//en este muestro los datos que introdujo el usuario
void listarAlumnos(Alumno alumnos[], int cantidad);
//mostramos el alumno con mejor promedio
void mostrarMejorPromedio(Alumno alumnos[], int cantidad);

int main() {
    const int cantidadAlumnos = 5;
    Alumno alumnos[cantidadAlumnos];

    cargarAlumnos(alumnos, cantidadAlumnos);
    listarAlumnos(alumnos, cantidadAlumnos);
    mostrarMejorPromedio(alumnos, cantidadAlumnos);

    return 0;
}

void cargarAlumnos(Alumno alumnos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese los datos del alumno %d:\n", i + 1);
        printf("Nombre: ");
        fflush(stdin);//es para limpiar el buffer de entrada
        fgets(alumnos[i].nombre, 30, stdin);// Usar fgets para leer cadenas con espacios
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0'; // Eliminar el salto de línea
        printf("Legajo: ");
        scanf("%d", &alumnos[i].legajo);
        printf("Nota promedio: ");
        scanf("%f", &alumnos[i].notaPromedio);
        printf("\n");
    }
}

void listarAlumnos(Alumno alumnos[], int cantidad) {
    printf("Listado de alumnos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Alumno %d:\n", i + 1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Legajo: %d\n", alumnos[i].legajo);
        printf("Nota promedio: %.2f\n\n", alumnos[i].notaPromedio);
    }
}

void mostrarMejorPromedio(Alumno alumnos[], int cantidad) {
    int indiceMejor = 0;
    for (int i = 1; i < cantidad; i++) {
        if (alumnos[i].notaPromedio > alumnos[indiceMejor].notaPromedio) {
            indiceMejor = i;
        }
    }
    printf("El alumno con el mejor promedio es:\n");
    printf("Nombre: %s\n", alumnos[indiceMejor].nombre);
    printf("Legajo: %d\n", alumnos[indiceMejor].legajo);
    printf("Nota promedio: %.2f\n", alumnos[indiceMejor].notaPromedio);
}


