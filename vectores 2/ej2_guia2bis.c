/*
2. Promedios de notas y cantidad de aprobados
Enunciado:
Cargar un arreglo de 30 posiciones, donde cada 3 posiciones representa a un alumno y
contiene 3 notas (valores entre 1 y 10). Calcular el promedio de las 3 notas de cada
alumno y guardar esos promedios en un nuevo vector llamado resumen. Finalmente,
informar cuántos alumnos aprobaron, considerando que la nota mínima de aprobación
es 6 inclusive.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define totales 30
#define resumen 10

int numAle();
void cargarNotas(int v[]);
int promedioG(int v[],float alumnos[],float prom);
void informe(int aprobado, float alumnos[]);

int main()
{
    srand(time(NULL));
    int notas[totales];
    float alumnos[resumen];
    cargarNotas(notas);
    float promedio;

    promedioG(notas,alumnos,promedio);
    //int aprobado=promedioG(notas,alumnos,promedio);

    //informe(aprobado, alumnos);


    return 0;
}

int numAle()
{
    return (rand() % 10) +1;
}

void cargarNotas(int v[])
{
    for (int i = 0; i < totales; i++)
    {
        v[i]=numAle();
    }
    
}

int promedioG(int v[],float alumnos[],float prom)
{
    int aprobado=0;
    for (int i = 0; i < resumen; i++)
    {
        int indicex = i*3;
        prom = (v[indicex] + v[indicex +1] + v[indicex +2]) / 3.0;
        alumnos[i] = prom;

        if (prom >= 6)
        {
            aprobado++;
        }
        
    }
    return aprobado;
}

void informe(int aprobado, float alumnos[])
{
    //informar cuántos alumnos aprobaron, considerando que la nota mínima de aprobación
    //es 6 inclusive.

    printf("La cantidad de alumnos aprobados es: %d\n",aprobado);

    printf("Aca esta el promedio de los alumnos:\n");

    for (int i = 0; i < resumen; i++)
    {
        printf("Alumnos %d tiene nota: %.2f\n",i+1,alumnos[i]);
    }
    
}