#include <stdio.h>
#include <string.h>
#define TAMNOMBRE 30
#define TAMALUMNOS 2

struct alumno {
    char nombre[TAMNOMBRE];
    int legajo;
    float promedio;
} alumnos[TAMALUMNOS];

int main(){
    puts("***REGISTRO DE ESTUDIANTES***");
    for (int i = 0; i < TAMALUMNOS; i++)
    {
        printf("Escriba el nombre del alumno %i:\n",i+1);
        scanf("%s",alumnos[i].nombre);
        printf("Escriba el legajo del alumno %i:\n",i+1);
        scanf("%i",&alumnos[i].legajo);
        printf("Escriba el promedio del alumno %i:\n",i+1);
        scanf("%f",&alumnos[i].promedio);

    }
    puts("***DATOS REGISTRADOS***");
    for (int i = 0; i < TAMALUMNOS; i++)
    {
        printf("El alumno %i es %s y tiene legajo %i con promedio %.2f\n",i+1,alumnos[i].nombre,alumnos[i].legajo,alumnos[i].promedio);
        
    }
    
    float mejorPromedio=alumnos[0].promedio;
    int indiceMejorAlumno = 0;
    
    for (int i = 0; i < TAMALUMNOS; i++)
    {
        if (mejorPromedio<alumnos[i].promedio)
        {
            mejorPromedio=alumnos[i].promedio;
            indiceMejorAlumno = i;
        }
        
    }

    puts("***AlUMNO CON MEJOR PROMEDIO***");
    printf("Nombre del alumno: %s\n",alumnos[indiceMejorAlumno].nombre);
    printf("Legajo: %i\n",alumnos[indiceMejorAlumno].legajo);
    printf("Promedio: %.2f\n",mejorPromedio);
    
    return 0;
}


