/*
Ejercicio 02 – Encuesta de satisfacción en una clínica
Una clínica desea analizar los resultados de una encuesta de satisfacción realizada a 100
pacientes sobre la atención recibida en 3 especialidades médicas:
• Traumatología (1)
• Gastroenterología (2)
• Cardiología (3)
Cada paciente calificó la atención recibida con un puntaje del 1 al 5, donde:
• 1 = Muy mala
• 5 = Excelente
Objetivo del programa
El sistema debe procesar las respuestas y brindar los siguientes resultados:
1. Informar el promedio de calificaciones obtenidas por cada especialidad.
2. Calcular la media general considerando todas las calificaciones.
3. Para cada especialidad, indicar el porcentaje de calificaciones que fueron 4 o 5,
consideradas como positivas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define pacientes 100
#define especialidades 3

int puntajeAleatorio();
int sorteoEspecialidad();
void simular100encuestas(int sumaC[], int cantC[], int califPos[]);

int main()
{
    srand(time(NULL));
    int sumaCalificaciones[especialidades] = {0};
    int cantidadCalificaciones[especialidades] = {0};
    int calificacionesPositivas[especialidades] = {0};


}

int puntajeAleatorio()
{
    return (rand() % 5) +1;
}

int sorteoEspecialidad()
{
    return rand() % 3;
}

void simular100encuestas(int sumaC[], int cantC[], int califPos[])
{
    for (int i = 0; i < pacientes; i++)
    {
        int especialidad = sorteoEspecialidad();  // 0 a 2
        int puntaje = puntajeAleatorio();  // 1 a 5

        sumaC[especialidad] += puntaje;
        cantC[especialidad]++;

        if (puntaje >= 4)
        {
            califPos[especialidad]++;
        }
    }
}

//No lo termine